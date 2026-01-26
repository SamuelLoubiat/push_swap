/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:27:40 by sloubiat          #+#    #+#             */
/*   Updated: 2026/01/26 17:27:43 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	del(int *stack, size_t *len)
{
	size_t	i;
	int		temp;

	if (*len < 1)
		return (0);
	temp = stack[0];
	i = 0;
	while (i < *len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	*len -= 1;
	return (1);
}

static void	add(int value, int *stack, size_t *len)
{
	int	i;

	i = *len;
	while (i-- > 0)
		stack[i + 1] = stack[i];
	stack[0] = value;
	*len += 1;
}

void	push_b(int *b, size_t *len_b, int *a, size_t *len_a)
{
	int	value;

	value = a[0];
	if (del(a, len_a))
	{
		add(value, b, len_b);
		write(1, "pb\n", 3);
	}
}

void	push_a(int *b, size_t *len_b, int *a, size_t *len_a)
{
	int	value;

	value = b[0];
	if (del(b, len_b))
	{
		add(value, a, len_a);
		write(1, "pa\n", 3);
	}
}
