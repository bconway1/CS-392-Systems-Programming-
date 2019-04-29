#“I pledge my honor that I have abided by the Stevens Honor System.” - Brereton Conway
cs392_thread: cs392_thread.o
	gcc -o cs392_thread cs392_thread.o -pthread

cs392_thread.o: cs392_thread.c
	gcc -c cs392_thread.c -pthread

clean:
	rm *.o cs392_thread
