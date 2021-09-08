/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:51:36 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/08 17:52:01 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	check_arguments(argc, argv);
	a = buildstack(argc, argv);
	if (a->size == 1)
		return (0);
	stk_sort(a);
	return (0);
}
