# PYTHON SUPPORTING MODULE (in a nutshell :chestnut:)
Useful things in other supporting modules that comes with python (*I am gonna assume you know the general logic of coding*).

## Table of Contents
- [`os` Module](#os) - for operating system API
- [`shutil` Module](#shutil) - os file manipulation mostly for copying, moving and deleting files and directories
- [`collections` Module](#collections) - list manipulation
- [`math` Module](#math) - math operations
- [`re` Module](#re) - regular expression

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
For Math operations (duh) - [Online Ref](https://docs.python.org/2.7/library/math.html)

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


### re
For string search/replace/matching... with pattern syntax- [Online Ref](https://docs.python.org/2.7/library/re.html)

`re` modules usually comes with 4 components: `pattern`, `str`, `flags`, `MatchObject`


**Useful Methods**

method|return|description
:---|:---|:---
`re.match(pattern, str, flag=0)`				| `<MatchObject>` 	| finds beginning of the string
`re.search(pattern, str, flag=0)` 				| `<MatchObject>` 	| finds all of the string
`re.sub(pattern, replStr, str, max=0)` 			| `str`				| substitute `str` with `replStr` base on `pattern`
`re.split(pattern, str, maxsplit=0, flag=0)` 	| `[str, str]` 		| substitute `str` with `replStr` base on `pattern`
`re.findall(pattern, str)` 	| `[str, str]` 		| find all occerance of `str`
`re.compile(pattern)` | `<reObject>` | compile `pattern` in an object


**MatchObject methods**

method|return|return type
:---|:---|:---
`<MatchObject>.group()`| matched string | 'str'
`<MatchObject>.start()`| matched string's index, start position | `int`
`<MatchObject>.end()`  | matched string's index, end position | `int`
`<MatchObject>.span()` | matched string's index, range | `(int, int)`

`None` returned if no match

**pattern** *(partial)*

pattern|match|example
:---|:---|:---
`^`		| beginning of **line** 			| `'^potato'`
`$`		| end of **line** 					| `'potato$'`
`.`		| anything, *except newline* 		| `'po.o'`
`[...]`	| a set of characters 				| `[0-9]`
`[^..]`	| except the set of characters		| `[^0-9]`
`a|b`	| a or b 							| `po| p`
`\w`	| word character					|
`\W`	| non-word character				|
`\s`	| whitespace						|
`\S`	| non-whitespace					|
`\d`	| digits							|
`\D`	| non-digits						|
`\A`	| beginning of **string**			|
`\Z`	| end of **string**					|
`\b`	| begining or end of **word**		| `r'\bP'`
`\B`	| not begining or end of **word**	| `r'o\b'`
`\n`	| newline, tabs, etc				|
`{#}`	| exactly `#` of repetition			|
`{#,}`	| `#` or more repetition			|
`{#,#}`	| `#`~`#` repetitions				|
