/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:51:36 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/07 15:32:39 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"

int	main(int argc, char **argv)
{
	t_struct	*a;

	if (check_arguments(argc, argv) < 0)
		;
	a = buildstack(argc, argv);
	// sort that stuff (a);
	return (0);
}
