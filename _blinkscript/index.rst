Blinkscript in a nutshell
=========================

Nuke NDK in a node with C++ like syntax

.. contents:: Table of Contents

   
Blinkscript Basics
------------------

For what I understand, Foundary's Blinkscript (or Blink Kernel) is a mix of C++ and GLSL. 
It is very much a language of its own with a C++ like syntax, and is very simiar to GLSL in how it works

.. image:: Kernel Diagram
   :target: https://en.wikipedia.org/wiki/Kernel_(operating_system)#/media/File:Kernel_Layout.svg

There are numbers of good online resources for learning Blinkscript, list below are just a few:

* `Foundary Blink Kernel Documentation <https://learn.foundry.com/nuke/developers/90/BlinkKernels/>`_
* `Gabriel Roy Tuts <https://learn.foundry.com/nuke/developers/90/BlinkKernels/>`_
* `Guillem Ramisa de Soto - Blink 101 <https://learn.foundry.com/nuke/developers/90/BlinkKernels/>`_
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
   :linenos:

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


`> Back to top < <#top>`_


Kernel Granularity
------------------


`> Back to top < <#top>`_


Image
-----


`> Back to top < <#top>`_

Variables
---------


`> Back to top < <#top>`_

Blinkscript vs GLSL
-------------------