/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:03:58 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/24 00:05:49 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_range	*init_range(int option)
{
	t_range	*algo;

	algo = malloc(sizeof(t_range));
	if (!algo)
		return (NULL);
	algo->start = 0;
	algo->end = option;
	return (algo);
}

void	sorting_range(t_stack *a, t_stack *b, int sorted[], int option)
{
	t_range	*algo;

	algo = init_range(option);
	while (a->top > -1)
	{
		algo->op = range(a->arr[a->top], sorted, algo, a->size);
		if (algo->op == 1)
		{
			pb(a, b);
			algo->start++;
			algo->end++;
		}
		else if (algo->op == 0)
			ra(a);
		else if (algo->op == 2)
		{
			pb(a, b);
			rb(b);
			algo->start++;
			algo->end++;
		}
	}
	push_to_a(a, b);
	free(algo);
}

int	ft_max(t_stack *b)
{
	int	i;
	int	max;

	i = 0;
	max = b->top;
	while (i < b->top)
	{
		if (b->arr[max] < b->arr[i])
			max = i;
		i++;
	}
	return (b->arr[max]);
}

int	ft_mx(t_stack *b)
{
	int	i;
	int	max;

	i = 0;
	max = b->top;
	while (i < b->top)
	{
		if (b->arr[max] < b->arr[i])
			max = i;
		i++;
	}
	return (max);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	mx;

	max = ft_max(b);
	while (b->top > 0)
	{
		max = ft_max(b);
		if (max == b->arr[b->top])
			pa(a, b);
		else
		{
			mx = ft_mx(b);
			if (mx <= b->size / 2)
				rrb(b);
			else
				rb(b);
		}
	}
	pa(a, b);
}
