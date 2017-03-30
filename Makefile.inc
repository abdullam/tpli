#TLPI_DIR from application point of view.
TLPI_DIR = ../lib
TLPI_LIB = $(TLPI_DIR)/libtlpi.a

#for implicit rules
CC = gcc
AR = ar
CFLAGS = -I$(TLPI_DIR) -Wall -Werror
LDLIBS = $(TLPI_LIB)

RM = rm -f
