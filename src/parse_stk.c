/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_stk.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 16:45:27 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/09 14:47:05 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../incl/libft/libft.h"
#include <limits.h>

int	check_arg(char *arg)
{
	int	cnt;
	int	len;

	cnt = 0;
	len = ft_strlen(arg);
	if (!ft_isdigit(arg[cnt]))
	{
		if ((arg[cnt] != '+' && arg[cnt] != '-') || len <= 1)
		{
			found_error(ERR_NO_INT);
			return (0);
		}
	}
	cnt++;
	while (cnt < len)
	{
		if (!ft_isdigit(arg[cnt]))
		{
			found_error(ERR_NO_INT);
			return (0);
		}
		cnt++;
	}
	return (1);
}

int	conv_arg(char *arg)
{
	long	ret;

	ret = ft_atol(arg);
	if (ret < INT_MIN || ret > INT_MAX)
		found_error(ERR_INT_OVER);
	return ((int)ret);
}

void	check_doubles(int new, t_element *stk)
{
	t_element	*temp;

	temp = stk;
	while (temp != NULL)
	{
		if (new == temp->content)
			found_error(ERR_DOUBLES);
		temp = temp->next;
	}
}

t_stack	init_stk(void)
{
	t_stack	stk;

	stk.top = NULL;
	stk.bottom = NULL;
	stk.size = 0;
	stk.msd = 1;
	return (stk);
}

t_stack	build_stk(int argc, char **argv)
{
	int			cnt;
	int			content;
	t_stack		stk;
	t_element	*new_elem;

	cnt = 1;
	stk = init_stk();
	while (cnt < argc)
	{
		if (check_arg(argv[cnt]))
		{
			content = conv_arg(argv[cnt]);
			if (content >= (stk.msd * 10))
				stk.msd *= 10;
			check_doubles(content, stk.top);
			new_elem = stknew(content);
			stkadd_back(&(stk.top), new_elem);
			stk.size++;
		}
		cnt++;
	}
	stk.bottom = new_elem;
	return (stk);
}
