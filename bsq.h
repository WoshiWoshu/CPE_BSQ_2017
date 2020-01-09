/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** headers of bsq project
*/

int min(int x, int y, int z);
int open_file(char *name_file, int *val);
int read_to(int val);
void bsq(int R, int C, char M[R][C]);
int min(int x, int y, int z);
void into_binary(int R, int C, char M2[R][C], char M[R][C]);
void array_opt(int R, int C, char M2[R][C], char K[R][C]);
void find_maximum(int R, int C, char K[R][C], char *maximum, int *s1, int *s2);
void put_in(char *buffer, char *buffer_line, int *line, int val);
int add(char *buffer, char *buffer_2, char *buffer_line);
void driver(char **av);
