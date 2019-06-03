# TCL in a nutshell :chestnut:
Useful things in TCL, also used by Nuke Expressions

# Syntax

### Labelling

###### Return Values
```javascript
// knob value
[value this.name]

// input knob value
[value this.input.name]

// input knob value outside group
[value this.parent.input.name]

// node channel value at [x,y]
[sample [node input] red 10 10]

// topnode
[value [topnode].name]
```

###### File Path
```javascript
// File Path (no extension)
[file rootname [value [topnode].file]]

```

### Knob Values ('Add Expression')

```javascript
// ifs
a > 0 ? 1 : 0

// random
( random( seed, frame * freq ) * amp ) + offset
( random( 101, frame * 0.5 ) * 3 ) + 5

// knob value at frame
nodename.knob.( frame )
Transform1.translate.x ( 50 )

// animation curve at frame
curve( frame )

// animation curve inverse
nodename.knob.inverse
TimeWrap1.lookup.inverse


```

### Expression Node

```javascript
// pixel value
x( frame )
y( frame )

// comp size
width
height

// math
sin( x )
sqrt( x*x + y*y )
atan( x, y )
abs( v )

// generating noise
fBm(x, y, z, octaves, lacunarity, gain) // full range values
turbulence(x, y, z, octaves, lucanarity, gain) // only abs values
noise(x, y, z)
```

# Snippets

###### UV with overscan
```javascript
(((((x+overscan)/(width+overscan*2))*(width+overscan*2))-overscan)/width)-(0.5/width)
(((((y+overscan)/(height+overscan*2))*(height+overscan*2))-overscan)/height)-(0.5/height)
```
