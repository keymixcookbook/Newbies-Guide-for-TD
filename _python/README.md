# Python in a nutshell :chestnut:
Useful things in python (*I am gonna assume you know the general logic of coding*)

### Table of Contents
- [<span style="color:#e6e6e6">Python Scripting Structure](#Python-Scripting-Structure)
- [<span style="color:#e6e6e6">Variables](#Variables)


## Python Scripting Structure

Python works in hierarchy

>  - main_script.py
>    - module_A.py
>      - function_a()

Let's define `function_a()` in `module_A.py`

```python
def function_a():
  return "something"
```

As in the script `main_script.py`

```python
# to import the module
import module_A

# To Reference a function within the module
module_A.function_a()

```

so to use the function: `module.function()` and modules are basically a set of python script file

**OR**

```python

# to import the module with "from...import..."

#--------------------------------------------------

### Method 1 ###

from module_A import *

# To Reference the function
function_a()

#--------------------------------------------------

### Method 2 ###

import module_A as mod_A

# To Reference the function
mod_A.function_a()

#--------------------------------------------------

### Method 3 ###

from module_A import function_a as function_a_renamed

# To Reference the function
function_a_renamed()
```

>! Because we used "from...import...", we don't have to put the module name in front of the function to reference it


## Variables
