import sys
from PyQt4 import QtGui, QtCore
from new_file_action import NewFileAction
from open_file_action import OpenFileAction
from save_file_action import SaveFileAction


COORDINATE_X = 300
COORDINATE_Y = 300

WIGTH = 300
HIGHT = 300

class Main(QtGui.QMainWindow):
 
    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        self._initUI()
        
 
    def _initUI(self):
        self.setGeometry(COORDINATE_X, COORDINATE_Y, WIGTH, HIGHT)
        self.setWindowTitle("Editor de Texto simple")

        self._cofigure_menu()

        self.txt = QtGui.QTextEdit(self)
        self.setCentralWidget(self.txt)

        self.show()
 

    def _cofigure_menu(self):
        menubar = self.menuBar()
        fileMenu = menubar.addMenu('File')
        fileMenu.addAction(NewFileAction("New", self))
        fileMenu.addAction(SaveFileAction("Save", self))
        fileMenu.addAction(OpenFileAction("Open", self))
 


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    main = Main()
    main.show()
 
    sys.exit(app.exec_())