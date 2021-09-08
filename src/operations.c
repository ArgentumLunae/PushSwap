/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 14:42:57 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/08 18:40:54 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include "../lib/libft/libft.h"

void	stk_swap(t_stack *stack)
{
	t_list	*temp;

	if (!stack || !stack->top)
		return ;
	temp = stack->top->next;
	stack->top->next = temp->next;
	temp->next = stack->top;
	stack->top = temp;
}

void	stk_push(t_stack *src, t_stack *dest)
{
	t_list	*temp;

	if (!src || !dest || !src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	src->size--;
	temp->next = dest->top;
	dest->top = temp;
	dest->size++;
}

void	stk_rotate(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top->next;
	stack->top = tmp;
}

void	stk_rotrev(t_stack *stack)
{
	t_list	*temp;

	temp = stack->top;
	while (temp->next != stack->top)
		temp = temp->next;
	stack->top = temp;
}
