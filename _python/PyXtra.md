# Additional Python codes


### List Manipulation

```python
# Add
ls.append(item)
ls[key] = value
ls.extend([item1, item2])

# Remove
ls.remove(item) # Can't be assigned as a new variable directly

# Sort
sorted(ls)

# List to Strings
', '.join(ls)

# Zip
ls_a = ['a','b','c']
ls_b = [1, 2, 3]
zip(ls_a, ls_b)

>>> [['a', 1], ['b', 2], ['c', 3]] 
```

### Ternary Operators
```Python
# var
condition = True

# method 1
x = 1 if condition else 0
print x

>>> 1

# method 2
x = (0, 1)[condition]
print x

>>> 1

# method 3
x = condition or "something else"
print x

>>> 1

```

### Loop with multiple lists
```python
# enumerate(list, start_number)
ls = ['potato', 'cabbage', 'burrito']

for item, idx in enumerate(ls, 1):
	print "%s: %s" % (item, idx)

>>>'potato': 1
>>>'cabbage': 2
>>>'burrito': 3


# zip(list_1, list_2, ...)
ls_a = ['potato', 'cabbage', 'burrito']
ls_b = [1, 2, 3]

for a, b in zip(ls_a, ls_b)
	print "%s: %s" % (a, b)

>>>'potato': 1
>>>'cabbage': 2
>>>'burrito': 3

```

### Unpacking
```python

a, b, *c = (1, 2, 3, 4, 5)
print a
print b
print c

>>>1
>>>2
>>>[3, 4, 5]

```

### name & main

```python

if __name__ == '__main__':
	# module being directly ran
else
	# module not being directly ran, but ran as an import

```

- if run directly, variable `__name__` will be `__main__`;
- if run imported, variable `__name__` will be the **module name**.

###### Example
`main_module.py` contains `import_module.py`

`import_module.py`
```python
def main():
	print __name__
print main()

>>>__main__ # When run standalone
```
`main_module.py`
```Python
import import_module

>>> 'import_module' # When run inside main_module
```
