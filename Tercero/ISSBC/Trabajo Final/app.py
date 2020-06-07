
import sys
from PyQt5.QtWidgets import *
from application.create_domain_window import CreateDomainDialog
from application.main_window import MainWindow
from src.domain_repository import DomainRepository
from src.observable_repository import ObservableRepository


COORDINATE_X = 300
COORDINATE_Y = 300

WIGTH = 500
HIGHT = 500

from dotenv import load_dotenv

load_dotenv()

class NewDomainButton(QPushButton):

    def __init__(self, name, widget):
        super(NewDomainButton, self).__init__(name, widget)
        self.initUI()
        self.__create_domain_window = None

    def initUI(self):
        self.setToolTip('Create new domain')
        self.move(50, 50)
        self.resize(self.sizeHint())
        self.clicked.connect(self.on_pushButton_clicked)

    def on_pushButton_clicked(self):
        self.__create_domain_window = CreateDomainDialog()
        self.__create_domain_window.exec_()
        self.parent().reloadDomains()


class ReloadDomainButton(QPushButton):

    def __init__(self, name, widget):
        super(ReloadDomainButton, self).__init__(name, widget)
        self.initUI()

    def initUI(self):
        self.setToolTip('Create new domain')
        self.move(50, 50)
        self.resize(self.sizeHint())


class AcceptDomainButton(QPushButton):

    def __init__(self, name, widget):
        super(AcceptDomainButton, self).__init__(name, widget)
        self.initUI()
        self.__create_domain_window = None

    def initUI(self):
        self.setToolTip('Create new domain')
        self.move(50, 50)
        self.resize(self.sizeHint())
        self.clicked.connect(self.on_pushButton_clicked)

    def on_pushButton_clicked(self):
        domain_repository = DomainRepository()
        domain = domain_repository.getByName(self.parent().domain.currentText())
        self.__create_domain_window = MainWindow(domain.domain_id)
        self.__create_domain_window.exec_()


class SelectDomain(QDialog):
 
    def __init__(self):
        QDialog.__init__(self)
        self._initUI()
        
    def _initUI(self):
        self.setGeometry(COORDINATE_X, COORDINATE_Y, WIGTH, HIGHT)
        self.setWindowTitle("Select Domain")

        self.createFormGroupBox()
        self.accept_button = AcceptDomainButton("Accept", self)
        self.new_button = NewDomainButton("New", self)
        self.reload_button = ReloadDomainButton("Reload", self)
        self.reload_button.clicked.connect(self.reloadDomains)
        

        buttonLayout = QHBoxLayout()
        buttonLayout.addWidget(self.accept_button)
        buttonLayout.addWidget(self.new_button)
        buttonLayout.addWidget(self.reload_button)

        formLayout = QVBoxLayout()
        formLayout.addWidget(self.formGroupBox)
        formLayout.addLayout(buttonLayout)

        self.setLayout(formLayout)

    def createFormGroupBox(self):
        self.formGroupBox = QGroupBox("Select Domain")
        layout = QFormLayout()
        self.domain = QComboBox()
        self.domain.width = 250
        self.reloadDomains()
        layout.addRow(QLabel("Domain:"), self.domain)
        self.formGroupBox.setLayout(layout)

    def reloadDomains(self):
        domain_repository = DomainRepository()
        self.domain.clear()
        domain_list = domain_repository.getAll()
        if not domain_list:
            return False
        self.domain.addItems(list(map(lambda domain: domain.name, domain_repository.getAll())))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    select_domain = SelectDomain()
    select_domain.show()
    sys.exit(app.exec_())