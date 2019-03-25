# PYSIDE (in a nutshell :chestnut:)
Python on steriods

###### The Basics
- PySide has 2 main objects: `QtCore` & `QtGui`
- `QWidget`: all visiable elements (**widget**) 
- `QApplication()`: **only one** per Qt application

```python
# Import Module
from PySide.QtCore import *
from PySide.QtGui import *

# Define QApplication
app = QApplication(parent=none)

# Make Widgets
widget = QLabel('Any QWidget Object here')

# Run Application
widget.show()
app.exec_()

```
