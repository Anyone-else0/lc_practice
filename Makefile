CC=gcc

CFLAGS=-I. -I./lib -I./test -I./solution
CFLAGS+=-include pea_types.h 
CFLAGS+=-include stdio.h
CFLAGS+=-include stddef.h
CFLAGS+=-include stdlib.h
CFLAGS+=-include stdbool.h
CFLAGS+=-include string.h
CFLAGS+=-include time.h
CFLAGS+=-include limits.h
CFLAGS+=-g
CFLAGS+=-Wall
CFLAGS+=-Werror
CFLAGS+=-DLOCAL_TEST

SRCDIR=.
OBJDIR=obj
TARGET=practice

SOURCES:=$(wildcard $(SRCDIR)/**/*.c)
OBJECTS:=$(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o practice

$(OBJDIR)/%.o : $(SRCDIR)/**/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f obj/*.o practice