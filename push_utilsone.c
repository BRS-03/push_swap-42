/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utilsone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:03:38 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/23 23:25:13 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	_c;

	i = 0;
	a = (unsigned char *)b;
	_c = (unsigned char)c;
	while (len > i)
	{
		a[i] = _c;
		i++;
	}
	return (a);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((int)count < 0 && (int)size < 0)
		return (NULL);
	p = malloc(size * count);
	if (!p)
		return (p);
	ft_bzero(p, count * size);
	return (p);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0' && dstsize - 1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	char	*s2;

	s = (char *)s1;
	s2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s, ft_strlen(s) + 1);
	s2[ft_strlen(s)] = '\0';
	return (s2);
}
