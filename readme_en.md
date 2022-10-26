> «Programs should be written to be read by humans and only secondarily to be executed by machines..»
>     — Harold Abelson, Gerald Jay Sussman, Julie Sussman («Structure and Interpretation of Computer Programs»)


***EasyLogic scripting language --  is a specialized simple C-like language with static typing used to extend the capabilities of Galileosky tracking devices.***

**Main features:**
- Functions for working with ports (RS232, RS485, CAN port) and inputs / outputs.
- tag access (read / write)
- access to graphical algorithm variables (read / write) used to run the script
- access to global variables (read only)
- orking with SD card files

It supports writing functional and imperative style code.

**Used data types:**
- bool
- int32 - character integers ranging from -2,147,483,648 to 2,147,483,647
- one-dimensional and multidimensional arrays int32[]
- character strings in ASCII format ( stored as one-dimensional character arrays)

# Programming language syntax

*Distinguishing features from the C language:*
- no need to add header files
- the ";" characters are optional, except when several expressions are written in one line
- if the function body consists of a single instruction, parentheses {} are optional

## Comments 
```cpp

// single line comment

/*  multiline
	comment
	*/

```

## Variables and constants
```cpp

#define CONST_5 5

const CONST_0 = 0

new var1
new var2 = 0

var1 = CONST_5
var2 = CONST_0
var1 = var2

```

## Arrays

Indexing starts with a 0 element.
An array is a sequence of 32-bit words, accessed using square brackets [].
Each word consists of 4 bytes, so in order to reduce memory usage, by-byte access can be used with curly brackets {}, allowing the array to be used as a sequence of bytes.
Just like regular variables, an array can also be defined as a constant and/or be initialized.
```cpp

const PORT_BUF_SIZE = 245

new oBuf{PORT_BUF_SIZE} //Declaration of an array, size 245 bytes, taking up 245/4 => 62 elements in memory (32-bit words)
new cBuf[10] //Declaration of an array of 10 elements (32-bit words), i.e. 10*4 => 40 bytes
new const fMap_fAttr[2] = [0x20000, 0x50000] //Declaration of a constant array with its initialization

```
mples of accessing array elements:
```cpp

oBuf{0} = 2          //Assigning the value 2 to byte 0 of the array
oBuf[1] = 0x5028100  //Assigning the value 0x5028100 to the 1st element of the same array, which would be equivalent to the following:
                     //oBuf{4} = 0x05
                     //oBuf{5} = 0x02
                     //oBuf{6} = 0x81
                     //oBuf{7} = 0x00

cBuf{1} = 0x5        //Equivalent to the following entry (attention, 4 bytes are written at once): cBuf[0] = 0x00050000

```
Multidimensional arrays are arrays that contain references to subarrays.
Each subarray can have a different length.
The following are examples of two-dimensional array declarations:

```cpp

new a[4][3] //4 lines of 3 columns each

/*  Two-dimensional array with subarrays of different lengths. 
	e[1][5] contains the letter "l", but 
	e[0][5] - is an invalid element, because  
	the length of the subarray 0 is 3 ("O", "K", "\0")
	*/
new e[2][] = [ "OK", "Cancel" ]

```
The sizeof operator is used to determine the size of an array.
This operator returns the number of elements (32-bit words), not bytes!
For multidimensional arrays, calling this operator with an array name without parentheses will return the main dimension, with parentheses - the dimension of the subarray:
```cpp

new matrix[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } }

Diagnostics("%d %d", sizeof matrix, sizeof matrix[]); // The diagnostics will show a line "3 2"

```
## Opertaors

Common brackets () - control the order of calculation of the expression.
Square brackets [] are used for array indexing.
The *new* operator is used to create variables and arrays.

### Mathematical operators
- multiplication (a \* b),
- division (a / b) - fractional part is discarded,
- addition (a + b),
- subtraction (a - b),
- the remainder of dividing *a* by *b* (a % b).

### Comparison operators
- "less than" (<)
- "less or equal" (<=)
- "more" (>)
- "more or equal" (>=)
- "equal" (==)
- "not equal" (!=)

### Logical operators
- "И" (&&)
- "OR" (||)
- "NOT" (!) - inverts a value other than zero into *0*, and *0* into *1*, true into false and vice versa.

### Bit operators
- "И" (&)
- OR (|)
- NOT (\~)
- exclusive OR (XOR) (^)
```cpp

// Define 8 separate bit flags (they can represent anything you want).
const option1 = 0x01; // hex literal for 0000 0001
const option2 = 0x02; // hex literal for 0000 0010
const option3 = 0x04; // hexadecimal literal for 0000 0100
const option4 = 0x08; // hexadecimal literal for 0000 1000
const option5 = 0x10; // hexadecimal literal for 0001 0000
const option6 = 0x20; // hexadecimal literal for 0010 0000
const option7 = 0x40; // hexadecimal literal for 0100 0000
const option8 = 0x80; // hexadecimal literal for 1000 0000
 
// Byte values to store combinations of the 8 possible choices
new myflags = 0; // all flags/parameters are disabled before start

```
To know the bit state, bitwise AND is used:
```cpp
if (myflags & option4) ... // if option4 is set - do something
```
To turn bits on, bitwise OR is used:
```cpp
myflags |= option4; // enable option4
myflags |= (option4 | option5); // enable option4 and option5
```
To turn bits off, a bitwise AND with inverted literal is used:
```cpp
myflags &= ~option4; // turn option4 off
myflags &= ~(option4 | option5); // turn off option4 and option5
```
To switch between bit states, a bitwise exclusive OR (XOR) is used:
```cpp
myflags ^= option4; // turn option4 on and off 
myflags ^= (option4 | option5); // we change states of option4 and option5
```

### Selection operators
```cpp

if (a > b)
{
	Diagnostics("true")
}

if (a > b)
{
	Diagnostics("true")
}
else
{
	Diagnostics("false")
}

if (a > b)
{
	Diagnostics("true")
}
else if (a < b)
{
	Diagnostics("false")
}
else
{
	Diagnostics("equals")
}

switch (a)  // only one block of code will be executed in order when the value to be searched for matches
{
	case 0, 1: // when *a* == 0 or 1. The other blocks will not be executed.
	{
		Diagnostics("true")
	}
	case 2:  // when *а* == 2
	{
		Diagnostics("false")
	}
	default:  // at any other value. The other blocks will not be executed.
	{
		Diagnostics("null")
	}
}

new var = (a > b) ? a : b // if (a > b) == true, it returns *a*, otherwise *b*

```

### Cycle operators
```cpp

for (new i = 0; i < 10; i++)
{
	Diagnostics("%d", i)
}

new i = 0
for (; i < 10; i++)
{
	Diagnostics("%d", i)
}

new j = 0
while (j < 10)
{
	Diagnostics("%d", j++)
}

while(true)  // infinite cycle
{
	// code
}

while (1)  // infinite cycle
{
	// code
}

```

## Functions

Variables are passed to functions by value, and arrays by reference.
A variable can be passed by reference with the "&" symbol.
The order in which the function is declared is not important.
The function can either return a value (for this purpose the operator return *<value>* is used) or not.
```cpp

//User-defined function
myFunc(&a, b) //The *a* argument will be passed by reference, the *b* argument will be passed by value
{
    a += 2
    return a + b //return value
}

myArrayFunc(buf{}, size)  // Passing arrays into a function is always by reference.
{
    for(new i = 0; i < size; i++)
    {
        Diagnostics("Buf[%d] = %d", i, buf{i})
    }
}

```

### Structure
```cpp

// constant declaration
#define CONST_5 5

const CONST_0 = 0
const CONST_1 = 1

// global variable declaration
new var1 = 42
new var2 = 0

/*	Any program must contain an "input" function main, 
	which will be called when running the script from the algorithms. 
	After exiting the main function, the script terminates and all variables are eliminated,  
	so if it is necessary to save data between iterations of the script call 
        global variables of the graphical algorithms should be used
	*/
main()
{
    // code
}


// user function declaration
myFunc0()
{
    // code
}

myFunc1(a)
{
    // code
}

```

# Code appearance

- _Up to 80% of the software cost is spent on support_
- _usually it is not the author who provides support_
- _Agreements improve code readability, allowing developers and other engineers to understand (other people's) code faster_

### Indents

Use 4 spaces per indentation level.

### Maximum line length

Limit the maximum line length to 79 characters.

Line spacing (general principles):
- hyphenation after a comma
- before operators
- it is better to use hyphenation
- newlines must be aligned with the expression on the previous line
- if the rules lead to poor readability, 8 spaces are used
- Each line must contain only one expression

#### Line hyphenation - Examples
```cpp

function(longExpression1, longExpression2, longExpression3,
         longExpression4, longExpression5);

var = function(longExpression1,
               func2(longExpression2,
                     longExpression3));

alpha = (aLongBooleanExpression)
        ? beta
        : gamma;

argv++; // Correct
argc--; // Correct

argv++; argc--; // AVOID!

```

### Blank lines.

- An empty line MUST be added before the comment
- A blank line MUST be added before the function declaration
- Function groups must be separated by TWO blank lines
- Groups of variables and constants must be separated by an empty line

### Source file encoding

The encoding must be **UTF-8**

### Parentheses

- "Internal" expressions are shifted 1 level to the right
- The opening "{" is placed on a new line of code
- Closing "}" is placed on a separate line, aligned with the expression that opens the block
- Parentheses are ALWAYS used around expressions that are part of control expressions (even single line expressions)
- Always use brackets in long expressions, this avoids problems with the priority of operations. If the priority is clear to you, it is not necessarily clear to others.

```cpp

if (condifion)
{
    Diagnostics(“condition is true!”);
}

if ( (a == b) && (c == d) )
{
    statements;
} 
else if (condition)
{
    statements;
} 
else
{
    statements;
}

```

### Spaces

- Keywords followed by a parenthesis must be separated by a space
- A space is NOT used between a function name and a bracket (parameters). This helps to distinguish between methods and control constructions.
- Space is mandatory after a comma in the parameter list
- All binary operators (except for the period) must be separated by a space from both operands
- Expressions defining a for loop are separated by spaces

### Naming

- Names should be short, but "semantic", making their meaning clear.
- Variable names defined as constants are written in uppercase, with words separated by an underscore ("\_")

```cpp

const ASCII_ZERO	=	0x30;
const ASCII_ONE		=	0x31;
const ASCII_TWO		=	0x32;
const ASCII_THREE	=	0x33;
const ASCII_FOUR	=	0x34;
const ASCII_FIVE	=	0x35;
const ASCII_SIX		=	0x36;
const ASCII_SEVEN	=	0x37;
const ASCII_EIGHT	=	0x38;
const ASCII_NINE	=	0x39;

const ASCII_DOT		=	0x2E;

```

- Numeric constants should not be used in the code directly, except for the values -1, 0, and 1, which often appear in cycles
- Single-character names should be avoided except for temporary variables. 
Standard names for them are: 
- i, j, k, m and n for integers
- c, d and e for characters

[Good article on coding](https://frontender.info/why-coding-style-matters/)