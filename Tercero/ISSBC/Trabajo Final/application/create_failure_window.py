from PyQt5.QtWidgets import *

from src.observable import Observable
from src.observable_repository import ObservableRepository

COORDINATE_X = 300
COORDINATE_Y = 300

WIGTH = 300
HIGHT = 300


class CreateFailureDialog(QDialog):

    def __init__(self, domain_id):
        QDialog.__init__(self)
        self.domain_id = domain_id
        self.saved_observable = None
        self._initUI()
        
 
    def _initUI(self):
        self.setGeometry(COORDINATE_X, COORDINATE_Y, WIGTH, HIGHT)
        self.setWindowTitle("New Failure")
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