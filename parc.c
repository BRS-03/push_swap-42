/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:03:17 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/23 23:18:29 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ftt_free(char ***ptr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			free(ptr[i][j]);
			j++;
		}
		free(ptr[i][j]);
		free(ptr[i]);
		i++;
	}
	free(ptr[i]);
	free(ptr);
}

char	***split_arguments(int ac, char *av[])
{
	char	***ptr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	ptr = malloc(sizeof(char **) * ac);
	if (!ptr)
		return (NULL);
	while (av[i])
	{
		ptr[j] = ft_split(av[i], ' ');
		i++;
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}

void	fill_stack(t_stack *stack, char ***ptr, int *flag)
{
	int	i;
	int	j;
	int	k;

	*flag = 0;
	stack->size = len(ptr);
	stack->top = stack->size - 1;
	k = stack->size - 1;
	stack->arr = malloc(sizeof(int) * stack->size);
	if (!stack->arr)
		return ;
	j = 0;
	while (ptr[j])
	{
		i = 0;
		while (ptr[j][i])
		{
			stack->arr[k] = ft_atoi(ptr[j][i], flag);
			k--;
			i++;
		}
		j++;
	}
}

t_stack	*parc(int ac, char *av[])
{
	int		flag;
	t_stack	*stack;
	char	***ptr;

	flag = 0;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	ptr = split_arguments(ac, av);
	if (!ptr)
	{
		free(stack);
		return (NULL);
	}
	fill_stack(stack, ptr, &flag);
	if (check(stack->arr, len(ptr)) == 1 || flag == 1)
	{
		write(2, "error\n", 6);
		ftt_free(ptr);
		free(stack->arr);
		free(stack);
		exit(1);
	}
	ftt_free(ptr);
	return (stack);
}
