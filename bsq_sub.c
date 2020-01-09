/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** bsq sub functions
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"
#include "include/my.h"

int min(int x, int y, int z)
{
	int slot = x;
	if (slot > y) {
		slot = y;
	}
	else if (slot > z) {
		slot = z;
	}
	return (slot);
}

void into_binary(int line, int column, char M2[line][column], char M[line][column])
{
	for (int y2 = 0 ; y2 < line ; y2++) {
		for (int x2 = 0 ; x2 < column ; x2++) {
			if (M[y2][x2] == '.') {
				M2[y2][x2] = 1;
			}
			if (M[y2][x2] == 'o') {
				M2[y2][x2] = 0;
			}
		}
	}
}

void array_opt(int line, int column, char M2[line][column], char K[line][column])
{
	for (int y = 0 ; y < line ; y++) {
		K[y][0] = M2[y][0];
	}
	for (int x = 0 ; x < column ; x++) {
		K[0][x] = M2[0][x];
	}
}

void find_maximum(int line, int column, char K[line][column], char *maximum, int *s1, int *s2)
{
	for (int y4 = 0 ; y4 < line ; y4++) {
		for (int x4 = 0 ; x4 < column ; x4++) {
			if(*maximum < K[y4][x4]) {
				*maximum = K[y4][x4];
				*s2 = y4;
				*s1 = x4;
			}
		}
	}
}
