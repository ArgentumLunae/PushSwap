/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/06 13:40:43 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/17 16:43:12 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <stdlib.h>

int	is_sorted(t_stk *stk)
{
	t_elem	*temp;

	temp = stk->top;
	while (temp->next)
	{
		if (temp->next->content <= temp->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_stk	*init_stk(void)
{
	t_stk	*stk;

	stk = malloc(sizeof(t_stk));
	stk->top = NULL;
	stk->bot = NULL;
	stk->size = 0;
	return (stk);
}

int	main(int argc, char **argv)
{
	t_stk	*stk[2];

	if (argc < 2)
		return (1);
	stk[A] = build_stk(argc, argv);
	index_stk(stk[A]);
	stk[B] = init_stk();
	if (!is_sorted(stk[A]))
		sort_stk(stk);
	stkclear(stk);
	return (0);
}
