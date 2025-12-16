# SIMPLE SHELL PROJECT
Creation of our own Simple Shell by Enzo MESSAOUDI, Vincent RENAUD C#28-Sens

## Summary
- [Description](#description)
- [Allowed](#allowed)
  - [String Manipulation and Memory Handling Functions](#string-manipulation-and-memory-handling-functions)
  - [File & Directory Operations](#file--directory-operations)
  - [Directory Stream Functions](#directory-stream-functions)
  - [Process Control](#process-control)
  - [Process Synchronization / Waiting](#process-synchronization--waiting)
  - [Signals](#signals)
  - [Memory Management](#memory-management)
  - [Standard I/O (stdio)](#standard-io-stdio)
  - [Terminal & Strings](#terminal--strings)
- [Compilation](#compilation)
- [Requirements](#requirements)
- [Usage exemples](#usage-exemples)
- [Man page](#man-page)
- [Testing](#testing)
- [Flowchart](#flowchart)
- [Usefull informations](#usefull-informations)

## Description [#Summary](#Summary)
Write a simple UNIX command interpreter.

The Shell behaves like the standard one in the terminal.

It supports several functions and system calls.

## Allowed [#Summary](#Summary)
### String Manipulation and Memory Handling Functions
- all functions from string.h

### File & Directory Operations
- access – Check a file’s existence or permissions (read/write/execute).
- chdir – Change the current working directory.
- open – Open (or create) a file and return a file descriptor.
- close – Close a file descriptor.
- read – Read bytes from a file descriptor.
- write – Write bytes to a file descriptor.
- stat – Get file metadata (size, permissions, timestamps).
- lstat – Like stat, but does not follow symbolic links.
- fstat – Get file metadata using a file descriptor.
- getcwd – Get the current working directory path.

### Directory Stream Functions
- opendir – Open a directory stream.
- readdir – Read the next directory entry.
- closedir – Close a directory stream.

### Process Control
- fork – Create a new process by duplicating the current one.
- execve – Replace the current process image with a new program.
- exit – Terminate the process after flushing stdio buffers.
- _exit – Terminate the process immediately (no stdio cleanup).
- getpid – Return the calling process’s PID.

### Process Synchronization / Waiting
- wait – Wait for any child process to terminate.
- waitpid – Wait for a specific child process.
- wait3 – Wait for a child and get resource usage.
- wait4 – Like wait3, but allows selecting a specific child.

### Signals
- signal – Set a signal handler.
- kill – Send a signal to a process or process group.

### Memory Management
- malloc – Allocate memory from the heap.
- free – Release previously allocated heap memory.

### Standard I/O (stdio)
- printf – Print formatted output to standard output.
- fprintf – Print formatted output to a specified stream.
- vfprintf – Like fprintf, but uses a va_list.
- sprintf – Write formatted output to a string buffer.
- putchar – Write a single character to standard output.
- fflush – Flush a stream’s output buffer.
- perror – Print a descriptive error message for errno.
- getline – Read an entire line from a stream.

### Terminal & Strings
- isatty – Check if a file descriptor refers to a terminal.
- strtok – Tokenize a string using delimiters.

## Compilation [#Summary](#Summary)
Use the GCC commande below to compile and run the project:
- gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Requirements
- Edit the code on vi, vim or emacs.
- Use git for version control.
- Compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89.

## Usage exemples
- /# echo "qwerty" | /bin/sh  --> /bin/sh: 1: qwerty: not found
- /# echo "qwerty" | ./hsh    --> ./hsh: 1: qwerty: not found

## Man page
To view the custom manual page:
man ./man_1_simple_shell

## Testing
To validate the fonctionnality of our shell, we used:
- Betty for style
- Valgrind to check memory leaks
- GCC for error:
  - Wall (enable most warning messages)
  - Werror (treat all warnings as errors)
  - Wextra (enables additional warnings that -Wall does not cover)
  - pedantic (enforces strict ISO C compliance)
  - std=gnu89 (specifies the C standard to use)
- /bin/hs  ./hsh (should be the same error)

## Flowchart
![Link](flowchart.png)

## Usefull informations [#Summary](#Summary)
shell.h containts all the prototypes.
