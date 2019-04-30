# PYSIDE (in a nutshell :chestnut:)
Python on steriods

### PySide or PyQt
basically the same ([for more detailed differences](https://wiki.qt.io/Differences_Between_PySide_and_PyQt))

### The Basics
- PySide has 2 main objects: `QtCore` & `QtGui`
- `QWidget`: all visiable elements (**widget**)
- `QApplication()`: **only one** per Qt application
- [Infographic for the components](./pysideInfographic.md)

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

### Useful/Basic Widgets
Building blocks for PySide, just like bricks of Lego

```python
from PySide import QtGui

# QtGui.QLabel
label = QLabel('Label')

# QtGui.QLineEdit
line = QLineEdit("Initial Value") # Define Widget

line.setText("My Text") # Same as above
line.text() # Return the text of the 'QLineEdit' object
line.setReadOnly(False)
line.setMaxLength(20) # Max numbers of charactor can enter
line.setAlignment(Qt.AlignCenter) # Align Text
line_suggestion = ['Potato', 'Cabbage', 'Burrito']
completer = QCompleter(line_suggestion)
line.setCompleter(completer)
line.setPlaceholderText("This is a placeholder text ")

# QtGui.QPushButton
push = QPushButton('push')

push.setText("New Push") # Overwrites param in object
push.setIcon(QIcon("/location"))
push.setShortcut('u')
push.setToolTip("This is a tooltip when hover")
push.setCheckable(True) # State of the QPushButton

# QtGui.QCheckBox
checkbox = QCheckBox('Checkbox')

checkbox.setChecked(True)
checkbox.isChecked() # Return if checked or not, Boolean

# QtGui.QCombobox
combo = QComboBox()

combo.addItem('Potato') # Add one Item per line
combo.addItems(['Cabbage', 'Burrito']) # Add with list
combo.currentText() # return: current text
combo.currentIndex() # return: current index
combo.findText('Potato') # return: index of the text
combo.setCurrentIndex(0) # set default text with input index

```

### Layouts
Every Widget object needs a layout

```python
class Panel(QWidget):
    def __init__(self):
        super(Panel, self).__init__()

		line = QLineEdit("Initial Value") # Define Widget
		layout = QHBoxLayout() # Define a Layout
		layout.addWidget(line) # Add Widget to the layout
		self.setLayout(layout) # Define what's the main layout of the panel

layout_horizontal = QHBoxLayout()
layout_horizontal.addWidget(widget, 1) # (widget, spacing)

layout_grid = QGridLayout()
layout_grid.addWidget(widget, 0, 1) # (widget, row, column)

layout.addStretch(25) # replace with empty space, (space ratio)
layout.addSpacing(25) # add spacing in-between (space in pixels)
```

###### Layouts inside a Layout
`Master_LayoutObject.addLayout(Child_LayoutObject)`
```Python
layout_a = QHBoxLayout()
layout_b = QHBoxLayout()

master_layout = QVBoxLayout()
master_layout.addLayout(layout_a)
master_layout.addLayout(layout_b)

self.setLayout(master_layout)
```
