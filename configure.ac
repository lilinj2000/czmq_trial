#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(czmq_trial, 0.1, lilinj2000@gmail.com)
AC_CONFIG_SRCDIR([])
#AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

#AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
LT_INIT
AC_PROG_RANLIB
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
#AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
LT_RELEASE=0.1
LT_CURRENT=0
LT_REVISION=1
LT_AGE=0
AC_SUBST(LT_RELEASE)
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)

home_3rd=~/3rd
home_libs=~/libs

if test -d /llj/3rd ; then
   home_3rd=/llj/3rd
fi

if test -d /llj/libs ; then
   home_libs=/llj/libs
fi


dnl boost lib
AC_ARG_WITH([boost],
    [AS_HELP_STRING([--with-boost],
        [home path of the boost, defaults to $home_3rd/boost])],
    [BOOST_HOME="$withval"],
    [BOOST_HOME="$home_3rd/boost"])
AC_SUBST([BOOST_HOME])

BOOST_CPPFLAGS="-I$BOOST_HOME/include -DBOOST_ALL_DYN_LINK"
BOOST_LIBADD="$BOOST_HOME/lib/libboost_log_setup.so \
              $BOOST_HOME/lib/libboost_log.so \
	      $BOOST_HOME/lib/libboost_filesystem.so \
  	      $BOOST_HOME/lib/libboost_program_options.so \
	      $BOOST_HOME/lib/libboost_regex.so \
	      $BOOST_HOME/lib/libboost_thread.so \
	      $BOOST_HOME/lib/libboost_chrono.so \
	      $BOOST_HOME/lib/libboost_date_time.so \
	      $BOOST_HOME/lib/libboost_system.so"
AC_SUBST(BOOST_CPPFLAGS)
AC_SUBST(BOOST_LIBADD)

dnl soil lib
AC_ARG_WITH([soil],
    [AS_HELP_STRING([--with-soil],
        [home path of the soil, defaults to $home_libs/soil])],
    [SOIL_HOME="$withval"],
    [SOIL_HOME="$home_libs/soil"])
AC_SUBST([SOIL_HOME])

SOIL_CPPFLAGS="-I$SOIL_HOME/include"
SOIL_LIBADD="$SOIL_HOME/lib/libsoil.la"
AC_SUBST(SOIL_CPPFLAGS)
AC_SUBST(SOIL_LIBADD)

dnl zmq lib
ZMQ_HOME=$home_3rd/libzmq
AC_ARG_WITH([zmq],
    [AS_HELP_STRING([--with-zmq],
        [home path of the soil, defaults to $ZMQ_HOME])],
    [ZMQ_HOME="$withval"],
    [ZMQ_HOME=$ZMQ_HOME])
AC_SUBST([ZMQ_HOME])

ZMQ_CPPFLAGS="-I$ZMQ_HOME/include"
ZMQ_LIBADD="$CZMQ_HOME/lib/libzmq.la"
AC_SUBST(ZMQ_CPPFLAGS)
AC_SUBST(ZMQ_LIBADD)

dnl czmq lib
CZMQ_HOME=$home_3rd/czmq
AC_ARG_WITH([czmq],
    [AS_HELP_STRING([--with-czmq],
        [home path of the soil, defaults to $CZMQ_HOME])],
    [CZMQ_HOME="$withval"],
    [CZMQ_HOME=$CZMQ_HOME])
AC_SUBST([CZMQ_HOME])

CZMQ_CPPFLAGS="-I$CZMQ_HOME/include"
CZMQ_LIBADD="$CZMQ_HOME/lib/libczmq.la"
AC_SUBST(CZMQ_CPPFLAGS)
AC_SUBST(CZMQ_LIBADD)



dnl gtest lib
AC_ARG_WITH([gtest],
    [AS_HELP_STRING([--with-gtest],
        [home path of the gtest, defaults to $topdir/../gtest])],
    [GTEST_HOME="$withval"],
    [GTEST_HOME="$home_3rd/gtest"])
AC_SUBST([GTEST_HOME])

GTEST_CPPFLAGS=-I$GTEST_HOME/include
GTEST_LIBADD="$GTEST_HOME/lib/libgtest.a $GTEST_HOME/lib/libgtest_main.a"
AC_SUBST(GTEST_CPPFLAGS)
AC_SUBST(GTEST_LIBADD)

AC_OUTPUT([
	Makefile
	zsock/Makefile])


