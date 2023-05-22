#include "S_shell.h"

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */

void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);

/**
 * help_all - It shows all the builtin shellby commands like --help or man.
 */
void help_all(void)
{
	char *msg = "Shellby\nWelcome to the help page.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "Kindly type 'help' to view the commands. ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "Type 'help name’ to learn more about the function 'name'.\n ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n  alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_alias - Shows info about 'alias'.
 */
void help_alias(void)
{
	char *msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n\talias: Outputs a list of all aliases, one alias per line, in ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_cd - outputs info about  'cd'.
 */
void help_cd(void)
{
	char *msg = "cd: cd [DIRECTORY]\n\tChanges current working directory of the";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "after a change of directory.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_exit - Outputs info about 'exit'.
 */
void help_exit(void)
{
	char *msg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " exit 0.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_help - Outputs info about 'help'.
 */
void help_help(void)
{
	char *msg = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "builtin command.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
