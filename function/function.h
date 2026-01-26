/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:28:23 by sloubiat          #+#    #+#             */
/*   Updated: 2026/01/26 17:28:25 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

void	push_b(int *b, size_t *len_b, int *a, size_t *len_a);
void	push_a(int *b, size_t *len_b, int *a, size_t *len_a);

void	swap_a(int *a, int size);
void	swap_b(int *a, int size);
void	swap_ss(int *a, int a_size, int *b, int b_size);

void	rotate_a(int *a, size_t len);
void	rotate_b(int *b, size_t len);
void	rotate_rr(int *a, size_t len_a, int *b, size_t len_b);

void	reverse_rotate_a(int *a, size_t len);
void	reverse_rotate_b(int *b, size_t len);
void	reverse_rotate_rr(int *a, size_t len_a, int *b, size_t len_b);
#endif
