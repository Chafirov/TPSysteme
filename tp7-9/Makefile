CFLAGS = -D_REENTRANT -I. -Wall -m32 -g
LDFLAGS = -lpthread -m32
CC	= gcc

PROGRAMMES = trier trier-mt

all : $(PROGRAMMES)

trier : trier.o liste-noms.o liste-triee-noms.o tri-fichier.o

trier-mt : trier-mt.o liste-noms-mt.o liste-triee-noms.o tri-fichier.o

clean :
	rm -f liste-noms-mt.o  liste-triee-noms.o  trier.o liste-noms.o     trier-mt.o *~ $(PROGRAMMES)
