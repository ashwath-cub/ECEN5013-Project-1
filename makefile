#Author: Ashwath Gundepally, Sayan Barman

vpath %.c sourcefiles
vpath %.h headers


objects= main.o project.o data.o memory.o

ifeq()
CC=cc;
CFLAGS=-Wall 

if(target==bbb)

default: host

host: $(objects)
	cc -o host $(objects)
main.o: main.c project.h
	cc -c $<
project.o: project.c memory.h
	cc -c $<
memory.o: memory.c memory.h
	cc -c $<


clean:
	rm host $(objects)


