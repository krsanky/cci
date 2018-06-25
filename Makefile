chap1_q3: _chap1_q3.cpp
	@echo echo echo 
	c++ -o chap1_q3 _chap1_q3.cpp

install: 
	cp chap1_q3 ${HOME}/bin

uninstall: clean
	rm -f ${HOME}/bin/chap1_q3 

clean:
	rm -f chap1_q3 

#depend:  '>' is gnu specific
#	cc -E -MM *.c > .depend
#	cc -E -MM *.cpp > .depend


#Local variables
#    Variables that are defined specific to a certain target.  Standard
#    local variables are as follows:
#    @
#	The name of the target.
#
#    %
#	The name of the archive member (only valid for library
#	rules).
#
#    !
#	The name of the archive file (only valid for library rules).
#
#    ?
#	The list of prerequisites for this target that were deemed
#	out of date.
#
#    <
#	The name of the prerequisite from which this target is to
#	be built, if a valid inference rule (suffix rule) is in
#	scope.
#
#    *
#	The file prefix of the file, containing only the file
#	portion, no suffix or preceding directory components.
#
#    The six variables `@F', `@D', `<F', `<D', `*F', and `*D' yield
#    the "filename" and "directory" parts of the corresponding macros.
#    For maximum compatibility, `<' should only be used for actual
#    inference rules.  It is also set for normal target rules when
#    there is an inference rule that matches the current target and
#    prerequisite in scope.  That is, in
#
#	.SUFFIXES: .c .o 
#	file.o: file.c
#		cmd1 $<
#
#	.c.o:
#		cmd2

