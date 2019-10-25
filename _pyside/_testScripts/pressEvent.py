from PySide.QtGui import *
from PySide.QtCore import *

class SetLabel(QDialog):
    def __init__(self):
        super(SetLabel,self).__init__()

        prevLabel = nuke.selectedNode()['label'].getValue()

        self.lineInput = QLineEdit()
        self.lineInput.setText(prevLabel)
        self.lineInput.returnPressed.connect(self.onPressed)
        self.title = QLabel("<b>Set Label</b>")
        self.title.setAlignment(Qt.AlignHCenter)

        self.layout = QVBoxLayout()
        self.layout.addWidget(self.title)
        self.layout.addWidget(self.lineInput)
        self.setLayout(self.layout)
        self.move(QCursor.pos())
        self.setWindowTitle("Set Label")
        #self.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint)
        
        

    def onPressed(self):
        # Change Values

        newLabel = self.lineInput.text()
        for n in nuke.selectedNodes():
            n['label'].setValue(newLabel)
        
        self.close()

p = SetLabel()
p.show()

