CC=gcc
CFLAGS=-I.
CFLAGS+=-g
CFLAGS+=-Wall
CFLAGS+=-Werror
OBJ=main.o ut.o 
OBJ+=pea_lc_practice_ut.o pea_stack_ut.o pea_queue_ut.o pea_hash_table_ut.o pea_sort_ut.o
OBJ+=pea_hash_table.o pea_stack.o pea_queue.o pea_sort.o
OBJ+=1_two_sum.o 215_find_kth_largest.o 208_achieve_trie.o

%.o : %.c
	$(CC) -c -o $@ $< $(CFLAGS)

practice : $(OBJ)
	$(CC) -o practice $^ $(CFLAGS)

clean:
	rm -f *.o practice