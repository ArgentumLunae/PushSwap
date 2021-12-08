/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 11:50:17 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/05 12:35:52 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <unistd.h>

void	revrot_a(t_stack *stk)
{
	rev_rotate_stk(stk);
	write(1, "rra\n", 4);
}

void	revrot_b(t_stack *stk)
{
	rev_rotate_stk(stk);
	write(1, "rrb\n", 4);
}

void	revrot_rr(t_stack *a, t_stack *b)
{
	rev_rotate_stk(a);
	rev_rotate_stk(b);
	write(1, "rrr\n", 4);
}
