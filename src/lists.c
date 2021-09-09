/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 16:02:05 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/09 16:08:44 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"

int	get_lstcontent(t_list lst)
{
	int	i;

	i = *(int *)lst.content;
	return (i);
}
