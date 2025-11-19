# Minishell

A simplified implementation of a Unix shell written in C, recreating core functionalities of bash. This project is part of the 42 curriculum and demonstrates system programming concepts including process management, signal handling, and command parsing.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Built-in Commands](#built-in-commands)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Implementation Details](#implementation-details)
- [Requirements](#requirements)
- [Authors](#authors)

## Description

Minishell is a custom shell implementation that mimics the behavior of bash. It provides a command-line interface where users can execute commands, manage environment variables, handle redirections, use pipes, and interact with built-in commands. This project offers deep insights into process creation, signal handling, file descriptors, and parsing techniques.

## Features

### Core Functionality
- **Interactive Prompt**: Display a prompt when waiting for a new command
- **Command History**: Browse through previously executed commands using arrow keys (via readline)
- **Command Execution**: Search and launch executables based on PATH variable or relative/absolute paths
- **Quote Handling**: Proper interpretation of single (`'`) and double (`"`) quotes
- **Environment Variable Expansion**: Support for `$` expansion with variables
- **Exit Status**: Access the exit status of the last executed command via `$?`
- **Signal Handling**: 
  - `Ctrl-C`: Display new prompt
  - `Ctrl-D`: Exit shell
  - `Ctrl-\`: No action (ignored)

### Redirections
- `<` : Input redirection
- `>` : Output redirection
- `<<` : Here-document (heredoc)
- `>>` : Append output redirection

### Pipe Support
- `|` : Pipe commands (connect output of one command to input of another)

## Built-in Commands

The following commands are implemented as built-ins:

- **`echo`** with `-n` option
- **`cd`** - Change directory (relative or absolute path)
- **`pwd`** - Print working directory (no options)
- **`export`** - Set environment variables
- **`unset`** - Remove environment variables
- **`env`** - Display environment variables
- **`exit`** - Exit the shell

## Installation

### Prerequisites
- GCC compiler
- GNU Make
- Readline library

### On macOS
```bash
# Install readline via Homebrew if not already installed
brew install readline
```

### Build
```bash
# Clone the repository
git clone git@github.com:ky05h1n/Minishell.git
cd Minishell

# Compile the project
make

# The executable 'minishell' will be created
```

### Clean
```bash
# Remove compiled files
make clean

# Remove all generated files
make fclean

# Recompile everything
make re
```

## Usage

```bash
# Run the shell
./minishell

# Example commands
minishell$ echo "Hello, World!"
minishell$ pwd
minishell$ export MY_VAR=42
minishell$ echo $MY_VAR
minishell$ ls -la | grep minishell
minishell$ cat < input.txt > output.txt
minishell$ exit
```

## Project Structure

```
Minishell/
├── include/           # Header files
│   ├── builtins.h    # Built-in commands declarations
│   ├── data.h        # Data structures
│   ├── functions.h   # Function prototypes
│   ├── include.h     # Main include file
│   ├── init_nodes.h  # Node initialization
│   ├── lexer.h       # Lexer declarations
│   ├── parser.h      # Parser declarations
│   ├── parser_exec.h # Parser execution
│   └── token.h       # Token definitions
│
├── main/             # Main program files
│   ├── main.c        # Entry point
│   ├── init_sh.c     # Shell initialization
│   ├── init_nodes.c  # Node initialization
│   ├── get_prompt.c  # Prompt handling
│   ├── signal.c      # Signal handlers
│   └── error_msg.c   # Error messages
│
├── lexer/            # Lexical analysis
│   ├── lexer.c       # Main lexer logic
│   ├── token.c       # Token handling
│   └── lexer_utils.c # Lexer utilities
│
├── parser/           # Parsing and execution
│   ├── parser.c      # Main parser
│   ├── expand_doller.c # Variable expansion
│   ├── get_data.c    # Data extraction
│   └── parser_exec_preparation.c # Execution prep
│
├── builtins/         # Built-in commands
│   ├── builtins.c    # Built-in dispatcher
│   ├── cd.c          # Change directory
│   ├── echo.c        # Echo command
│   ├── env.c         # Environment display
│   ├── export.c      # Export variables
│   ├── unset.c       # Unset variables
│   ├── pwd.c         # Print working dir
│   ├── exit.c        # Exit command
│   ├── herdoc.c      # Here-document handling
│   └── envirement.c  # Environment management
│
├── libft/            # Custom C library
│   └── [various utility functions]
│
├── makefile          # Build configuration
└── README.md         # This file
```

## Implementation Details

### Lexer
The lexer tokenizes the input string, identifying:
- Commands and arguments
- Operators (pipes, redirections)
- Quotes (single and double)
- Environment variables

### Parser
The parser processes tokens to:
- Build command structures
- Handle variable expansion
- Resolve quotes
- Prepare execution data

### Executor
The executor:
- Creates child processes for external commands
- Manages pipes and redirections
- Handles file descriptors
- Executes built-in commands directly in the parent process

### Memory Management
- Custom memory allocation tracking system
- Prevents memory leaks through centralized allocation

### Signal Handling
- Custom signal handlers for SIGINT, SIGQUIT, and SIGCHLD
- Different behavior in interactive vs. non-interactive modes

## Requirements

- Compiled with: `gcc -Wall -Wextra -Werror`
- Uses the readline library for line editing and history
- Follows 42's Norm coding standards
- No memory leaks (verified with valgrind)
- Handles edge cases and errors gracefully

## Authors

- **yer-retb** - [@ky05h1n](https://github.com/ky05h1n)

## Acknowledgments

This project is part of the 42 Network curriculum, designed to teach:
- System calls and process management
- File descriptor manipulation
- Signal handling
- Memory management
- Parsing and interpretation techniques
- Command-line interface design

---

*Created as part of 42 School curriculum - 2022*




















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































minishell is a bash .
thank you !