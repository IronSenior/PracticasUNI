



from PyQt4.QtGui import QAction
from PyQt4.QtGui import QFileDialog

class SaveFileAction(QAction):


    def __init__(self, title, window):
        super(SaveFileAction, self).__init__(title, window)
        self.setShortcut('Ctrl+S')
        self.triggered.connect(self.saveFile)


    def saveFile(self):
        filename = QFileDialog.getSaveFileName(self, 'Save File')

        with open(filename, 'w') as text_file:
            filedata = self.parentWidget().txt.toPlainText()
            text_file.write(filedata)
            text_file.close()
         