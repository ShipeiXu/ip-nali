

#all: iptool nali
all: iptool 

iptool: ip_tool.o
	gcc -o iptool ip_tool.o 

#nali: main.o ipip.o
#	gcc -o nali ipip.o main.o

.PHONY: clean

clean:
	rm -f *.o iptool 
#	rm -f *.o iptool nali
