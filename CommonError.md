# Nuke Common Error and Solutions

### Rotoshape not showing via alpha channel
Solution: 
- Nuke Preferences > Panels > viewer 
- viewer buffer bit depth "half-float" 
- enable "use GPU for viewer when possible" 
- enable "disable GPU viewer dithering" 
- restart Nuke


### Rotoshape lag in viewer (Nuke11 on Linux and MacOS)
Solution:
- set ENV variable 'QT_COMPRESS_TABLET_EVENTS'='1' (**1 has to be string**)
- in `menu.py` add line `os.setenv('QT_COMPRESS_TABLET_EVENTS')='1'`
- **OR** in cshell/terminal, `setenv QT_COMPRESS_TABLET_EVENTS 1`
- restart nuke


### Hide Status Bar in Nuke 11
```python
from Qt import QtWidgets

try:
    for n in QtWidgets.QApplication.allWidgets():
        if isinstance(n, QtWidgets.QStatusBar):
            n.hide()
except:
    print "not in nuke 11"
```


### Use nuke native QT menubar instead of OS menubar in MacOS
source: [Nukepedia - W_dontUseNativeMenuBar by Wouter Gilsing](http://www.nukepedia.com/python/ui/w_dontusenativemenubar/finishdown?mjv=1)
```python
import nuke 

if nuke.NUKE_VERSION_MAJOR < 11:
        from PySide import QtCore, QtGui, QtGui as QtWidgets
else:
        from PySide2 import QtGui, QtCore, QtWidgets
        
def init():
    '''
    Prevent Nuke from using the native OS toolbar (like on macOS) and use the Nuke's default Qt toolbar instead.
    This will allow the user to work properly in fullscreen mode on a Mac without losing/hiding the menubar. 
    Besides that the toolbar will behave like any other part of the interface.
    '''

    # loop over all toplevel widgets and find all QMenuBars
    for widget in QtWidgets.QApplication.instance().topLevelWidgets():
        for child in widget.children():
            if isinstance(child, QtWidgets.QMenuBar):
                if child.isNativeMenuBar():
                    child.setNativeMenuBar(False)
                    return True

    return False
```
in `menu.py`
```python
import W_dontUseNativeMenuBar
W_dontUseNativeMenuBar.init()
```

### Exit codes

#### 137

- OS: `Linux`
- Cause: render blade ran out of memory
- Discription: render blade errors and there is no clear indication of where it errors, but at the end of the log it shots
- [Source link](https://support.circleci.com/hc/en-us/articles/115014359648-Exit-code-137-Out-of-memory#:~:text=This%20is%20a%20Linux%20error,memory%2C%20your%20build%20will%20fail.)

#### 139

- OS: `Linux`
- Cause: I/O issue, file inputs or node input
- Discription: render blade error on start
- [Source link](https://stackoverflow.com/questions/42882168/how-to-solve-exit-code-139-error-when-reading-from-file-on-unix/42882179#:~:text=3%20Answers&text=It%20means%20the%20program%20crashed,is%20successfully%20opened%20after%20fopen%20.)



