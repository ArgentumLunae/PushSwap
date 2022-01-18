/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:41:22 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 17:02:54 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pschecker.h"
#include <stdlib.h>

int	is_sorteda(t_stk *stk)
{
	t_elem	*temp;

	temp = stk->top;
	while (temp->next)
	{
		if (temp->next->content <= temp->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_sortedb(t_stk *stk)
{
	t_elem	*temp;

	temp = stk->top;
	while (temp->next)
	{
		if (temp->next->content >= temp->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_stk	*init_stk(void)
{
	t_stk	*stk;

	stk = malloc(sizeof(t_stk));
	stk->top = NULL;
	stk->bot = NULL;
	stk->size = 0;
	return (stk);
}
