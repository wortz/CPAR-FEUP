# src/Makefile.  Generated from Makefile.in by configure.

package = tiptop
version = 2.3.1
tarname = tiptop
distdir = $(tarname)-$(version)

prefix      = /usr/local
exec_prefix = ${prefix}
bindir      = ${exec_prefix}/bin
datarootdir = ${prefix}/share
mandir      = ${datarootdir}/man
man1dir     = $(mandir)/man1

# VPATH-specific substitution variables
srcdir= .



CC =       gcc
LIBS =     
CFLAGS =   -g -O2 -I..
CPPFLAGS = 
INSTALL  = /usr/bin/install -c
LEX =      flex
YACC =     bison -y

OBJS=tiptop.o pmc.o process.o requisite.o conf.o screen.o \
     debug.o version.o helpwin.o options.o hash.o spawn.o \
     xml-parser.o target.o utils-expression.o priv.o \
     error.o lex.yy.o y.tab.o 


all: tiptop

tiptop: $(OBJS)
	$(CC) $(LDFLAGS) -o tiptop $(OBJS) $(LIBS)
	rm -f ptiptop
	ln tiptop ptiptop


Makefile: Makefile.in ../config.status
	cd .. && ./config.status src/$@

../config.status: ../configure
	cd .. && ./config.status --recheck



version.o: version.c
	$(CC) $(CFLAGS) -DCOMPILE_HOST="\""`hostname`"\"" \
                        -DCOMPILE_DATE="\"`date`\"" \
                        -c $(srcdir)/version.c


lex.yy.c: calc.lex
	$(LEX) $(srcdir)/calc.lex

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -I$(srcdir) -c lex.yy.c


y.tab.c y.tab.h: calc.y
	$(YACC) -d $(srcdir)/calc.y

y.tab.o: y.tab.c
	$(CC) $(CFLAGS) -I$(srcdir) -c y.tab.c

install:
	$(INSTALL) -d $(DESTDIR)$(bindir)
	$(INSTALL) -m 0755 tiptop $(DESTDIR)$(bindir)
	$(INSTALL) -d $(DESTDIR)$(man1dir)
	$(INSTALL) -m 0644 tiptop.1 $(DESTDIR)$(man1dir)
	ln $(DESTDIR)$(bindir)/tiptop $(DESTDIR)$(bindir)/ptiptop
	ln $(DESTDIR)$(man1dir)/tiptop.1 $(DESTDIR)$(man1dir)/ptiptop.1

uninstall:
	-rm $(DESTDIR)$(bindir)/tiptop
	-rm $(DESTDIR)$(bindir)/ptiptop
	-rm $(DESTDIR)$(man1dir)/ptiptop.1
	-rm $(DESTDIR)$(man1dir)/tiptop.1

clean:
	/bin/rm -f $(OBJS) lex.yy.c y.tab.c y.tab.h tiptop ptiptop


depend:
	makedepend -Y *.c


.PHONY: all clean depend install uninstall


# DO NOT DELETE

conf.o: conf.h options.h screen.h utils-expression.h
conf.o: process.h xml-parser.h
error.o: error.h

hash.o: hash.h process.h screen.h options.h
options.o: options.h version.h
pmc.o: pmc.h
process.o: error.h hash.h process.h screen.h options.h pmc.h
process.o: spawn.h
requisite.o: pmc.h requisite.h
screen.o: conf.h options.h screen.h process.h
screen.o: utils-expression.h error.h
spawn.o: options.h process.h screen.h spawn.h
target-x86.o: screen.h options.h target.h
target.o: target.h
tiptop.o: conf.h options.h screen.h debug.h error.h
tiptop.o: helpwin.h pmc.h process.h requisite.h spawn.h utils-expression.h
utils-expression.o: process.h screen.h options.h
utils-expression.o: utils-expression.h y.tab.h
version.o: version.h
lex.yy.o: utils-expression.h y.tab.h
y.tab.o: utils-expression.h formula-parser.h 
