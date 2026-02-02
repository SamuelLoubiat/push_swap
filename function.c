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