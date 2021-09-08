/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/08 14:02:35 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/08 18:39:02 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#include "../lib/libft/libft.h"

void	print_stack(t_stack *a)
{
	t_list	*tmp;

	tmp = a->top;
	while (1)
	{
		ft_putnbr_fd(*(int *)tmp->content, 1);
		ft_putchar_fd('\n', 1);
		if (tmp->next == a->top)
			break ;
		tmp = tmp->next;
	}
}

int	issorted(t_stack *a)
{
	t_list	*tmp;

	tmp = a->top;
	
	while (tmp->next != a->top)
	{
		if (*(int *)tmp->content >= *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	stck_smallsort(t_stack *a)
{
	while (!issorted(a))
	{
		if (*(int *)a->top->content > *(int *)a->top->next->content)
		{
			stk_swap(a);
			write(1, "sa\n", 3);
		}
		else
		{
			stk_rotate(a);
			write(1, "ra\n", 3);
		}
		ft_putnbr_fd(*(int *)a->top->content, 1);
		ft_putchar_fd('\n', 1);
		ft_putnbr_fd(*(int *)a->top->next->content, 1);
		ft_putchar_fd('\n', 1);
		ft_putnbr_fd(*(int *)a->top->next->next->content, 1);
		ft_putchar_fd('\n', 1);
		ft_putchar_fd('\n', 1);
	}
}

void	stk_sort(t_stack *a)
{
	t_stack	*b;

	b = ft_calloc(1, sizeof(t_stack));
	if (!b)
		found_error(ERR_MALLOC);
	if (a->size <= 3)
		stck_smallsort(a);
}
