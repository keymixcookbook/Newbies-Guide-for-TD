# Useful Methods/Setups in Qt

## Table of Contents
- [Initialize](#Initialize)
- [Layout Management](#Layout-Mangement)
- [Widget Status](#Widget-Status)
- [Widget Sizing & Style](#Widget-Sizing-&-Style)
- [Add Remove Widgets](#Add-Remove-Widgets)
- [Event Handler](#Event-Handler)
- [Show Window/Instance](#Showing)
- [Nuke with Qt](#Nuke)


#### Initialize
Multiple showing of the same instance
```python
class MultipleShowing:
	def __init__():

		#Set Widgets and layout

		self.setDefault() #function to set default value


	def setDefault(self):
		'''set default values when instancing'''


	def run(self):
		'''show instance'''
		self.setDefault() # recall setDefault method before showing
		self.show()
```

[&#9776;](#Table-of-Contents)


#### Layout Management
[Qt Layout Management documentation](https://doc.qt.io/qt-5/layout.html)

###### Layout Spacing
- `setContentsMargin(0,0,0,0)`
- `setContentsMargin(left=0)`
- `setSpacing(0)`

- `setAlignment(QtCore.Qt.AlignRight)` - Set alignment

[Remove Nuke PythonPanel Margins](https://stackoverflow.com/questions/43224402/how-to-create-custom-panel-without-framing-via-python-in-nuke)
###### Window Flags

###### Spacing



[&#9776;](#Table-of-Contents)


#### Widget Status

[&#9776;](#Table-of-Contents)


#### Sizing & Style
[Qt Style Sheet reference](https://doc.qt.io/qt-5/stylesheet-reference.html)

- `sizeHint()` - preferred size of the widget
- `minimumsSizeHint()` - smallest size the widget can have
- `setSizePolicy(QSizePolicy.Expanding)`- specify the space requirements of the widget.
- `setSizeConstraint(QtCore.QLayout.SetFixedSize)` - shown as its optimal size
- `setFont(QtGui.Qfont().setPointSize())` - set font size

- `setFrameStyle(QFrame.Box | QFrame.Raised)` - set border along widgets


[&#9776;](#Table-of-Contents)


#### Add Remove Widgets

[&#9776;](#Table-of-Contents)

#### Event Handler
[Qt Event Documentation](https://doc.qt.io/qtforpython/overviews/eventsandfilters.html#event-handlers)

[&#9776;](#Table-of-Contents)

#### Showing
Define a `run()` method for instancing
```python
def run(self):
	'''run for every showing'''
	self.setDefault() # Set Default values

	self.move(QtGui.QCursor) # Set Widget to Mouse position, [0,0] at top-left corner
	self.move(QtGui.QCursor.pos() + QtCore.QPoint(-100,-12)) # Mouse positon with offset

	self.widget.setFocus() # Focus on a specific widget
	self.lineInput.selectAll() # Select all in the edit field

	self.raise_() # Bring to front
	self.activeWindow() # Bring to front, with keyboard input focus
	self.show() # Show but doesn't block Event Loop
```

###### `QDialog`
`exec_()`: blocking until the user closes it
 - return: *DialogCode*
 	- QDialog.Accepted
 	- QDialog.Rejected
 - also: `result()`



[&#9776;](#Table-of-Contents)


#### Nuke

[&#9776;](#Table-of-Contents)
