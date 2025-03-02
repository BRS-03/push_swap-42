/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorttwo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:04:32 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/24 00:33:44 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_stack *a)
{
	int	i;
	int	min;
	int	k;

	i = 0;
	min = 2147483647;
	while (i <= a->top)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			k = i;
		}
		i++;
	}
	return (k);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	while (a->top > 2)
	{
		min_index = ft_min(a);
		if (min_index == a->top)
			pb(a, b);
		else if (min_index > a->top - min_index)
			ra(a);
		else if (min_index <= a->top - min_index)
			rra(a);
	}
	sort_three(a);
	while (b->top >= 0)
		pa(a, b);
}

int	*copy_stack(t_stack *a)
{
	int	*res;
	int	i;

	res = (int *)malloc(sizeof(int) * (a->top + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i <= a->top)
	{
		res[i] = a->arr[i];
		i++;
	}
	return (res);
}

int	*bubble_sort(t_stack *a)
{
	int	*res;
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	res = copy_stack(a);
	while (i <= a->top)
	{
		j = 0;
		while (j < a->top - i)
		{
			if (res[j] > res[j + 1])
			{
				t = res[j];
				res[j] = res[j + 1];
				res[j + 1] = t;
			}
			j++;
		}
		i++;
	}
	return (res);
}

int	range(int a, int *list, t_range *algo, int size)
{
	int	k;

	k = 0;
	while (k < size)
	{
		if (a == list[k])
			break ;
		k++;
	}
	if (k >= algo->start && k <= algo->end)
		return (1);
	else if (k < algo->start)
		return (2);
	return (0);
}
