/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_stk.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 16:45:27 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/05 13:44:01 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../incl/libft/libft.h"
#include <limits.h>

int	conv_arg(char *arg)
{
	long	ret;

	ret = ft_atol(arg);
	if (ret < INT_MIN || ret > INT_MAX)
		found_error(ERR_INT_OVER);
	return ((int)ret);
}

t_stack	init_stk(void)
{
	t_stack	stk;

	stk.top = NULL;
	stk.bottom = NULL;
	stk.size = 0;
	return (stk);
}

void	add_element(int content, t_stack *stk)
{
	t_element	*new_elem;

	check_doubles(content, stk->top);
	new_elem = stknew(content);
	stkadd_back(&(stk->top), new_elem);
	stk->size++;
}

t_stack	build_stk(int argc, char **argv)
{
	int			cnt;
	int			content;
	t_stack		stk;

	cnt = 1;
	stk = init_stk();
	while (cnt < argc)
	{
		if (check_arg(argv[cnt]))
		{
			content = conv_arg(argv[cnt]);
			add_element(content, &stk);
		}
		cnt++;
	}
	stk.bottom = stklast(stk.top);
	return (stk);
}
