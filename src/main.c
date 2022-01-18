/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/06 13:40:43 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 14:42:17 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"

int	main(int argc, char **argv)
{
	t_stk	*stk[2];

	if (argc < 2)
		return (1);
	stk[A] = build_stk(argc, argv);
	index_stk(stk[A]);
	stk[B] = init_stk();
	if (!is_sorteda(stk[A]))
		sort_stk(stk);
	stkclear(stk);
	return (0);
}
