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



class Help(QtGui.QWidget):
    
    def __init__(self):
        super(Help, self).__init__()
        self.initUI()
        

    def initUI(self):
        # We define what the help message is going to say
        self.setToolTip('Esto es una ayuda emergente')
        false_button = HelpButton('Prueba', self)
        self.setWindowTitle('Ayuda Emergente')    
        self.show()


def main():
    app = QtGui.QApplication(sys.argv)
    ex = Help()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()