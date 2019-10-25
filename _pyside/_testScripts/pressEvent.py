from PySide.QtGui import *
from PySide.QtCore import *

class core_SetLabel(QDialog):
    def __init__(self):
        super(core_SetLabel,self).__init__()

        prevLabel = nuke.selectedNode()['label'].getValue()

        self.lineInput = QLineEdit()
        self.lineInput.setText(prevLabel)
        self.lineInput.setAlignment(Qt.AlignCenter)
        self.lineInput.returnPressed.connect(self.onPressed)
        self.title = QLabel("<b>Set Label</b>")
        self.title.setAlignment(Qt.AlignHCenter)

        self.layout = QVBoxLayout()
        self.layout.addWidget(self.title)
        self.layout.addWidget(self.lineInput)
        self.setLayout(self.layout)
        self.move(QCursor.pos())
        self.setWindowTitle("Set Label")
        self.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint)
        
    def onPressed(self):
        # Change Values

        newLabel = self.lineInput.text()
        for n in nuke.selectedNodes():
            n['label'].setValue(newLabel)
        
        self.close()
        
    def open(self):
        sel = nuke.selectedNodes()
        if len(sel)>0:    
            self.show()
        else:
            print "No node selected"


p = core_SetLabel()
p.open()     
