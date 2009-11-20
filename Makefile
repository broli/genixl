#This makefile has all the debugging info enabled, and no optimization, because is a development file
#i wont even try to make a more formal one until i finish, or understand howto use autoconf :P

CFLAGS=$(pkg-config --cflags mxml) -ggdb3 -Wall -Wextra -pedantic -ansi -Wmissing-prototypes  -Wstrict-prototypes -Wcast-qual -Wcast-align -Wundef 

LIBS=$(pkg-config --libs mxml)

objects = 

all : $(objects)
	touch obj/touched
	touch bin/touched
	gcc  $(CFLAGS) $(LIBS) $(objects) -o bin/genixl-cli



clean :
	rm obj/* 
	rm bin/*

tags :
	ctags -R --c-kinds=dfglmstv .

#if anyone knows a better way, to add logic to the makefile so if this dirs dont exits, it creates, pls tell me how
mkdir :
	mkdir obj/
	mkdir bin/
