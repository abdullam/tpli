SOURCES := copy.c
INCLUDES := "./lib"
CFLAGS += -Wall -Werror

test.o: $(SOURCES)
	echo gcc $(SOURCES) ${CFLAGS} -I$(INCLUDES) -o test
	gcc $(SOURCES) -I$(INCLUDES) -o test -Wall -Werror
