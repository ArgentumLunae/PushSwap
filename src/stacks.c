/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stacks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 12:39:58 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/09 16:07:34 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../hdr/pushswap.h"
#include <stdlib.h>
#include <limits.h>

#include <stdio.h>

long int	get_value(char *arg)
{
	long int	lval;

	lval = ft_atol(arg);
	if (lval < INT_MIN || lval > INT_MAX)
		found_error(ERR_INT_OVER);
	return (lval);
}

int	*get_intptr(int val)
{
	int	*ptr;

	ptr = malloc(sizeof(int));
	if (!ptr)
		found_error(ERR_MALLOC);
	*ptr = val;
	return (ptr);
}

t_stack	*stk_alloc(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		found_error(ERR_MALLOC);
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_stack	*buildstack(int argc, char **argv)
{
	int			cnt;
	long int	lval;
	int			*val;
	t_list		*top;
	t_list		*lst;
	t_stack		*stack;

	stack = stk_alloc();
	cnt = 1;
	check_isint(argv[cnt]);
	lval = get_value(argv[cnt]);
	val = get_intptr((int)lval);
	top = ft_lstnew(val);
	if (!top)
		found_error(ERR_MALLOC);
	stack->top = &top;
	cnt++;
	while (cnt < argc)
	{
		check_isint(argv[cnt]);
		lval = get_value(argv[cnt]);
		val = get_intptr((int)lval);
		lst = ft_lstnew(val);
		if (!lst)
			found_error(ERR_MALLOC);
		check_dupl(stack, lst);
		ft_lstadd_back(stack->top, lst);
		stack->size++;
		cnt++;
	}
	stack->bottom = &lst;
	(*stack->bottom)->next = *stack->top;
	return (stack);
}
