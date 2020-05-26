# Import UI as a separate file
Use with QtDesigner or code your own UI separately to save some lines


## Basic Steps
1. in your UI module
    - create a class/object
    - define a method to setup ui
    - pass in a `mainWidget` object as an argument (ie. `setupUi(self, mainWidget)`)
2. in your main module
    - import UI module
    - define `mainWidget`
    - call `setupUi()` function and pass in `mainWidget` or `self` if called within `mainWidget`

## Examples

create 2 files:
- `ui.py`
- `core.py`: contains UI files

`ui.py`
```python

from Qt import QtWidgets, QtCore, QtGui
import sys

class Ui_Class(object):
    def setupUi(self, mainWidget):
        # adding ui elements
        self.buttons = QtWidgets.QPushButton()
        self.lineedits = QtWidgets.QLineEdit()
        ...

```

`main.py`
```Python
from Qt import QtWidgets, QtCore, QtGui
import sys

# import ui module
from ui import Ui_Class as ui

class main_Class(QtWidgets.QWidget):
    def __init__(self):
        super(main_Class, self).__init__()

        # calling setupUi method
        ui.setupUi(self)

        # finish importing ui and do otherthings
        ...
```
