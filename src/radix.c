/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/06 10:35:33 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/17 16:21:38 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../incl/libft/libft.h"
#include <unistd.h>
#include <stdio.h>

void	btoa(t_stk *stk[2], int bitcnt)
{
	int	tmp;
	int	cnt;
	int	cnt2;

	tmp = stk[B]->size;
	cnt = 0;
	cnt2 = 0;
	while (cnt < tmp)
	{
		if (bitcnt & stk[B]->top->index)
		{
			push_stk(stk, A);
			cnt2++;
		}
		else
			rotate_stk(stk, B);
		cnt++;
	}
	while (cnt2 > 0)
	{
		rotate_stk(stk, A);
		cnt2--;
	}
}

void	atob(t_stk *stk[2], int n, int bitcnt)
{
	int	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if (!(bitcnt & stk[A]->top->index))
			push_stk(stk, B);
		else
			rotate_stk(stk, A);
		cnt++;
	}
}

void	empty_b(t_stk *stk[2])
{
	while (stk[B]->top)
		push_stk(stk, A);
}

void	print_stk(t_stk *stk)
{
	t_elem	*temp;

	if (!stk || !stk->top)
		return ;
	temp = stk->top;
	write(1, "size:\t", 6);
	ft_putnbr_fd(stk->size, 1);
	ft_putchar_fd('\n', 1);
	write(1, "top:\t", 5);
	ft_putnbr_fd(stk->top->content, 1);
	ft_putchar_fd('\n', 1);
	write(1, "bottom:\t", 8);
	ft_putnbr_fd(stk->bot->content, 1);
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

void	radix_sort(t_stk *stk[2])
{
	int		bitcnt;
	int		max;
	int		tmp;

	bitcnt = 1;
	max = stk[A]->size;
	while (bitcnt <= max)
	{
		tmp = stk[A]->size;
		if (stk[B]->top)
			btoa(stk, bitcnt);
		if (stk[A]->top && tmp > 0)
			atob(stk, tmp, bitcnt);
		bitcnt = bitcnt << 1;
	}
	empty_b(stk);
}
