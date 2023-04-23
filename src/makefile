# Makefile TP3

CC= gcc
CFLAGS=  -Wall -ansi -pedantic -pg
FICHIER_O= *.o
F1= calc
F2= Pile
F3= Parseur
F4= Calcul
EXECUTABLES= $(F1) $(F2) $(F3) $(F4) Test
CLEAN_EXEC_RULE= make clean_exec

all:
	make calc


calc: main.o $(F2).o $(F3).o $(F4).o
	$(CC) -o $(F1) main.o $(F2).o $(F3).o $(F4).o -lreadline
	$(CC) -c main.c $(CFLAGS)
	$(CLEAN_EXEC_RULE)

parseur: $(F2).o
	$(CC) -o $(F2) $(F2).o
	$(CC) -c $(F2).c $(CFLAGS)
	$(CLEAN_EXEC_RULE)

pile: $(F3).o
	$(CC) -o $(F3) $(F3).o
	$(CC) -c $(F3).c $(CFLAGS)
	$(CLEAN_EXEC_RULE)

$(F4): $(F4).o
	$(CC) -o $(F4) $(F4).o
	$(CC) -c $(F4).c $(CFLAGS)
	$(CLEAN_EXEC_RULE)

Test : Test.o $(F2).o $(F3).o $(F4).o
	$(CC) -o Test Test.o $(F2).o $(F3).o $(F4).o -lreadline
	$(CC) -c Test.c	$(CCFLAGS)
	$(CLEAN_EXEC_RULE)

clean_exec:
	rm -f $(FICHIER_O)

clean:
	rm -f $(FICHIER_O) $(EXECUTABLES)


