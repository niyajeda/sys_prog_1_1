CC=gcc
CFLAGS="-Wall"

DEPS = my_string.h linked_list.h macros.h
OBJ = main.o my_string.o linked_list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sys_prog_1_1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -g

clean:
	rm -vfr *~ sys_prog_1_1