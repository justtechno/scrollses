cc := gcc


all:
	$(cc) -c src/scrollses.c -o scrollses.o
	ar rcs libscrollses.a scrollses.o


install: all
	cp libscrollses.a /usr/local/lib/
	cp include/scrollses.h /usr/local/include/

uninstall:
	rm /usr/local/lib/libscrollses.a
	rm /usr/local/include/scrollses.h

.PHONY clean:
	rm scrollses.o
	rm libscrollses.a

reinstall: uninstall install
