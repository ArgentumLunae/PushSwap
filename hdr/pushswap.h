/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:51:33 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/09/09 16:09:04 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../lib/libft/libft.h"

typedef enum e_error
{
	ERR_NO_ARG,
	ERR_NO_INT,
	ERR_MALLOC,
	ERR_INT_OVER,
	ERR_DOUBLES
}	t_error;

typedef struct s_stack
{
	t_list	**top;
	t_list	**bottom;
	int		size;
}	t_stack;

void	found_error(int	errcode);
void	check_arguments(int argc, char **argv);
void	check_isint(char *arg);
void	check_dupl(t_stack *stack, t_list *lst);

t_stack	*stk_alloc(void);
t_stack	*buildstack(int argc, char **argv);

int		get_lstcontent(t_list lst);

void	stk_sort(t_stack *a);

void	stk_swap(t_stack *stack);
void	stk_push(t_stack *src, t_stack *dest);
void	stk_rotate(t_stack *stack);
void	stk_rotrev(t_stack *stack);

#endif