# PYSIDE for nuke in a nutshell :chestnut:
PySide within Nuke

### Show Panels
Launch panels from **Nuke menu**
```Python
# Outside Nuke
app = QApplication(sys.argv)
panel = Panel()
panel.show()
app.exec_()

# Inside Nuke
panel = Panel()
panel.show()
```
- Nuke has already provide `QApplication()`, so there is no need for `QApplication()` and `exec_()`

###### Add Panel to the menu
in `myPanel.py`
```Python
def start():
    start.panel = Panel()
    start.penel.show()
```
in `menu.py`
```python
 import myPanel

 menu = nuke.menu('Nuke')
 kuPanel = menu.addMenu('KuPanel')
 kuPanel.addCommand("My Custom Panel", 'myPanel.start()')
```

### Register Panels
Launch panels from **Nuke panel**

Method 1:
-  `nukescripts.PythonPanel`
- `nukescripts.registerPanel(id, PythonPanelClass)`

```python
# Create the panel
class CustomPanel(nukescripts.PythonPanel):
    def __init__(self):
        nukescripts.PythonPanel.__init__(self, 'CustomPanel', 'com.ohufx.CustomPanel')
		...# Add knobs and functions

# Register Panel
nukescripts.registerPanel('com.ohufx.CustomPanel', CustomPanel)

# Register and Add Panel to the Pane/Custom menu
def addPanel():
    global cusPanel
    cusPanel = CustomPanel()
    return cusPanel.addToPane()

paneMenu = nuke.menu('Pane')
paneMenu.addCommand('CustomPanel', addPanel)
nukescripts.registerPanel('com.ohufx.CustomPanel', addPanel)
```

Method 2:
- `PySide.QtCore` `PySide.QtGui`, `nukescripts.panels`
- `registerWidgetAsPanel(widget, name, id, create=False)`

###### Floating Panel
```python
label = QtGui.QLabel("Hello World")
label.show()
```

###### Dockable Widgets/Panel
```python
import nuke
import PySide.QtCore as QtCore
import PySide.QtGui as QtGui

class NukeTestWindow(QtGui.QWidget):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.setLayout(QtGui.QVBoxLayout())
        self.myTable = QtGui.QTableWidget()
		self.layout().addWidget(self.myTable)
		...# Set Values

nukescripts.panels.registerWidgetAsPanel('NukeTestWindow', 'Test table panel', 'uk.co.thefoundry.NukeTestWindow')

```
