# Useful Methods/Setups in Qt

## Table of Contents
- [Initialize](#Initialize)
- [Layout Management](#Layout-Mangement)
- [Widget Status](#Widget-Status)
- [Widget Sizing & Style](#Widget-Sizing-&-Style)
- [Add Remove Widgets](#Add-Remove-Widgets)
- [Event Handler](#Event-Handler)
- [Show Window/Instance](#Showing)

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

**Get rid of the margins surrounding custom Panels**
[Remove Nuke PythonPanel Margins](https://stackoverflow.com/questions/43224402/how-to-create-custom-panel-without-framing-via-python-in-nuke)
```python

import nuke
import PySide.QtCore as QtCore
import PySide.QtGui as QtGui
from nukescripts import panels

def set_widget_margins_to_zero(widget_object):

    if widget_object:
        target_widgets = set()
        target_widgets.add(widget_object.parentWidget().parentWidget())
        target_widgets.add(widget_object.parentWidget().parentWidget().parentWidget().parentWidget())

        for widget_layout in target_widgets:
            try:
                widget_layout.layout().setContentsMargins(0, 0, 0, 0)
            except:
                pass

class Example_Window(QtGui.QWidget):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        layout = QtGui.QVBoxLayout()
        label = QtGui.QLabel('Margins be-gone!')
        label.setStyleSheet('QLabel{background: #eeffcc}')

        layout.setContentsMargins(0,0,0,0)
        layout.addWidget(label)
        self.setLayout(layout)

        expandingPolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding,
                                            QtGui.QSizePolicy.Expanding)
        label.setSizePolicy(expandingPolicy)
        self.setSizePolicy(expandingPolicy)

    def event(self, event):
        if event.type() == QtCore.QEvent.Type.Show:

            try:
                set_widget_margins_to_zero(self)
            except:
                pass

        return QtGui.QWidget.event(self, event)

panels.registerWidgetAsPanel('Example_Window', 'Example Widget',
                             'mwbp.Example_Widget')

```
###### Window Flags

- `QtCore.Qt.WindowCloseButtonHint`: only show close button
- `QtCore.Qt.MSWindowsFixedSizeDialogHint`: window not resizeable

[&#9776;](#Table-of-Contents)

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

**Expand size of a widget in a cell in QGridLayout**
```Python
_sizepolicy = QtWidgets.QSizePolicy.Expanding
self.widget.setSizePolicy(_sizepolicy,_sizepolicy)
```

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




#### Add Divider Line

```python
separador = QtWidgets.QFrame()
separador.setFrameShape(QtWidgets.QFrame.HLine)
separador.setSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
```

[&#9776;](#Table-of-Contents)
