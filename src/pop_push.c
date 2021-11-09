/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop_push.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 16:47:58 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/02 14:07:20 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"

t_element	*pop_elem(t_stack *stk)
{
	t_element	*ret;

	ret = stk->top;
	stk->top = stk->top->next;
	ret->next = NULL;
	return (ret);
}

void	push_elem(t_element *elem, t_stack *stk)
{
	elem->next = stk->top;
	stk->top = elem;
}
