
import sys
from PyQt5 import QtGui, QtCore


COORDINATE_X = 300
COORDINATE_Y = 300

WIGTH = 300
HIGHT = 300

class CreateDomainWindow(QtGui.QMainWindow):
 
    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        self._initUI()
        
 
    def _initUI(self):
        self.setGeometry(COORDINATE_X, COORDINATE_Y, WIGTH, HIGHT)
        self.setWindowTitle("New Domain")

        self.show()

    def createFormGroupBox(self):
        self.formGroupBox = QGroupBox("Form layout")
        layout = QFormLayout()
        layout.addRow(QLabel("Name:"), QLineEdit())
        layout.addRow(QLabel("Description:"), QLineEdit())
        self.formGroupBox.setLayout(layout)