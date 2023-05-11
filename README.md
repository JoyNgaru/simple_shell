shell is a user interface that implements the command line interface of Unix/Linux operating systems.
An example of a shell program is like Bash shell.
Our program will implement everything that happens in a shell :)
  - print a $prompt
  - Read input from STDIN
  - Parses it and executes it, then loops back to the prompt

The shell is a bridge between the user and the kernel of a machine. It takes input from the user and passes passes them to the machine to execute them through the kernel.

It also verifies if the command inputs from the user are correct. If there is an error, it outputs an error message to the user and enters a new line using (\n);

If you have used command line, you might have noticed that one you enter a command, it processes your command, gives you a result, and then prints a new line, awaiting another command from you, right?

so thats a infinite loop, it'll never stop, and that there is our first step in this program.

We will create a loop that outputs a $ indicating that it is ready to receive user input.

As we proceed with coding, we will be building our header file to incorporate all our function prototypes and the libraries that we will need.

We will also declare the buffer storage size to be the largest == 1024, so that it can take as much input from the user as possible.

Jay and Joy welcome you to our wild ride through the shell, buckle up, and lets go!!

