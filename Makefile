
CC := g++ --std=c++2a -g

target := main
objs := main.o node.o ring.o


$(target) : $(objs) ; $(CC) -o $@ $^

node.o : node.cc node.hh ; $(CC) -c -o $@ $<
main.o : main.cc ring.hh node.hh ; $(CC) -c -o $@ $<
ring.o : ring.cc ring.hh node.hh ; $(CC) -c -o $@ $<

.PHONY : clean
clean : ; rm -f $(target) $(objs)
