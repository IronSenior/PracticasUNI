
import sys
from PyQt5.QtWidgets import *
import uuid

from src.domain import Domain
from src.domain_repository import DomainRepository


COORDINATE_X = 300
COORDINATE_Y = 300

WIGTH = 300
HIGHT = 300


class CreateDomainDialog(QDialog):
 
    def __init__(self):
        QDialog.__init__(self)
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
        layout.addRow(QLabel("Name:"), self.name)
        layout.addRow(QLabel("Description:"), self.description)
        self.formGroupBox.setLayout(layout)


    def accept(self):
        domain_repository = DomainRepository()
        domain = Domain(uuid.uuid4(), self.name.text(), self.description.text())
        domain_repository.add(domain)
        return super().accept()