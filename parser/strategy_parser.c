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

static int	ft_strstr(char *s, char *s2)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strncmp(&s[i++], s2, ft_strlen(s2)) == 0)
			return (1);
	}
	return (0);
}

static void	is_strategy(char *s, enum strategy *str, char *tag, enum strategy t)
{
	if (ft_strstr(s, tag))
	{
		if (!*str)
		{
			*str = t;
		}
		else
			*str = ERROR;
	}
}

enum strategy	find_strategy(char **s)
{
	enum strategy	str;
	int				i;

	str = 0;
	i = 0;
	while (s[i])
	{
		is_strategy(s[i], &str, "--simple", SIMPLE);
		is_strategy(s[i], &str, "--medium", MEDIUM);
		is_strategy(s[i], &str, "--complex", COMPLEX);
		is_strategy(s[i], &str, "--adaptive", ADAPTIVE);
		if (str == ERROR)
			return (str);
		if (s[i][0]== '-' && s[i][1] == '-' && !str)
			return (ERROR);
		i++;
	}
	return (str);
}
