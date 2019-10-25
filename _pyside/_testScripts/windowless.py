from PySide.QtGui import *
from PySide.QtCore import *
import sys


def diceRoll():
    import random

    #face = ['1','2','3','4','5','6']
    face = ['9856','9857','9858','9859','9860','9861']

    roll = random.randint(0,int(len(face)-1))

    label.setText('<h1>&#%s;</h1>' % face[roll])


app = QApplication(sys.argv)
panel = QWidget()


button = QPushButton("Roll")
button.setMinimumHeight(50)
button.clicked.connect(diceRoll)
label = QLabel('<h1>This is Frame less dice roll</h1>')
label.setAlignment(Qt.AlignHCenter)

layout = QVBoxLayout()
layout.addWidget(button)
layout.addWidget(label)
panel.setLayout(layout)

panel.move(QCursor.pos())
panel.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint)






# Show the panel

panel.show()
app.exec_()
