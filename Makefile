SOURCES= boot.o main.o
CFLAGS= -nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32
LDFLAGS= -m elf_i386 -T link.ld
ASFLAGS=-felf32

all: $(SOURCES) link 

clean:
	-rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $< 

.c.o:
	gcc -c $(CFLAGS) $< -o $@