/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 11:47:16 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/08 15:23:21 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <unistd.h>

void	rot_a(t_stack *stk)
{
	if (!stk || !stk->top || !stk->bottom)
		return ;
	rotate_stk(stk);
	write(1, "ra\n", 3);
}

void	rot_b(t_stack *stk)
{
	if (!stk || !stk->top || !stk->bottom)
		return ;
	rotate_stk(stk);
	write(1, "rb\n", 3);
}

void	rot_rr(t_stack *a, t_stack *b)
{
	rotate_stk(a);
	rotate_stk(b);
	write(1, "rr\n", 3);
}
