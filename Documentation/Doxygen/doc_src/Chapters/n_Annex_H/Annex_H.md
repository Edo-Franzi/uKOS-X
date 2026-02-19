# 🌈  Annex H, Misra - C µKOS-X compliance matrix

## Introduction

The µKOS-X project source code has been developed with a strong emphasis on software reliability, and as such, it is **nearly fully compliant** with the **MISRA C Coding Standards** (Motor Industry Software Reliability Association). These standards were established to promote safe, secure, and robust programming practices in the C language, particularly for use in **mission-critical automotive systems** where predictable behaviour is essential.

The **MISRA guidelines** are widely recognised across safety-critical industries and have become a de facto standard for high-integrity software development. The consortium behind these standards comprises prominent industrial players and academic partners, including **Delco Electronics, Ford Motor Company, Jaguar Cars Ltd., Lotus Engineering, Lucas Electronics, Rolls-Royce, Rover Group Ltd.**, and several universities - all dedicated to advancing safety and reliability in embedded and automotive systems.

Comprehensive information about these standards can be found on the official MISRA website: [http://www.misra.org.uk](http://www.misra.org.uk/).

µKOS-X includes a **detailed compliance matrix** that maps its coding practices against the original **MISRA C:1998 ruleset**, providing transparency on adherence and identifying any exceptions. Due to the µKernel’s robust architectural design and disciplined coding approach, only **minor adjustments** are needed for complete compliance. In fact, µKOS-X was architected from the outset with many of MISRA’s principles inherently built in — reflecting a long-standing commitment to **software quality, maintainability, and safety**.

<div class="full_width_table">

| **µKOS-X**      |                   |                      | MISRA C 1998 compliance matrix                               |
| :-------------- | :---------------- | :------------------- | :----------------------------------------------------------- |
| **Rule number** | **Required rule** | **µKOS-X compliant** | **Brief description of the rule**                            |
|                 |                   |                      | **Environment**                                              |
| 1               | Required          | Yes                  | All code shall conform to ISO/IEC 9899:1990 “Programming languages — C”, amended and corrected by ISO/IEC 9899/COR1:1995, ISO/IEC 9899/AMD1:1995, and ISO/IEC 9899/COR2:1996 |
| 2               | Advisory          | Yes                  | Code written in languages other than C should only be used if there is a defined interface standard for object code to which the compilers/assemblers for both languages conform |
| 3               | Advisory          | No (1)               | Assembly language functions that are called from C should be written as C functions containing only in-line assembly language, and in-line assembly language should not be embedded in normal C code |
| 4               | Advisory          | Yes                  | Provision should be made for appropriate run-time checking   |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Character Sets**                                           |
| 5               | Required          | Yes                  | Only those characters and escape sequences which are defined in the ISO C standard shall be used |
| 6               | Required          | Yes                  | Values of character types shall be restricted to a defined and documented subset of ISO 10646-1 |
| 7               | Required          | Yes                  | Trigraphs shall not be used                                  |
| 8               | Required          | Yes                  | Multibyte characters and wide string literals shall not be used |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Comments**                                                 |
| 9               | Required          | Yes                  | Comments shall not be nested                                 |
| 10              | Advisory          | Yes                  | Sections of code should not be 'commented out'               |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Identifiers**                                              |
| 11              | Required          | Yes                  | Identifiers (internal and external) shall not rely on significance of more than 31 characters. Furthermore the compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers |
| 12              | Advisory          | Yes                  | No identifier in one name space shall have the same spelling as an identifier in another name space |
| 13              | Advisory          | Yes                  | The basic types of char, int, short, long, float and double should not be used, but specific-length equivalents should be typedef'd for the specific compiler, and these type names used in the code |
| 14              | Required          | Yes                  | The type char shall always be declared as unsigned char or signed char |
| 15              | Advisory          | Yes (2)              | Floating point implementations should comply with a defined floating point standard |
| 16              | Required          | Yes (2)              | The underlying bit representations of floating point numbers shall not be used in any way by the programmer |
| 17              | Required          | Yes                  | typedef names shall not be reused                            |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Constants**                                                |
| 18              | Advisory          | Yes (3)              | Numeric constants should be suffixed to indicate type, where an appropriate suffix is available |
| 19              | Required          | Yes                  | Octal constants (other than zero) shall not be used          |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Declarations and Definitions**                             |
| 20              | Required          | Yes                  | All object and function identifiers shall be declared before use |
| 21              | Required          | Yes                  | Identifiers in an inner scope shall not use the same name as an identifier in an outer scope, and therefore hide that identifier |
| 22              | Advisory          | Yes                  | Declarations of objects should be at function scope unless a wider scope is necessary |
| 23              | Advisory          | Yes                  | All declarations at file scope should be static where possible |
| 24              | Required          | Yes                  | Identifiers shall not simultaneously have both internal and external linkage in the same translation unit |
| 25              | Required          | Yes                  | An identifier with external linkage shall have exactly one external definition |
| 26              | Required          | Yes                  | If objects or functions are declared more than once they shall have compatible declarations |
| 27              | Advisory          | Yes                  | External objects should not be declared in more than one file |
| 28              | Advisory          | Yes                  | The register storage class specifier should not be used      |
| 29              | Required          | Yes                  | The use of a tag shall agree with its declaration            |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Initialisation**                                           |
| 30              | Required          | Yes                  | All automatic variables shall have been assigned a value before being used |
| 31              | Required          | Yes                  | Braces shall be used to indicate and match the structure in the non-zero initialisation of arrays and structures |
| 32              | Required          | Yes                  | In an enumerator list, the '=' construct shall not be used to explicitly initialize members other than the first, unless all items are explicitly initialized |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Operators**                                                |
| 33              | Required          | Yes                  | The right hand operand of a && or \|\| operator shall not contain side effects |
| 34              | Required          | Yes                  | The operands of a logical && or \|\| shall be primary expressions |
| 35              | Required          | Yes                  | Assignment operators shall not be used in expressions which return Boolean values |
| 36              | Advisory          | Yes                  | Logical operators should not be confused with bitwise operators |
| 37              | Required          | Yes                  | Bitwise operations shall not be performed on signed integer types |
| 38              | Required          | Yes                  | The right hand operand of a shift operator shall lie between 0 and one less than the width in bits of the left hand operand (inclusive) |
| 39              | Required          | Yes                  | The unary minus operator shall not be applied to an unsigned expression |
| 40              | Required          | Yes                  | The sizeof operator should not be used on expressions that contain side effects |
| 41              | Advisory          | Yes                  | The implementation of integer division in the chosen compiler should be determined, documented and taken into account |
| 42              | Required          | Yes                  | The comma operator shall not be used, except in the control expression of a for loop |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Conversions**                                              |
| 43              | Required          | Yes                  | Implicit conversions which may result in a loss of information shall not be used |
| 44              | Advisory          | No                   | Redundant explicit casts should not be used                  |
| 45              | Required          | No (4)               | Type casting from any type to or from pointers shall not be used |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Expressions**                                              |
| 46              | Required          | Yes                  | The value of an expression shall be the same under any order of evaluation that the standard permits |
| 47              | Advisory          | Yes                  | No dependence should be placed on C's operator precedence rules in expressions |
| 48              | Advisory          | Yes                  | Mixed precision arithmetic should use explicit casting to generate the desired result |
| 49              | Advisory          | Yes                  | Tests of a value against zero should be made explicit, unless the operand is effectively Boolean |
| 50              | Required          | Yes                  | Floating point variables shall not be tested for exact equality or inequality |
| 51              | Required          | Yes                  | Evaluation of constant unsigned integer expressions should not lead to wrap-around |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Control Flow**                                             |
| 52              | Required          | Yes                  | There shall be no unreachable code                           |
| 53              | Required          | Yes                  | All non-null statements shall have a side-effect             |
| 54              | Required          | Yes                  | A null statement shall only occur on a line by itself, and shall not have any other text on the same line |
| 55              | Advisory          | Yes                  | Labels should not be used, except in switch statements       |
| 56              | Required          | Yes                  | The goto statement shall not be used                         |
| 57              | Required          | No                   | The continue statement shall not be used                     |
| 58              | Required          | Yes                  | The break statement shall not be used (except to terminate the cases of a switch statement) |
| 59              | Required          | Yes                  | The statements forming the body of an if, else if, else, while, do while or for statement shall always be enclosed in braces |
| 60              | Advisory          | No                   | All if, else if constructs should contain a final else clause |
| 61              | Required          | Yes                  | Every non-empty case clause in a switch statement shall be terminated with a break statement |
| 62              | Required          | Yes                  | All switch statements should contain a final default clause  |
| 63              | Advisory          | Yes                  | A switch expression should not represent a Boolean value     |
| 64              | Required          | Yes                  | Every switch statement shall have at least one case          |
| 65              | Required          | Yes                  | Floating point variables shall not be used as loop counters  |
| 66              | Advisory          | Yes                  | Only expressions concerned with loop control should appear within a for statement |
| 67              | Advisory          | Yes                  | Numeric variables being used within a for loop for iteration counting should not be modified in the body of the loop |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Functions**                                                |
| 68              | Required          | Yes                  | Functions shall always be declared at file scope             |
| 69              | Required          | Yes                  | Functions with variable numbers of arguments shall not be used |
| 70              | Required          | Yes                  | Functions shall not call themselves, either directly or indirectly |
| 71              | Required          | Yes                  | Functions shall always have prototype declarations and the prototype shall be visible at both the function definition and call |
| 72              | Required          | Yes                  | For each function parameter the type given in the declaration and definition shall be identical, and the return types shall also be identical |
| 73              | Required          | Yes                  | Identifiers shall either be given for all of the parameters in a function prototype declaration, or for none |
| 74              | Required          | Yes                  | If identifiers are given for any of the parameters, then the identifiers used in the declaration and definition shall be identical |
| 75              | Required          | Yes                  | Every function shall have an explicit return type            |
| 76              | Required          | Yes                  | Functions with no parameters shall be declared with parameter type void |
| 77              | Required          | Yes                  | The unqualified type of parameters passed to a function shall be compatible with the unqualified expected types defined in the function prototype |
| 78              | Required          | Yes                  | The number of parameters passed to a function shall match the function prototype |
| 79              | Required          | Yes                  | The values returned by void functions shall not be used      |
| 80              | Required          | Yes                  | Void expressions shall not be passed as function parameters  |
| 81              | Advisory          | Yes                  | const qualification should be used on function parameters which are passed by reference, where it is intended that the function will not modify the parameter |
| 82              | Advisory          | No                   | A function should have a single point of exit                |
| 83              | Required          | Yes                  | For functions with non-void return type: i) there shall be one return statement for every exit branch (including the end of the program) , ii) each return shall have an expression, iii) the return expression shall match the declared return type |
| 84              | Required          | Yes                  | For functions with void return type, return statements shall not have an expression |
| 85              | Advisory          | Yes                  | Functions called with no parameters should have empty parentheses |
| 86              | Advisory          | No                   | If a function returns error information, then that error information should be tested |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Pre-processing Directives**                                |
| 87              | Required          | Yes                  | **include** statements in a file shall only be preceded by other pre- processor directives or comments |
| 88              | Required          | Yes                  | Non-standard characters shall not occur in header file names in **include** directives |
| 89              | Required          | Yes                  | "The #include directive shall be followed by either a <filename> or ""filename"" sequence." |
| 90              | Required          | Yes                  | C macros shall only be used for symbolic constants, function-like macros, type qualifiers and storage class specifiers |
| 91              | Required          | Yes                  | Macros shall not be **define** and **undef** within a block  |
| 92              | Advisory          | No                   | **undef** should not be used                                 |
| 93              | Advisory          | Yes                  | A function should be used in preference to a function-like macro |
| 94              | Required          | Yes                  | A function-like macro shall not be 'called' without all of its arguments |
| 95              | Required          | Yes                  | Arguments to a function-like macro shall not contain tokens that look like pre-processing directives |
| 96              | Required          | Yes                  | In the definition of a function-like macro the whole definition, and each instance of a parameter, shall be enclosed in parentheses |
| 97              | Advisory          | Yes                  | Identifiers in pre-processor directives should be defined before use |
| 98              | Required          | Yes                  | There shall be at most one occurrence of the # or ## pre- processor operators in a single macro definition |
| 99              | Required          | Yes                  | All uses of the **pragma** directive shall be documented and explained |
| 100             | Required          | Yes                  | The defined pre-processor operator shall only be used in one of the two standard forms |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Pointers and Arrays**                                      |
| 101             | Advisory          | No                   | Pointer arithmetic should not be used                        |
| 102             | Advisory          | Yes                  | No more than 2 levels of pointer indirection should be used  |
| 103             | Required          | Yes                  | Relational operators shall not be applied to pointer types except where both operands are of the same type and point to the same array, structure or union |
| 104             | Required          | Yes                  | Non-constant pointers to functions shall not be used         |
| 105             | Required          | Yes                  | All the functions pointed to by a single pointer to function shall be identical in the number and type of parameters and the return type |
| 106             | Required          | Yes                  | The address of an object with automatic storage shall not be assigned to an object which may persist after the object has ceased to exist |
| 107             | Required          | Yes                  | The null pointer shall not be de-referenced                  |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Structures and Unions**                                    |
| 108             | Required          | Yes                  | In the specification of a structure or union type, all members of the structure or union shall be fully specified |
| 109             | Required          | Yes                  | Overlapping variable storage shall not be used               |
| 110             | Required          | Yes                  | Unions shall not be used to access the sub-parts of larger data types |
| 111             | Required          | Yes                  | Bit fields shall only be defined to be of type unsigned int or signed int |
| 112             | Required          | Yes                  | Bit fields of type signed int shall be at least 2 bits long  |
| 113             | Required          | Yes                  | All the members of a structure (or union) shall be named and shall only be accessed via their name |
|                 |                   |                      |                                                              |
|                 |                   |                      | **Standard Libraries**                                       |
| 114             | Required          | Yes                  | Reserved words and standard library function names shall not be redefined or undefined |
| 115             | Required          | Yes                  | Standard library function names shall not be reused          |
| 116             | Required          | Yes (5)              | All libraries used in production code shall be written to comply with the provisions of this document, and shall have been subject to appropriate validation |
| 117             | Required          | Yes                  | The validity of values passed to library functions shall be checked |
| 118             | Required          | No (6)               | Dynamic heap memory allocation shall not be used             |
| 119             | Required          | Yes                  | The error indicator errno shall not be used                  |
| 120             | Required          | Yes                  | The macro offsetof, in library <stddef.h>, shall not be used |
| 121             | Required          | Yes                  | <locale.h> and the setlocale function shall not be used      |
| 122             | Required          | Yes                  | The setjmp macro and the longimp function shall not be used  |
| 123             | Required          | Yes                  | The signal handling facilities of <signal.h> shall not be used |
| 124             | Required          | Yes                  | The input/output library <stdio.h> shall not be used in production code |
| 125             | Required          | Yes                  | The library functions atof, atoi and atol from library <stdlib.h> shall not be used |
| 126             | Required          | Yes (7)              | The library functions abort, exit, getenv and system from library <stdlib.h> shall not be used |
| 127             | Required          | Yes                  | The time handling functions of library <time.h> shall not be used |

</div>

<div class="full_width_table">

| **MISRA C 1998** |      | **µKOS-X**                 |
| :--------------- | :--- | :------------------------- |
|                  |      | **Violations**             |
| Required rules   | 97   | 2 (45, 118)                |
| Advisory rules   | 30   | 6 (3, 60, 82, 86, 92, 101) |

</div>

Notes

1. µKOS-X assembly code is encapsulated by C macros located in the macros.h file. The only exception is the inline assembly code used by the µKernel for the context switching, for the exception crash management and for the initialisation of the stack pointer in the **crt0**. For readability reason, it is better to maintain the assembler code “visible” in these part of the project.
2. µKOS-X uses the gcc implementation.
3. µKOS-X assumes that the compiler will catch those .
4. Too restrictive in embedded.
5. Computer specific.
6. µKOS-X µKernel does not use any dynamic memory allocation. However, some operating system modules (not mandatory) could use memo_malloc and derivative. In SoC, for footprint memory reasons, it is necessary to dynamically share memory regions; in this case, memo_malloc is unavoidable.
7. µKOS-X uses its own exit and not the stdlib one.


## References

1. **MISRA** “Guidelines For The Use Of The C Language In Vehicle Based Software”, April 1998.
