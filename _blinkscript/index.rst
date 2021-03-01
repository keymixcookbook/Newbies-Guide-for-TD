Blinkscript in a nutshell
=========================

Nuke NDK in a node with C++ like syntax

.. contents:: Table of Contents

   
Blinkscript Basics
------------------

For what I understand, Foundary's Blinkscript (or Blink Kernel) is a mix of C++ and GLSL. 
It is very much a language of its own with a C++ like syntax, and is very simiar to GLSL in how it works

.. image:: Kernel Diagram
   :target: /img/kernel.png

There are numbers of good online resources for learning Blinkscript, list below are just a few:

* `Foundary Blink Kernel Documentation <https://learn.foundry.com/nuke/developers/90/BlinkKernels/>`_
* `Gabriel Roy Tuts <hhttps://sites.google.com/site/gabrielroytuts/nuke/blinkscript/intro>`_
* `Guillem Ramisa de Soto - Blink 101 <http://www.guillemramisadesoto.com/tutorials#/blink-101/>`_
* `Xavier Martin - X_Aton <http://www.xaviermartinvfx.com/x_aton/>`_

And this guide is a consolidation of the online resources I can find

`> Back to top < <#top>`_

Necessary Components
--------------------

The necessary parts to setup Blinkscript are as follows, in order:

#. Define the **Name** of your Kernel
#. Define a **Kernel Type**
#. Define a **Kernel Granularity**
#. Define **Inputs** and **Output**
#. Any Declaration of **Global Functions**
#. Define **Parameters** and/or **local** variables
#. Set **User Knobs**, if any, and their default values
#. **Initilize** functions to call when node is created *(or when compiled)*
#. **Processing** to run at every pixel or every channel

**In code examples**: A Simple kernel to invert input

.. code-block:: C++

	kernel InvertKernel : ImageComputationKernel<eComponentWise>
	{
		// Define Inputs(src) and Output(dst)
		Image<eRead, eAccessPpint, eEdgeClammped> src;
		Image<eWrite> dst;

		// Define parameters: veriable that are avaliable to the user
		param:
			float multiply;

		// Define local variables, that are exposed to the user
		local:
			float whiteAccessPoint;

		void deine(){
			defineParam(multiply, "Multiply", 1.0f);
		}

		void init(){
			whiteAccessPoint = 1.0f;
		}

		void process(){
		dst() = (whiteAccessPoint - src()) * multiply;
	}


`> Back to top < <#top>`_

Kernel Types
------------

There are 3 types of Kernel you can define, which the most common one is ``ImageComputationKernel``

.. list-table::
	:widths: 25 50 25

	* - **Type**
	  - **Description**
	  - **Access Order**
	* - ``ImageComputationKernel``
	  - takes zero or more images as input and ouput one image
	  - radom
	* - ``ImageRollingKernel``
	  - Where there is a data dependency between the output at different points in the output space
	  - either hrizontally or vertically
	* - ``ImageReductionKernel``
	  - Reduce an image down to a value/set of values
	  - N/A

.. note:: Most of the Blinkscripts are ``ImageComputationKernel``

`> Back to top < <#top>`_


Kernel Granularity
------------------

A Kernel Granularity defines how big the size of prociess is.

There are 2 types of Granularity in Blinkscript:

.. list-table::
	:widths: 1 2

	* - ``<eComponentWise>``
	  - One **channel** at a time 
	* - ``<ePixelWise>``
	  - One **pixel** at a time 

.. note::
	
	**Granularity (Parallel computing):**

	In parallel computing, granularity (or grain size) of a task is a measure of the amount of work (or computation) which is performed by that task



`> Back to top < <#top>`_


Image Specfication
------------------

Image Specification defines how the input and output is accessed.

It includes 3 main classes:

* **ReadSpec**
* **AccessPattern**
* **EdgeMethod**

+---------------+---------------------+-------------------------------------------------------------------------+
|**States**     |**Options**          |**Description**                                                          |
+---------------+---------------------+-------------------------------------------------------------------------+
|ReadSpec       |``eRead``            |Reading access                                                           |
|               +---------------------+-------------------------------------------------------------------------+
|               |``eWrite``           |Writing access                                                           |
+---------------+---------------------+-------------------------------------------------------------------------+
|AccessPattern  |``eAccessPoint``     |Access only the current position                                         |
|               +---------------------+-------------------------------------------------------------------------+
|               |``eAccessRanged1D``  |Access a one-dimensional range of positions relative to current position |
|               +---------------------+-------------------------------------------------------------------------+
|               |``eAccessRanged2D``  |Access a two-dimensional range of positions relative to current position |
|               +---------------------+-------------------------------------------------------------------------+
|               |``eAccessRandom``    |Access any pixel                                                         |
+---------------+---------------------+-------------------------------------------------------------------------+
|EdgeMethod     |``eEdgeClamped``     |Edge values is repeated outside the image bounds/format                  |
|               +---------------------+-------------------------------------------------------------------------+
|               |``eEdgeConstant``    |Zero values will be returned outside the image bounds/format             |
|               +---------------------+-------------------------------------------------------------------------+
|               |``eEdgeNone``        |(Default) Values are undefined outside bounds, no bounds check hence     |
+---------------+---------------------+-------------------------------------------------------------------------+

`> Back to top < <#top>`_

Variables
---------

You can deine variables in 2 ways, both or either one:
* ``param:``: parameter variable that are user **accessible**
* ``local:``: script variable that are user **not accessible**

Datatypes
^^^^^^^^^

Blinkscript datatype are very similar to GLSL with some keywards differences:

.. list-table::
	:widths: 1 1 4

	* - **Datatype**
	  - **GLSL Equivalent**
	  - **Description**
	* - ``bool``
	  - ``bool``
	  - gool ol' friend true/false
	* - ``int``
	  - ``int``
	  - single intiger value
	* - ``int2``
	  - ``ivec2``
	  - 2-dimensional integer, can define upto *4 dimensions*
	* - ``float``
	  - ``float``
	  - single float point value
	* - ``float2``
	  - ``vec2``
	  - 2-dimensional float, can define upto *4 dimensions* also can be ``rgba`` knobs
	* - ``<t> multi[n]``
	  - ``<t> multi[n]``
	  - n-dimensional array, where ``<t>`` is ``int`` or ``float``
	* - ``<t> multi[n]``
	  - ``<t> multi[n]``
	  - n dimensional array, where <t> is ``int`` or ``float``
	* - ``float3x3``
	  - ``mat3``
	  - 3x3 floating matrix, can also define 4x4 the same way

Special Datatypes
^^^^^^^^^^^^^^^^^

There are datatypes you can get the datatype from a vairable.
Because Blinkscript or C++ is not dynmacially typed, those datatypes can be extremly handy!

.. list-table::
	:widths: 1 3

	* - **Datatype**
	  - **Description**
	* - ``SampleType(var)``
	  - Gets the data type of variable ``var``
	* - ``ValueType(var)``
	  - Gets the data type of Image components ``var`` per item

.. note::
	if ``ValueType(image)`` is ``float`` and there are **3 components** in your image, ``SampleType(image)`` will be ``float3``.

You can use those special datatypes as such:

.. code-block:: c++

	SampleType(dst) sample(0.0f);

`> Back to top < <#top>`_

Methods
-------


`> Back to top < <#top>`_

Blinkscript vs GLSL
-------------------