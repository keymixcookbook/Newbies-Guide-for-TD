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
- [Constructor](#Constructor)
- [Class](#Class)
- [Modules](#Modules)
- [Python Structure](#Python-Structure)
- [Other ways of scripting in Python](PyXtra.md)

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

[:chestnut:](#Table-of-Contents)

###### Basic Syntax
- `""`,`''` String
- `\n` Line break, to used in String
- `;` multiple statement in a single line
- `:` to define a **Suite**, used with `if`,`for`, `def`, etc.
- `[]`, `()`, `{}` list, tuples, dictionary

[:chestnut:](#Table-of-Contents)


###### Comments
```python
# this is a comment, for labeling, one line only

'''
This is a multi line comment
can also be string in paragraph form
'''
```
[:chestnut:](#Table-of-Contents)


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
[:chestnut:](#Table-of-Contents)


###### Value Convert
```python
int() # String or Float -> Integer
float() # String or Integer -> Float
str() # Integer or Float -> String
```
[:chestnut:](#Table-of-Contents)

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
[:chestnut:](#Table-of-Contents)


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
[:chestnut:](#Table-of-Contents)


###### Comprehensions
```python
list_new = [i for i in list_orig if 'condition' == True]

for i in list_orig: # condition in the middle
	if 'condition' == True: # condition at the end
		list_new.append(i) #list item at the beginning
```
[:chestnut:](#Table-of-Contents)


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
[:chestnut:](#Table-of-Contents)


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
[:chestnut:](#Table-of-Contents)



###### Constructor

```python
# Initiate the value of a Class when an object of Class is created

def __init__(self):
	self.method = 'something'
```
[:chestnut:](#Table-of-Contents)



###### Class
The Holy Grail of Python

```python
# Define a Class
class ThisClass:
	def __init__(self):
		self.param = 'parameters'

	def ClassMethod(self):
		var = "Function in a Class is a Method"

# Reference instance value
ThisClass().param
ThisClass().ClassMethod()

# Example
class ExampleClass:
    def __init__(self, name, number):
        self.name = name
        self.number = number

    def exampleMethod(self):
        print "%s: %s" % (self.name, self.number)

myClass = ExampleClass('Potato', 1)
print myClass

>>> "Potato: 1"

myClass.number = 3 # manipulate parameter value
del myClass.number # delete parameter

```

- `self` - A reference to current instance of the `Class`
    - it **must be** the **FIRST parameter** of the `function` in the class
    - does't has to be named `'self'`, as long as it's the **first parameter**


###### Class Inheritance
**Child Class** inherits properties from **Parent Class**

```python
class ChildClass(ParentClass):
    pass

class ChildClass(ExampleClass):
    def __init__(self, name, number, newParam): # Overwrites ParentClass property
        ExampleClass.__init__(self, name, number) # Bring back ParentClass properties
        self.newParam = newParam
myChild = ChildClass('Potato', 1, 'King Potato')
print "%s: %s is %s" (myChild.name, myChild.number, myChild.newParam)

>>> "Potato: 1 is King Potato"
```

###### Class Inheritance - super()
to ignore this class' `__init__(self)` and inherits properties from Parent Class

> "...In a class hierarchy with single inheritance, super can be used to refer to parent classes without naming them explicitly..."
> -- [Python 2.0 Doc](https://docs.python.org/2/library/functions.html#super)


```Python
super(currentClass, self).__init__()

class ParentClass(object):
    def __init__(self, parent):
        pass
    def get_name():
        print "This is from Parent Class"

class ChildClass(ParentClass):
    def __init__(self): # Overwrites QWidget properties
        super(ChildClass, self).__init__() # Ignore the overwrite

c = ChildClass()
print c.get_name()

>>> "This is from Parent Class"
```

[:chestnut:](#Table-of-Contents)



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
[:chestnut:](#Table-of-Contents)


###### Python Structure

Python works in hierarchy

> - `main_script.py`
>   - `./package`
>     - `__init__.py`
>     - `pkg_module.py`
>   - `module_A.py`
>     - `ClassA()`
>       - `classMethod()`
>     - `function_a()`
[:chestnut:](#Table-of-Contents)
