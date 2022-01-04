/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_huge.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 17:02:48 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/14 16:04:34 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <unistd.h>
#include <stdio.h>

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

	if (!stk || !stk->top || !stk->bottom)
		return ;
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

void	sort_b(t_stack *a, t_stack *b, t_func func, int leftovers)
{
	int	cnt;
	int	rev;

	if (!a || !b || !b->top)
		return ;
	printf("Stack B\n");
	printf("size = %d\n", b->size);
	print_stk(b);
	if (leftovers <= 1)
		leftovers = 0;
	if (b->size <= 3)
	{
		sort_small(b, func, B);
		empty_b(a, b, func);
		printf("Stack A\n");
		print_stk(a);
	}
	else if (b->size <= 6)
	{
		printf("Bsize = %d\n", b->size);
		leftovers = b->size / 2;
		cutnstk(a, b, b->size, B);
		printf("Stack A\n");
		print_stk(a);
		printf("Stack B\n");
		print_stk(b);
		sort_small(b, func, B);
		printf("Stack B\n");
		print_stk(b);
		empty_b(a, b, func);
		printf("LEFTOVERS: %d\n", leftovers);
		refill_b(a, b, leftovers, func);
		printf("Stack A\n");
		print_stk(a);
		printf("Stack B\n");
		print_stk(b);
		sort_small(b, func, B);
		printf("Stack B\n");
		print_stk(b);
		empty_b(a, b, func);
		printf("Stack A\n");
		print_stk(a);
		leftovers = 0;
		return ;
	}
	else
	{
		if (leftovers > 1)
			leftovers = b->size / 2;
		else
			leftovers = 0;
		cutnstk(a, b, b->size, B);
		sort_b(a, b, func, leftovers);
	}
	if (leftovers)
	{
		printf("leftovers = %d\n", leftovers);
		rev = cutnstk(a, b, leftovers, A);
		if (leftovers > 1)
			leftovers = leftovers / 2;
		else
			leftovers = 0;
		printf("leftovers = %d\n", leftovers);
		cnt = 0;
		while (cnt < rev)
		{
			revrot_a(a);
			cnt++;
		}
		sort_b(a, b, func, leftovers);
	}
}

void	sort_huge(t_stack *a, t_func func)
{
	t_stack	b;
	int		leftovers;
	int		cut;
	int		cnt;
	int		rev;

	b = init_stk();
	cut = a->size;
	leftovers = cut / 2;
	printf("TOTAL SIZE: %d\n", a->size);
	while (leftovers > 1)
	{
		printf("Stack A\n");
		print_stk(a);
		printf("Cut from A: %d\n", cut);
		printf("LEFTOVERS: %d\n", leftovers);
		rev = cutnstk(a, &b, cut, A);
		cnt = 0;
		printf("Stack A\n");
		print_stk(a);
		printf("leftovers = %d\n", leftovers);
		printf("how many need reversing? %d\n", rev);
		while (cut < a->size && rev && cnt < rev)
		{
			revrot_a(a);
			cnt++;
		}
		printf("Stack A\n");
		print_stk(a);
		sort_b(a, &b, func, leftovers);
		cut = leftovers;
		leftovers = cut / 2;
	}
	printf("leftovers = %d\n", leftovers);
	empty_b(a, &b, func);
	stkclear(&b.top);
}
