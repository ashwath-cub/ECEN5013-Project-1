vpath %.c sourcefiles
vpath %.h headers

objects= main.o project.o data.o memory.o
platform=GCC;
CC=gcc -std=c99
CFLAGS=-Wall -g -O0
LDFLAGS=-Wl,-Map=
prepocessed= main.i project.i data.i memory.i
asmfiles= main.s project.s data.s memory.s
BBB_address=root@192.168.7.2
OUTPUT=project


