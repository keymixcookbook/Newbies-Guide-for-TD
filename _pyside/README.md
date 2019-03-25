# PYSIDE (in a nutshell :chestnut:)
Python on steriods

###### PySide or PyQt
same

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

# Make Widget Objects
class AppObject(QLabel):
	# Constructor
	def __init__(self):
		QLable.__init__(self, "Any QWidget Object here")

		# Set initial values
		self.setMinimumSize(QSize(600,400))
		self.setAlignment(Qt.AlignCenter)
		self.setWindowTitle("This QWidget Title")

	# Run Application
	def run(self):
		self.show()
		app.exec_()
		
AppObject().run()
```
