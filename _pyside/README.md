# PYSIDE in a nutshell :chestnut:
Python on steriods

- [The Basics](#The-Basics)
- [Useful/Basic Widgets](#Useful/Basic-Widgets)
- [Layouts](#Layouts) ( [Types of Layout](#Types-of-Layout) | [Layout Stack](#Layout-Stack) | [Layout Groups](#Layout-Groups) )

---

### PySide or PyQt
basically the same ([for more detailed differences](https://wiki.qt.io/Differences_Between_PySide_and_PyQt))

### The Basics
- PySide has 2 main objects: `QtCore` & `QtGui`
- `QWidget`: all visiable elements (**widget**)
- `QApplication()`: **only one** per Qt application, not needed if ran within Nuke
- [Infographic for the components](./pysideInfographic.md)

```python
# Import Module
from PySide.QtCore import *
from PySide.QtGui import *

# Make Widget Objects
class Panel(QWidget):
	# Constructor
    def __init__(self):
        super(Panel, self).__init__()

		# Define widget object
		label = QLabel('Label Text')
		# Define widget layout
		label_layout = QHBoxLayout()
		# Set properties for widget object
		label.setMinimumSize(QSize(600,400))
		label.setAlignment(Qt.AlignCenter)
		label.setWindowTitle("This QWidget Title")
		# Adding widget to layout
		label_layout.addWidget(label)
		# Adding layout to Clas
		self.addLayout(label_layout)

	def otherMethods():
		pass

# Run Application (stand along outside of Nuke)
app = QApplication(sys.argv)
panel = Panel()
panel.show()
app.exec_()
```

### Useful/Basic Widgets
Building blocks for PySide, just like bricks of Lego

`QLabel`
```python
label = QLabel('Label')
```
`QLineEdit`
```python
line = QLineEdit("Initial Value") # Define Widget

line.setText("My Text") # Same as above
line.text() # Return the text of the 'QLineEdit' object
line.setReadOnly(False)
line.setMaxLength(20) # Max numbers of charactor can enter
line.setAlignment(Qt.AlignCenter) # Align Text
line.setPlaceholderText("This is a placeholder text ")

line_suggestion = ['Potato', 'Cabbage', 'Burrito']
completer = QCompleter(line_suggestion)
line.setCompleter(completer)
```
`QPushButton`
```python
push = QPushButton('push')

push.setText("New Push") # Overwrites param in object
push.setIcon(QIcon("/location"))
push.setShortcut('u')
push.setToolTip("This is a tooltip when hover")
push.setCheckable(True) # State of the QPushButton
```
`QCheckBox`
```python
checkbox = QCheckBox('Checkbox')

checkbox.setChecked(True)
checkbox.isChecked() # Return if checked or not, Boolean
```
`QComboBox`
```python
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
line = QLineEdit("Initial Value") # Define Widget
layout = QHBoxLayout() # Define a Layout
layout.addWidget(line) # Add Widget to the layout
self.setLayout(layout) # Define what's the main layout of the panel
```
###### Types of Layout
```python
layout_horizontal = QHBoxLayout()
layout_horizontal.addWidget(widget, 1) # (widget, spacing)

layout_vertical = QVBoxLayout()
layout_vertical.addWidget(widget, 1) # (widget, spacing)

layout_grid = QGridLayout()
layout_grid.addWidget(widget, 0, 1) # (widget, row, column)

# Add Empty Space
layout.addStretch(25) # replace with empty space, (space ratio)
layout.addSpacing(25) # add spacing in-between (space in pixels)
```

###### Layout Stack
`MasterLayout.addLayout(ChildLayout)`
```Python
layout_a = QHBoxLayout()
layout_b = QHBoxLayout()

master_layout = QVBoxLayout()
master_layout.addLayout(layout_a)
master_layout.addLayout(layout_b)

self.setLayout(master_layout)
```


###### Layout Groups
`QGroupBox()`

```Python
group = QGroupBox('This is the title of the Group')
group_layout = QHBoxLayout()
# ...adding widgets
group.setLayout(group_layout)
```
