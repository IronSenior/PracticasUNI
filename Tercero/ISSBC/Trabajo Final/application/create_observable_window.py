
import sys
from PyQt5.QtWidgets import *
import uuid

from src.observable import Observable
from src.observable_repository import ObservableRepository


COORDINATE_X = 300
COORDINATE_Y = 300

WIGTH = 300
HIGHT = 300

VALUE_TYPES = ["Boolean", "Integer", "String"]

class CreateObservableDialog(QDialog):
 
    def __init__(self, domain_id):
        QDialog.__init__(self)
        self.domain_id = domain_id
        self._initUI()
        
 
    def _initUI(self):
        self.setGeometry(COORDINATE_X, COORDINATE_Y, WIGTH, HIGHT)
        self.setWindowTitle("New Domain")
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
        self.name = QLineEdit()
        self.description = QLineEdit()
        self.value_type = QComboBox()
        self.value_type.addItems(VALUE_TYPES)
        layout.addRow(QLabel("Name:"), self.name)
        layout.addRow(QLabel("Description:"), self.description)
        layout.addRow(QLabel("Value Type:"), self.value_type)
        self.formGroupBox.setLayout(layout)


    def accept(self):
        observable_repository = ObservableRepository()
        observable = Observable(uuid.uuid4(), self.domain_id, self.name.text(), 
                        self.description.text(), self.value_type.currentText()
                        )
        observable_repository.add(observable)
        return super().accept()
