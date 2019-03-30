
prog: main.o sum.o
	gcc -o prog main.o sum.o

main.o: main.c sum.h
	gcc -c main.c

sum.o: sum.c
	gcc -c sum.c

clean:
	rm *.o prog
