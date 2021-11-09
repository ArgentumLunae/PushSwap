/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:51:33 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/09 17:26:25 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../incl/libft/libft.h"

typedef enum e_error
{
	ERR_NO_ARG,
	ERR_NO_INT,
	ERR_MALLOC,
	ERR_INT_OVER,
	ERR_DOUBLES
}	t_error;

typedef struct s_element
{
	int					content;
	struct s_element	*next;
}	t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*bottom;
	int			size;
	int			msd;
}	t_stack;

void		found_error(int errcode);

t_element	*stknew(int content);
t_element	*stklast(t_element *lst);
void		stkadd_back(t_element **stk, t_element *new);
void		stkclear(t_element **stk);

t_element	*pop_elem(t_stack *stk);
void		push_elem(t_element *elem, t_stack *stk);

void		swap_stk(t_stack *stk);
void		push_stk(t_stack *src, t_stack *dest);
void		rotate_stk(t_stack *stk);
void		rev_rotate_stk(t_stack *stk);

t_stack		init_stk(void);
t_stack		build_stk(int argc, char **argv);

t_stack		sort_stk(t_stack a);

#endif