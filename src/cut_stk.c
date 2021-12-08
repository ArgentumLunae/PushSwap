/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cut_stk.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 11:07:41 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/08 18:40:12 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

static int	find_pivot(t_stack *stk, int n)
{
	t_element	*temp;
	int			cnt;
	int			max;
	int			min;

	if (!stk || !stk->top)
		return (0);
	temp = stk->top;
	cnt = 0;
	max = INT_MIN;
	min = INT_MAX;
	while (temp && cnt < n)
	{
		if (max < temp->index)
			max = temp->index;
		if (min > temp->index)
			min = temp->index;
		temp = temp->next;
		cnt++;
	}
	return (((max - min) / 2) + min);
}

void	cutnstk(t_stack *a, t_stack *b, int n, int ab)
{
	int	pivot;
	int	cnt;

	if (!a || !b)
		return ;
	cnt = 0;
	pivot = find_pivot(a, n);
	while (ab && cnt < n)
	{
		printf("top B = %p\n", b->top);
		if (b->top->index >= pivot)
			push_a(a, b);
		else
			rot_b(a);
		cnt++;
	}
	while (!ab && cnt < n)
	{
		if (n <= 3 || a->top->index <= pivot)
			push_b(a, b);
		else
			rot_a(a);
		cnt++;
	}
}
