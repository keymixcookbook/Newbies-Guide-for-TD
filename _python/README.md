# PYTHON (in a nutshell :chestnut:)
Useful things in python (*I am gonna assume you know the general logic of coding*). Only includes the things that are often used, you can go [Homepage](./README.md) to find the reference for more detailed documentation.

This is python only, does not include the [Nuke module](NukeModule.md), and [supporting modules](SupportModule.md) (i.e. **os**(very useful), **collection**(can be useful) )

## Table of Contents
- [Operators](#Operators)
- [Basic Syntax](#Basic-Syntax)
- [Comments](#Comments)
- [Variables Types](#Variable-Types)
- [Value Convert](#Value-Convert)
- [If Condition Statement](#If-Condition-Statement)
- [Loops](#Loops)
- [Comprehensions](#Comprehensions)
- [Exception Statement](#Exception-Statement)
- [Functions](#Functions)
- [Modules](#Modules)
- [Python Structure](#Python-Structure)

###### Operators
- Comparison
  - `=` assign
  - `==` is equal to
  - `!=` is not equal to
  - `>`,`<` bigger, smaller than
  - `=>`, `=<` bigger/smaller and equal to
- Math
  - `+`, `-`, `*`, `/` plus, minus, multiply, divide
  - `%`, `**` modulus, exponent
- Logical
  - `and` if a and b
  - `or`  if a or b
  - `not` if not(a and b)
- Membership (*I know...that's what it is called*)
  - `in`, `not in` if or not included
  - `is`, `is not` if or not is exactly

###### Basic Syntax
- `""`,`''` String
- `\n` Line break, to used in String
- `;` multiple statement in a single line
- `:` to define a **Suite**, used with `if`,`for`, `def`, etc.
- `[]`, `()`, `{}` list, tuples, dictionary

###### Comments
```python
# this is a comment, for labeling, one line only

'''
This is a multi line comment
can also be string in paragraph form
'''
```

###### Variable Types
```python
string = "This is a String"
integer = 1 # Integer Number
float = 1.0 # Float Number, gotta have the decimals

list = ['This', 1, ['list']] #list, can contain string, integer and float at the same time
tuple = (1, 'tuple') #list, but can't manipulate afterwards
dic = {'key': 'value', 'second': 2} #dictionary, with a Key and a Value

# lists starts with Index 0, lists are assigned above
print list[0] # Returns 'This'
print tuple[1] # returns 'tuple'
print dic['key'] # returns 'value'
```

###### Value Convert
```python
int() # String or Float -> Integer
float() # String or Integer -> Float
str() # Integer or Float -> String
```
###### If Condition Statement
```python
if var == "assign": # '==' is to check if variable, var, is "assign", ':' is to end the statement
  return True # this is a Boolean
  print "This is True" # Print is to see the result
elif var != "assign": # '!=' means if it is not...
  return False
else:
  print "gotta have the else"
```

###### Loops
```python
# for loops
for i in list:
  return "something with looping through the list"

# while loops
while i<10:
  return "while i is still smaller then 10"
  print "do something"
  i = i+1 #manipulate the value, or while loop never ends
```

###### Comprehensions
```python
list_new = [i for i in list_orig if 'condition' == True]

for i in list_orig: # condition in the middle
  if 'condition' == True: # condition at the end
    list_new.append(i) #list item at the beginning
```

###### Exception Statement
```python
# try except statement; if error, it will skip
try:
  print "Do something here"
except:
  print "Something went wrong"
  print "but code keeps running and skip the above action"

# Code keeps running
```

###### Functions
```python
# A set of codes, run on demand
def this_function():
  # something happened here
  return "this is a function"

def another_function(input_var, arg='keywards'):
  if input_var == "used as a input for this function":
    print "variable, arg, is predefined in the suite headline"
```

###### Modules
```python
# Python script in a directory

# import a external script, name without .py extension
import module_a # Method 1
module_a.function_a() # reference its function

from module_b import * # Method 2
function_b() # reference its function

import module_c as c # Method 3
c.function_c() # reference its function

import package.module_d as d # Method 4
d.function_d() # reference its function

```

###### Python Structure

Python works in hierarchy

>  - `main_script.py`
>    - `./package`
>     - `__init__.py`
>     - `pkg_module.py`
>    - `module_A.py`
>      - `ClassA()`
>         - `classMethod()`
>      - `function_a()`
