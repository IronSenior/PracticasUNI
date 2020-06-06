#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
from PyQt4 import QtCore, QtGui, uic

class MainWindow(QtGui.QWidget):
   def __init__(self, parent=None):
       super(MainWindow, self).__init__(parent)
       self.setAttribute(QtCore.Qt.WA_DeleteOnClose)
       self.setAttribute(QtCore.Qt.WA_GroupLeader)
       self.menuI = QtGui.QPushButton("Menu")
       self.menuI.setToolTip("Click here...")
       self.menuI.setContextMenuPolicy(QtCore.Qt.ActionsContextMenu)

       mainLayout = QtGui.QHBoxLayout()
       mainLayout.addWidget(self.menuI)
       self.setLayout(mainLayout)
       self.resize(49,40)
       self.setWindowTitle("Qt menu")

       self.clicAct0 = QtGui.QAction("0", self)
       self.clicAct0.setToolTip("tooltip 0")
       self.connect(self.clicAct0, QtCore.SIGNAL("triggered()"), self.clic)

       self.clicAct1 = QtGui.QAction("1", self)
       self.clicAct1.setToolTip("tooltip 1")
       self.connect(self.clicAct1, QtCore.SIGNAL("triggered()"), self.clic)

       self.clicAct2 = QtGui.QAction("2", self)
       self.clicAct2.setToolTip("tooltip 2")
       self.connect(self.clicAct2, QtCore.SIGNAL("triggered()"), self.clic)

       menu0 = QtGui.QMenu(self)
       menu0.addAction(self.clicAct0)
       menu0.addAction(self.clicAct1)
       menu0.addAction(self.clicAct2)

       self.connect(menu0, QtCore.SIGNAL("hovered(QAction *)"),
       self._actionHovered)

       menu1 = QtGui.QMenu(self)

       menu1.setTitle("submenu")
       menu1.setToolTip("tooltip submenu")

       menu1_0 = QtGui.QAction("subentry",self)
       menu1_0.setToolTip("tooltip subentry")

       self.connect(menu1_0, QtCore.SIGNAL("triggered()"), self.clic)
       menu1.addAction(menu1_0)
       menu0.addMenu(menu1)
       self.menuI.setMenu(menu0)

   def clic(self):
       print "clic"

   def _actionHovered(self, action):
       tip = action.toolTip()
       QtGui.QToolTip.showText(QtGui.QCursor.pos(), tip)

def main():
   app = QtGui.QApplication(sys.argv)
   locale = QtCore.QLocale.system().name()
   appTranslator = QtCore.QTranslator()
   app.setApplicationName(app.translate("main", "qtmenu"))

   form = MainWindow()
   form.show()
   app.exec_()

if __name__ == "__main__":
   main()





