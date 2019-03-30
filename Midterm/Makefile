
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

CC = gcc

CFLAGS = -O0 -g -fPIC
LIBFLAGS =  -shared -fPIC

PROG = cs392_midterm
LIBS = libcs392_midterm.so

$(PROG) : cs392_midterm.o $(LIBS) 
	$(CC) $(CFLAGS) -o $@ $^

$(LIBS): cs392_strcpy.o cs392_strcmp.o cs392_strncat.o
	$(CC) $(LIBFLAGS) -o $@ $^ 

clean:
	rm -rf *.o *.so $(PROG)

test:
	export LD_LIBRARY_PATH=$(shell pwd); ./$(PROG) 
