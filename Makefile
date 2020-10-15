
CC := g++ --std=c++2a -g
VALGRIND := /usr/bin/valgrind

target := main
objs := main.o node.o ring.o


$(target) : $(objs) ; $(CC) -o $@ $^

node.o : node.cc node.hh ; $(CC) -c -o $@ $<
main.o : main.cc ring.hh node.hh ; $(CC) -c -o $@ $<
ring.o : ring.cc ring.hh node.hh ; $(CC) -c -o $@ $<

val : $(target) ; $(VALGRIND) --leak-check=full ./$<

.PHONY : clean
clean : ; rm -f $(target) $(objs)
