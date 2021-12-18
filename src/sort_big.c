/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/18 15:08:16 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/18 15:26:14 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../incl/libft/libft.h"
#include <stdio.h>

void	quarter_stk(t_stack *a, t_stack *b)
{
	int	pivots[3];
	int	cnt;

	if (!a || !b)
		return ;
	pivots[1] = (a->size - 1) / 2; //rounded down
	pivots[0] = pivots[1] / 2; //rounded down
	pivots[2] = (pivots[1] + a->size) / 2; // rounded down
	cnt = 0;
	while (cnt <= pivots[1])
	{
		if (a->top->index < pivots[1])
			push_b(b, a);
		else
			rot_a(a);
		cnt++;
	}
	printf("Size A:\t%d\nSize B:%d\n", a->size, b->size);
}

// void	sort_big(t_stack *a, t_func func)
// {
// 	t_stack	b;

// 	b = init_stk();
// }