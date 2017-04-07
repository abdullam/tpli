
/*
tee -a file
*/

extern  int optind, opterr, optopt;
extern char *optarg;

int main (int argc, char *argv[])
{
 int opt, fd;
 uint8_t append_option;
 char *p_file_name;
 
 /*validate command*/
 if ( argc != 3 || strcmp( argv[1], "--help) == 0 )
  usageErr("%s [-a] file\n", argv[0]);
  
 /*see if user set append_option*/
 optind = 1;
 while ( opt = getopt(argc, argv, ":a") != -1 )
 {
  switch (opt)
  {
   case 'a':
    append_option = 1;
    break;
   case ':':
    usageErr("\nMissing argument", optopt);
    break;
   case '?':
    usageErr("\nUnrecognized option", optopt);
    break;
   default:
    fatal("\nUnexpected case in switch()");
  }  
 }
 
 /*get file name*/
 if ( optind == argc )
  fatal("\nfile name not given");
 
 p_file_name = argv[optind];
 printf("\nwriting to %s", p_file_name);
 
 /* open destination file */
 if ( append_option )
  fd = open( p_file_name, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH ); /* rw-rw-rw- */
 else
  fd = open( p_file_name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH ); /* rw-rw-rw- */

 while ( read( 
}