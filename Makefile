CFLAGS+= -W -Wall -O2 -std=c99 -g -pedantic

all: compress_string _chap1_q3

clean:
	rm -f compress_string _chap1_q3 test_ll

2_1: $@.c ll.c ll.h
	$(CC) $(CFLAGS) -o $@ $@.c ll.c $(LDFLAGS)

test_ll: $@.c ll.c ll.h
	$(CC) $(CFLAGS) -o $@ $@.c ll.c $(LDFLAGS)

