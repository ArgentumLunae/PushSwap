/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:33:53 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 17:01:38 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../hdr/get_next_line.h"
#include "../hdr/pschecker.h"
#include "../incl/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	command_list(char *(*commands)[11])
{
	*commands[0] = "sa";
	*commands[1] = "sb";
	*commands[2] = "ss";
	*commands[3] = "ra";
	*commands[4] = "rb";
	*commands[5] = "rr";
	*commands[6] = "rra";
	*commands[7] = "rrb";
	*commands[8] = "rrr";
	*commands[9] = "pa";
	*commands[10] = "pb";
}

static t_func	*list_functions(t_func *func)
{
	func[0] = &swap_stk;
	func[1] = &rotate_stk;
	func[2] = &rev_rotate_stk;
	func[3] = &push_stk;
	return (func);
}

static int	validate_command(char *command, char **commands)
{
	int	cnt;

	cnt = 0;
	while (cnt < 11)
	{
		if (!ft_strncmp(command, commands[cnt], 4))
			return (cnt);
		cnt++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	char	*command;
	char	*commands[11];
	t_func	*func;
	t_stk	*stk[2];
	int		commandnr;

	if (argc < 2)
		return (1);
	command_list(&commands);
	func = malloc(4 * sizeof(t_func));
	func = list_functions(func);
	stk[A] = build_stk(argc, argv);
	stk[B] = init_stk();
	while (get_next_line(0, &command))
	{
		commandnr = validate_command(command, commands);
		if (commandnr < 0 || commandnr > 10)
			found_error(1);
		else
			func[commandnr / 3](stk, (commandnr % 3));
	}
	if (stk[B]->size == 0 && is_sorteda(stk[A]))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(func);
	return (0);
}
