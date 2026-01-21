/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 01:08:11 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/12 11:54:00 by sloubiat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

size_t find_min_index(const int *a, size_t len)
{
    size_t i;
    size_t index;
    int min;

    if (len == 0)
        return -1;
    min = 2147483647;
    i = 0;
    while (i < len)
    {
        if (a[i] < min)
        {
            min = a[i];
            index = i;
        }
        i++;
    }
    return index;
}

void rotate(int *a, size_t len)
{
int temp;
size_t i;

i = 0;
temp = a[0];
while (++i < len)
{
    a[i - 1] = a[i];
}
a[i - 1] = temp;
printf("ra\n");
}

void rrotate(int *a, size_t len)
{
    int temp;
    size_t i;

    i = 0;
    temp = a[len - 1];
    while (len-- > 1)
    {
        a[len] = a[len - 1];
    }
    a[0] = temp;
    printf("rra\n");
}

void pushb(int *a, size_t *len)
{
size_t i;

i = 0;
while (i < *len)
{
    a[i] = a[i + 1];
    i++;
}
*len -= 1;
printf("pb\n");
}

void simple(int *a, size_t len)
{
    size_t search;
    size_t i;
    size_t olen;

    olen = len;
    while (len >= 1)
    {
        i = 0;
        search = find_min_index(a, len);
        if (search != 0)
        {
            if ((len /2) > search)
                while (i++ != search)
                    rotate(a, len);
            else
            {
                while (search != 0)
                {
                    rrotate(a, len);
                    search = find_min_index(a, len);
                }
            }
        }
        pushb(a, &len);
    }

    while (olen-- > 0)
    {
        printf("pa\n");
    }
}

int	ft_isdigit(int c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

float compute_disorder(int *a, int size)
{
    int mistakes = 0;
    int total_pairs = 0;
    int i = 0;
    int j = 0;
    while (i < size)
    {
        j = i +1;
        while (j < size)
        {
            total_pairs += 1;
            if (a[i] > a[j])
                mistakes += 1;
            j++;
        }
        i++;
    }
	if (!mistakes)
		return (0);
    float b = (float) mistakes / total_pairs;
    return (b);
}