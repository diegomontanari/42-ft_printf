# 42-ft_printf, Step By Step Guide:
If you want to get a clear idea of how the printf function works in C, this repo is for you. This is a 42 school project, for which I am required to follow a norm. I will walk through step by step how you too can create a copy of the printf function. let's start.

![640px-Hokusai,_The_Underwave_off_Kanagawa](https://github.com/user-attachments/assets/014357e5-563b-43a7-af17-1ab5f908714a)
# 1) Creating the header file

First of all we must define our header. With this project I understood better what the header guard was.

## Header guard

- `#ifndef FUNCTION`: Checks if a macro hasn't been defined.
- `#define FUNCTION`: If the macro wasn't defined, it defines it.
- Function call
- `#endif`: Terminates the conditional block.

This technique is known as "header guard" and serves to protect the file from multiple inclusions, which could cause compilation errors.

After that, I defined and called all the functions that I needed in the header.

# 2) Creating ft_printf()

This is the main function of the project. First of all, we connect the function to the header with `#include "ft_printf.h"`.

Now, we create a function for each format specifier (%d, %s, %c, etc.). Given that each format specifier represents a different data type, a dedicated function is needed that knows how to handle it.

PS: Obviously a format specifier is a symbol that indicates the data type, and in C, these symbols always start with %.

Once created this group of functions, a "traffic controller" function is needed that decides which of these functions to call based on the specifier. I chose to call it controller()())(.

Now I must create the most important function of all: printf(). Printf has the task of reading the format string, and when it finds the character % it calls controller()()() which "routes" the request to the various helper functions for each format type.

To understand each other, the flow is this:

ft_printf scans the format string character by character.
When it finds the character %, it understands that the next character is a format flag (or specifier).
At this point, ft_printf calls the flag_print function passing the specifier character and the list of arguments.
(Therefore, the format string is "read" by ft_printf which, when it encounters %, delegates to flag_print the task of choosing and calling the correct helper function for that particular specifier.)

Remember that printf() has another very important function: handling va_list arguments

## Va_list

📌 What is va_list and what is it for?
va_list is a data type defined in <stdarg.h> that allows handling a variable number of arguments in a function.

✅ Classic example: printf(), which can receive a variable number of parameters.
✅ In your project: ft_printf() must do the same.

🛠 The 4 fundamental macros of stdarg.h
Macro | Purpose
--- | ---
va_list | Declaration of the variable to handle variable arguments.
va_start | Initializes va_list and prepares it to read arguments.
va_arg | Extracts the next argument from the list.
va_end | Terminates the use of va_list and frees the memory allocated internally. (It's a macro that frees the resources associated with va_list, it must be used after finishing processing all variadic arguments, to avoid any memory problems or undefined behaviors and it's practically malloc associated with va lists)

🔍 How to use them?
📌 1. Declare a function with variable arguments
```c
#include <stdarg.h>
#include <stdio.h>

void my_function(int num, ...);
```
🔹 The first parameter int num is a fixed argument (at least one argument is needed to understand how many others there are).
🔹 The ... indicates that there are variable arguments.

📌 2. Declare and initialize va_list
```c
void my_function(int num, ...)
{
    va_list args;  // Declaration
    va_start(args, num);  // Initialization, specifying the last fixed argument
}
```
✅ va_start(args, num): starts reading the variable parameters after num.

📌 3. Extract values with va_arg
```c
for (int i = 0; i < num; i++)
{
    int value = va_arg(args, int); // Retrieves the next parameter (of type int)
    printf("Parameter %d: %d\n", i + 1, value);
}
```
✅ va_arg(args, int): takes the next parameter from the list and converts it to int.
✅ Each call to va_arg() advances the reading to the next parameter.

📌 4. Terminate reading with va_end
```c
va_end(args);  // Cleans the memory used internally
}
```
✅ va_end(args): IMPORTANT! Must always be called when you've finished reading the arguments.

🚀 Complete example code
```c
#include <stdarg.h>
#include <stdio.h>

void my_function(int num, ...)
{
    va_list args;
    va_start(args, num);

    for (int i = 0; i < num; i++)
    {
        int value = va_arg(args, int);
        printf("Parameter %d: %d\n", i + 1, value);
    }

    va_end(args);
}

int main()
{
    my_function(3, 10, 20, 30);
    return 0;
}
```
🔹 Output:
```yaml
Parameter 1: 10  
Parameter 2: 20  
Parameter 3: 30  
```

Well, now that we have seen how printf() uses va_list, we have finished, we are missing two steps: create a main.c file to test our program, and create the Makefile to automate the compilation of our program.

------

(PS that must be put in the readme of libft): Automating the compilation of your program means creating a process that automatically compiles all necessary source files and generates the executable with a single command.

You can do this by creating a Makefile, which is a script used by the make utility to manage the project compilation.

------

-----------------------------
3 questions i had between the printf() and collector() functions that you may also have:

Where in the code do you call args to advance to the next variadic argument? 
In the code, the args variable is advanced when you call va_arg(args, type) inside the ft_specifiers function. For example, va_arg(args, int) fetches the next argument and moves the pointer forward.

ft_print_char(va_arg(args, int), count); a friend told me that in args, type called in the helper functions I must put the type of the next argument of args. But I haven't understood well the process, how do I know the next argument? 
In ft_printf, the format string (s) determines the type of the next argument. Each format specifier (like %c, %s, %d, etc.) in the string tells ft_specifiers which type to expect and how to handle it. For example, %c expects an int, %s expects a char*, and %d expects an int. When you encounter a format specifier, you use va_arg(args, type) to extract the next argument of the specified type. Here's how the process works: Read the format string character by character. When you encounter a %, read the next character to determine the type. Call va_arg(args, type) with the corresponding type. In your code, ft_specifiers handles this logic: ```c if (c == 'c') ft_print_char(va_arg(args, int), count); // '%c' expects an int else if (c == 's') ft_print_str(va_arg(args, char *), count); // '%s' expects a char* else if (c == 'd' || c == 'i') ft_print_int(va_arg(args, int), count); // '%d' or '%i' expects an int ...``` So, to know the type of the next argument, you rely on the format specifier in the format string.

why are u x and X unsigned? 
In ft_printf, the format specifiers %u, %x, and %X are used to print unsigned integers. Here's why: %u prints an unsigned decimal integer. %x prints an unsigned hexadecimal integer in lowercase. %X prints an unsigned hexadecimal integer in uppercase. Unsigned integers are used for these specifiers because they represent non-negative numbers, making them suitable for displaying hexadecimal values and large positive numbers without the risk of negative values. 
-----------------------

# 3) Creating the main.c file to test the program
Creating the main.c file:

Inside your project, create a file called main.c.
Writing the test code in main.c:

Add code to test the functionalities of your ft_printf function.
```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s! Number: %d\n", "world", 42);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Unsigned: %u\n", 123456789);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Percent: %%\n");
    return 0;
}
```
# 4) Creating the Makefile to automate compilation
Creating the Makefile file:

Inside your project, create a file called Makefile.
Writing the compilation instructions in the Makefile:

