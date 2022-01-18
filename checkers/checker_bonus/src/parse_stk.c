/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_stk.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 16:45:27 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 16:17:29 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pschecker.h"
#include "../incl/libft/libft.h"
#include <limits.h>
#include <stdlib.h>

static int	conv_arg(char *arg)
{
	long	ret;

	ret = ft_atol(arg);
	if (ret < INT_MIN || ret > INT_MAX)
		found_error(ERR_INT_OVER);
	return ((int)ret);
}

static void	add_element(char *arg, t_stk *stk)
{
	int		content;
	t_elem	*new_elem;

	if (check_arg(arg))
	{
		content = conv_arg(arg);
		check_doubles(content, stk->top);
		new_elem = stknew(content);
		stkadd_back(&(stk->top), new_elem);
		stk->size++;
	}
}

static int	split_arg(char **argv, char ***arg)
{
	int	cnt;

	cnt = 0;
	*arg = ft_split(argv[1], ' ');
	while ((*arg)[cnt] != NULL)
	{
		cnt++;
	}
	return (cnt);
}

static void	free_split(char ***split)
{
	int	cnt;

	cnt = 0;
	while ((*split)[cnt])
	{
		free((*split)[cnt]);
		cnt++;
	}
	free(*split);
}

t_stk	*build_stk(int argc, char **argv)
{
	char		**arg;
	int			cnt;
	int			end;
	t_stk		*stk;

	stk = init_stk();
	if (argc == 2)
		end = split_arg(argv, &arg);
	else
	{
		arg = &(argv[1]);
		end = argc - 1;
	}
	cnt = 0;
	while (cnt < end)
	{
		add_element(arg[cnt], stk);
		cnt++;
	}
	stk->bot = stklast(stk->top);
	if (argc == 2)
		free_split(&arg);
	return (stk);
}
