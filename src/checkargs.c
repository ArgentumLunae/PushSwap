/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkargs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:59:34 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/07 15:56:57 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft/libft.h"
#include <unistd.h>

void	found_error(void)
{
	write(1, "Error\n", 6);
	//close program;
}

void	check_arguments(int argc, char **argv)
{
	int	cnt;

	if (argc < 2)
		found_error();
	cnt = 1;
	while (cnt < argc)
	{
		if (!ft_isdigit(argv[cnt][0]) && \
			 (argv[cnt][0] != '-' || argv[cnt][0] != '+'))
			found_error();
		cnt++;
	}
	return ;
}
