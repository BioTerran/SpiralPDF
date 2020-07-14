# the compiler to use
CC = g++

# compiler flags to use
CFLAGS = -O2 -Wall -std=c++11

LIBHARU = ../libharu

# Build an executable spiralPDF from files and libraries.
all: spiralPDF.o Spiral.o HaruPDF.o
	$(CC) $(CFLAGS) -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o -I$(LIBHARU)/include -L$(LIBHARU)/src -lz -lhpdfs

spiralPDF.o: spiralPDF.cpp Spiral.h HaruPDF.h
	$(CC) $(CFLAGS) -c spiralPDF.cpp -I$(LIBHARU)/include -L$(LIBHARU)/src -lz -lhpdfs

Spiral.o: Spiral.cpp Spiral.h
	$(CC) $(CFLAGS) -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp HaruPDF.h
	$(CC) $(CFLAGS) -c HaruPDF.cpp -I$(LIBHARU)/include -L$(LIBHARU)/src -lz -lhpdfs

clean:
	rm spiralPDF *.o

test:
	./spiralPDF "Please start working I am trying so hard to get this to work I'm ready to not give up but im ready to finish this hopefully soon. Hopefully I can be done soon so I can work on fixing all that money that got stolen out of my bank account. For reals though, I found out today (thursday) that most of the money in my bank account got stolen. Honestly I am in severe trouble if I dispute and don't get the money back"
	okular spiralPDF.pdf