/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   three_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/07 13:40:58 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/17 15:27:28 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <stdio.h>
#include <stdbool.h>

static bool	tri_arrangea(t_stk *stk[2])
{
	if (stk[A]->top->index > stk[A]->bot->index)
	{
		if (stk[A]->top->index < stk[A]->top->next->index)
			rev_rotate_stk(stk, A);
		else
			rotate_stk(stk, A);
		return (1);
	}
	else if (stk[A]->top->index > stk[A]->top->next->index || \
				stk[A]->top->next->index > stk[A]->bot->index)
	{
		swap_stk(stk, A);
		return (1);
	}
	else
		return (0);
}

static bool	tri_arrangeb(t_stk *stk[2])
{
	if (stk[B]->top->index < stk[B]->bot->index)
	{
		if (stk[B]->top->index > stk[B]->top->next->index)
			rev_rotate_stk(stk, B);
		else
			rotate_stk(stk, B);
		return (1);
	}
	else if (stk[B]->top->index < stk[B]->top->next->index || \
				stk[B]->top->next->index < stk[B]->bot->index)
	{
		swap_stk(stk, B);
		return (1);
	}
	else
		return (0);
}

static bool	tri_rotsim(t_stk(*stk[2]))
{
	if (stk[A]->top->index < stk[A]->top->next->index)
	{
		if (stk[B]->top->index > stk[B]->top->next->index)
			rev_rotate_stk(stk, SIM);
		else
		{
			if (tri_arrangea(stk) + tri_arrangeb(stk) == 0)
				return (0);
		}
	}
	else if (stk[A]->top->index > stk[A]->top->next->index && \
				stk[B]->top->index < stk[B]->top->next->index)
		rotate_stk(stk, SIM);
	else
	{
		if (tri_arrangea(stk) + tri_arrangeb(stk) == 0)
			return (0);
	}
	return (1);
}

void	tri_sortsim(t_stk *stk[2])
{
	while (1)
	{
		if (stk[A]->top->index > stk[A]->bot->index && \
				stk[B]->top->index < stk[B]->bot->index)
		{
			if (tri_rotsim(stk) == 0)
				break ;
		}
		else if ((stk[A]->top->index > stk[A]->top->next->index || \
					stk[A]->top->next->index > stk[A]->bot->index) && \
					(stk[B]->top->index < stk[B]->top->next->index || \
					stk[B]->top->next->index < stk[B]->bot->index))
			swap_stk(stk, SIM);
		else
		{
			if (tri_arrangea(stk) + tri_arrangeb(stk) == 0)
				break ;
		}
	}
}

void	tri_sort(t_stk *stk[2], int ab)
{
	if (!stk || !stk[A]->top || !stk[A]->top->next)
		return ;
	while (ab == A)
	{
		if (!tri_arrangea(stk))
			break ;
	}
	while (ab == B)
	{
		if (!tri_arrangeb(stk))
			break ;
	}
	if (ab == SIM)
	{
		if (stk[B]->size < 2)
			tri_arrangea(stk);
		else
			tri_sortsim(stk);
	}
}
