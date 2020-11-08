TESTS = dummy
check_PROGRAMS = dummy

CFLAGS = -I$(top_builddir)/src
LDADD = $(top_builddir)/src/libbuf.la

.ts.c:
	checkmk $< > $@
