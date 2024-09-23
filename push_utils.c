/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:03:33 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/23 23:24:18 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_long(int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str, int *flag)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		*flag = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (ft_long(result * sign) != ft_strlen(str))
		*flag = 1;
	return (result * sign);
}

int	len(char ***ptr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			j++;
		}
		k = k + j;
		i++;
	}
	return (k);
}

int	check(int *arr, int size)
{
	int	i;
	int	j;
	int	num;
	int	pos;

	i = 0;
	j = 0;
	while (i < size)
	{
		num = arr[i];
		pos = i;
		j = 0;
		while (j < size)
		{
			if (num == arr[j] && j != pos)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
