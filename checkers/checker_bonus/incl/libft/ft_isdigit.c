/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:50:46 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/02 14:20:58 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int argi)
{
	if ((argi >= '0') && (argi <= '9'))
		return (1);
	return (0);
}
