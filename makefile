### Makefile ###

all: josephus

josephus: josephus.o main.o
	gcc -o josephus josephus.o main.o

josephus.o: josephus.c
	gcc -c josephus.c

main.o: main.c
	gcc -c main.c

clean:
	rm -rf *.o

rmproper: clean
	rm -rf josephus

run: josephus
	./josephus