/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 17:13:54 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/09 17:07:28 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../incl/libft/libft.h"
#include <unistd.h>

void	print_stk(t_stack *stk)
{
	t_element	*temp;

	temp = stk->top;
	write(1, "top:\t", 5);
	ft_putnbr_fd(stk->top->content, 1);
	ft_putchar_fd('\n', 1);
	write(1, "bottom:\t", 8);
	ft_putnbr_fd(stk->bottom->content, 1);
	ft_putchar_fd('\n', 1);
	while (temp != NULL)
	{
		ft_putnbr_fd(temp->content, 1);
		ft_putchar_fd('\n', 1);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;

	if (argc <= 2)
		return (0);
	a = build_stk(argc, argv);
	a = sort_stk(a);
	//print_stk(&a);
	stkclear(&(a.top));
	return (0);
}
