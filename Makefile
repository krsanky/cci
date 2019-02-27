CFLAGS+= -W -Wall -O2 -std=c99 -g -pedantic

all: 02_01 01_03

clean:
	rm -f *.core *.BAK
	rm -f test_include_stuff
	rm -f test_ll 
	rm -f 01_03
	rm -f 02_01

01_03: $@.c 
	$(CC) $(CFLAGS) -o $@ $@.c $(LDFLAGS)

02_01: $@.c ll.c ll.h 02.h 
	$(CC) $(CFLAGS) -o $@ $@.c ll.c $(LDFLAGS)

test_ll: $@.c ll.c ll.h
	$(CC) $(CFLAGS) -o $@ $@.c ll.c $(LDFLAGS)

test_include_stuff: $@.c lib1.h lib1.c
	$(CC) $(CFLAGS) -o $@ $@.c lib1.c $(LDFLAGS)
