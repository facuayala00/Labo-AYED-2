CC = gcc
GDB = gdb
VAL = valgrind
CFLAGS = -Wall -Werror -Wextra -ansi -pedantic -std=c99 -g
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes -s
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = ejecutable

run: $(TARGET)
	./$^

run_args: $(TARGET)
	./$^ $(ARGS)

gdb: $(TARGET)
	$(GDB) ./$^

gdb_args: $(TARGET)
	$(GDB) --args ./$^ $(ARGS)

val: $(TARGET)
	$(VAL) $(VFLAGS) ./$^
	
val_args: $(TARGET)
	$(VAL) $(VFLAGS) ./$^ $(ARGS)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(TARGET)

