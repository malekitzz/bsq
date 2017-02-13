#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 1000 
char ft_putfile(int fd, char c)	 										// ecrire dans un fichier 
{
	write(fd, &c, 1);
}
int calcul(char **tab)
{
	int i;
	int j;
	i = 0;
	j = 0;
	int compteur = 0;

	while(i < 30){
		if(tab[i][0] == '.'){
			compteur ++;
		}
		i++;	
	}
	return(compteur);
}
char **creaMap(char *filename, int taille)
{
	char **map;
	char premiereligne[6] = {0};
	int i;
	int j;
	int fd;
	
	fd = open(filename, O_RDONLY);

	if(fd == -1){
		printf("Open () Failed\n");
		exit(1);
	}
	
	i = 0;
	while(i < 6){
		read(fd, &premiereligne[i], 1);
		i++;
	}
/*
	ft_putchar('\n');
	ft_putchar('\n');
	i = 0;
	while(i < 6){
		ft_putchar(premiereligne[i]);
		i++;
	}

	ft_putchar('\n');
	ft_putchar('\n');
*/
	map = (char **)malloc(sizeof(char *) * taille);
	i = 0;
	while(i < taille){
		map[i] = (char *)malloc(sizeof(char) * (taille + 1));
		read(fd, map[i], taille + 1);
		map[i][taille] = '\0';
		i++;
	}

	close(fd);
/*	
	i = 0;
	while(i < taille){
		j = 0;
		while(j < taille){
			ft_putchar(map[i][j]);	
			j++;
		}
	ft_putchar('\n');
	i++;
	}
*/

	return(map);
}
void readpoints(char *ligne, int taille)
{
	int i;
	i = 0;
	while(i < taille){
		if(ligne[i] == '.' && ligne[i] != 'o'){
			ligne[i] = 'x';
			i++;
		}	
	}	
}
void recursivecalcul(char *filename)
{
	int i, j;
	char **coucou;
	coucou = creaMap(filename, 30);
	int count = 0;	
	i = 0;
	j = 0;
	while(j < 30){
		coucou[i][j] = readpoints(i, 30);
	}


	i = 0;
	while(i < 30){
		j = 0;
		while(j < 30){
			ft_putchar(coucou[i][j]);	
			j++;
		}
	ft_putchar('\n');
	i++;
	}

	
}
int main(int argc, char **argv)
{
	if(argc == 2){
		recursivecalcul(argv[1]);
	}
	else if(argc < 2 || argc > 2){
		ft_putstr("usage() ./a.out map name");
	}
return (0);
}	
