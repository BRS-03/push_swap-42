/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:21:21 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/24 00:33:07 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(t_stack *stack, int size)
{
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->arr = malloc(sizeof(int) * size);
	stack->top = -1;
	stack->size = 0;
	return (stack);
}
/*
void	printstack(t_stack *a, t_stack *b)
{
	int	i;
	int	k;

	i = a->size - 1;
	while (0 <= i)
	{
		printf("stack A = 			%d\n", a->arr[i]);
		i--;
	}
	k = b->size - 1;
	printf("***************\n");
	while (k >= 0)
	{
		printf("stack B		%d\n", b->arr[k]);
		k--;
	}
}
*/

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		*list;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	a = parc(ac, av);
	b = init(b, a->size);
	if (a->size <= 5 && sorted(a) == 1)
		sort_five(a, b);
	else if (a->size <= 100 && sorted(a) == 1)
	{
		list = bubble_sort(a);
		sorting_range(a, b, list, 15);
	}
	else if (a->size > 100 && sorted(a) == 1)
	{
		list = bubble_sort(a);
		sorting_range(a, b, list, 30);
	}
	return (0);
}
