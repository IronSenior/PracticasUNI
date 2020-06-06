
import sys
from PyQt5 import QtGui, QtCore 

from create_domain_window import CreateDomainWindow

COORDINATE_X = 300
COORDINATE_Y = 300

WIGTH = 300
HIGHT = 300

class NewDomainButton(QtGui.QPushButton):

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
        self.__create_domain_window = CreateDomainWindow()
        self.__create_domain_window.show()



class Main(QtGui.QMainWindow):
 
    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        self._initUI()
        
 
    def _initUI(self):
        self.setGeometry(COORDINATE_X, COORDINATE_Y, WIGTH, HIGHT)
        self.setWindowTitle("Editor de Texto simple")

        self.new_domain_button = NewDomainButton("New Domain", self)
        self.setCentralWidget(self.new_domain_button)

        self.show()
 


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    main = Main()
    main.show()
 
    sys.exit(app.exec_())