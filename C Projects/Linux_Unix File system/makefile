CC=gcc
CFLAGS=-I.
DEPS = p1_make.h
OBJ = p1_main.o p1_commands.o p1_func.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pratoomratana_p1_make: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
