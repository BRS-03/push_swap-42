/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:22:34 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/24 00:25:12 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	size;
	int	top;
	int	index;
	int	*arr;
}		t_stack;

typedef struct z_stack
{
	int	start;
	int	end;
	int	op;

}		t_range;
int		ft_mx(t_stack *b);
int		ft_max(t_stack *b);
int		sorted(t_stack *a);
void	ft_free(char **s);
int		range(int top, int *list, t_range *algo, int size);
void	push_to_a(t_stack *a, t_stack *b);
int		*bubble_sort(t_stack *a);
void	sorting_range(t_stack *a, t_stack *b, int sorted[], int option);
int		ft_strlen(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		*copy_stack(t_stack *a);
char	**ft_split(char *s, char c);
void	ftt_free(char ***ptr);
t_range	*init_range(int option);
int		ft_long(int n);
int		ft_atoi(char *str, int *flag);
int		len(char ***ptr);
int		check(int *arr, int size);
int		sorted(t_stack *a);
t_stack	*parc(int ac, char *av[]);
void	sort_five(t_stack *a, t_stack *b);
t_stack	*init(t_stack *stack, int size);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	push_to_stack(t_stack *src, t_stack *dst);
void	sort_three(t_stack *stack);
void	sort_fc(t_stack *arr);
void	rrr(t_stack *stacka, t_stack *stackb);
void	rrotatea(t_stack *arr);
void	rrotateb(t_stack *arr);
void	rrb(t_stack *arr);
void	rra(t_stack *arr);
void	rr(t_stack *stacka, t_stack *stackb);
void	rotate_a(t_stack *arr);
void	rotate_b(t_stack *arr);
void	rb(t_stack *arr);
void	ra(t_stack *arr);
void	ss(t_stack *a, t_stack *b);
void	sb(t_stack *arr);
void	sa(t_stack *arr);

#endif