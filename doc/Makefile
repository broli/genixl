#This make file is kept here for convenience
#its easy to call make on it than to make an script to run ctags

#also, want to keep a copy of the compile flags it took me so much time to research
#specially because i cant find how to add them to the autoconfig thingy

CFLAGS=`pkg-config --cflags mxml` -ggdb3 -Wall -Wextra -pedantic -ansi -Wmissing-prototypes  -Wstrict-prototypes -Wcast-qual -Wcast-align -Wundef 

LIBS=`pkg-config --libs mxml`

ctags :
	ctags -R --c-kinds=dfglmstvep .


