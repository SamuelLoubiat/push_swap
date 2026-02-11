#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "function/function.h"
enum strategy {ERROR = -1, SIMPLE = 1, MEDIUM = 2, COMPLEX = 3, ADAPTIVE = 4};
enum strategy	find_strategy(char **s);
int	*parse_stack(char **s, int len, size_t *stack_len);
void simple(int *a, size_t len);
float compute_disorder(int *a, int size);

void	error_clear(char **arg);
void	clean_args(char **arg);
#endif
