/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 13:03:48 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/16 14:17:21 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
#include "../hdr/pushswap.h"
#include <stdlib.h>
#include <unistd.h>

void	found_error(int errcode)
{
	if (errcode >= 0)
	{
		ft_putnbr_fd(errcode, 1);
		write(1, " Error!\n", 8);
	}
	exit(0);
}

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
