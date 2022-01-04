/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 17:13:54 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/13 15:09:11 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../incl/libft/libft.h"
#include <unistd.h>
#include <stdio.h>

static void	print_stk(t_stack *stk)
{
	t_element	*temp;

	if (!stk || !stk->top)
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

static t_func	set_func(void)
{
	t_func	ret;

	ret.swap[0] = *swap_a;
	ret.swap[1] = *swap_b;
	ret.push[0] = *push_a;
	ret.push[1] = *push_b;
	ret.rot[0] = *rot_a;
	ret.rot[1] = *rot_b;
	ret.rrot[0] = *revrot_a;
	ret.rrot[1] = *revrot_b;
	return (ret);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_func	func;

	if (argc <= 2)
		return (0);
	func = set_func();
	a = build_stk(argc, argv);
	index_stk(&a);
	a = sort_stk(a, func);
	printf("stack A\n");
	print_stk(&a);
	stkclear(&(a.top));
	return (0);
}
