/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 16:02:09 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 13:44:50 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <unistd.h>

void	hex_sort(t_stk *stk[2])
{
	int	size;

	size = stk[A]->size;
	while (stk[A]->size > 3)
	{
		if (stk[A]->top->index < (size - 3))
			push_stk(stk, B);
		else if (stk[A]->bot->index < size - 3)
		{
			rev_rotate_stk(stk, A);
			push_stk(stk, B);
		}
		else
			rotate_stk(stk, A);
	}
	tri_sort(stk, SIM);
	empty_b(stk);
}

void	sort_stk(t_stk *stk[2])
{
	if (stk[A]->size <= 3)
		tri_sort(stk, A);
	else if (stk[A]->size <= 6)
		hex_sort(stk);
	else if (stk[A]->size <= 9)
		nov_sort(stk);
	else
		radix_sort(stk);
	return ;
}
