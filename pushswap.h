#ifndef PUSHSWAP_H
# define _PUSHSWAP_H_
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
enum strategy {ERROR = -1, SIMPLE = 1, MEDIUM = 2, COMPLEX = 3, ADAPTIVE = 4};
enum strategy	find_strategy(char **s);
int check_valid_number(char *nbr, int *stack, int size);
void simple(int *a, size_t len);
float compute_disorder(int *a, int size);
#endif
