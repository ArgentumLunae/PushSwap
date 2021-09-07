/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stacks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 12:39:58 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/07 15:57:31 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
#include "../hdr/pushswap.h"
#include <limits.h>

t_stack	*buildstack(int argc, char **argv)
{
	int			cnt;
	long int	temp;
	t_list		*lst;
	t_stack		*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	cnt = 1;
	while (cnt < argc)
	{
		temp = ft_atol(argv[cnt]);
		if (temp < INT_MIN || temp > INT_MAX)
			//found error
		lst = ft_lstnew((int)temp);
		ft_lstadd_back(stack->top, lst);
		stack->size++;
		cnt++;
	}
	lst->next = stack->top;
	return (stack);
}
