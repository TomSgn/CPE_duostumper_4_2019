/*
** EPITECH PROJECT, 2020
** CPE_duostumper_4_2019
** File description:
** strlen
*/

int my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i ++;
	return (i);
}
