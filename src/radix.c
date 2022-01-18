/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/06 10:35:33 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 14:54:52 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../incl/libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void	btoa(t_stk *stk[2], int bitcnt)
{
	int	tmp;
	int	cnt;
	int	cnt2;

	tmp = stk[B]->size;
	cnt = 0;
	cnt2 = 0;
	while (cnt < tmp)
	{
		if (bitcnt & stk[B]->top->index)
		{
			push_stk(stk, A);
			cnt2++;
		}
		else
			rotate_stk(stk, B);
		cnt++;
	}
	while (cnt2 > 0)
	{
		rotate_stk(stk, A);
		cnt2--;
	}
}

void	atob(t_stk *stk[2], int n, int bitcnt, int max)
{
	int	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if ((bitcnt << 1) > max && is_sorteda(stk[A]) && is_sortedb(stk[B]))
			break ;
		if (!(bitcnt & stk[A]->top->index))
			push_stk(stk, B);
		else
			rotate_stk(stk, A);
		cnt++;
	}
}

void	empty_b(t_stk *stk[2])
{
	while (stk[B]->top)
		push_stk(stk, A);
}

void	radix_sort(t_stk *stk[2])
{
	int		bitcnt;
	int		max;
	int		tmp;

	bitcnt = 1;
	max = stk[A]->size;
	while (bitcnt < max)
	{
		tmp = stk[A]->size;
		if (stk[B]->top)
			btoa(stk, bitcnt);
		if (stk[A]->top && tmp > 0)
			atob(stk, tmp, bitcnt, max);
		bitcnt = bitcnt << 1;
	}
	empty_b(stk);
}
