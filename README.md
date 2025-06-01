#  Monty Bytecode Interpreter

**Monty** is a C-based bytecode interpreter for a custom stack-based scripting language. It parses `.m` bytecode files and executes commands using a **LIFO** (Last In, First Out) stack model.

This project demonstrates deep understanding of low-level memory management, file I/O, token parsing, custom error handling, and dynamic data structures using **doubly linked lists**.

##  Features

-  Parses and executes Monty bytecode files
-  Implements core opcodes like `push`, `pall`, `pop`, `add`, `nop`
-  Handles stack manipulations and arithmetic operations
-  Graceful handling of unknown or malformed opcodes
-  Dynamically tokenizes and interprets commands line-by-line
-  Doubly linked list implementation for stack
-  Modular, maintainable design with opcode dispatch table

##  Core Architecture

- **Entry Point:**  
  `main_monty.c` opens and reads bytecode line-by-line, sending each line to the interpreter.

- **Opcode Execution:**  
  `execute_opcode.c` uses a dispatch table to route instructions like `push`, `pall`, `pop`, etc., to their handler functions.

- **Opcode Handlers:**  
  `opcodes1.c` implements all stack operations (e.g., `op_push`, `op_pall`, `op_pop`, `op_add`, `op_nop`).

- **Header File:**  
  `monty.h` defines all function prototypes, macros, and the `stack_t` and `instruction_t` structs.

- **Bytecode Programs:**  
  The `bytecodes/` directory contains example scripts such as:
  - `00.m`: Push and pall
  - `07.m`: Stack manipulation with `pop`
  - `66.m`: Contains deliberate error (`addd`) to test handling

##  Example Bytecode File

```
push 1
push 2
push 3
pall
pop
pall
```

##  Output
```
3
2
1
2
1
```

##  Stack Structure

Each element is stored in a **doubly linked list** (`stack_t`), allowing flexible stack/queue behaviors if extended.  
Current implementation operates strictly in **stack mode** (LIFO).

##  Build & Run

###   Compile

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

### Run a Bytecode File
```
./monty bytecodes/00.m
```

## Learning Objectives

- Handling custom scripting languages
- Building interpreters with token-based parsing
- Using function pointers and dispatch tables
- Building a flexible, dynamic stack with linked lists
- Graceful memory and file management
