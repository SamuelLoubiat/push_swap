/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:37:55 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/19 14:56:33 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n && (str1[i] && str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i >= n)
		return (0);
	return (str1[i] - str2[i]);
}
