/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 16:54:27 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/08 18:46:11 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <stdio.h>

void	swap_stk(t_stack *stk)
{
	t_element	*tmp;

	if (stk == NULL)
		return ;
	tmp = stk->top;
	stk->top = stk->top->next;
	tmp->next = stk->top->next;
	stk->top->next = tmp;
}

void	push_stk(t_stack *src, t_stack *dest)
{
	t_element	*tmp;

	if (src == NULL || src->top == NULL)
		return ;
	tmp = pop_elem(src);
	push_elem(tmp, dest);
}

void	rotate_stk(t_stack *stk)
{
	t_element	*tmp;

	if (stk == NULL)
		return ;
	tmp = pop_elem(stk);
	stk->bottom->next = tmp;
	stk->bottom = stk->bottom->next;
	stk->size++;
}

void	rev_rotate_stk(t_stack *stk)
{
	t_element	*tmp;

	if (stk == NULL)
		return ;
	tmp = stk->top;
	while (tmp->next != stk->bottom)
		tmp = tmp->next;
	stk->bottom = tmp;
	tmp = tmp->next;
	stk->bottom->next = NULL;
	stk->size--;
	push_elem(tmp, stk);
}
