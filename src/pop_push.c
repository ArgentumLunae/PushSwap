/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop_push.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 16:47:58 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 10:40:32 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <stddef.h>

t_elem	*pop_elem(t_stk *stk)
{
	t_elem	*ret;

	if (!stk->top)
		return (NULL);
	ret = stk->top;
	stk->top = stk->top->next;
	stk->size--;
	ret->next = NULL;
	return (ret);
}

void	push_elem(t_elem *elem, t_stk *stk)
{
	if (!elem || !stk)
		return ;
	elem->next = stk->top;
	stk->top = elem;
	if (!elem->next)
		stk->bot = stk->top;
	stk->size++;
}
