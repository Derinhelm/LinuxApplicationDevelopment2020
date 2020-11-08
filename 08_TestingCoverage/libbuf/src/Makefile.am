CFLAGS += -Wall -fprofile-arcs -ftest-coverage -O0 -g

lib_LTLIBRARIES = libbuf.la

gcov:
	gcov .libs/libbuf -t -j -k
