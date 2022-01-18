/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   element_op.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 09:30:14 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/06 15:54:27 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../hdr/pushswap.h"

t_elem	*stknew(int content)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_elem	*stklast(t_elem *stk)
{
	if (stk == NULL)
		return (NULL);
	while (stk->next != NULL)
		stk = stk->next;
	return (stk);
}

void	stkadd_back(t_elem **stk, t_elem *new)
{
	t_elem	*last;

	if (*stk == NULL)
	{
		*stk = new;
		return ;
	}
	last = stklast(*stk);
	last->next = new;
	return ;
}

void	stkclear(t_stk *stk[2])
{
	t_elem	*temp;

	if (!stk)
		return ;
	while (stk[A]->top)
	{
		temp = stk[A]->top->next;
		free(stk[A]->top);
		stk[A]->top = temp;
	}
	while (stk[B]->top)
	{
		temp = stk[B]->top->next;
		free(stk[B]->top);
		stk[B]->top = temp;
	}
	free(stk[A]);
	free(stk[B]);
	return ;
}
