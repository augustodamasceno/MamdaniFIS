srcdir = src

CFLAGS = -g -Wall -pedantic

LIBS = -lm

OBJS = mamdani.o export.o

all : $(srcdir)/main.c $(OBJS)
	cc -o mamdanifis $(srcdir)/main.c  $(OBJS) $(LIBS) $(CFLAGS)
export.o: $(srcdir)/export.c
	cc -c $(srcdir)/export.c $(CFLAGS)
mamdani.o: $(srcdir)/mamdani.c
	cc -c $(srcdir)/mamdani.c $(CFLAGS)
clean :
	rm -f $(OBJS) main.o