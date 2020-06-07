from PyQt5.QtWidgets import *

from src.diagnosis_service import DiagnosisService

from src.observable_repository import ObservableRepository
from src.observable import Observable

from src.hypothesis_repository import HypothesisRepository
from src.hypothesis import Hypothesis

from application.create_observable_window import CreateObservableDialog
from application.create_hypothesis_window import CreateHypothesisDialog
from application.create_failure_window import CreateFailureDialog

COORDINATE_X = 300
COORDINATE_Y = 300

WIGTH = 1000
HIGHT = 500

class NewObservableButton(QPushButton):

    def __init__(self, name, widget):
        super(NewObservableButton, self).__init__(name, widget)
        self.initUI()
        self.__create_observable_window = None

    def initUI(self):
        self.setToolTip('Create new Observable')
        self.move(50, 50)
        self.resize(self.sizeHint())
        self.clicked.connect(self.on_pushButton_clicked)

    def on_pushButton_clicked(self):
        self.__create_observable_window = CreateObservableDialog(self.parent().domain_id)
        self.__create_observable_window.exec_()
        self.parent().reload_lists()

class ReloadButton(QPushButton):

    def __init__(self, name, widget):
        super(ReloadButton, self).__init__(name, widget)
        self.initUI()

    def initUI(self):
        self.setToolTip('Create new domain')
        self.move(50, 50)
        self.resize(self.sizeHint())


class NewHypothesisButton(QPushButton):

    def __init__(self, name, widget):
        super(NewHypothesisButton, self).__init__(name, widget)
        self.initUI()
        self.__create_hypothesis_window = None

    def initUI(self):
        self.setToolTip('Create new Hypothesis')
        self.move(50, 50)
        self.resize(self.sizeHint())
        self.clicked.connect(self.on_pushButton_clicked)

    def on_pushButton_clicked(self):
        self.__create_hypothesis_window = CreateHypothesisDialog(self.parent().domain_id)
        self.__create_hypothesis_window.exec_()
        self.parent().reload_lists()

class NewFailButton(QPushButton):

    def __init__(self, name, widget):
        super(NewFailButton, self).__init__(name, widget)
        self.initUI()
        self.__create_fail_window = None

    def initUI(self):
        self.setToolTip('Create new failure')
        self.move(50, 50)
        self.resize(self.sizeHint())
        self.clicked.connect(self.on_pushButton_clicked)

    def on_pushButton_clicked(self):
        self.__create_fail_window = CreateFailureDialog(self.parent().domain_id)
        self.__create_fail_window.exec_()
        self.parent().failures.append(self.__create_fail_window.saved_observable)
        self.parent().reload_lists()


class ExecuteButton(QPushButton):

    def __init__(self, name, widget):
        super(ExecuteButton, self).__init__(name, widget)
        self.initUI()

    def initUI(self):
        self.setToolTip('Create new Hypothesis')
        self.move(50, 50)
        self.resize(self.sizeHint())
        self.clicked.connect(self.on_pushButton_clicked)

    def on_pushButton_clicked(self):
        diagnosis = DiagnosisService(ObservableRepository(), HypothesisRepository())
        self.parent().results = diagnosis.execute(self.parent().failures, self.parent().domain_id)
        self.parent().reload_lists()


class MainWindow(QDialog):

    def __init__(self, domain_id):
        QDialog.__init__(self)
        self.domain_id = domain_id
        self.failures = []
        self.results = []
        self._initUI()

    def _initUI(self):
        new_observable_button = NewObservableButton("New Observable", self)
        new_hypothesis_button = NewHypothesisButton("New Hypothesis", self)
        new_fail_button = NewFailButton("New Failure", self)
        execute_button = ExecuteButton("Execute Diagnosis", self)
        reload_button = ReloadButton("Reload", self)
        reload_button.clicked.connect(self.reload_lists)
        self.create_observables_list()
        self.create_hypotheses_list()
        self.create_failures_list()
        self.create_result_list()

        obser_button_layout = QHBoxLayout()
        obser_button_layout.addWidget(new_observable_button)
        obserLayout = QVBoxLayout()
        obserLayout.addWidget(self.observables_list)
        obserLayout.addLayout(obser_button_layout)

        hypo_button_layout = QHBoxLayout()
        hypo_button_layout.addWidget(new_hypothesis_button)
        hypoLayout = QVBoxLayout()
        hypoLayout.addWidget(self.hypothesis_list)
        hypoLayout.addLayout(hypo_button_layout)

        DomainLayout = QHBoxLayout()
        DomainLayout.addLayout(obserLayout)
        DomainLayout.addLayout(hypoLayout)

        AppLayout = QHBoxLayout()
        failLayout = QVBoxLayout()
        failLayout.addWidget(self.failures_list)
        failLayout.addWidget(new_fail_button)
        AppLayout.addLayout(failLayout)
        AppLayout.addWidget(execute_button)
        AppLayout.addWidget(self.result_list) 

        MainLayout = QVBoxLayout()
        MainLayout.addLayout(DomainLayout)
        MainLayout.addLayout(AppLayout)
        MainLayout.addWidget(reload_button)

        
        self.setLayout(MainLayout)
        self.setGeometry(COORDINATE_X, COORDINATE_Y, WIGTH, HIGHT)
        self.setWindowTitle("Diagnosis")

    
    def create_observables_list(self):
        observables_respository = ObservableRepository()
        self.observables_list = QListWidget()

        observables = observables_respository.getByDomain(self.domain_id)
        if not observables:
            return False

        order = 0
        for observable in observables:
            self.observables_list.insertItem(order, observable.name)
            order += 1

    def create_hypotheses_list(self):
        hypothesis_respository = HypothesisRepository()
        self.hypothesis_list = QListWidget()

        hypotheses = hypothesis_respository.getByDomain(self.domain_id)
        if not hypotheses:
            return False

        order = 0
        for hypothesis in hypotheses:
            self.hypothesis_list.insertItem(order, hypothesis.name)
            order += 1


    def create_failures_list(self):
        self.failures_list = QListWidget()
        if not self.failures:
            return False

        order = 0
        for fail in self.failures:
            self.failures_list.insertItem(order, fail.name)
            order += 1

    def create_result_list(self):
        self.result_list = QListWidget()
        if not self.results:
            return False

        order = 0
        for result in self.results:
            self.result_list.insertItem(order, result.name)
            order += 1

    def reload_lists(self):
        self.reload_observable_list()
        self.reload_hypotheses_list()
        self.reload_result_list()
        self.reload_failures_list()


    def reload_observable_list(self):
        observables_respository = ObservableRepository()
        self.observables_list.clear()

        observables = observables_respository.getByDomain(self.domain_id)
        if not observables:
            return False

        order = 0
        for observable in observables:
            self.observables_list.insertItem(order, observable.name)
            order += 1

    def reload_hypotheses_list(self):
        hypothesis_respository = HypothesisRepository()
        self.hypothesis_list.clear()

        hypotheses = hypothesis_respository.getByDomain(self.domain_id)
        if not hypotheses:
            return False

        order = 0
        for hypothesis in hypotheses:
            self.hypothesis_list.insertItem(order, hypothesis.name)
            order += 1

    def reload_failures_list(self):
        self.failures_list.clear()
        if not self.failures:
            return False

        order = 0
        for fail in self.failures:
            self.failures_list.insertItem(order, fail.name)
            order += 1

    def reload_result_list(self):
        self.result_list.clear()
        if not self.results:
            return False

        order = 0
        for result in self.results:
            self.result_list.insertItem(order, result.name)
            order += 1