AM_CFLAGS = -Wall -g

@DX_RULES@

bin_PROGRAMS=guess
pkgdata_DATA=ru/LC_MESSAGES/guess.mo

messages.pot: guess.pot guess.c
	xgettext -k_ -c guess.c -o messages.new.pot
	cp guess.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

ru.po:	messages.pot
	msgmerge -U $@ $<

ru/LC_MESSAGES/guess.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

gitclean: maintainer-clean
	git clean -fd

clean:
	rm config.* aclocal.m4 compile configure depcomp guess guess.o install-sh Makefile Makefile.in messages.* missing stamp-h1
	rm -r ru autom4te.cache .deps

all-local:	doxygen-doc

