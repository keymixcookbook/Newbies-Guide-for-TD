# PYTHON SUPPORTING MODULE (in a nutshell :chestnut:) - WIP
Useful things in other supporting modules that comes with python (*I am gonna assume you know the general logic of coding*).

## Table of Contents
- [`os` Module](#os)
- [`collections` Module](#collections)


### os

### collections
Ideal for counting the duplicates of an item in an arry, and number of occerance - [Online Ref](https://docs.python.org/2/library/collections.html)

`collection.Counter(ls)`

```python
ls = ['a', 'a', 'b', 'b', 'c', 'c', 'c', 'd']

collections.Counter(ls)
### Counter({'a': 2, 'b': 2, 'c': 3, 'd': 1})


collections.Counter(ls).keys()
### ['a', 'b', 'c', 'd']

```
