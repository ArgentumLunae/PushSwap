/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 16:02:09 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/10 15:55:02 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <stdio.h>
#include <unistd.h>

void	sort_small(t_stack *stk, t_func func, int ab)
{
	if (!stk || !stk->top || !stk->top->next)
		return ;
	while (1)
	{
		if (stk->top->content > stk->bottom->content)
		{
			if (stk->top->content < stk->top->next->content)
				func.rrot[ab](stk);
			else
				func.rot[ab](stk);
		}
		else if (stk->top->content > stk->top->next->content || \
					stk->top->next->content > stk->bottom->content)
			func.swap[ab](stk);
		else
			break ;
	}
}

t_stack	sort_stk(t_stack a, t_func func)
{
	if (a.size <= 3)
		sort_small(&a, func, A);
	else
		sort_huge(&a, func);
	return (a);
}
