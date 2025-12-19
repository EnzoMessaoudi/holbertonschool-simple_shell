# High-Level Flow of a Simple Shell

## Legend

 - Oval → Start/End
 - Parallelogram → Input/Output
 - Rectangle → Process / Action
 - Diamond → Decision / Condition

## Flow for the Shell Project

1. Start the Shell
	Shape: Oval
	Text: “Start Shell”
2. Print Prompt $ and Wait for Input
	Shape: Parallelogram (Input/Output)
	Text: “Print $ and read command”
3. User Enters Command
	Shape: Parallelogram
	Text: “User types command”
4. Check if Command is exit
	Shape: Diamond (Decision)
	Text: “Is command exit?”
5. If Yes → Exit Shell
	Shape: Oval
	Text: “Exit”
6. If No → Check if Command Exists in PATH
	Shape: Diamond
	Text: “Command in PATH?”
7. If Command Exists → Fork a Child Process
	Shape: Rectangle
	Text: “fork() a child process”
8. Execute Command with execve() in Child
	Shape: Rectangle
	Text: “execve(command)”
9. Parent Waits for Child
	Shape: Rectangle
	Text: “wait() for child”
10. Loop Back to Print Prompt $
	Shape: Arrow
	Text: “Loop back”
11. If Command Does Not Exist → Print Error
	Shape: Parallelogram
	Text: “Print ‘command not found’”

## Flowchart Steps

1- Start → Shell starts
2- Display prompt → $
3- Read input → Use getline to read user command
4- Check for EOF or exit
  - Yes → Exit shell
  - No → Continue
5- Remove newline from input
6- Check if command is empty
  - Yes → Go back to Displgoutsay prompt
  - No → Continue
7- Parse command line → Split input into arguments (argv) using strtok
8- Check for built-in commands
  - exit → Exit shell
  - setenv → Call _setenv
  - unsetenv → Call _unsetenv
  - env / printenv → Print environment
  - Else → Continue
9- Find executable
  - If command contains / → Use as path
  - Else → Search PATH (linked list or PATH variable)
10- Fork process → fork()
11- In child process → Execute command using execve
12- In parent process → wait() for child to finish
13- Go back to Display prompt

           ┌─────────────┐
           │   Start     │
           └─────┬──────┘
                 │
           ┌─────▼──────┐
           │ Display $  │
           │  prompt    │
           └─────┬──────┘
                 │
           ┌─────▼──────┐
           │ Read input │
           └─────┬──────┘
                 │
          ┌──────▼─────────┐
          │ EOF or "exit"? │
          └┬─────┬─────────┘
          Yes    │ No
           │      ▼
       ┌───▼─┐ ┌───────────────┐
       │Exit │ │ Remove newline│
       └─────┘ └────────┬──────┘
                        │
               ┌────────▼─────────┐
               │ Command empty?   │
               └┬─────┬───────────┘
               Yes    │ No
                │     ▼
           ┌────▼───────┐
           │ Parse argv │
           └────┬───────┘
                │
       ┌────────▼──────────┐
       │ Built-in command? │
       └───┬───────────────┘
     setenv│unsetenv│env│other
         ▼       ▼         ▼
       _setenv  _unsetenv printenv
                │
         ┌──────▼─────────┐
         │ Find executable│
         │ (PATH or /cmd) │
         └──────┬─────────┘
                │
           ┌────▼────────────┐
           │ fork()  		 │
           └────┬──────────┬─┘
     	   child│		   │parent
			┌───▼───┐  ┌───▼───┐
			│execve │  │ wait()│
			└───────┘  └───┬───┘
						   │
					┌──────▼───────┐
					│ Go back to $ │
					└──────────────┘
