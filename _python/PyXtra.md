# Additional Python codes

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
