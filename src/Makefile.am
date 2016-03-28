AM_CPPFLAGS = @VMOD_INCLUDES@ -Wall -Werror

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_dogatemyhomework.la

libvmod_dogatemyhomework_la_LDFLAGS = -module -export-dynamic -avoid-version -shared

libvmod_dogatemyhomework_la_SOURCES = \
	vmod_dogatemyhomework.c

nodist_libvmod_dogatemyhomework_la_SOURCES = \
	vcc_if.c \
	vcc_if.h

vmod_dogatemyhomework.lo: vcc_if.c vcc_if.h

vcc_if.c: vcc_if.h

vcc_if.h: @VMODTOOL@ $(top_srcdir)/src/vmod_dogatemyhomework.vcc
	@VMODTOOL@ $(top_srcdir)/src/vmod_dogatemyhomework.vcc

VMOD_TESTS = $(top_srcdir)/src/tests/*.vtc
.PHONY: $(VMOD_TESTS)

$(top_srcdir)/src/tests/*.vtc: libvmod_dogatemyhomework.la
	@VARNISHTEST@ -Dvarnishd=@VARNISHD@ -Dvmod_topbuild=$(abs_top_builddir) $@

check: $(VMOD_TESTS)

EXTRA_DIST = \
	vmod_dogatemyhomework.vcc \
	$(VMOD_TESTS)

CLEANFILES = \
	$(builddir)/vcc_if.c \
	$(builddir)/vcc_if.h \
	$(builddir)/vmod_dogatemyhomework.rst \
	$(builddir)/vmod_dogatemyhomework.man.rst
