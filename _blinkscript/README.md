# Blinkscript in a nutshell :chestnut:
C++ modded with Nuke NDK

###### Table of Contents
- [Start with C++](./cpp.md)
- [Blinkscript Basics](#Blinkscript-Basics)
- [Blinkscript vs GLSL](#Blinkscript-vs-GLSL)

### Blinkscript Basics
for what I understand, Foundary's Blinkscript (or Blink Kernel, ["WTF is a Kernel"](https://en.wikipedia.org/wiki/Kernel_(operating_system)#/media/File:Kernel_Layout.svg)) is a mix of C++ and GLSL (or you can argue GLSL is base off C++, so Blinkscript is a child of C++)

The following is a consolidation of Blink Tutorials I found online: [here](https://learn.foundry.com/nuke/developers/90/BlinkKernels/InvertKernel.html) and [here](https://sites.google.com/site/gabrielroytuts/nuke/blinkscript/intro) and [here](http://www.guillemramisadesoto.com/tutorials#/blink-101/) and [here](http://www.xaviermartinvfx.com/x_aton/) in an orgnized manner, I hope

###### Necessary Components
The necessary parts to setup for Blinkscript to run, with following orders (and more details for each parts below)
1. Any declaration of global functions (optional)
1. Declare a Kernel Granularity: `kernel BlinkName: ImageComputationKernel<eSomethingWise>{}`
1. Image Specification, define src and dst: `Image<eRead> src`, `Image<eWrite> dst`
1. Define parameters and/or variables: `param:` and `void define(){ defineParam() }`
1. Initialize: `void init(){}`
1. Process to run at evey pixel: `void process(){}`

**Example: InvertKernel** from nuke documentation
```C++
kernel InvertKernel : ImageComputationKernel<eComponentWise>
{
  Image<eRead, eAccessPoint, eEdgeClamped> src;  //the input image
  Image<eWrite> dst;  //the output image

  param:
    float multiply;  //This parameter is made available to the user.

  local:
    float whiteAccessPoint;  //This local variable is not exposed to the user.

  //In define(), parameters can be given labels and default values.
  void define() {
    defineParam(multiply, "Multiply", 1.0f);
  }

  //The init() function is run before any calls to process().
  void init() {
    whiteAccessPoint = 1.0f;  //Local variables can be initialised here.
  }

  //The process function is run at every pixel to produce the output.
  void process() {
    //Invert the input value from src and multiply:
    dst() = (whiteAccessPoint - src()) * multiply;
   }
};
```

##### Kernel Type
- `ImageComputationKernel`: takes zero or more images input and ouput one or more images
    - access order random
- `ImageRollingKernel`(not common): where there is a data dependency between the output at different points in the output space
    - access order either horizontally or vertically
- `ImageReductionKernal` (not common): reduce an image down to a value/set of values

##### Kernel Granularity
There are 2 types of Blinkscript Kernel, which sets what kind of data you can access.
1. `<eComponentWise>`: one **channel** at a time.
2. `<ePixelWise>`: one **pixel** at a time


##### Image
Define the input and ouput image, and what can you access from each.

**3 arguments must be defined**: `Image<ReadSpec, AccessPattern, EdgeMethod> myImage`
- ReadSpec:
    - `<eRead>`: only read access to the image
    - `<eReadWrite>`: read and write access
    - `<eWrite>`: write-only access
- AccessPattern
    - `<eAccessPoint>`: will only be accessed at current position in output space
    - `<eAccessRange1D>`: 1 axis, 1 dimensional position to current iteration space
    - `<eAccessRange2D>`: 2 axis, 2 dimensional position to current iteration space
    - `<eAccessRandom>`: any pixel in the iteration space
- EdgeMethod
    - `<eEdgeClamped>`: repeat edge pixels of the input image
    - `<eEdgeConstant>`: 0 value returned outside image bounds
    - `<eEdgeNone>`: values undefined outside of the image bounds, most efficient way if out bounds not require access

> How you setup the AccessPattern, determines what you have to define in init(), more in the Reserved Methods section


##### Variables
there are 2 types of variable ('types' here I don't mean data types, but more on this later), you can declare both or either one
- `param`: parameter variable user **accessible**
- `local`: script variable user **not accessible**

**Datatypes** (awfully similar to GLSL)
- `bool`: good ol' friend true/false
- `int`: single intiger value
- `int2`: 2 dimensional integer
- `int3`: 3 dimensional integer
- `int4`: 4 dimensional integer
- `int multi_int[4]` : array of intiger values
- `float`: single float value
    - `1.0f`, the tailing `f` is a tricky one, cuz sometimes you need it, sometimes you don't...what the `f`, man
- `float2`: 2 dimensional float
- `float3`: 3 dimensional float
- `float4`: 4 dimensional float (also can be used as color knob for `r`, `g`, `b`, `a` or `x`, `y`, `z`, `w`, or `0`, `1`, `2`, `3`)
- `float multi_float[n]`: n dimensional float
- `float3x3`: 3x3 matrices
- `float4x4`: 4x4 matrices

**Reserved Variables**
variables pre-defined by nuke (for this, I use `src` for sources images for clearity)

- `PI`: pi
- `eX`/`eY`: axis of the image
- used with `void process()`
    - `int2 pos`: the x `pos.x` and y `pos.y` coordinates of their position in the iteration space
    - `int3 pos`: same as `int2 pos`, but with pos.z as Component
- `src.kMin`, `src.kMax`: minimum and maximum possible value for any component
- `src.kWhitePoint`: boundary value between white and super-white, usually set to `1`
- `src.kComps`: number of components of src
- `src.kClamps`: bool, if src should be clamps or not
- `src.bounds`: image bounds
    - `bound.width()`, `bound.height()`
    - `bound.x1()`, `bound.y1()`: bottom left corner
    - `bound.x2()`, `bound.y2()`: top right corner
- `ValueType(src)`: data type of src, ie `float`, `int` (yes i know, it looks like a function, but it's considered as a variable, C++ madness, low-level computing is weird)
- `SampleType(src)`: similar to `ValueType()`, but it shows the length/number of components, ie `float3`

**Reserved Methods**
- `define()`: define parameters
    - `defineParam(paramName, "externalParamName", defaultValue)`: actual define parameters (if value is float, needs tailing `f`)
- `init()`: setting up access to images and initialising local variables
    - setup ranged image access
    - `setAxis(eX)`: set axis for `<eAccessRange1D>` and `<eAccessRange2D>`
    - `setRange(int rangeMin, int rangeMax)`: set range from min value to max (if 2D, set both axis)
    - `setRange(int xMin, int yMin, int xMax, int yMax)`: set range min to max for **2 axises only**
    - `<eAccessPoint>` and `<eAccessRandom>` does not need to `setRange()`
- `process()`: main function for Blinkscript
- `src()`: source access
    - `src()`: `<eAccessPoint>` access, no argument is needed
    - `src(int offset)`: `<eAccessRange1D>` access, interation space + `offset`
    - `src(int xOffset, int yOffset)`: `<eAccessRange2D>` access, interation space + `xOffset, yOffset`
    - `src(int x, int y)`: `<eAccessRandom>` access, src at `x,y` coordinate
    - for `<eComponentWise>`: it can access per component
    - for `<ePixelWise>`: `src(..., int c)`: to specifiy a component `c` as intiger
    - Reutrn type:
        - if `<eComponentWise>`: same as `src.ValueType`
        - if `<ePixelWise>`: `int c` given: `src.ValueType` or vector with all component type
- Math Functions: almost same as GLSL ([list of GLSL functions](https://www.khronos.org/registry/OpenGL-Refpages/gl4/index.php))
    - `bilinear(Image src, float x, float y, int c)` where `int c` is optional
    - `sin()`,`cos()`, `tan()`, `asin()`, `acos()`, `atan()`, `atan2()`
    - `exp()`, `log()`, `log2()`, `log10()`
    - `floor()`, `ceil()`, `round()`, `pow()`, `sqrt()`, `rsqrt()`, `abs()`, `fabs()`, `fmod()`, `modf()`, `sign()`, `min()`, `max()`, `clamp()`, `rcp()`
    - `atomicAdd()`, `atomicInc()`
    - `median(scalar data[], int size)`: median value of `data[]` with given `size`
    - `rect(scalar x1, scalar y1, scalar x2, scalar y2)`: Construct a rectangle from `(x1,y1)` to `(x2,y2)`
    - `rect.grow(scalar x, scalar y)`: grow bounds by `x` and `y`
    - `rect.inside(scalar x, scalar y)`, `rect.inside(vec v)`: bool, whether `(x,y)` or `v` inside `rect`
    - `rect.width()`, `rect.height()`: `vec` or `scalar`, width and height
- GLSL Functions that are not avaliable in Blinkscript
    1. `mix(a,b,f)`: mixing input `a` with input `b` at rate of `f`
    2. `step(a,b)`: comparing `a` with `b` and reutrn a `bool`
    3. `clamp()`
    4. `length()`
    5. `distance()`

### Blinkscript vs GLSL

Although Blinkscript is very similar to GLSL, but it has differences with their syntax

GLSL | Blinkscript
---- | ----------
`vec2` | `float2`, xy knob
`vec3` | `float3`, xyz knob
`vec4` | `float4`, rgba knob
`gl_FragCoord.xy` | `int2 pos`, defined in `void process(int2 pos){}`
`gl_FragCoord.xyz` | `int3 pos`
`uniform vec2 u_resolution` | `float2(src.bounds.x2,src.bounds.y2)`
