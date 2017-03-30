/*
./lseek file_name {r<length>|R<length>|w<string>|s<offset>}
usage examples:
./lseek file_name s100 wabc (seek to offset 100, write "abc")
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

int main (int argc, char *argv[])
{
  size_t len;
  char* buff;
  off_t offset;
  int fd, ap, j;
  ssize_t numRead, numWritten;
  
  /* validate command */
  if (argc < 3 || strcmp(argv[1], "--help") == 0)
    usageErr("%s file {r<length>|R<length>|w<string>|s<offset>}...\n", argv[0]);
  
  /* open file, create if it doesn't exist  */
  fd = open( argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH ); /* rw-rw-rw- */
  
  if (fd == -1)
    errExit("opening file %s", argv[1]);
  
  for (ap = 2; ap < argc; ap++)
  {
   switch ( argv[ap][0] )
   {
     case 'r': /*display bytes at current offset, as text */
     case 'R': /*display bytes at current offset, as hex */
       len = getLong( &argv[ap][1], GN_ANY_BASE, argv[ap]);
       buff = (char *)malloc( len );       
       if (buff == NULL )
	 errExit("malloc");
       
       numRead = read(fd, buff, len);
       if (numRead == -1)
	 errExit("read");
       
       if (numRead == 0)
	 printf("%s: end-of-file\n", argv[ap]);
       else
       {
	  printf("%s: ", argv[ap]);
	  for (j = 0; j < numRead; j++)
	  {
	    if ( argv[ap][0] == 'r' ) 
	      printf("%c", isprint((unsigned char) buff[j]) ? buff[j] : '?');
	    else
	      printf("%02x ", (unsigned char)buff[j] );
	  }
	  printf("\n");
       }
       
       free(buff);
       break;
       
     case 'w': /* Write string at current offset */
       len = strlen( &argv[ap][1] );
       numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]) );
       
       if (numWritten == -1)
	 errExit("write");
       
       printf("%s: wrote %ld bytes\n", argv[ap], (long)numWritten);
       break;
       
     case 's': /*change file offset */
       offset = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
       if ( lseek(fd, offset, SEEK_SET) == -1 )
	 errExit("lseek");
       
       printf("%s: seek succeeded\n", argv[ap]);
       break;
       
     default:
       cmdLineErr("Argument must start with [rRws]: %s\n", argv[ap]);
   }
  }
  
  exit(EXIT_SUCCESS);
}