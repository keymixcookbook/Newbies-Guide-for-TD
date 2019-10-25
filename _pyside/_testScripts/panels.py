
from PySide.QtGui import *
from PySide.QtCore import *
import sys


class Panel(QWidget):
    def __init__(self):
        super(Panel, self).__init__()

        self.tx_label = QLabel("<h1>ROLL THE DICE</h1>")
        self.tx_label.setAlignment(Qt.AlignHCenter)
        self.tx_label.setFont(QFont(pointSize=100, weight=1))
        self.bt_roll = QPushButton()
        self.bt_roll.setText('ROLL')
        self.bt_roll.clicked.connect(self.diceRoll)

        self.layout = QVBoxLayout()
        self.layout.addWidget(self.bt_roll)
        self.layout.addWidget(self.tx_label)
        self.setLayout(self.layout)

    def diceRoll(self):
        import random

        #face = ['1','2','3','4','5','6']
        face = ['9856','9857','9858','9859','9860','9861']

        roll = random.randint(0,int(len(face)-1))

        self.tx_label.setText('<h1>&#%s;</h1>' % face[roll])

# Show the panel
app = QApplication(sys.argv)
panel = Panel()
panel.show()
app.exec_()
