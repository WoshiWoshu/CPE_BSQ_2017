/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** file for the bsq
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"
#include "include/my.h"

void draw_square(int line, int column, char M2[line][column], char *maximum, int s1, int s2)
{
	int x1;
	int y1;

	y1 = s2;
	while (y1 > s2 - *maximum) {
		x1 = s1;
		while (x1 > s1 - *maximum) {
			M2[y1][x1] = 3;
			x1--;
		}
		y1--;
	}
}

void to_print(int line, int column, char M2[line][column], char M3[line][column])
{
	for (int y3 = 0 ; y3 < line ; y3++) {
		for (int x3 = 0 ; x3 < column ; x3++) {
			if (M2[y3][x3] == 3) {
				M3[y3][x3] = 'x';
			}
			if (M2[y3][x3] == 0) {
				M3[y3][x3] = 'o';
			}
			if (M2[y3][x3] == 1) {
				M3[y3][x3] = '.';
			}
			printf("%c", M3[y3][x3]);
		}
		printf("\n");
	}
}

void to_algo(int line, int column, char M2[line][column], char K[line][column])
{
	int y1;
	int x1;

	y1 = 1;
	while (y1 < line) {
		x1 = 1;
		while (x1 < column) {
			if (M2[y1][x1] == 1) {
				K[y1][x1] = min(K[y1][x1 - 1], K[y1 - 1][x1], K[y1 - 1][x1 - 1]) + 1;
			}
			else {
				K[y1][x1] = 0;
			}
			x1++;
		}
		y1++;
	}
}

void bsq(int line, int column, char M[line][column])
{
	char M2[line][column];
	char M3[line][column];
	char K[line][column];
	int s1;
	int s2;
	char maximum = K[0][0];

	into_binary(line, column, M2, M);
	array_opt(line, column, M2, K);
	to_algo(line, column, M2, K);
	find_maximum(line, column, K, &maximum, &s1, &s2);
	draw_square(line, column, M2, &maximum, s1, s2);
	to_print(line, column, M2, M3);
}
