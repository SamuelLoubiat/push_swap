/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:28:10 by sloubiat          #+#    #+#             */
/*   Updated: 2026/01/26 17:28:11 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	swap_a(int *a, int size)
{
	if (size < 2)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(int *a, int size)
{
	if (size < 2)
		return ;
	swap_b(a);
	write(1, "sb\n", 3);
}

void	swap_ss(int *a, int a_size, int *b, int b_size)
{
	if (a_size > 1)
		swap(a);
	if (b_size > 1)
		swap(b);
	write(1, "ss\n", 3);
}
