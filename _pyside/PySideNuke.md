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


### Reoccering panels
it took me a while to figure this shit out, thanks to [TurboNode5000 by Matt Roe](http://www.nukepedia.com/python/nodegraph/turbonode)

for reoccering pyside widgets with a single instance and dynamic inputs
Excecuing Seq:
1. Initiate class: nuke launch, `__init__(self)` is defined
2. Initiate class: inside `__init__(self)`, setting layouts and widgets with **empty input values** 
3. Initiate class: **`self.default()`** is run to set default values and get input values
4. Calling instance: `instance.run()`
5. Calling instance: `self.default()` is run to set values dynamically
6. Calling instance: `self.show()` to show widgets


```python
import PySide.QtGui as QtGui
import nuke


class Panel(QtGui.QWidget):
    def __init__(self):
        super(Panel, self).__init__()
        
        self.line = QtGui.QLabel()
        self.layout = QtGui.QVBoxLayout()
        self.layout.addWidget(self.line)
        self.setLayout(self.layout)
        self.resize(100,50)
        
        # Reset Default value when instancing the class
        self.default()

    # setting defalt value when run
    def default(self):
        self.line.setText(nuke.selectedNode().name())
    
    # sequence of events when relaunch
    def run(self):
        self.default()
        self.show()
        
            
p = Panel()
```
