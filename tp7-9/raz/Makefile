CFLAGS = -D_REENTRANT -I. -Wall -m32 -g
LDFLAGS = -pthread -m32
CC	= gcc

PROGRAMME = trier-mt

all : $(PROGRAMME)

trier-mt : trier-mt.o liste-noms-mt.o liste-triee-noms.o tri-fichier.o

clean :
	rm -f liste-noms-mt.o  liste-triee-noms.o  trier.o liste-noms.o     trier-mt.o *~ $(PROGRAMME)
