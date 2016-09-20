#Author: Ashwath Gundepally, Sayan Barman
include sources.mk


ifeq ($(platform), ARM_LINUX)
CC= arm-linux-gnueabi-gcc 
else($(platform), ARM_NONE)
CC= arm-none-eabi-gcc
endif

.PHONY: build
build: $(objects)
	$(CC) $(objects) -o project $(LDFLAGS)project.map


.PHONY: compile-all
compile-all: $(objects)


main.o: main.c project.h
	$(CC) -c $(CFLAGS) $< 
project.o: project.c memory.h project.h
	$(CC) -c $(CFLAGS) $<
memory.o: memory.c memory.h
	$(CC) -c $(CFLAGS) $<
data.o: data.c data.h memory.h
	$(CC) -c $(CFLAGS) $<

.PHONY: preprocess
preprocess: $(preprocessed)
	
main.i: main.c project.h 
	$(CC) -E $<
project.i: project.c memory.h project.h
	$(CC) -E $<
memory.i: memory.c memory.h 
	$(CC) -E $<
data.i: data.c data.h memory.h
	$(CC) -E $<

.PHONY: asm-file
asm-file: $(asmfiles)

main.s: main.c project.h
	$(CC) -S $<
project.s: project.c memory.h project.h
	$(CC) -S $<
memory.s: memory.c memory.h
	$(CC) -S $<
data.s: data.c data.h memory.h
	$(CC) -S $<

.PHONY: upload	
upload:
	ssh $(BBB_connect) "rm -rf ~/home/debian/bin/release"
	ssh $(BBB_connect) "mkdir ~/home/debian/bin/release"
	scp $(OUTPUT) $(BBB_connect):~/home/debian/bin/release

.PHONY: build-lib
build-lib:
	ar rcs libproject1.a sourcefiles/memory.c sourcefiles/data.c	

.PHONY: clean

clean:
	rm -f $(objects) $(asmfiles) *.i *.map *.s *.a $(OUTPUT)


 
