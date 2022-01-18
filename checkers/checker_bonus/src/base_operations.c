/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 16:54:27 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 16:20:45 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pschecker.h"
#include <stddef.h>

void	swap_stk(t_stk *stk[2], int type)
{
	t_elem	*tmp;
	int		rep;

	if (stk == NULL)
		return ;
	if (type == SIM)
	{
		rep = 2;
		type--;
	}
	else
		rep = 1;
	while (rep > 0)
	{
		tmp = stk[type]->top;
		stk[type]->top = stk[type]->top->next;
		tmp->next = stk[type]->top->next;
		stk[type]->top->next = tmp;
		type--;
		rep--;
	}
}

void	push_stk(t_stk	*stk[2], int type)
{
	t_elem	*tmp;
	int		src;

	if (!stk || type > 1)
		return ;
	if (type == A)
		src = B;
	else
		src = A;
	tmp = pop_elem(stk[src]);
	push_elem(tmp, stk[type]);
}

void	rotate_stk(t_stk *stk[2], int type)
{
	t_elem	*tmp;
	int		rep;

	if (stk == NULL)
		return ;
	if (type == SIM)
	{
		rep = 2;
		type--;
	}
	else
		rep = 1;
	while (rep > 0)
	{
		tmp = pop_elem(stk[type]);
		stk[type]->bot->next = tmp;
		stk[type]->bot = stk[type]->bot->next;
		stk[type]->size++;
		type--;
		rep--;
	}
}

void	rev_rotate_stk(t_stk *stk[2], int type)
{
	t_elem	*tmp;
	int		rep;

	if (stk == NULL)
		return ;
	rep = 1;
	if (type == SIM)
	{
		rep = 2;
		type--;
	}
	while (rep > 0)
	{
		tmp = stk[type]->top;
		while (tmp->next != stk[type]->bot)
			tmp = tmp->next;
		stk[type]->bot = tmp;
		tmp = tmp->next;
		stk[type]->bot->next = NULL;
		stk[type]->size--;
		push_elem(tmp, stk[type]);
		type--;
		rep--;
	}
}
