AUTOMAKE_OPTIONS = foreign

noinst_PROGRAMS = unittest

unittest_SOURCES = XSubTest.cc

unittest_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(CZMQ_CPPFLAGS) \
		$(ZMQ_CPPFLAGS) \
		$(GTEST_CPPFLAGS)


unittest_LDADD = $(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(CZMQ_LIBADD) \
	$(GTEST_LIBADD)

unittest_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = 

EXTRA_DIST = env.sh




