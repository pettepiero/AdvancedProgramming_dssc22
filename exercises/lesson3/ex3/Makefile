#Piero Pettena
CC=g++
#where to look for headers
INCDIR=include
#where to place object files
OBJDIR=obj
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -I$(INCDIR)
OBJECTS= main.o $(OBJDIR)/coeffs.o $(OBJDIR)/quadeq.o

#$@ = target -> in this case it will be replaced by hello.x
eq1.x: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

#inside obj/ all the files with extension .o will be considered
obj/%.o: src/%.cpp  
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf obj/*.o *.o *.x