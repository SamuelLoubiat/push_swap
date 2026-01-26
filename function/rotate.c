#include "../pushswap.h"

static void int rotate(int *stack, size_t size)
{
	size_t i;
	int temp;

	if (*len < 2)
		return (0);
	temp = stack[0];
	i = 0;
	while (i < *len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}

	return (1);
}