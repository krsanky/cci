CFLAGS+= -W -Wall -O2 -std=c99 -g -pedantic

all: compress_string _chap1_q3 02_01_test

clean:
	rm -f compress_string _chap1_q3 test_ll 02_01_test
	rm -f *.core

02_01_test: $@.c ll.c ll.h 02.h 02_01.c
	$(CC) $(CFLAGS) -o $@ $@.c ll.c 02_01.c $(LDFLAGS)

test_ll: $@.c ll.c ll.h
	$(CC) $(CFLAGS) -o $@ $@.c ll.c $(LDFLAGS)

