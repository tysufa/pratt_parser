
# Pratt Parser - Basic Implementation in C++

## Description
A Pratt Parser is an efficient method for parsing arithmetic expressions and other grammatical structures with operators of varying precedence. This C++ implementation provides a simple version capable of parsing mathematical expressions like `1 + 2 * (-3 - 4)` while respecting operator precedence.

## Features
- Support for binary operators (`+`, `-`, `*`, `/`)
- Operator precedence handling
- Simple parsing of arithmetic expressions
- Support correctly parenthesized expressions

## Installation
You can compile it by using cmake : 
```
mkdir build && cd build
cmake ..
make
./Pratt_parser
```
or using any compiler, here is an exemple with g++ :
```
g++ main.cpp parser.h parser.cc lexer.h lexer.cc -o Pratt_parser
./Pratt_parser
```

## Usage
1. Run the executable:
   ```bash
   ./pratt_parser
   ```
2. Enter a mathematical expression, for example:
   ```
   > 1 + 2 * 3
   ```
   The program will show the correctly parenthesized expression, here `(1+(2*3))`

## Project Structure
```
pratt_parser/
├── main.cpp        # Main entry point of the application
├── parser.cpp      # Pratt Parser implementation
├── parser.h        # Function and class definitions for the parser
├── lexer.cpp       # Lexer implementation to generate tokens
├── lexer.h         # Function and class definitions for the lexer
└── README.md       # Project documentation
```

## Code Example
Here is an example of how to use the parser in `main.cpp`:
```cpp
#include "parser.hh"
#include <string>

int main(int argc, char *argv[]){
   Lexer lexer("1 + -2*3");
   Parser parser(lexer);

   std::cout << parser.prattParser(0) << std::endl;;

  return 0;
}
```

---

Thank you for using this project! If you have any questions or suggestions, feel free to open an issue.

