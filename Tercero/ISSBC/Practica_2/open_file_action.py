from PyQt4.QtGui import QAction
from PyQt4.QtGui import QFileDialog

class OpenFileAction(QAction):


    def __init__(self, title, window):
        super(OpenFileAction, self).__init__(title, window)
        self.setShortcut('Ctrl+O')
        self.triggered.connect(self.openFile)


    def openFile(self):
        filename = QFileDialog.getOpenFileName(self, 'Open File')

        with open(filename, 'r') as text_file:
            filedata = text_file.read()
            self.parentWidget().txt.setText(filedata)
            text_file.close()
         