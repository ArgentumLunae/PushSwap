/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   element_op.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 09:30:14 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/02 14:02:32 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../hdr/pushswap.h"

t_element	*stknew(int content)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof(t_element));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_element	*stklast(t_element *stk)
{
	if (stk == NULL)
		return (NULL);
	while (stk->next != NULL)
		stk = stk->next;
	return (stk);
}

void	stkadd_back(t_element **stk, t_element *new)
{
	t_element	*last;

	if (*stk == NULL)
	{
		*stk = new;
		return ;
	}
	last = stklast(*stk);
	last->next = new;
	return ;
}

void	stkclear(t_element **stk)
{
	t_element	*temp;

	while (*stk != NULL && stk != NULL)
	{
		temp = (*stk)->next;
		free(*stk);
		*stk = temp;
	}
	return ;
}
