#include "../pushswap.h"

void	insertion(int *stack_a, size_t *size_a, int *stack_b, size_t *size_b)
{
	size_t	i;

	i = 0;
	while (i < size_a - 2)
	{
		if (i == 0)
		{
			if (stack_a[i] > stack_a[i + 1])
			{
				swap_a(int *a, int size);
			}
		}
		if (stack_a[i] > stack_a[i + 1])
		{
			push_b(stack_b, size_b, stack_a, size_a);
		}
	}
}