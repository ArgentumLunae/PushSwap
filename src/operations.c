/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 14:42:57 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/09 13:52:08 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../lib/libft/libft.h"

void	stk_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->top)
		return ;
	tmp = *(int *)(*stack->top)->content;
	*(int *)(*stack->top)->content = *(int *)(*stack->top)->next->content;
	*(int *)(*stack->top)->next->content = tmp;
}

void	stk_push(t_stack *src, t_stack *dest)
{
	t_list	*temp;

	if (!src || !dest || !src->top)
		return ;
	temp = (*src->top);
	*src->top = (*src->top)->next;
	(*src->bottom)->next = *src->top;
	src->size--;
	temp->next = *dest->top;
	*dest->top = temp;
	(*dest->bottom)->next = *dest->top;
	dest->size++;
}

void	stk_rotate(t_stack *stack)
{
	stack->bottom = stack->top;
	stack->top = &(*stack->top)->next;
}

void	stk_rotrev(t_stack *stack)
{
	t_list	*temp;

	temp = *stack->top;
	stack->bottom = &temp;
	while (temp->next != *stack->top)
	{
		if (temp->next == *stack->bottom)
			stack->bottom = &temp;
		temp = temp->next;
	}
	stack->top = &temp;
}
