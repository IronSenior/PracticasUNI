from PyQt5.QtWidgets import *

import uuid

from src.hypothesis import Hypothesis
from src.hypothesis_repository import HypothesisRepository

from src.observable import Observable
from src.observable_repository import ObservableRepository

COORDINATE_X = 300
COORDINATE_Y = 300

WIGTH = 300
HIGHT = 300

class AddObservableDialog(QDialog):

    def __init__(self, domain_id):
        QDialog.__init__(self)
        self.domain_id = domain_id
        self.saved_observable = None
        self._initUI()
        
 
    def _initUI(self):
        self.setGeometry(COORDINATE_X, COORDINATE_Y, WIGTH, HIGHT)
        self.setWindowTitle("Add Observable")
        self.createFormGroupBox()

        buttonBox = QDialogButtonBox(QDialogButtonBox.Ok | QDialogButtonBox.Cancel)
        buttonBox.accepted.connect(self.accept)
        buttonBox.rejected.connect(self.reject)
        
        mainLayout = QVBoxLayout()
        mainLayout.addWidget(self.formGroupBox)
        mainLayout.addWidget(buttonBox)
        self.setLayout(mainLayout)

    def createFormGroupBox(self):
        self.formGroupBox = QGroupBox("Create Domain")
        layout = QFormLayout()
        self.observable = QComboBox()
        self.reloadObservables()
        layout.addRow(QLabel("Observable:"), self.observable)
        self.formGroupBox.setLayout(layout)

    def reloadObservables(self):
        observable_repository = ObservableRepository()
        self.observable.clear()
        observable_list = observable_repository.getByDomain(self.domain_id)
        if not observable_list:
            return False
        self.observable.addItems(list(map(lambda domain: domain.name, observable_list)))

    def accept(self):
        observable_repository = ObservableRepository()
        observable = observable_repository.getByName(self.observable.currentText())
        observable.setValue(True)
        self.saved_observable = observable
        return super().accept()



class AddObservableButton(QPushButton):

    def __init__(self, name, widget):
        super(AddObservableButton, self).__init__(name, widget)
        self.initUI()
        self.__add_observable_window = None

    def initUI(self):
        self.setToolTip('Add new Observable')
        self.move(50, 50)
        self.resize(self.sizeHint())
        self.clicked.connect(self.on_pushButton_clicked)

    def on_pushButton_clicked(self):
        self.__add_observable_window = AddObservableDialog(self.parent().domain_id)
        self.__add_observable_window.exec_()
        self.parent().observables.append(self.__add_observable_window.saved_observable)
        self.parent().reloadObservables()


class CreateHypothesisDialog(QDialog):

    def __init__(self, domain_id):
        QDialog.__init__(self)
        self.domain_id = domain_id
        self.observables = []
        self._initUI()
        
 
    def _initUI(self):
        self.setGeometry(COORDINATE_X, COORDINATE_Y, WIGTH, HIGHT)
        add_observable_button = AddObservableButton("Add Observable", self)
        self.setWindowTitle("New Hypothesis")
        self.createFormGroupBox()

        self.create_observable_list()
        buttonBox = QDialogButtonBox(QDialogButtonBox.Ok | QDialogButtonBox.Cancel)
        buttonBox.accepted.connect(self.accept)
        buttonBox.rejected.connect(self.reject)
        
        mainLayout = QVBoxLayout()
        mainLayout.addWidget(self.formGroupBox)
        mainLayout.addWidget(self.observables_list)
        mainLayout.addWidget(add_observable_button)
        mainLayout.addWidget(buttonBox)

        self.setLayout(mainLayout)

    def createFormGroupBox(self):
        self.formGroupBox = QGroupBox("Create Domain")
        layout = QFormLayout()
        self.name = QLineEdit()
        self.description = QLineEdit()
        layout.addRow(QLabel("Name:"), self.name)
        layout.addRow(QLabel("Description:"), self.description)
        self.formGroupBox.setLayout(layout)


    def create_observable_list(self):
        self.observables_list = QListWidget()

        if not self.observables:
            return False

        order = 0
        for observable in self.observables:
            self.observables_list.insertItem(order, observable.name)
            order += 1

    def reloadObservables(self):
        self.observables_list.clear()
        if not self.observables:
            return False
        order = 0
        for observable in self.observables:
            self.observables_list.insertItem(order, observable.name)
            order += 1
        
    def accept(self):
        hypothesis_repository = HypothesisRepository()
        hypothesis = Hypothesis(uuid.uuid4(), self.domain_id, self.name.text(), self.description.text(), self.observables)
        hypothesis_repository.add(hypothesis)
        return super().accept()