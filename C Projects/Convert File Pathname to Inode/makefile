CC=gcc
CFLAGS=-I.
OBJ = file_info_main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pratoomratana_p4: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

