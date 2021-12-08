/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_huge.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 17:02:48 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/08 18:51:33 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <unistd.h>
#include <stdio.h>

int	issorted(t_stack *stk)
{
	t_element	*temp;

	temp = stk->top;
	while (temp)
	{
		if (temp->next->content <= temp->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	empty_b(t_stack *a, t_stack *b, t_func func)
{
	if (!a || !b)
		return ;
	while (b->top)
	{
		func.push[A](b, a);
		func.rot[A](a);
	}
}

static void	refill_b(t_stack *a, t_stack *b, int n, t_func func)
{
	if (!a || !b)
		return ;
	while (n)
	{
		func.push[B](a, b);
		n--;
	}
}

static void	print_stk(t_stack *stk)
{
	t_element	*temp;

	temp = stk->top;
	write(1, "top:\t", 5);
	ft_putnbr_fd(stk->top->content, 1);
	ft_putchar_fd('\n', 1);
	write(1, "bottom:\t", 8);
	ft_putnbr_fd(stk->bottom->content, 1);
	ft_putchar_fd('\n', 1);
	while (temp)
	{
		ft_putstr_fd("content: ", 1);
		ft_putnbr_fd(temp->content, 1);
		ft_putstr_fd("\tindex: ", 1);
		ft_putnbr_fd(temp->index, 1);
		ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}

void	sort_b(t_stack *a, t_stack *b, t_func func)
{
	int	cut;
	int	leftovers;

	printf("size B = %d\n", b->size);
	print_stk(b);
	cut = b->size / 2;
	leftovers = b->size - cut;
	if (b->size <= 3)
	{
		sort_small(b, func, B);
		empty_b(a, b, func);
	}
	else if (b->size <= 6)
	{
		cutnstk(b, a, b->size, B);
		sort_small(b, func, B);
		empty_b(a, b, func);
		refill_b(a, b, leftovers, func);
		sort_small(b, func, B);
	}
	else
	{
		cutnstk(b, a, b->size, B);
		cut -= b->size;
		sort_b(a, b, func);
	}
}

void	sort_huge(t_stack *a, t_func func)
{
	t_stack	b;
	int		leftovers;

	b = init_stk();
	leftovers = a->size;
	while (leftovers > 1)
	{
		printf("leftovers = %d\n", leftovers);
		cutnstk(a, &b, leftovers, A);
		sort_b(a, &b, func);
		leftovers = leftovers - (leftovers / 2);
	}
	stkclear(&b.top);
}
