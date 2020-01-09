/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sub functions of bsq project
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"
#include "include/my.h"

int open_file(char *name_file, int *val)
{
	*val = open(name_file, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
	if (*val == -1) {
		write(2, "open error\n", 11);
		return(84);
	}
	return(0);
}

void put_in(char *buffer, char *buffer_line, int *line, int val)
{
	int i;

	i = 0;
	while (read(val, buffer + i, 1) == 1) {
		i = i + 1;
	}
	buffer[i] = '\0';
	i = 0;
	while (buffer[i] != '\n') {
		buffer_line[i] = buffer[i];
		i++;
	}
	buffer_line[i+1] = '\0';
	*line = my_get_nbr(buffer_line);
}

int add(char *buffer, char *buffer_2, char *buffer_line)
{
	int m = 0;
	int n;
	int i2;
	int column;

	n = strlen(buffer_line) + 1;
	while (buffer[n] != '\0') {
		buffer_2[m] = buffer[n];
		n++;
		m++;
	}
	buffer_2[n] = '\0';
	i2 = 0;
	while (buffer_2[i2] != '\n') {
		i2++;
	}
	column = i2;
	return(column);
}

void driver(char **av)
{
	int val;

	open_file(av[1], &val);
	read_to(val);
}

int read_to(int val)
{
	char buffer[450000];
	char buffer_2[450000];
	char buffer_line[10000];
	int line;
	int column;

	put_in(buffer, buffer_line, &line, val);
	column = add(buffer, buffer_2, buffer_line);
	char array[line][column];
	for(int k = 0 ; k < line ; k++) {
		for(int j = 0 ; j < column ; j++) {
			array[k][j] = buffer_2[k * (column + 1) + j];
		}
	}
	bsq(line, column, array);
	return(0);
}
