/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:27:29 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 13:07:35 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*concat_args(char **arg, int len)
{
	char	*s;
	char	*s_temp;
	int		i;

	i = 1;
	s = ft_strdup("");
	if (!s)
		return (NULL);
	while (i < len)
	{
		s_temp = s;
		s = ft_strjoin(s, " ");
		free(s_temp);
		s_temp = s;
		s = ft_strjoin(s, arg[i]);
		free(s_temp);
		i++;
	}
	return (s);
}

void	clean_args(char **arg)
{
	int		i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

char	**get_args(char **arg, int len)
{
	char	*concat;
	char	**splited;

	concat = concat_args(arg, len);
	if (!concat)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	splited = ft_split(concat, ' ');
	free(concat);
	return (splited);
}

void	parse(char **arg, int len)
{
	char			**s;
	enum strategy	strategy;
	int				*stack;
	int				stack_len;

	stack_len = 0;
	s = get_args(arg, len);
	if (!s)
		return ;
	strategy = find_strategy(s);
	if (strategy == ERROR)
	{
		clean_args(s);
		write(2, "Error\n", 6);
		return ;
	}
	if (!strategy)
		strategy = ADAPTIVE;
	stack = parse_stack(s, len, &stack_len);
	if (!stack)
	{
		clean_args(s);
		write(2, "Error\n", 6);
		return ;
	}
	clean_args(s);
	if (compute_disorder(stack, stack_len) != (float) 0)
		simple(stack, stack_len);
	free(stack);
}

int	main(int argc, char **argv)
{
	parse(argv, argc);
	return (0);
}
