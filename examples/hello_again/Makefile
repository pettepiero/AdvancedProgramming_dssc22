# This is a comment line
CC=g++
# This is a folder to look for header files
INCDIR=include/
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -I$(INCDIR)
#you can add -03 -Wall on the line above

#hello.x is the "target", followed by the "dependencies" that should exist before the target is made
#the following line is the "rule" to make the target. You have to tab the rule line
#you can think of "$(CC)" as "g++"
hello.x: main.o hello.o
	$(CC) main.o hello.o -o hello.x
#these explain how to make the main.o file
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp"
src/hello.o: src/hello.cpp
	$(CC) $(CFLAGS) src/hello.cpp
#this line will not be executed by default
#maybe if you type clean it will be executed
clean:
	rm -rf *.o *.x 


#to have a different makefile executed you have to write "make name-of-file"