CSC=	chicken-csc

#/usr/local/bin/chicken
#/usr/local/bin/chicken-csc
#/usr/local/bin/chicken-csi
#/usr/local/bin/chicken-do
#/usr/local/bin/chicken-install
#/usr/local/bin/chicken-profile
#/usr/local/bin/chicken-status
#/usr/local/bin/chicken-uninstall
#/usr/local/bin/feathers

#
#You should compile your two files with the following commands:
#
#% csc -c bar.scm % csc -c foo.scm
#
#That should produce two files, bar.o and foo.o.  They contain the
#code from your source files in compiled form.
#
#To link your compiled files use the following command:
#
#% csc foo.o bar.o -o foo
#
#This should produce the foo executable, which you can run just as
#in the previous example.  At this point you can also erase the *.o
#files.
#
#You could avoid one step and link the two files just as foo.scm is
#compiled:
#
#% csc -c bar.scm % csc foo.scm bar.o -o foo
#
#


foo: $@.o bar.o 
	${CSC} $@.o bar.o -o $@

.SUFFIXES: .scm .o
.scm.o:
	${CSC} -c $<


clean:
	rm -f *.o
	rm -f foo

