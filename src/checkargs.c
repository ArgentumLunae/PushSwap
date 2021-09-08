/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkargs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:59:34 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/08 17:32:35 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../hdr/pushswap.h"
#include <stdlib.h>
#include <unistd.h>

void	found_error(int	errcode)
{
	static const char	*error_msg[5] = {\
				"No argument found, please provide a list of integers.\n", \
				"Non integer argument found, please provide only integers.\n", \
				"Memory allocation failed.\n", \
				"Argument out of integer boundries.\n",
				"Duplicate values found in argument.\n"};

	write(1, "Error\n", 6);
	write(1, error_msg[errcode], ft_strlen(error_msg[errcode]));
	exit(EXIT_FAILURE);
}

void	check_arguments(int argc, char **argv)
{
	int	cnt;

	if (argc < 2)
		found_error(ERR_NO_ARG);
	cnt = 1;
	while (cnt < argc)
	{
		if (!ft_isdigit(argv[cnt][0]) && \
			 !(argv[cnt][0] == '-' || argv[cnt][0] == '+'))
			found_error(ERR_NO_INT);
		cnt++;
	}
	return ;
}

void	check_isint(char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			found_error(ERR_NO_INT);
		i++;
	}
	return ;
}

void	check_dupl(t_stack *stack, t_list *lst)
{
	t_list	*tmp;

	if (!stack || !lst)
		found_error(ERR_MALLOC);
	tmp = stack->top;
	while (tmp != NULL)
	{
		if (*(int *)lst->content == *(int *)tmp->content)
			found_error(ERR_DOUBLES);
		tmp = tmp->next;
	}
}
