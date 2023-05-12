
#ifndef _shell_
#define _shell_

/* *************************************************** */
/*                                                     */
/*                                                     */
/*              Function of file: Header file          */
/*                                                     */
/*              Created by: Joram Oloo                 */
/*                          Joy Ngaru                  */
/* *************************************************** */





/*including libs to be used*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/stat.h>

/*declaring how exit and end of file will be executed*/
#define END_OF_FILE -2
#define EXIT -3

/* declaring
/* declaring global varibales to be used in the global environment*/
extern char **env

