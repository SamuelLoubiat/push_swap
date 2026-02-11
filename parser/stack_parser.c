/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:27:29 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 13:07:35 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	check_already_contains(int *stack, int number, int size)
{
	while (size > 0)
	{
		if (stack[size - 1] == number)
			return (1);
		size--;
	}
	return (0);
}

static int	check_valid_number(char *nbr, int *stack, int size)
{
	int		nb;

	nb = ft_atoi(nbr);
	if (nb == 0)
		if (!ft_strncmp(nbr, "0", ft_strlen(nbr))
			&&!ft_strncmp(nbr, "-0", ft_strlen(nbr))
			&& !ft_strncmp(check, "+0", ft_strlen(nbr)))
			return (0);
	if (check_already_contains(stack, nb, size))
	{
		return (0);
	}
	return (1);
}

int	*parse_stack(char **s, int len, size_t *stack_len)
{
	int		i;
	int		*stack;

	i = 0;
	stack = malloc(sizeof(int) * len);
	if (!stack)
		return (NULL);
	while (s[i])
	{
		if (s[i][0] == '-' && s[i][1] == '-')
		{
			i++;
			continue ;
		}
		if (check_valid_number(s[i], stack, *stack_len))
			stack[(*stack_len)++] = atoi(s[i++]);
		else
		{
			free(stack);
			return (NULL);
		}
	}
	return (stack);
}
