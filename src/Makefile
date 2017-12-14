

all: iptool 

iptool: ip_tool.o
	gcc -o iptool ip_tool.o 

.PHONY: clean

clean:
	rm -f *.o iptool 
