# PYTHON (in a nutshell :chestnut:)
Useful things in python (*I am gonna assume you know the general logic of coding*)

###### > Table of Contents <
- [The Bare-Bones](#The-Bare-Bones)
- [Python Structure](#Python-Structure)
- [Put up Conditions](#Conditions)
- [Define Variables](#Variables)
- [Nuke It (separate page)](#The-Mighty-Nuke)

## The Bare-Bones
```python
# this is a comment, for labeling, one line only

# Modules
import module # import a external script, name without .py extension

# Variables
var = "assign" # Assign a variable
integer = 1 # Integer Number
float = 1.0 # Float Number, gotta have the decimals

# Conditions
if var == "assign": # '==' is to check if variable, var, is "assign", ':' is to end the statement
  return True # this is a Boolean
  print "This is True" # Print is to see the result
elif var != "assign": # '!=' means if it is not...
  return False
else:
  print "gotta have the else"

# Functions
def A_Function():
  # something happened here
  return "this is a function"

# To Use function in a module
module.other_function() #to run a function inside the module imported
```


## Python Structure

Python works in hierarchy

>  - main_script.py
>    - module_A.py
>      - class_a()
>      - function_a()

*Above is also how the `/.nuke` folder file structure looks like.*

Let's define `function_a()` in `module_A.py`, will leave `class_a()` for later on.

In `module_A.py`

```python
# define the function in module_A.py
def function_a():
  return "something"
```

In `main_script.py`

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


## Conditions
Ones they are often used: `if...else...`,`for...`, `try...except...`

## Variables
You can assign a variable in 5 ways or levels:
> - Environment
> - Script/Module
> - Class
> - Function
> - Conditions

And they are also in a hierarchy - if a `variable` is defined in one level, it **can't** be used in the level **above**, but it **can** be used in the level **below**

For this, we are mainly focus on 3 levels: **Script/Module**, **Function**, **Conditions**
