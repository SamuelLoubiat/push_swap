/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:27:29 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 13:07:35 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	check_already_contains(int *stack, int number, int size)
{
	while (size > 0)
	{
		if (stack[size - 1] == number)
			return (1);
		size--;
	}
	return (0);
}

int	check_valid_number(char *nbr, int *stack, int size)
{
	char	*check;
	int		nb;

	nb = ft_atoi(nbr);
	check = ft_itoa(nb);
	if (ft_strncmp(nbr, check, ft_strlen(nbr)) != 0)
	{
		free(check);
		return (0);
	}
	if (check_already_contains(stack, nb, size))
	{
		free(check);
		return (0);
	}
	free(check);
	return (1);
}
