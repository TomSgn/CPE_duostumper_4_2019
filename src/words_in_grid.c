/*
** EPITECH PROJECT, 2020
** CPE_duostumper_4_2019
** File description:
** word_in_grid.c
*/

#include "../include/my.h"

char **word_in_grid(char **tab, char **list_word)
{
	int i = 0;
	int j = 0;
	int column = 1;
	int line = 1;

	for (; list_word[i]; i ++) {
		for (j = 0; list_word[i][j]; j++) {
			tab[line][column] = list_word[i][j];
			column ++;
		}
		line ++;
		column = 1;
	}
	return (tab);
}

char **random_in_tab(char **tab)
{
	int i = 0;
	int j = 0;

	for (; tab[i]; i ++) {
		for(j = 0; tab[i][j]; j++) {
			if (tab[i][j] == ' ') {
				tab[i][j] = rand() % 26 + 97;
			}
		}
	}
	for (i = 0; tab[i]; i++)
		printf("%s\n", tab[i]);
	return (tab);
}
