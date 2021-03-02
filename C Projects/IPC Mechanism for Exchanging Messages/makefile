CC=gcc
CFLAGS=-I. -lm
DEPS = proj3_header.h
OBJ = proj3_main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pratoomratana_p3_make: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
