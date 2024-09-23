#include "push_swap.h"
void ftt_free(char ***ptr)
{
    int i ;
    int j = 0;
    
    i = 0;

    if (!ptr)
        return;

    while (ptr[i])
    {
        j = 0;
        while (ptr[i][j])
        {
            free(ptr[i][j]);
            j++;
        }
        free(ptr[i]);
        i++;
    }
    free(ptr);
}
char ***split_arguments(int ac, char *av[])
{
    char ***ptr;
    int i = 1;
    int j = 0;

    ptr = malloc(sizeof(char **) * ac);
    if (!ptr)
        return NULL;

    while (av[i])
    {
        ptr[j] = ft_split(av[i], ' ');
        i++;
        j++;
    }
    ptr[j] = NULL;
    return ptr;
}
void fill_stack(t_stack *stack, char ***ptr , int *flag)
{
    int i; 
   int  j;
    int  k;
    *flag = 0;

    stack->size = len(ptr);
    stack->top = stack->size - 1;
    k = stack->size - 1;

    stack->arr = malloc(sizeof(int) * stack->size);
    if (!stack->arr)
       return ; 

 	j = 0;
    while(ptr[j])
    {
        i = 0;
        while(ptr[j][i])    
        {
            	stack->arr[k] = ft_atoi(ptr[j][i],flag);
                k--;
            	i++;
    
        }
        j++;
    }
}

t_stack *parc(int ac, char *av[])
{
    int flag = 0;
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;

    char ***ptr = split_arguments(ac, av);
    if (!ptr)
    {
        free(stack);
        return NULL;
    }

    fill_stack(stack, ptr , &flag);
    if (check(stack->arr, len(ptr)) == 1 || flag == 1)
    {
    	write(2,"error\n",6);
        ftt_free(ptr);
        free(stack->arr);
        free(stack);
        exit(1);
    }
    ftt_free(ptr);
    return stack;
}
