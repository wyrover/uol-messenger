EXTRA_DIST = dtmfsend.sh dtmfrecv.sh mltest.sh bxtest.sh
if COMPILE_MINIUA
bin_PROGRAMS = miniua miniuacl
endif

if GLIB_SUPPORT
MORE_CFLAGS = @CFLAGS@ @PTHREAD_CFLAGS@ @EXOSIP_FLAGS@ `pkg-config --cflags glib-2.0`
else
MORE_CFLAGS = @CFLAGS@ @PTHREAD_CFLAGS@ @EXOSIP_FLAGS@
endif

if UCL_SUPPORT
AM_CFLAGS = $(MORE_CFLAGS) -DUCL_SUPPORT
else
if ORTP_SUPPORT
AM_CFLAGS = $(MORE_CFLAGS) -DORTP_SUPPORT
else
if MEDIASTREAMER_SUPPORT
AM_CFLAGS = $(MORE_CFLAGS) -DMEDIASTREAMER_SUPPORT
endif
endif
endif

miniua_SOURCES = miniua.c

miniuacl_SOURCES = miniua.c


if GLIB_SUPPORT
miniua_LDFLAGS = -O @EXOSIP_LIB@ @PTHREAD_LIBS@   `pkg-config --libs glib-2.0`
else
miniua_LDFLAGS = -O @EXOSIP_LIB@ @PTHREAD_LIBS@  
endif

if UCL_SUPPORT
MORE_MYADD = /usr/local/lib/libuclmmbase.a

MORE_INCLUDES = -I/ucl
else
if ORTP_SUPPORT
MORE_MYADD = -L$(libdir) -lortp -lm

MORE_INCLUDES = -I$(includedir)/ortp
else
if MEDIASTREAMER_SUPPORT
MORE_MYADD = -L$(libdir) -lortp -lm -lmediastreamer -lmsspeex

MORE_INCLUDES = -I$(includedir)/mediastreamer -I$(includedir)/ortp
endif
endif
endif

if COMPILE_GSM
GSM_LIBS= -L$(top_builddir)/phapi/gsm -lgsm
endif

if COMPILE_ILBC
ILBC_LIBS=-L$(top_builddir)/phapi/ilbc -lilbc
endif

if COMPILE_AMR
if EMBED_TARGET
AMR_LIBS=  -L$(top_builddir)/phapi/amr -lamr    
else
AMR_LIBS=  -L$(top_builddir)/phapi/amrwb -lamrwb   -L$(top_builddir)/phapi/amrnb -lamrnb -L$(top_builddir)/phapi/amr -lamr     
endif
endif

CODECLIBS=$(GSM_LIBS) $(ILBC_LIBS) $(AMR_LIBS)  

miniua_LDADD = $(top_builddir)/phapi/libphapi.la $(top_builddir)/src/libeXosip.la $(CODECLIBS) -L$(libdir) -losip2 -losipparser2  $(MORE_MYADD) -lstdc++

INCLUDES = -I$(top_srcdir) -I$(top_srcdir)/include   -I$(top_srcdir)/phapi  -I$(includedir) $(MORE_INCLUDES)

#miniuacl_LDADD = $(top_builddir)/phapi/libphapicl.a $(top_builddir)/josua/libjosua.la -losip2 -lpthread
miniuacl_LDADD = $(top_builddir)/phapi/libphapicl.a -lpthread -lstdc++

