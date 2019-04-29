# I pledge my honor that I have abided by the Stevens Honor System. - Brereton Conway
#
# CC=gcc
#
# HEADERS = cs392_exec.h cs392_log.h cs392_signal.h
#
# cs392_shell: cs392_shell.o cs392_exec.o cs392_log.o cs392_signal.o
# 	$(CC) -o cs392_shell cs392_shell.o cs392_exec.o cs392_log.o cs392_signal.o
#
# cs392_shell.o: cs392_shell.c $(HEADERS)
# 	$(CC) -c cs392_shell.c
#
# cs392_exec.o: cs392_exec.c
# 	$(CC) -c cs392_exec.c
#
# cs392_log.o: cs392_log.c
# 	$(CC) -c cs392_log.c
#SS
# cs392_signal.o: cs392_signal.c
# 	$(CC) -c cs392_signal.c
#
# clean:
# 	rm *.o *.gch cs392_shell
#
# run:
# 	./cs392_shell

CC = gcc
CFLAGS = -Wall
OBJFILES = cs392_signal.o cs392_log.o cs392_exec.o cs392_shell.o
TARGET = cs392_shell

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)
clean:
	rm -f $(OBJFILES) $(TARGET) *~
