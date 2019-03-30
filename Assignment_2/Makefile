# I pledge my honor that I have abided by the Stevens Honor System. - Brereton Conway

CC=gcc


libcs392string.so: cs392_memcpy.o cs392_strlen.o
	$(CC) -shared -fPIC -o libcs392string.so cs392_memcpy.o cs392_strlen.o

cs392_memcpy.o: cs392_memcpy.c
		$(CC) -o cs392_memcpy.o -c cs392_memcpy.c

cs392_strlen.o: cs392_strlen.c
	$(CC) -o cs392_strlen.o -c cs392_strlen.c

clean:
	rm *.so *.o
# CC=gcc
#
# prog : cs392_ass2_test.o libcs392string.so
# 	$(CC) -o prog cs392_ass2_test.o libcs392string.so
#
# cs392_ass2_test.o: cs392_ass2_test.c
# 	$(CC) -o cs392_ass2_test.o -c cs392_ass2_test.c
#
# libcs392string.so: cs392_memcpy.o cs392_strlen.o
# 	$(CC) -shared -fPIC -o libcs392string.so cs392_memcpy.o cs392_strlen.o
#
# cs392_memcpy.o: cs392_memcpy.c
# 	$(CC) -o cs392_memcpy.o -c cs392_memcpy.c
#
# cs392_strlen.o: cs392_strlen.c
# 	$(CC) -o cs392_strlen.o -c cs392_strlen.c
#
#
# clean:
# 		rm *.so *.o prog
