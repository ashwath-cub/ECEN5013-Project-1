#Author: Ashwath Gundepally, Sayan Barman

vpath %.c sourcefiles
vpath %.h headers


objects= main.o project.o data.o memory.o
platform=GCC;
CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-Wl,-Map=
prepocessed= main.i project.i data.i memory.i
asmfiles= main.s project.s data.s memory.s


ifeq ($(platform), ARM_LINUX)
CC= arm-linux-gnueabi-gcc 
else($(platform), ARM_NONE)
CC= arm-none-eabi-gcc
endif

build: $(objects)
	$(CC) $(objects) -o project $(LDFLAGS)project.map

compile-all: $(objects)

main.o: main.c project.h
	$(CC) -c $(CFLAGS) $< 
project.o: project.c memory.h project.h
	$(CC) -c $(CFLAGS) $<
memory.o: memory.c memory.h
	$(CC) -c $(CFLAGS) $<
data.o: data.c data.h memory.h
	$(CC) -c $(CFLAGS) $<

preprocess: $(preprocessed)
	
main.i: main.c project.h 
	$(CC) -E $<
project.i: project.c memory.h project.h
	$(CC) -E $<
memory.i: memory.c memory.h 
	$(CC) -E $<
data.i: data.c data.h memory.h
	$(CC) -E $<

asm-file: $(asmfiles)

main.S: main.c project.h
	$(CC) -S $<
project.S: project.c memory.h project.h
	$(CC) -S $<
memory.S: memory.c memory.h
	$(CC) -S $<
data.S: data.c data.h memory.h
	$(CC) -S $<
	
.PHONY: clean asm-file preprocess compile-all build 

clean:
	rm $(objects) $(asmfiles) 

 
