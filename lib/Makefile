include ../Makefile.inc

MY_LIB = libtlpi.a

SOURCES = *.c

$(MY_LIB) : $(SOURCES) enames.c.inc
	gcc -c -g $(CFLAGS) $(SOURCES)
	rm -f $(MY_LIB)
	ar rcs $(MY_LIB) *.o

clean : 
	$(RM) *.o $(MY_LIB)	
