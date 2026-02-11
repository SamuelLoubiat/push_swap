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

void	selection(int *a, size_t *len_a, int *b, size_t *len_b);

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
	int				*stack_b;
	size_t			stack_len;
	size_t			len_b;

	stack_len = 0;
	len_b = 0;
	s = get_args(arg, len);
	if (!s)
		return ;
	strategy = find_strategy(s);
	if (strategy == ERROR)
		return (error_clear(s));
	if (!strategy)
		strategy = ADAPTIVE;
	stack = parse_stack(s, len, &stack_len);
	if (!stack)
		return (error_clear(s));
	clean_args(s);
	stack_b = malloc(sizeof(int) * stack_len);
	if (compute_disorder(stack, stack_len) != (float) 0)
		selection(stack, &stack_len, stack_b, &len_b);
	free(stack);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	parse(argv, argc);
	return (0);
}
