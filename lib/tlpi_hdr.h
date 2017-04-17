#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H		/*prevent accidental double inclusion*/

#include <sys/types.h>		/*Type definitions used by many programs*/
#include <stdio.h>		/*Standard I/O functions*/
#include <stdlib.h>		/*Prototypes of commonly used library functions,plus EXIT_SUCESS and EXIT_FAILURE constants*/
#include <unistd.h>		/*Prototypes for many system calls*/
#include <errno.h>		/*Declares errno and defines error constatns*/
#include <string.h>		/*Commonly used string-handling functions */
#include <stdint.h>		/*definitions for int8_t, and the likes*/

#include "get_num.h"		/* Declares our functions for handling numeric arguments (getInt(), getLong()) */

#include "error_functions.h"	/* Declares our error-handling functions */

typedef enum { FALSE, TRUE } Boolean;

#define min(m,n) ( (m) < (n) ? (m) : (n) )
#define max(m,n) ( (m) > (n) ? (m) : (n) )


#endif
