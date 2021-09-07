/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:51:33 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/07 15:21:07 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../incl/libft/libft.h"

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

void	check_arguments(int argc, char **argv);
void	found_error(void);

t_stack	*buildstack(int argc, char **argv);

#endif