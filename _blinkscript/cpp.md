# C++ for Python programmers
cout << main reference << [cpp4python](https://runestone.academy/runestone/books/published/cpp4python/index.html) << endl;

cout << cpp Basic Tutorials << [T Payne](https://www.youtube.com/playlist?list=PL82YdDfxhWsCyZLsg_kXhH8sy5ixQNras) << endl;


### The Syntaxes
- `#`: header
- `<>`: libraries
- `;`: use to end a line
- `{}`: start and end a function

### Import libraries
libraries are `header` and to be imported with `#include`
```c++
#include <libraryname>
#include "filename"
```
**Standard Libraries**
a collection of classes and functions which are written in the core language

[list of std::libraries](https://en.cppreference.com/w/cpp/header)
```c++
#include <iostream> // Standard Output
#include <string> // String class and templates
#include <list>
#include <iterators>
...
```
### Main functions

### Comments
`\\`: single line; `/*  */`: multi line
```c++
// The remainder of this line is a C++ comment which is ignored by the compiler

/* This is a multi-line C++ comment that can
span many lines, beginning and ending with the given symbols */
```
### Input and Output
`stream` - handles input and output or `cin`, `cout`
Every function has to be contained by `int main()`
```c++
#include <iostream>
using namespace std;

int main() {

    //declares num as a variable that can hold a floating point number
    float num;

    // Displays this text to the console
    cout << "Give me a number: ";

    // Takes the user's input and stores it in num
    cin >> num;

    // Displays to the console
    cout << "This is your number doubled: " << num*2;

    return 0;
}
```


###### User inputs and exit programs
`cin` ask for user inputs, but taking `space` as `enter`

`getline(cin, var)` takes everthing until `enter` is hit
```c++
int main(){
    string y; // declare variable
    cout << "Type of the potato"; // console string
    getline(cin, y); // ask for input, same line as previous
    cout << "creating" << y; // combine string with input value
    cout << " Potato." << endl; // add to end of previous line, same line
    cout << "Press enter to exit..." << endl; // console string
    getline(cin, y); // allow exit with enter key pressed

    return 0;
}
```

### Common Keywords
- `namespace`: declarative region for identifiers (names of type, function, vars); in order to prevent name collisions
- `using namespace std;`: Sets the current namespace, in replace of `std::`
- `cin`: user input


### Data Types and Declarations
Data values in C++ are basically size/length in the memory.

Require declaring data type before each variable, built-in data types are:
- `int`: integer `1, 2, 3`
- `float`: floating point (7 digits, 32 bit) `1.1234567`
- `double`: floating point (15-16 digits, 64 bit) `1.1234567e7`
- `decimal`: floating point (28-29 digits, 128 bit) `1.1234567e12`
- `bool`: boolean (lower case) `true`
- `char`: character (one letter) `'p'`
    - `char*`: character (string) `"potato"`
- `auto`: set data type after `=` assignment

###### Data Size
`sizeof(<type>)` - max value/length of a datatype

`<type>` can be: `char`, `int`, `float`, `double`, `bool`

`sizeof(int)` can have: `short int`, `long int`, `long long int`

###### Signed / Unsigned Values
Min and Max values a variable can possibly hold from a given point
- `signed`: return positive and negative values (bi-directional)
    - counting from smallest to this value
- `unsigned`: return *only* positive values (directional)
    - counting from this value to the biggest

###### Arrays
similar to python's `list`, but different (cpp has `list` too)

> individual variables next to each other in the memory

**Array Declaration**
```c++
int array_int[2]; // integer array with length of 2
int array_other[3] = {0,1,2}; // integer array with length of 3, assign on declare
int array_int2[]{4,4,4} // declared with length determined by giving value
int array_int3[4]{} // declare with length, but empty array
int array_2d[2][3] // 2 dimensional array with 2x'row', 3x'columns'

// assign values to array
my_array[0] = 0;
my_array[1] = 1;
```

**Character Array**
a string of characters that ends with `'\0'`, a null character
```c++
char a[] = "potato";
char b[6] = "potato"; // character array with length of 6, number of letters + a null character
char c[]{'a', 'b', '\0'}; //'\0' being the null character to end the string
char c[]{'a', 'b', '\0', 'c'} // 'c' won't be displayed, null listed before
```

###### String
list of characters with more function

```c++
string potato = "potato";
string burrito = "burrito";

potato.swap(burrito); // swap "potato" with "burrito"
potato.size(); // python: len(potato)
potato.find('p'); // index of letter 'p'
potato[1]; // letter with string index of 1

combine = potato + burrito; // combine strings
```


###### Pointer and address-of
- point to a memory location with `*` before a variable name
	- `int *pointerVariable;`
- refer the memory location with `&` before a variable name
	- `int &addressVariable;`

*Data type has to be the same when declare*

```c++
#include <iostream>
using namespace std;

// demonstrates what happens when you dereference a pointer
int main( ) {
    int varN = 100;
    int *ptrN = &varN; //*
    // ptrN points to varN address

    cout << "varN value: " << varN << endl;
    cout << "varN location: " << ptrN << endl;
    cout << "dereference ptrN: " << *ptrN << endl; //*

    return 0;
}
```
return:
```
varN value: 100
varN location: 0x7fff3f8f2f2c
dereference ptrN: 100
```

### Cpp specific Operators
common operators, [full operators](https://www.geeksforgeeks.org/operators-c-c/)
- `=`: assignment
- `<<`: insertion stream out
- `>>`: extraction stream in
- `::`: scope (name used within a portion of source code, library of keywords?)
- `&&`: logic 'and'
- `||`: logic 'or'
- `?`, `:`: one line conditional, same as tcl, `<condition> ? <true_condition> : <false_condition>`
- `sizeof()`: Determine size in bytes on this implementation (dunno why this is an operator)


### Conditional and Loops
### Functions
### Console errors
