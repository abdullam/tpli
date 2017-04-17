/*lesson learnt

when you write to stdout you write to a file with fd of 1.
so by definition any file with fd of 1 is stdout

*/

#include "tlpi_hdr.h"
#include <fcntl.h> //O_CREATE ...

void main ()
{
 if (close(STDOUT_FILENO) == -1)
  errExit("close stdin error");
 
 int fd = open("my_stdout_1", O_WRONLY | O_CREAT,  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
 if (fd == -1)
  errExit("error on my_stdout_1 open");
 
 fd = open("my_stdout_2", O_WRONLY | O_CREAT,  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
 if (fd == -1)
  errExit("error on my_stdout_2 open");
 
 printf("\n fileno(stdout) : %ld\n", fileno(stdout));
 
 printf("hello world");
 
 exit(EXIT_SUCCESS);
}