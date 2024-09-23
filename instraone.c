/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:03:05 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/23 23:13:37 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *arr)
{
	int	k;

	k = 0;
	if (arr->size <= 1)
		return ;
	k = arr->arr[arr->size - 1];
	arr->arr[arr->size - 1] = arr->arr[arr->size - 2];
	arr->arr[arr->size - 2] = k;
	write(1, "sa\n", 3);
}

void	sb(t_stack *arr)
{
	int	k;

	if (arr->size <= 1)
		return ;
	k = 0;
	k = arr->arr[arr->size - 1];
	arr->arr[arr->size - 1] = arr->arr[arr->size - 2];
	arr->arr[arr->size - 2] = k;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	k;
	int	n;

	k = 0;
	n = 0;
	if (a->size <= 1 || b->size <= 1)
		return ;
	k = a->arr[a->size - 1];
	a->arr[a->size - 1] = a->arr[a->size - 2];
	a->arr[a->size - 2] = k;
	n = b->arr[b->size - 1];
	b->arr[b->size - 1] = b->arr[b->size - 2];
	b->arr[b->size - 2] = n;
	write(1, "ss\n", 3);
}
