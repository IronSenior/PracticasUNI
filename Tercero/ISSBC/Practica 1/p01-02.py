#!/usr/bin/python
# -*- coding: utf-8 -*-
# This is a qt4 example made for class
# I dont recommend to follow this practices

import sys
from PyQt4 import QtGui

class HelpButton(QtGui.QPushButton):

    def __init__(self, name, widget):
        super(HelpButton, self).__init__(name, widget)
        self.initUI()

    def initUI(self):
        # We define what the help message is going to say
        self.setToolTip('Esto es una ayuda emergente pero en un boton')
        self.move(50, 50)
        self.resize(self.sizeHint())


class Help(QtGui.QMainWindow):
    
    def __init__(self):
        super(Help, self).__init__()
        self.initUI()
        

    def initUI(self):
        # We define what the help message is going to say
        self.setToolTip('Esto es una ayuda emergente')
        HelpButton('Prueba', self)
        self.setWindowTitle('Ayuda Emergente')    
        false_button = HelpButton('Prueba', self)
        self.statusBar().showMessage('Todo Listo')  
        self.show()

        exitAction = QtGui.QAction(QtGui.QIcon('exit.png'), '&Exit', self)        
        exitAction.setShortcut('Ctrl+Q')
        exitAction.setStatusTip('Exit application')
        exitAction.triggered.connect(QtGui.qApp.quit)

        self.statusBar()

        menubar = self.menuBar()


        fileMenu = menubar.addMenu('&File')


        fileMenu.addAction(exitAction)
        
        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Menubar')    
        self.show()

        self.toolbar = self.addToolBar('Exit')
        self.toolbar.addAction(exitAction)


def main():
    app = QtGui.QApplication(sys.argv)
    ex = Help()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()