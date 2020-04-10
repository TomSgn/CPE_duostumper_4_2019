/*
** EPITECH PROJECT, 2020
** CPE_duostumper_4_2019
** File description:
** main.c
*/

#include "../include/my.h"

char *get_words(char *filepath)
{
	int fd = 0;
	int rd = 0;
	struct stat st;
	char *content;

	fd = open(filepath, O_RDONLY);
	if (fd == -1) {
		exit (84);
	}
	stat(filepath, &st);
	content = malloc(sizeof(char) * st.st_size + 1);
	rd = read(fd, content, st.st_size);
	content[st.st_size] = '\0';
	if (rd == -1)
		exit (84);
	close(fd);
	return (content);
}

char **good_surround(int grid, char **tab)
{
	int i = 0;
	int j = 0;

	tab = malloc(sizeof(char*) * (grid + 1));
	for (; i < grid; i++) {
		tab[i] = malloc(sizeof(char) * (grid + 1));
		if (i == 0 || i == grid - 1) {
			for (j = 0; j < grid; j++) {
				tab[i][j] = '+';
			}
			tab[i][j] = '\0';
		} else {
			for (j = 0; j < grid; j++) {
				if (j == 0 || j == grid - 1)
					tab[i][j] = '|';
				else
					tab[i][j] = ' ';
			}
			tab[i][j] = '\0';
		}
	}
	tab[i] = NULL;
	return (tab);
}


char **put_in(char **list_word, char *content)
{
	int i = 0;
	int j = 0;
	int e = 0;
	
	for (; content[j]; j++) {
		if (j + 1 == '\0')
			break;
		if (content[j] == '\n') {
			j ++;
			i ++;
			e = 0;
		}
		list_word[i][e] = content[j];
		e ++;
	}
	return (list_word);
}

char **word_in(char **tab, char *content, int grid)
{
	int i = 0;
	int nb_word = 0;
	int l_word = 0;
	char **list_word = NULL;

	while (content[l_word] != '\n')
		l_word ++;
	if (l_word > grid - 2)
		exit (84);
	while (content[i] != '\0') {
		if (content[i] == '\n')
			nb_word += 1;
		i ++;
	}
	list_word = malloc(sizeof(char *) * (nb_word + 2));
	for (i = 0; i < (nb_word + 2); i ++) {
		list_word[i] = malloc(sizeof(char) * (l_word + 1));
		list_word[i][l_word] = '\0';
	}
	list_word[nb_word + 1] = NULL;
	return (list_word);
}

int main(int ac, char **av)
{
	int grid = 0;
	char *words = '\0';
	char **tab = NULL;
	char **list_word = NULL;

	if (ac != 3 && ac != 5)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'f')
		words = get_words(av[2]);
        else
		return (84);
	if (!av[3])
		grid = 8;
	else if (av[3][0] == '-' && av[3][1] == 's')
		grid = atoi(av[4]);
        else
		return (84);
	tab = good_surround(grid, tab);
	list_word = word_in(tab, words, grid);
	list_word = put_in(list_word, words);
	tab = word_in_grid(tab, list_word);
	tab = random_in_tab(tab);
	return (0);
}
