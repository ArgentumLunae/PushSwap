/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cut_stk.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 11:07:41 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/18 15:08:06 by mteerlin      ########   odam.nl         */
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

int	cutnstk(t_stack *a, t_stack *b, int n, int ab)
{
	int	pivot;
	int	cnt;
	int	cnt2;

	if (!a || !b || n > a->size + b->size)
		return (0);
	cnt = 0;
	if (ab == A)
		pivot = find_pivot(a, n);
	else
		pivot = find_pivot(b, n);
	cnt2 = 0;
	while (ab && cnt < n)
	{
		if (b->top->index > pivot)
		{
			push_a(b, a);
			cnt2++;
		}
		else
			rot_b(b);
		cnt++;
		if (cnt2 > n / 2)
			break ;
	}
	while (!ab && cnt < n)
	{
		if (n <= 3 || a->top->index <= pivot)
		{
			push_b(a, b);
			cnt2++;
		}
		else
			rot_a(a);
		cnt++;
		if (n > 3 && cnt2 > n - (n / 2))
			break ;
	}
	return (cnt - cnt2);
}
