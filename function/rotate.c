/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:28:00 by sloubiat          #+#    #+#             */
/*   Updated: 2026/01/26 17:28:01 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	rotate(int *stack, size_t len)
{
	size_t	i;
	int		temp;

	if (len < 2)
		return (0);
	temp = stack[0];
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
	return (1);
}

void	rotate_a(int *a, size_t len)
{
	if (rotate(a, len))
	{
		write(1, "ra\n", 3);
	}
}

void	rotate_b(int *b, size_t len)
{
	if (rotate(b, len))
	{
		write(1, "rb\n", 3);
	}
}

void	rotate_rr(int *a, size_t len_a, int *b, size_t len_b)
{
	int	res_a;
	int	res_b;

	res_a = rotate(a, len_a);
	res_b = rotate(b, len_b);
	if (res_a || res_b)
	{
		write(1, "rr\n", 3);
	}
}
