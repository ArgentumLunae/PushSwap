/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 14:02:35 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/09 15:58:55 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#include "../lib/libft/libft.h"
#include <stdio.h>

void	print_stack(t_stack *a)
{
	t_list	*tmp;

	tmp = *a->top;
	while (1)
	{
		ft_putnbr_fd(*(int *)tmp->content, 1);
		ft_putchar_fd('\n', 1);
		if (tmp->next == *a->top)
			break ;
		tmp = tmp->next;
	}
}

int	issorted(t_stack *a)
{
	t_list	*tmp;

	tmp = *a->top;
	while (tmp->next != *a->top)
	{
		printf("%p\n", tmp);
		if (*(int *)tmp->content >= *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	stk_smallsort(t_stack *a)
{
	while (!issorted(a))
	{
		if (*(int *)(*a->bottom)->content < *(int *)(*a->top)->content)
		{
			stk_rotate(a);
			write(1, "sa\n", 3);
		}
		else
		{
			stk_swap(a);
			write(1, "ra\n", 3);
		}
	}
}

void	stk_sort(t_stack *a)
{
	t_stack	*b;

	b = stk_alloc();
	if (a->size <= 3)
		stk_smallsort(a);
}
