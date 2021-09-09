/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:51:36 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/09 16:19:03 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;

	check_arguments(argc, argv);
	a = buildstack(argc, argv);
	if (a->size == 1)
		return (0);
	printf("%i\n", get_lstcontent(**a->top));
	stk_sort(a);
	return (0);
}
