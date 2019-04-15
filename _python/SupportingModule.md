# PYTHON SUPPORTING MODULE (in a nutshell :chestnut:)
Useful things in other supporting modules that comes with python (*I am gonna assume you know the general logic of coding*).

## Table of Contents
- [`os` Module](#os)
- [`shutil` Module](#shutil)
- [`collections` Module](#collections)

---

### os
For accessing system directories and files - [Online Ref (os.path)](https://docs.python.org/2/library/os.path.html) | [Online Ref (os)](https://docs.python.org/2/library/os.html)

`import os`

```python
# Directory operations
os.mkdirs('./path/subPath')
os.removedirs('./path/subPath')


# Enviroment variable
os.getenv('HOME')
>>>'/user/Tianlun'


# Listing directories
os.listdir('./path/targetParth')
>>>['folder_a', 'folder_b', 'folder_c']

```

`import os.path`

```python
#Var
path = '/user/Tianlun/Desktop/file.ext'


# Return end of the path
os.path.basename(path)
>>>'file.ext'


# Return path exclude last one
os.path.dirname(path)
>>>'/user/Tianlun/Desktop'


# Split/Joint path
os.path.split(path)
>>>['/user/Tianlun/Desktop', 'file.ext']


os.path.splitext(path)
>>>['/user/Tianlun/Desktop/file', '.ext']


os.path.join('root', path)
>>> '/root/user/Tianlun/Desktop/file.ext'


# Check existence
os.path.isdir(path)
>>>False # Path is a Directory


os.path.isfile(path)
>>>True
```

### shutil
with `os` module, with copying and removing files and directories - [Online Ref](https://docs.python.org/2/library/shutil.html)

```python
import shutil
shutil.copy2('/src/file_copy.ext', '/dst/file_paste.ext')

```

### collections
Ideal for counting the duplicates of an item in an arry, and number of occerance - [Online Ref](https://docs.python.org/2/library/collections.html)

```python
import collections
collections.Counter(ls)
```

```python
ls = ['a', 'a', 'b', 'b', 'c', 'c', 'c', 'd']

collections.Counter(ls)
>>> Counter({'a': 2, 'b': 2, 'c': 3, 'd': 1})


collections.Counter(ls).keys()
>>> ['a', 'b', 'c', 'd']

```

### math
For Math operations (duh) - [Online Ref](https://docs.python.org/2/library/math.html)

```python
import math
```

```python
num = 1.45

math.floor(num) # round down
>>> 1

math.ceil(num) # round up
>>> 2

math.round(num) # round
>>> 2
```
