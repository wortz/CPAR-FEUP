# Makefile.  Generated from Makefile.in by configure.

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
srcdir = .



export prefix
export exec_prefix
export bindir
export datarootdir
export mandir
export man1dir




all clean install uninstall tiptop:
	cd src && $(MAKE) $@


dist: $(distdir).tar.gz


$(distdir).tar.gz: $(distdir)
	tar chof - $(distdir) | gzip -9 -c > $@
	rm -rf $(distdir)


distcheck: $(distdir).tar.gz
	gzip -cd $(distdir).tar.gz | tar xvf -
	cd $(distdir) && ./configure
	cd $(distdir) && $(MAKE) all
	cd $(distdir) && $(MAKE) prefix=$${PWD}/_inst install
	cd $(distdir) && $(MAKE) prefix=$${PWD}/_inst uninstall
	@remaining="`find $${PWD}/$(distdir)/_inst -type f | wc -l`"; \
	if test "$${remaining}" -ne 0; then \
	  echo "*** $${remaining} file(s) remaining in stage directory!"; \
	  exit 1; \
	fi
	cd $(distdir) && $(MAKE) clean
	rm -rf $(distdir)
	@echo "*** Package $(distdir).tar.gz is ready for distribution."


Makefile: Makefile.in config.status
	./config.status $@

config.status: configure
	./config.status --recheck


$(distdir): FORCE
	mkdir -p $(distdir)/src
	cp $(srcdir)/configure.ac $(distdir)
	cp $(srcdir)/configure $(distdir)
	cp $(srcdir)/config.h.in $(distdir)
	cp $(srcdir)/install-sh $(distdir)
	cp $(srcdir)/AUTHORS $(distdir)
	cp $(srcdir)/COPYING $(distdir)
	cp $(srcdir)/INSTALL $(distdir)
	cp $(srcdir)/README $(distdir)
	cp $(srcdir)/Makefile.in $(distdir)
	cp $(srcdir)/tiptoprc $(distdir)
	cp $(srcdir)/src/Makefile.in $(distdir)/src
	cp $(srcdir)/src/tiptop.1 $(distdir)/src
	cp $(srcdir)/src/calc.lex $(distdir)/src
	cp $(srcdir)/src/calc.y $(distdir)/src
	cp $(srcdir)/src/conf.c $(distdir)/src
	cp $(srcdir)/src/conf.h $(distdir)/src
	cp $(srcdir)/src/debug.c $(distdir)/src
	cp $(srcdir)/src/debug.h $(distdir)/src
	cp $(srcdir)/src/error.c $(distdir)/src
	cp $(srcdir)/src/error.h $(distdir)/src
	cp $(srcdir)/src/formula-parser.h $(distdir)/src
	cp $(srcdir)/src/hash.c $(distdir)/src
	cp $(srcdir)/src/hash.h $(distdir)/src
	cp $(srcdir)/src/helpwin.c $(distdir)/src
	cp $(srcdir)/src/helpwin.h $(distdir)/src
	cp $(srcdir)/src/options.c $(distdir)/src
	cp $(srcdir)/src/options.h $(distdir)/src
	cp $(srcdir)/src/pmc.c $(distdir)/src
	cp $(srcdir)/src/pmc.h $(distdir)/src
	cp $(srcdir)/src/priv.c $(distdir)/src
	cp $(srcdir)/src/priv.h $(distdir)/src
	cp $(srcdir)/src/process.c $(distdir)/src
	cp $(srcdir)/src/process.h $(distdir)/src
	cp $(srcdir)/src/requisite.c $(distdir)/src
	cp $(srcdir)/src/requisite.h $(distdir)/src
	cp $(srcdir)/src/screen.c $(distdir)/src
	cp $(srcdir)/src/screen.h $(distdir)/src
	cp $(srcdir)/src/spawn.c $(distdir)/src
	cp $(srcdir)/src/spawn.h $(distdir)/src
	cp $(srcdir)/src/target.c $(distdir)/src
	cp $(srcdir)/src/target.h $(distdir)/src
	cp $(srcdir)/src/target-x86.c $(distdir)/src
	cp $(srcdir)/src/tiptop.c $(distdir)/src
	cp $(srcdir)/src/utils-expression.c $(distdir)/src
	cp $(srcdir)/src/utils-expression.h $(distdir)/src
	cp $(srcdir)/src/version.c $(distdir)/src
	cp $(srcdir)/src/version.h $(distdir)/src
	cp $(srcdir)/src/xml-parser.c $(distdir)/src
	cp $(srcdir)/src/xml-parser.h $(distdir)/src

FORCE:
	-rm $(distdir).tar.gz > /dev/null 2>&1
	-rm -rf $(distdir) > /dev/null 2>&1

.PHONY: FORCE all clean dist distcheck install uninstall
