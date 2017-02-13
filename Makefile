
regle_a:
	gcc -c main.c
regle_b:
	gcc main.o -L/home/nay/taff/Fonctions/ -lft
regle_c:
	./a.out map_30_30_10
clean:
	rm *.o
all:regle_a regle_b regle_c
