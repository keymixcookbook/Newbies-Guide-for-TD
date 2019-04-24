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

### Directories for python scripts

### Structure

### Nodes Tabs Knobs

###### Nodes
```python

nuke.createNode('Grade', inpanel=False)
nuke.nodes.Grade(knob=knobvalue, inputs=[node])

node.setInput(0, node)

# Referencing Nodes
node.dependencies(nuke.INPUTS | nuke.EXPRESSIONS | nuke.HIDDEN_INPUTS) # Reference Nodes from inputs
node.dependent() # Reference Nodes from outputs

# Layers/Channels
nuke.Layer('layerName', ['layerName.red', 'layerName.green', 'layerName.blue'])

nuke.layers(node) # return list of layer names
```

###### Knobs
```python
# Adding Knobs
knob = nuke.PyScript_Knob('name','label','value')
knob.clearFlag(nuke.STARTLINE)
knob.setFlag(nuke.STARTLINE)
node.addKnob(knob)

# Expression/Animation
knob.clearAnimated()
knob.isAnimated() # Boolean
knob.setExpression('$gui')
knob.hasExpression() # Boolean
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

nuke.addKnobChanged(functionName, nodeClass='PostageStamp')

```
