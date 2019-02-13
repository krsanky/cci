CFLAGS+= -W -Wall -O2 -std=c99 -g -pedantic
#CFLAGS+= -I/usr/local/include
#CFLAGS+= -Imtemplate
#LDFLAGS+= -L/usr/local/lib
#LDFLAGS+= -Lmtemplate
#LDFLAGS+= -lmarkdown 
#LDFLAGS+= -lmtemplate

all: compress_string _chap1_q3

clean:
	rm -f compress_string _chap1_q3

