CFLAGS = -Wall

lib_LTLIBRARIES = libbuf.la

CFLAGS += -fprofile-arcs -ftest-coverage -O0 -g

bin_PROGRAMS=buf
buf_LDADD = libbuf.la

gcov:
	gcov .libs/libnamegen -t -j -k
