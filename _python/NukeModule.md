# PYTHON FOR NUKE (in a nutshell :chestnut:) - WIP
Useful things in Nuke Python Module (*I am gonna assume you know the general logic of coding*).

Only includes the things that are often used, you can go [HERE](https://learn.foundry.com/nuke/developers/70/pythonreference/) to read the Nuke Bible, aka Nuke Python API.

## Table of Contents
- [Directories for python scripts](#Directories-for-python-scripts)
- [Structure](#Structure)
- [Nodes Tabs Knobs](#Nodes-Tabs-Knobs) ([list of knob types](#List-of-Knob-Types-with-Python-API))
- [Menu Items](#Menu-Items)
- [Panels](#Panels)
- [Callbacks](#Callbacks)
- [Rotoshapes](#Rotoshapes)
- [Other](#Other)

### Directories for python scripts
Initialize in the following order
1. `/usr/local/Nuke6.2v4/plugins`
2. `/usr/local/Nuke6.2v4/plugins/icons`
3. `/usr/local/Nuke6.2v4/plugins/user`
4. `/usr/local/NUKE/6.2/plugins`
5. `/home/nukeuser/.nuke`
	1. `init.py`
	2. `menu.py`

```python
nuke.pluginPath() # Show List of Plugin Path
nuke.pluginAddPath() # Add Plugin Path
```

### Structure
- `nuke`
	- `Node.Knob`
	- `Root.Group`
	- `Panel`
- `nukescripts`

### Nodes Tabs Knobs

###### Nodes
```python

# Create Nodes
nuke.createNode('<node class>', inpanel=False)
nuke.createNode("<node class>", "<knob name> <knob value> <knob name> <knob value>")
nuke.nodes.Grade(knob=knobvalue, inputs=[node])

# Accessing Nodes
nuke.selectedNode() # One selected node
nuke.selectedNodes() # Multiple selected nodes
nuke.toNode('<nodeName>') # one node by its name

# Set Inputs
node.setInput(0, node)

# Referencing Nodes
node.dependencies(nuke.INPUTS | nuke.EXPRESSIONS | nuke.HIDDEN_INPUTS) # Reference Nodes from inputs
node.dependent() # Reference Nodes from outputs

# Layers/Channels
nuke.Layer('layerName', ['layerName.red', 'layerName.green', 'layerName.blue']) # Create Layer
nuke.layers(node) # Return list of layer names

# DAG Position/Size
node.xpos() # left: -, right: +
node.ypos() # up: -, down: +
node.screenWidth() # Avg Node Width: 80
node.screenHeight() # Avf Node Height: 74
BackdropNode.knob('bdwidth') # for BackdropNode specifically
BackdropNode.knob('bdheight') # for BackdropNode specifically

node.setXpos() # integer
node.setYpos() # integer

nuke.zoom(2, [x,y]) # Focus DAG to [x,y]
```

###### Group Nodes
```python
# Accessing nodes within a group
# Method 1
with groupNode:
	# functions

# Method 2
group_node.begin()
# functions
group_node.end()

# Method 3
nuke.toNode('groupNode.insideNode')
```


[&#9776;](#Table-of-Contents)

###### Knobs
```python
# Adding Knobs
knob = nuke.PyScript_Knob('name','label','value')
knob.clearFlag(nuke.STARTLINE)
knob.setFlag(nuke.STARTLINE)
node.addKnob(knob)
knob.setFlag(0x00008000) # Another way of setting flags, expecting integer list from Nukepidia

# Expression/Animation
knob.clearAnimated()
knob.isAnimated() # Boolean
knob.setExpression('$gui')
knob.hasExpression() # Boolean

# Autolabel - this replace the built-in autolabel for the notes and can not parse tcl expressions
customLabel = "nuke.thisNode().name()+'\\n'+nuke.thisNode()['knobname'].value()" #'\\n' for new line
customLabel_ifs = "nuke.thisNode().name() + (' big!' if nuke.thisNode()['size'].value()>100 else ' small')" # With a if statement
# (<True Action> if <True Condition> else <Else Action>)

nuke.selectedNode()['autolabel'].setValue(customLabel)
```
[&#9776;](#Table-of-Contents)

###### List of Knob Types with Python API

|Knob Type (Class Object) | Arguments | Human readable / Annotations
|:---------|:--------- |:----------------------------
| AColor_Knob 					| 'name', 'label' | RGB+Alpha
| Array_Knob 					| 'name', 'label', int | Matrix like length defined by int
| Axis_Knob 					| 'name', 'label'
| BBox_Knob 					| 'name', 'label' | x,y,r/w,t/h
| Bitmask_Knob 					| 'name', 'label' | will crash your nuke
| Boolean_Knob 					| 'name', 'label' | checkbox
| Box3_Knob 					| 'name', 'label' | x,y,n,r,t,f (n: near, f: far)
| Channel_Knob 					| 'name', 'label'
| CascadingEnumeration_Knob 	| 'name', 'label', [list, list/sublist] | dropdown menu
| ChannelMask_Knob 				| 'name', 'label' |
| ColorChip_Knob 				| 'name', 'label' | Floating color wheel
| Color_Knob 					| 'name', 'label' | RGB
| Double_Knob 					| 'name', 'label' | floating slider
| Enumeration_Knob 				| 'name', 'label', [list] | dropdown menu
| EvalString_Knob 				| 'name', 'label', 'string' | not sure the use of it
| Eyedropper_Knob 				| 'name', 'label'
| File_Knob 					| 'name', 'label'
| Font_Knob 					| 'name', 'label'
| Format_Knob 					| 'name', 'label'
| GeoSelect_Knob 				| 'name', 'label'
| Histogram_Knob 				| 'name', 'label'
| IArray_Knob 					| 'name', 'label', [int,int] | Matrix array, int [row,column]
| Int_Knob 						| 'name', 'label'
| Keyer_Knob 					| 'name', 'label'
| Obsolete_Knob 				| 'name', 'label' | don't know why it's here
| Password_Knob 				| 'name', 'label'
| Pulldown_Knob 				| 'name', 'label', {'key': 'python value'} | parse string into python command
| PyCustom_Knob 				| 'name', 'label', cmd | for pyqt application inside a knob UI
| PyScript_Knob 				| 'name', 'label', cmd | Python button
| Range_Knob 					| 'name', 'label', [float,float,float,...] | Similar to that of Histogram slider
| String_Knob 					| 'name', 'label' | Text input
| Scale_Knob 					| 'name', 'label'
| SceneView_Knob 				| 'name', 'label'
| Tab_Knob 						| 'name', 'label'
| Text_Knob 					| 'name', 'label' | Title text with CSS
| Transform2d_Knob 				| 'name', 'label'
| Link_Knob 					| 'name', 'label' | use `makeLink(nodename, 'knob')` to link between knobs
| LookupCurves_Knob 			| 'name', 'label' | use addCurve('curveName') to add a new curve
| MultiView_Knob 				| 'name', 'label'
| ViewView_Knob 				| 'name', 'label'
| UV_Knob 						| 'name', 'label'
| WH_Knob 						| 'name', 'label' | simlier to Transfrom's scale knob
| XYZ_Knob 						| 'name', 'label'
| XY_Knob 						| 'name', 'label'


###### PyCustom Knob
[pyside widgets inside a nuke gizmo](http://tylerart.com/sketchbook/22/12/2015/pyside-widgets-inside-a-nuke-gizmo)

define widget as a Class, inheret from `nukescripts.PythonPanel` or `QWidget` and
**Define `makeUI(self)` inside the Class Wraper**

Example:
```python
from PySide import QtGui, QtCore
import nuke

class MyWidget(QtGui.QWidget):

    def __init__(self, node):
        super(self.__class__, self).__init__()

        self.node = node

        layout = QtGui.QHBoxLayout()
        layout.setAlignment(QtCore.Qt.AlignTop)
        self.setLayout(layout)

        btn1 = QtGui.QPushButton('Node Name')
        btn1.clicked.connect(self.btn1Clicked)

        btn2 = QtGui.QPushButton('Print Stuff')
        btn2.clicked.connect(self.btn2Clicked)

        dial = QtGui.QDial()
        dial.valueChanged.connect(self.dialValueChanged)

        layout.addWidget(btn1)
        layout.addWidget(btn2)
        layout.addWidget(dial)


    def btn1Clicked(self):
        print self.node.name()

    def btn2Clicked(self):
        print 'Hi, I\'m a button.'

    def dialValueChanged(self):
        print 'Value was just changed!'

    def makeUI(self):
        return self

    def updateValue(self):
        pass


if __name__ == '__main__':
    node = nuke.selectedNode()
    knob = nuke.PyCustom_Knob( "MyWidget", "", "MyWidget(nuke.thisNode())" )
    node.addKnob(knob)
```
[&#9776;](#Table-of-Contents)

###### Tabs
```python


```
[&#9776;](#Table-of-Contents)

# Menu Items
```python
kuMu = nuke.menu('Nuke').addMenu('KU')
kuMu.addCommand('menuLocation', 'functionName', 'alt+c', icon='/img.png', shortcutContext=2)
# shortcutContext: 0=window, 1=Application, 2=DAG
```
Other Manus
- `nuke.menu('Animation')`: right click menu for Animation icon
- `nuke.menu('Properties')`: right-click menu for the Property panel


[&#9776;](#Table-of-Contents)

# Panels

```python
p = nuke.Panel('Simple Panel')

p.addClipnameSearch('clip path', '/tmp')
p.addFilenameSearch('file path', '/tmp')
p.addTextFontPulldown('font browser', '/myFonts/')
p.addRGBColorChip('some pretty color', '')
p.addExpressionInput('enter an expression', '4*25')
p.addBooleanCheckBox('yes or no?', True)
p.addEnumerationPulldown('my choices', 'A B C')
p.addScriptCommand('tcl or python code', '')
p.addSingleLineInput('just one line', 'not much space')
p.addMultilineTextInput('multiple lines of user input text', 'lineA\nlineB')
p.addNotepad('write something', 'some very long text could go in here. For now this is just some random default value')
p.addPasswordInput('password', 'donttellanyone')
p.addButton('push here') # return: 0
p.addButton('or here') # return: 1
p.addButton('or even here') # return: 2
p.show()


pp = nukescripts.PythonPanel('Python Panel')

knob = nuke.Double_Knob('knobtype','knoblabel')
pp.addKnob(knob)
pp.show() # Floating and dockable
pp.addToPane() # Docked on create
```
[&#9776;](#Table-of-Contents)

# Callbacks
```python
# KnobChanged
nuke.addKnobChanged(functionName, nodeClass='PostageStamp') # functionName use without quotes

```
[&#9776;](#Table-of-Contents)


# Rotoshapes
Everything rotoshapes, very different, very annoying

[nuke Roto Rotopaint NDK reference](https://learn.foundry.com/nuke/developers/120/pythondevguide/rotopaint.html)

There are 3 types of elements in Rotoshape/Roto node:
- `Layer`: Groups/Layers, exclude Root (that returns a `NoneType`, use `rootLayer`)
- `Stroke`: Paint strokes, Dodges
- `Shape`: Anything Spline - Bezier, BSpline, Ecllips, Recotangle...
* `rootLayer`: Contains all above elements in the node, *iterable*; *when shape inside a layer, returns the layer object*

```python
n = nuke.toNode('Roto')
k = n['curves'] # Roto node rotoshape curve object

k.getSelected() # return: Iterable, Selected Rotoshapes as list
k.toElement('Rotoshape') # return: object, object refered by its name
k.toElement('Layer/Rotoshape') # return: object, shape inside a layer
k.getTransform() # return: object, AnimCTransform (whatever that is)
elem = [c for c in k.rootLayer] # return: every elements inside the Roto node

```

### Expression link Transform of a Rotoshape curve
sometimes it will be faster just to right-click or control-drag on animation parameter

[`link_tools.py`(sample script)](https://gist.github.com/jedypod/759871a41a35482704af) | [`_curvelib.AnimCTransform` methods](https://learn.foundry.com/nuke/developers/70/pythonreference/_curvelib.AnimCTransform-class.html)

Basic Event Sequence:
1. Define `_curvelib.AnimCurve()` object (per knob and axis)
2. Assign a *string value* to `<AnimCurve Object>.expressionString = 'Expression'`
3. Set `<AnimCurve Object>.useExpression = True`
4. Find *Transform Attribute object* for selected Rotoshape curve `<Curve object>.getTransform()`
5. Set Expressions (`Translation`, `Rotation`, `Scale`, `PivotPoint`)
	- `<Attribute object>.setTranslationAnimCurve(index, <AnimCurve object>)` - 0: x, 1: y
	- `<Attribute object>.setRotationAnimCurve(2, <AnimCurve object>)` - [why index is `2`](https://www.mail-archive.com/nuke-python@support.thefoundry.co.uk/msg02295.html)
	- `<Attribute object>.setScaleAnimCurve(index, <AnimCurve object>)` - 0: x, 1: y
	- `<Attribute object>.setPivotPointAnimCurve(index, <AnimCurve object>)` - 0: x, 1: y



[&#9776;](#Table-of-Contents)

# Pipeline Integration

### Startup
script to execute on startup
`nuke.addOnCreate(function, nodeClass='Root')`

# Other
```python
# Color Value Convert
int('%02x%02x%02x%02x' % (r,g,b,a), 16) # RGB -> Nuke; r,g,b,a: 0~255
int('%sFF' % ('2D2D2D'),16) # HEX -> Nuke

# Default custom knob default value
nuke.selectedNode()['knob'].setDefaultValue([1.0]) # Value must be a sequence/arry
```
