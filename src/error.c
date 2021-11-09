/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 13:03:48 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/02 14:17:00 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
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
