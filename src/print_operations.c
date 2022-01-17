/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/06 14:52:18 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/07 14:20:34 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <unistd.h>

void	prnt_swap(int type)
{
	if (type == A)
		write(1, "sa\n", 3);
	else if (type == B)
		write(1, "sb\n", 3);
	else if (type == SIM)
		write(1, "ss\n", 3);
}

void	prnt_push(int type)
{
	if (type == A)
		write(1, "pa\n", 3);
	else if (type == B)
		write(1, "pb\n", 3);
}

void	prnt_rot(int type)
{
	if (type == A)
		write(1, "ra\n", 3);
	else if (type == B)
		write(1, "rb\n", 3);
	else if (type == SIM)
		write(1, "rr\n", 3);
}

void	prnt_rrot(int type)
{
	if (type == A)
		write(1, "rra\n", 4);
	else if (type == B)
		write(1, "rrb\n", 4);
	else if (type == SIM)
		write(1, "rrr\n", 4);
}
