GENERATES = prog README
TRASH = *.o *~ o.*

all:    README prog

prog:   const.o fun.o prog.o
		cc $^ -o $@

fun.o:  outlib.h

README: prog
		./$< 2> $@

liboutput_static.a: fun.o const.o
		ar -rcs $@ $^

prog-a: prog.o liboutput_static.a
		cc -L. $< -loutput_static -o $@

clean:
		rm -f $(TRASH)

distclean:      clean
		rm -rf $(GENERATES)
