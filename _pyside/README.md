# PYSIDE in a nutshell :chestnut:
Python on steroids

###### Table of Contents
- [The Basics](#The-Basics)
- [Useful/Basic Widgets](#Basic-Widgets)
- [Layouts](#Layouts) ( [Types of Layout](#Types-of-Layout) | [Layout Stack](#Layout-Stack) | [Layout Groups](#Layout-Groups) )
- [Signal](#Signal) and [Event](#Event)
- [Snippets](./pysideSnippets)
- [Import UI as a separate file](./uiImporting)
- [Useful Resources](#Resources)

### Other Resources
- [Basic Widgets and its methods](https://www.tutorialspoint.com/pyqt/pyqt_basic_widgets.htm)
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

# If Run within Nuke
panel = Panel()
panel.show()
```

[&#9776;](#Table-of-Contents)


### Basic Widgets
Building blocks for PySide, just like bricks of Lego

[`Qlabel`](#Qlabel) [`QLineEdit`](#QLineEdit) [`QPushButton`](#QPushButton) [`QCheckBox`](#QCheckBox) [`QComboBox`](#QComboBox) [`QListWidget`](#QListWidget) [`QTabWidget`](#QTabWidget)
[`QTableWidget`](#`QTableWidget`)

###### `QLabel`
```python
label = QLabel('Label')
label = QLabel('<h1>HTML tag<br>Support</h1>')
```

[&#9776;](#Basic-Widgets)

###### `QLineEdit`
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

[&#9776;](#Basic-Widgets)

###### `QPushButton`
```python
push = QPushButton('push')

push.setText("New Push") # Overwrites param in object
push.setIcon(QIcon("/location"))
push.setShortcut('u')
push.setToolTip("This is a tooltip when hover")
push.setCheckable(True) # State of the QPushButton
```

[&#9776;](#Basic-Widgets)

###### `QCheckBox`
```python
checkbox = QCheckBox('Checkbox')

checkbox.setChecked(True)
checkbox.isChecked() # Return if checked or not, Boolean
```

[&#9776;](#Basic-Widgets)

###### `QComboBox`
```python
combo = QComboBox()

combo.addItem('Potato') # Add one Item per line
combo.addItems(['Cabbage', 'Burrito']) # Add with list
combo.currentText() # return: current text
combo.currentIndex() # return: current index
combo.findText('Potato') # return: index of the text
combo.setCurrentIndex(0) # set default text with input index
```

[&#9776;](#Basic-Widgets)

###### `QListWidget`
```python
list_widget = QListWidget()

ls = ['Potato','Cabbage','Burrito']
for i in ls:
    cur_item = QListWidgetItem(i) # Convert Str to Object
    cur_item.setToolTip('This is a tooltip')
    cur_item.setBackground(QColor(255,125,0))
    list_widget.addItem(i) # Adding list Object to widget
list_widget.sortItems() # Sorting list widget items
list_widget.setAlternatingRowColors(True)
list_widget.setSelectionMode(QAbstractItemView.ExtendedSelection) # Enable Multiple Selections

```

[&#9776;](#Basic-Widgets)

###### `QTabWidget`

```python
# Define QTabWidget Object
table = QTabWidget()

# Define Layout Object per tab
layout1 = QHBoxLayout()
layout2 = QHBoxLayout()
layout3 = QHBoxLayout()

# Add Widget Object per layout
layout1.addWidget(QPushButton())
layout2.addWidget(QCheckBox())
layout3.addWidget(QLineEdit())

# Define QWidget() per tab
tab1 = QWidget()
tab2 = QWidget()
tab3 = QWidget()

# Set layout per tab
tab1.setLayout(layout1)
tab2.setLayout(layout2)
tab3.setLayout(layout3)

# Add Tab to QTabWidget Object
table.addTab(tab1, 'Push') # (widget object, name)
table.addTab(tab2,'Checkbox' )
table.addTab(tab3, 'LineEdit' )

# Add QTabWidget Object to master layout
master_layout = QHBoxLayout()
master_layout.addWidget(table)
self.setLayout(master_layout)
```

[&#9776;](#Basic-Widgets)

###### `QTableWidget`
- Every item in the cell has to be an **Object**
	- `QtableWidgetItem(str)` for Strings;
	- `QTableWidget.setCellWidget(row, column, widget)` for Widget Objects in a cell

```python

class Table(QTableWidget):
    def __init__(self):
        super(Table, self).__init__()

        # Define the data
        data = self.get_data()

        # Set Attributes of the table
        self.setRowCount(len(data.keys()))
        self.setColumnCount(4)
        self.horizontalHeader().setStretchLastSection(True)
        self.setEditTriggers(QAbstractItemView.NoEditTriggers) # Set Cell not editable
        self.setSelectionBehavior(QAbstractItemView.SelectRows) # Set Selection for the entire row

        # Set Header Name
        self.setHorizontalHeaderItem(0,QTableWidgetItem('Name'))
        self.setHorizontalHeaderItem(1,QTableWidgetItem('Age'))
        self.setHorizontalHeaderItem(2,QTableWidgetItem('Gender'))
        self.setHorizontalHeaderItem(3,QTableWidgetItem('Married'))

        # Set Row cell value
        for row, key in enumerate(data):
            # 1st column - Just Text
            self.setItem(row, 0, QTableWidgetItem(key)) # (row, column, value)

            # 2nd column - Also Text
            self.setItem(row, 1, QTableWidgetItem(str(data[key]['age'])))

            # 3rd column - Combobox
            gender_combobox = QComboBox()
            gender_combobox.addItems(['male','female'])
            gender_idx = gender_combobox.findText(data[key]['gender'])
            gender_combobox.setCurrentIndex(gender_idx)
            self.setCellWidget(row, 2, gender_combobox) # (row, column, widget object)

            # 4th colum - checkbox
            married_checkbox = QCheckBox()
            married_checkbox.setChecked(data[key]['married'])
            self.setCellWidget(row, 3, married_checkbox)

    # Data
    def get_data(self):
        data = dict()
        data['John Smith'] = {'age': 18, 'gender': 'male', 'married': True}
        data['Carl Johnson'] = {'age': 24, 'gender': 'male', 'married': False}
        data['Lisa Porter'] = {'age': 37, 'gender': 'female', 'married': False}
        data['Emily Lewis'] = {'age': 54, 'gender': 'female', 'married': True}
        data['Robert Brown'] = {'age': 50, 'gender': 'male', 'married': False}
        return data

# Put Table object inside MasterPanel
class MasterPanel(QWidget):
    def __init__(self):
        super(MasterPanel, self).__init__()

        table = Table()
        table_layout = QHBoxLayout()
        table_layout.addWidget(table)
        self.setLayout(table_layout)
```
[&#9776;](#Basic-Widgets)

[&#9776;](#Table-of-Contents)

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

[&#9776;](#Table-of-Contents)

### Signal
When the **value** of a widget is changed
`QWidget().signalMehtod.connect(self.methodToExecute)`
```python
class Panel(QWidget):
    def __init__(self):
        super(Panel, self).__init__()

		# With built-in QWidget method
		push = QPushButton()
		push.clicked.connect(self.close)

		# With custom method
		self.line_input = QLineEdit()
		self.line_output = QLineEdit()
		self.line_input.textChanged.connect(self.line_edit_count)
		# ...Layout, add widget to layout

	def line_edit_count(self):
	    text = self.line_input.text()
	    count = len(text)
	    self.line_output.setText(str(count))
```
- `self` before `self.line_input = QLineEdit()` is necessary when defining a instance-level variable
- `self` as a function argument `line_edit_count(self)` is necessary when defining a method

###### `sender()`
To identify which widget is changed
```python
#...
	# Set Connection to the Widget Object
	self.checkbox.clicked.connect(self.signal_changed)

def signal_changed(self):
	sender = self.sender() # return: widget object
```

[&#9776;](#Table-of-Contents)

### Event
When user interact with the Widget Object, pressed a key or hover the cursor

`mousePressEvent(self, event)`, `keyPressEvent(self, event)`, `enterEvent(self, event)`, `leaveEvent(self, event)`

> `.connect()` overwrites the event for this widget object

```python
class Panel(QWidget):
    def __init__(self):
        super(Panel, self).__init__()

        self.label = QLabel('Click me...')
        line = MouseHover()

        layout = QHBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(line)
        self.setLayout(layout)

    # When Mouse is clicked
    def mousePressEvent(self, event):
        pos = event.pos()
        x,y = pos.x(), pos.y()
        self.label.setText("The Mouse Position is [%s,%s]" % (x,y))

    # When a key is pressed
    def keyPressEvent(self, event):
        key = event.text()
        self.label.setText("The key pressed is %s" % key)

# When Mouse hovers
class MouseHover(QLineEdit):
    def __init__(self):
        super(MouseHover, self).__init__()

    # Hovers in this widget object
    def enterEvent(self, event):
        self.setText("Mouse Enters")

    # Hovers out of ths widget object
    def leaveEvent(self, event):
        self.setText("Mouse Exits")
```
- Need to overwrite and redefine the Event method, and **keep** the `event` parameter
- For when mouse hover a Widget Object, the original widget is overwritten and **Events** are redefined
	- hence a **new class** is defined with a new Widget Object


### Resources
- [PySide2 API](https://doc.qt.io/qtforpython/)
- [Qt Examples](https://doc.qt.io/qtforpython/tutorials/index.html)
- [Signal and Slots](https://techbase.kde.org/Development/Tutorials/Python_introduction_to_signals_and_slots)
