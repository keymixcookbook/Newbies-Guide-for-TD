# Blinkscript in a nutshell :chestnut:
C++ modded with Nuke NDK

###### Table of Contents
- [Start with C++](./cpp.md)
- [Blinkscript Basics](#Blinkscript-Basics)

### Blinkscript Basics
for what I understand, Foundary's Blinkscript (or Blink Kernel, ["WTF is a Kernel"](https://en.wikipedia.org/wiki/Kernel_(operating_system)#/media/File:Kernel_Layout.svg)) is a mix of C++ and GLSL (or you can argue GLSL is base off C++, so Blinkscript is a child of C++)

The following is a consolidation of Blink Tutorials I found online: [here](https://learn.foundry.com/nuke/developers/90/BlinkKernels/InvertKernel.html) and [here](https://sites.google.com/site/gabrielroytuts/nuke/blinkscript/intro) and [here](http://www.guillemramisadesoto.com/tutorials#/blink-101/) and [here](http://www.xaviermartinvfx.com/x_aton/)

###### Necessary Components
The necessary functions to setup for Blinkscript to run (more details below)
1. Declare a Kernel: `kernel BlinkName: ImageComputationKernel<eSomethingWise>{}`
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
- `ImageRollingKernel`: where there is a data dependency between the output at different points in the output space
    - access order either horizontally or vertically
- `ImageReductionKernal`: reduce an image down to a value/set of values

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
    - `<eAccessRange1D>`: 1 dimensional position to current iteration space
    - `<eAccessRange1D>`: 2 dimensional position to current iteration space
    - `<eAccessRandom>`: any pixel in the iteration space
- EdgeMethod
    - `<eEdgeClamped>`: repeat edge pixels of the input image
    - `<eEdgeConstant>`: 0 value returned outside image bounds
    - `<eEdgeNone>`: values undefined outside of the image bounds, most efficient way if out bounds not require access


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
- `float4`: 4 dimensional float (also can be used as color knob for `r`, `g`, `b`, `a`)
- `float multi_float[n]`: n dimensional float


- `float3x3`: 3x3 matrices
- `float4x4`: 4x4 matrices

**Reserved Variables**
environment variables pre-defined by nuke

- `eX`/`eY`: axis of the image
- `bounds`: image bounds or `recti`/`rectf`
    - `bound.width()`, `bound.height()`
    - `bound.x1()`, `bound.y1()`: bottom left corner
    - `bound.x2()`, `bound.y2()`: top right corner
