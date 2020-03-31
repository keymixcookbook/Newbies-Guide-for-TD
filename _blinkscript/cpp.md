# C++ for Python programmers

Resources
1. cout << main reference << [cpp4python](https://runestone.academy/runestone/books/published/cpp4python/index.html) << endl;
2. cout << cpp Basic Tutorials << [T Payne](https://www.youtube.com/playlist?list=PL82YdDfxhWsCyZLsg_kXhH8sy5ixQNras) << endl;
3. cout << Basics of Computer Science << [CS50](https://cs50.harvard.edu/) << endl;


### The Syntaxes
- `#`: header
- `<>`: libraries
- `;`: use to end a line
- `{}`: start and end a function


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


- `void`: a type, but not a datatype. returns no value
	- Function can have a `void` which don't return a value
	- `int myFunction(void){}` declare a function with no parameter
- `const <type> <varName>`: to declare a constant value that will not be changed
- `(<type>) <variable>`: convert variable to a post-defined type inside '()'
	- `(float) intVariable`

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

3 components to declare an array`<type> <name>[<size>]`

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
**Reassigning Arrays**

you **can not** assign one array to another array directly, ie. ~~`int lsA[4] = int lsB[4]`~~

however, you can **loop** one array and assign items to another
```c++
int from[4] = {1,2,3,4};
int to[4];

for (i=0, i<=from.size(), i++){
	from[i] = to[i];
}
```

**Passed by Reference**
most variables in C are passed by value, function receives it as a **copy**,

but `array` are passed by **reference**, it does not copy.

```c++
void set_array(int array[4]);
void set_int(int x);

int main(void){
	int a = 10;
	int b[4] = {0, 1, 2 ,3};

	set_int(a);
	set_array(b);
	printf("%d %d\n", a, b[0])
}

void set_int(int x) {
	x = 22;						// Copy input to int x
}
void set_array(int array[4]){
	array[0] = 22;				// Reference input with array[0]
}

```
how above `main()`is ran
1. Define `int a = 10`
2. Define `array b[4] = {0, 1, 2 ,3}`
3. Call `set_int` > inputs `a`, value: `10`
	3.1 > copy to `x` > returns its copy `x`, value `22`
4. Call `set_array` > inputs `array b`, value b[4]{0,1,2,3}
	4.1 > referencing `b` > reassign `b` with `array`, value from `0` to `22`
5. prints output `10 22\n` or initially declared `a`, referenced and reassigned `b`


**Character Array**
a string of characters that ends with `'\0'`, a null character, or "8 zero bits"
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
strlen(potato) // also for length of the string
potato.find('p'); // index of letter 'p'
potato[1]; // letter with string index of 1

combine = potato + burrito; // combine strings
```

How is it stored in the memory
```c
string names[4];
names[0] = "EMMA";
names[1] = "RODRIGO";
names[2] = "BRIAN";
names[3] = "DAVID";
```
![string_array_CS50](https://cs50.harvard.edu/x/2020/notes/2/memory_with_string_array.png)


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


### Conditional and Loops
The `if`s:
```c++
if (int n==1){
	//do something
}else{ // must include else statement
	//else something
	return 0; // else can't be empty
}

if (int n==1){
	//do something
}else if (n!=1){
	//else if something
}else{
	//else something
}

int x = (condition) ? 5 : 6; // if condition true 5 else 6
```

The `for`s:
used for number of repetition is *clear and pre-defined*
```c++
for (int i=0; i<n; i++){ // Need to initialize i
	//something to loop
}
```
alternative `for`s
```c++
string s = "potato"

for (int i=0, n=5; i<strlen(s); i++){
	// define variables inside the 'for' statement
}

for (int i=0; s[i]!='\0'; i++){
	// break loop when 's[i]' isn't '\0'
	// similar to 'while' loop with condition 's[i]!='\0''
}
```
The `while`s:
good for number of repetition is *unclear and un-defined* until it meets the condition
```c++
int input;

while (input<0){
	//something to do 'after' condition is true
	//or will repeat infinitely
}


do{
	//something to do 'before' condition is true
}while(input<0); // while input<0 repeat previous do functions
```

The `switch`s:
```c++
int x = GetInt(); //get the number
switch(x){
	case 1: // if x is 1 do the following
		printf("one");
		break; // break the loops
	case 2:
		printf("two");
		break;
	case 3:
		printf("three");
		break;
	case 4:
		printf("four");
		// will still print out "four" if no break
	default: // Will always execute no matter the case
		printf("End")
}
```

###### Control Statement
- `break`: breaks and stops the loop
- `continue`: skip and continue remaining loop

###### Examples
1. [The Pyramid](ThePyramidExample.c) (loop printing characters)
2. [Capitalize](Capitalize.c) (loop and Ascii values for characters)


### Command-line
when running `C` or `C++` files in a command-line

`argc`: argument count | `argv`: argument value
```c
//file: cmdline.c
int main(int argc, string argv[]){
    if (argc == 2){
        printf("hello %s\n", argv[1]);
    }else{
        printf("hello there!\n");
    }
}
```

when run above code in terminal
```
host:~ username$ ./cmdline potato
hello potato!
```
*`./cmdline` and `potato` count as **2** command-line arguments, where `potato` is `argv[1]`*

### Functions
functions are declared with 3 components: `<return-type> <name>(<argument-list>)`, ie. `float funcPotatoes(void){}`

###### Order of Declaration
functions used within a function has be declared **before** being called.

There are **2 ways** of doing this, both starts with **declaring** the function.

`Declare` > `Define` > `Call`
```c
// Declare first
int subFunction(int potato){
	// Function stuff
}

// Call afterwards
int main(void){
	subFunction(potato)
}
```
`Declare` > `Call` > `Define`
```c
// Declare name and arguments
int subFunction(int potato);

// Call the function
int main(void){
	subFunction(potato)
}

// Define the function, return type and name has to be the same
int subFunction{
	// Function stuff
}
```
###### The `main()` function
every `C` or `C++` program needs a `int main(arg){}`, and everything inside will be run when execute

```c
#include <stdio.h>

int main(void){
	// everything in the program
	// when the script is run
}
```

###### Exit Code
the `return` value of a function is called **exit code**

`int main()` function has a default exit code of `0`, indicates nothing went wrong, but they are customizable.

```c
//ispotato.c
#include <stdio.h>

int main(int argc, string argv[]){
    if (argc < 2 || argv[1]!="potato"){
        printf("not a potato\n");
        return 1;
    }
	printf("potato it is!");
	return 0;
}
```
run above in terminal

exit code: `1`
```
host:~ username$ ./ispotato burrito
not a potato
```
exit code: `0`
```
host:~ username$ ./ispotato potato
potato it is!
```
*function breaks after `return` is ran*
### Console errors
