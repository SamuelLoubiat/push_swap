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

int	*parse_stack(char **s, int len, int *stack_len)
{
	int		i;
	int		*stack;
	char	*check;

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

void	clean_args(char **arg)
{
	int		i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

void	parse(char **arg, int len)
{
	char			**s;
	enum strategy	strategy;
	int				*stack;
	int				stack_len;
	char			*concat;

	stack_len = 0;
	concat = concat_args(arg, len);
	s = ft_split(concat, ' ');
	free(concat);
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
	/*while (stack_len > 0)
		printf("%d\n", stack[stack_len-- - 1]);*/
	clean_args(s);
	float b = compute_disorder(stack, stack_len);
	if (b != (float) 0)
		simple(stack, stack_len);
	free(stack);
}

int	main(int argc, char **argv)
{
	parse(argv, argc);
	return (0);
}
