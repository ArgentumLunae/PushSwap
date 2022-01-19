/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:33:53 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/19 09:05:36 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../hdr/get_next_line.h"
#include "../hdr/pschecker.h"
#include "../incl/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

static char	**cmnd_list(void)
{
	char	**cmnds;

	cmnds = malloc(11 * sizeof(char *));
	cmnds[0] = "sa";
	cmnds[1] = "sb";
	cmnds[2] = "ss";
	cmnds[3] = "ra";
	cmnds[4] = "rb";
	cmnds[5] = "rr";
	cmnds[6] = "rra";
	cmnds[7] = "rrb";
	cmnds[8] = "rrr";
	cmnds[9] = "pa";
	cmnds[10] = "pb";
	return (cmnds);
}

static t_func	*list_functions(void)
{
	t_func	*func;

	func = malloc(4 * sizeof(t_func));
	func[0] = &swap_stk;
	func[1] = &rotate_stk;
	func[2] = &rev_rotate_stk;
	func[3] = &push_stk;
	return (func);
}

static void	print_result(bool sorted, int cmndcnt, t_stk *stk[2])
{
	if (sorted == true && cmndcnt > 0)
		write(1, "KO\n", 3);
	else if (is_sorteda(stk[A]))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	char	**cmnds;
	t_func	*func;
	t_stk	*stk[2];
	bool	sorted;
	int		cmndcnt;

	if (argc < 2)
		return (1);
	cmnds = cmnd_list();
	func = list_functions();
	stk[A] = build_stk(argc, argv);
	stk[B] = init_stk();
	sorted = false;
	if (is_sorteda(stk[A]))
		sorted = true;
	cmndcnt = read_cmnd(cmnds, func, stk);
	print_result(sorted, cmndcnt, stk);
	free (cmnds);
	free(func);
	stkclear(stk);
	return (0);
}
