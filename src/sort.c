/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 16:02:09 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/09 17:05:18 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <stdio.h>
#include <unistd.h>

void	sort_small(t_stack *a)
{
	while (1)
	{
		if (a->top->content > a->bottom->content)
		{
			if (a->top->content < a->top->next->content)
			{
				rev_rotate_stk(a);
				write(1, "rra\n", 4);
			}
			else
			{
				rotate_stk(a);
				write(1, "ra\n", 3);
			}
		}
		else if (a->top->content > a->top->next->content || \
					a->top->next->content > a->bottom->content)
		{
			swap_stk(a);
			write(1, "sa\n", 3);
		}
		else
			break ;
	}
}

t_stack	sort_stk(t_stack a)
{
	if (a.size <= 3)
		sort_small(&a);
	//else
	//	sort_huge(&a);
	return (a);
}
