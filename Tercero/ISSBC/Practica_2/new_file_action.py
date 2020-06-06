from PyQt4.QtGui import QAction

class NewFileAction(QAction):
    def __init__(self, title, window):
        super(NewFileAction, self).__init__(title, window)
        self.setShortcut('Ctrl+N')
        self.triggered.connect(self.newFile)

    def newFile(self):
        self.parentWidget().txt.clear()