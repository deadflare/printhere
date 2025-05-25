## printhere
debugging print utility

### description:

this is a small program for debugging purposes. a common, rudimentary troubleshooting technique is to insert an `std::cout << "here\n";` in the code, and if it prints, then you know the code ran at least up to that point. if it doesnt print, the code broke before then. determining where exactly the code breaks can show you what went wrong. its also common in the same std::cout to print the value of a variable, which can provide further information.

the thing i dont like about this technique is that printing the output of several variables at a time is tedious and messy. for example:

`std::cout << "\n" << string_one << "\n" << string_two << "\n" << std::to_string (i) << "\n";`

the purpose of this program is to turn that into this:

`std::cout << here (string_one, string_two, i);`

### usage:

#### setting up:

copy 'here.h' into your project directory

`#include "here.h"`

 

#### function usage:

call the function wherever you want to test for:

`std::cout << here (variables);`

the function doesnt print anything itself, it just returns the string to be printed, so an std::cout is needed

can enter any number of variables separated by comma to be printed

can also enter direct strings, such as variable names

works with the common data types: int, string, char, bool, float, etc

### files:

here.h contains the function used. this is the only file needed to use the program

main.cpp is an example to demonstrate usage
