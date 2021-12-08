/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_push.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 11:40:58 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/08 15:26:39 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <unistd.h>
#include <stdio.h>

void	swap_a(t_stack *stk)
{
	swap_stk(stk);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stk)
{
	swap_stk(stk);
	write(1, "sb\n", 3);
}

void	swap_ss(t_stack *a, t_stack *b)
{
	swap_stk(a);
	swap_stk(b);
	write(1, "ss\n", 3);
}

void	push_a(t_stack *src, t_stack *dst)
{
	if (!src || !dst || !src->top)
		return ;
	push_stk(src, dst);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *src, t_stack *dst)
{
	if (!src || !dst || !src->top)
		return ;
	push_stk(src, dst);
	write(1, "pb\n", 3);
}
