#include "../pushswap.h"

static size_t find_min_index(const int *a, size_t len)
{
	size_t i;
	size_t index;
	int min;

	if (len == 0)
		return -1;
	min = 2147483647;
	i = 0;
	while (i < len)
	{
		if (a[i] < min)
		{
			min = a[i];
			index = i;
		}
		i++;
	}
	return index;
}

void selection(int *a, size_t *len_a, int *b, size_t *len_b)
{
	size_t search;
	size_t i;
	size_t olen;

	olen = *len_a;
	while (*len_a >= 1)
	{
		i = 0;
		search = find_min_index(a, *len_a);
		if (search != 0)
		{
			if ((*len_a /2) > search)
				while (i++ != search)
					rotate_a(a, *len_a);
			else
			{
				while (search != 0)
				{
					reverse_rotate_a(a, *len_a);
					search = find_min_index(a, *len_a);
				}
			}
		}
		push_b(b, len_b, a, len_a);
	}

	while (olen-- > 0)
	{
		push_a(b, len_b, a, len_a);
	}
}