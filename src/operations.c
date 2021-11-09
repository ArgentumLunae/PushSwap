/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 16:54:27 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/09 12:59:45 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"

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

	if (src == NULL)
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
	push_elem(tmp, stk);
}
