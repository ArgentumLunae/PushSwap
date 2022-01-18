/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nine_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 13:35:17 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 13:46:42 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"

static void	minimize_stka(t_stk *stk[2])
{
	int	size;

	size = stk[A]->size;
	while (stk[A]->size > 3)
	{
		if (stk[A]->top->index < size - 3)
			push_stk(stk, B);
		else if (stk[A]->bot->index < size - 3)
		{
			rev_rotate_stk(stk, A);
			push_stk(stk, B);
		}
		else
			rotate_stk(stk, A);
	}
}

static int	minimize_stkb(t_stk *stk[2])
{
	int	size;
	int	ret;

	size = stk[B]->size;
	ret = 0;
	while (stk[B]->size > 3)
	{
		if (stk[B]->top->index < size - 3)
		{
			push_stk(stk, A);
			ret++;
		}
		else if (stk[B]->bot->index < size - 3)
		{
			rev_rotate_stk(stk, B);
			push_stk(stk, A);
			ret++;
		}
		else
			rotate_stk(stk, B);
	}
	return (ret);
}

static void	sort_leftovers(t_stk *stk[2], int leftovers)
{
	int	cnt;

	cnt = leftovers;
	while (cnt > 0)
	{
		push_stk(stk, B);
		rotate_stk(stk, B);
		cnt--;
	}
	while (cnt < 3)
	{
		push_stk(stk, A);
		cnt++;
	}
	if (stk[B]->size > 1)
		tri_sort(stk, B);
	while (cnt < leftovers + 3)
	{
		push_stk(stk, A);
		cnt++;
	}
}

void	nov_sort(t_stk *stk[2])
{
	int	leftovers;

	minimize_stka(stk);
	tri_sort(stk, A);
	leftovers = minimize_stkb(stk);
	tri_sort(stk, B);
	sort_leftovers(stk, leftovers);
}
