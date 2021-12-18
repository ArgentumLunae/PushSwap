/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_huge.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 17:02:48 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/18 15:44:53 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../incl/libft/libft.h"
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
	if (leftovers == 1)
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
		printf("Bsize <= 6\n");
		leftovers = b->size - b->size / 2;
		cutnstk(a, b, b->size, B);
		sort_small(b, func, B);
		empty_b(a, b, func);
		refill_b(a, b, leftovers, func);
		sort_small(b, func, B);
		leftovers = 0;
		return ;
	}
	else
	{
		if (leftovers > 1)
			leftovers = b->size - b->size / 2;
		else
			leftovers = 0;
		cutnstk(a, b, b->size, B);
		sort_b(a, b, func, leftovers);
	}
	if (leftovers)
	{
		rev = cutnstk(a, b, leftovers, A);
		if (leftovers > 1)
			leftovers = leftovers / 2;
		else
			leftovers = 0;
		cnt = 0;
		while (cnt < rev)
		{
			revrot_a(a);
			cnt++;
		}
		sort_b(a, b, func, leftovers);
	}
}

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
	printf("pivots [%d, %d, %d]\n", pivots[0], pivots[1], pivots[2]);
	while (b->size <= pivots[1])
	{
		printf("Size A:\t%d\nSize B:\t%d\n", a->size, b->size);
		//printf("pivots[1]:\t%d\n", pivots[1]);
		if (a->top->index <= pivots[1])
			push_b(a, b);
		else
			rot_a(a);
		cnt++;
	}
}

void	sort_huge(t_stack *a, t_func func)
{
	t_stack	b;
	int		leftovers;
	int		cut;
	// int		cnt;
	// int		rev;

	b = init_stk();
	cut = a->size;
	leftovers = cut / 2;
	quarter_stk(a, &b);
	// while (leftovers > 1)
	// {
	// 	rev = cutnstk(a, &b, cut, A);
	// 	cnt = 0;
	// 	while (cut < a->size && rev && cnt < rev)
	// 	{
	// 		revrot_a(a);
	// 		cnt++;
	// 	}
	// 	sort_b(a, &b, func, leftovers);
	// 	cut = leftovers;
	// 	leftovers = cut / 2;
	// }
	//empty_b(a, &b, func);
	//stkclear(&b.top);
}
