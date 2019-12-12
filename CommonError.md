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
