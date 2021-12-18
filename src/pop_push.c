/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop_push.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 16:47:58 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/18 14:56:15 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <stddef.h>

t_element	*pop_elem(t_stack *stk)
{
	t_element	*ret;

	if (!stk->top)
		return (NULL);
	ret = stk->top;
	stk->top = stk->top->next;
	stk->size--;
	ret->next = NULL;
	return (ret);
}

void	push_elem(t_element *elem, t_stack *stk)
{
	if (!elem || !stk)
		return ;
	elem->next = stk->top;
	stk->top = elem;
	if (!elem->next)
		stk->bottom = stk->top;
	stk->size++;
}
