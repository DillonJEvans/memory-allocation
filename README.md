
# How to compile

The `Makefile` contains all of the rules necessary to compile the program.

To compile, run the command `make`


# How to run

The name of the executable produced by the `Makefile` will be `memory`.

It accepts no command line arguments, so run it like so: `./memory`


# How to use

While the program is running, enter commands into the as shown below:

| Command   | Syntax                        | Description                               |
| --------- | ----------------------------- | ----------------------------------------- |
| Allocate  | `A <process> <size> <policy>` | Allocates a block to a process            |
| Free      | `F <name>`                    | Free all blocks allocated to a process    |
| Show      | `S`                           | Shows the memory pool                     |
| Read File | `R <file>`                    | Reads and executes all commands in a file |
| Compact   | `C`                           | Compacts the memory pool                  |
| Exit      | `E`                           | Exits the program                         |


# Implementation notes

- If the user input does not perfectly match the expected syntax, the program will almost certainly crash.

- The `(E)xit` command will exit the entire program, even if it executed from a file that was `(R)ead`.

- If an allocation fails due to the program being unable to find a block of sufficient size, an error will be printed and the program will continue.
