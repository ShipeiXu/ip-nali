
all: nali 

nali: main.o ipip.o
	gcc -o nali main.o ipip.o

.PHONY: clean

clean:
	rm -f *.o nali 
