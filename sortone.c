/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:04:21 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/24 00:32:47 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_fc(t_stack *arr)
{
	if (arr->size <= 1)
		return ;
	if (arr->arr[arr->top] > arr->arr[arr->top - 1])
		sa(arr);
}

void	pb1(t_stack *stack)
{
	sa(stack);
	ra(stack);
}

void	pb2(t_stack *stack)
{
	ra(stack);
	sa(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->size <= 2)
	{
		sort_fc(stack);
		return ;
	}
	if (stack->arr[stack->top] < stack->arr[stack->top - 1]
		&& stack->arr[stack->top - 2] < stack->arr[stack->top - 1]
		&& stack->arr[stack->top - 2] > stack->arr[stack->top])
		pb1(stack);
	else if (stack->arr[stack->top] > stack->arr[stack->top - 1]
		&& stack->arr[stack->top - 2] > stack->arr[stack->top - 1]
		&& stack->arr[stack->top - 2] > stack->arr[stack->top])
		sa(stack);
	else if (stack->arr[stack->top] < stack->arr[stack->top - 1]
		&& stack->arr[stack->top - 2] < stack->arr[stack->top]
		&& stack->arr[stack->top - 2] < stack->arr[stack->top - 1])
		rra(stack);
	else if (stack->arr[stack->top] > stack->arr[stack->top - 1]
		&& stack->arr[stack->top - 2] > stack->arr[stack->top - 1]
		&& stack->arr[stack->top - 2] < stack->arr[stack->top])
		ra(stack);
	else if (stack->arr[stack->top] > stack->arr[stack->top - 1]
		&& stack->arr[stack->top - 2] < stack->arr[stack->top]
		&& stack->arr[stack->top - 2] < stack->arr[stack->top - 1])
		pb2(stack);
}

int	sorted(t_stack *a)
{
	int	i;

	if (a->top <= 0)
		return (0);
	i = 0;
	while (i <= (a->top))
	{
		if (a->arr[i] < a->arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}
