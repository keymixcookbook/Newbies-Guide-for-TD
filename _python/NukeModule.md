# PYTHON FOR NUKE (in a nutshell :chestnut:) - WIP
Useful things in Nuke Python Module (*I am gonna assume you know the general logic of coding*).

Only includes the things that are often used, you can go [HERE](https://learn.foundry.com/nuke/developers/70/pythonreference/) to read the Nuke Bible, aka Nuke Python API.

## Table of Contents
- [Directories for python scripts](#Directories-for-python-scripts)
- [Structure](#Structure)
- [Nodes Tabs Knobs](#Nodes-Tabs-Knobs)
- [Menu Items](#Menu-Items)
- [Simple Panels](#Simple-Panels)
- [Callbacks](#Callback)
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
	- `Group.Root`
	- `Panel`
- `nukescripts`

### Nodes Tabs Knobs

###### Nodes
```python

# Create Nodes
nuke.createNode('Grade', inpanel=False)
nuke.nodes.Grade(knob=knobvalue, inputs=[node])

# Accessing Nodes
nuke.selectedNode() # One selected node
nuke.selectedNodes() # Multiple selected nodes
nuke.toNode('nodeName') # one node by its name

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

# Autolabel
customLabel = "nuke.thisNode().name()+'\\n'+nuke.thisNode()['knobname'].value()" #'\\n' for new line
customLabel_ifs = "nuke.thisNode().name() + (' big!' if nuke.thisNode()['size'].value()>100 else ' small')" # With a if statement
# (<True Action> if <True Condition> else <Else Action>)

nuke.selectedNode()['autolabel'].setValue(customLabel)
```

###### Tabs
```python


```

# Menu Items
```python
kuMu = nuke.menu('Nuke').addMenu('KU')
kuMu.addCommand('menuLocation', 'functionName', 'alt+c', icon='/img.png', shortcutContext=2)
# shortcutContext: 0=window, 1=Application, 2=DAG
```

# Simple Panels

# Callbacks
```python
# KnobChanged
nuke.addKnobChanged(functionName, nodeClass='PostageStamp')

```

# Pipeline Integration

### Startup
script to execute on startup
`nuke.addOnCreate(function, nodeClass='Root')`

# Other
```python
# Color Value Convert
int('%02x%02x%02x%02x' % (r,g,b,a), 16) # RGB -> Nuke; r,g,b,a: 0~255
int('%sFF' % ('2D2D2D'),16) # HEX -> Nuke
```
