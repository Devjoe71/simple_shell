LET'S CODE A SIMPLE SHELL

	Our Shell should:

-Display a prompt and wait for the user to type a command. A command line always ends with a new line.
-The prompt is displayed again each time a command has been executed.
-The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
-The command lines are made only of one word. No arguments will be passed to programs.
-If an executable cannot be found, print an error message and display the prompt again.
-Handle errors.
You have to handle the “end of file” condition (Ctrl+D)

	WHAT WE NEED

 -A header file that will contain a function prototype
 -A function that displays a prompt
 -A function that will read user input
 -A function that will execute command
 -A main source code file that will be the entry point
