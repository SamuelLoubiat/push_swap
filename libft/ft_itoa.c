/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:12:53 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/17 15:15:37 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	find_size(int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = find_size(n);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[size--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[size--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

/*int main(void)
{
	printf("%s", ft_itoa(-2147483648));
	return (0);
}*/
