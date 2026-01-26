/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:27:50 by sloubiat          #+#    #+#             */
/*   Updated: 2026/01/26 17:27:52 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	rotate(int *stack, size_t len)
{
	int	i;
	int	temp;

	if (len < 2)
		return (0);
	temp = stack[len - 1];
	i = len - 2;
	while (i >= 0)
	{
		stack[i + 1] = stack[i];
		i--;
	}
	stack[0]  = temp;
	return (1);
}

void	reverse_rotate_a(int *a, size_t len)
{
	if(rotate(a, len))
	{
		write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(int *b, size_t len)
{
	if(rotate(b, len))
	{
		write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_rr(int *a, size_t len_a, int *b, size_t len_b)
{
	int	res_a;
	int	res_b;

	res_a = rotate(a, len_a);
	res_b = rotate(b, len_b);
	if (res_a || res_b)
	{
		write(1, "rrr\n", 4);
	}
}
