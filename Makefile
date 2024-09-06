CC=gcc

CFLAGS=-I. -I./lib -I./test -I./solution
CFLAGS+=-g
CFLAGS+=-Wall
CFLAGS+=-Werror

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