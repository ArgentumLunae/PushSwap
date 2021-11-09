/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_huge.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 17:02:48 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/09 17:30:54 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"

int	sig_digit(int number, int msd)
{
	int	ret;

	ret = (number / msd) % 10;
	return (ret);
}

int	find_cap_digit(t_stack *a)
{
	t_element	*temp;
	int			cd;
	int			cap_digit;

	temp = a->top;
	cap_digit = 0;
	while (temp != NULL)
	{
		cd = find_cap_digit(a);
		if (cd > cap_digit)
			cap_digit = cd;
		temp = temp->next;
	}
	return (cap_digit);
}

void	sort_huge(t_stack *a)
{
	t_stack	b;
	int		cd;

	b = init_stk();
	cd = find_cap_digit(a);
	while (1)
	{
		
	}
}
