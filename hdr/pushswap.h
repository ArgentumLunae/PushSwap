/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:51:33 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/08 17:18:48 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../incl/libft/libft.h"

typedef enum e_error
{
	ERR_NO_INT,
	ERR_MALLOC,
	ERR_INT_OVER,
	ERR_DOUBLES
}	t_error;

typedef enum e_stacknr
{
	A,
	B
}	t_stknr;

typedef struct s_element
{
	int					content;
	int					index;
	struct s_element	*next;
}	t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*bottom;
	int			size;

}	t_stack;

typedef void	(*t_swap)(t_stack*);
typedef void	(*t_push)(t_stack*, t_stack*);
typedef void	(*t_rot)(t_stack*);
typedef void	(*t_rrot)(t_stack*);

typedef struct s_func
{
	t_swap	swap[2];
	t_push	push[2];
	t_rot	rot[2];
	t_rrot	rrot[2];
}	t_func;

typedef struct s_branch
{
	t_element		*elem;
	struct s_branch	*parent;
	struct s_branch	*left;
	struct s_branch	*right;
}	t_branch;

void		check_doubles(int new, t_element *stk);
int			check_arg(char *arg);
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

void		swap_a(t_stack *stk);
void		swap_b(t_stack *stk);
void		swap_ss(t_stack *a, t_stack *b);
void		push_a(t_stack *src, t_stack *dst);
void		push_b(t_stack *src, t_stack *dst);

void		rot_a(t_stack *a);
void		rot_b(t_stack *b);
void		rot_rr(t_stack *a, t_stack *b);

void		revrot_a(t_stack *a);
void		revrot_b(t_stack *b);
void		revrot_rr(t_stack *a, t_stack *b);

t_stack		init_stk(void);
t_stack		build_stk(int argc, char **argv);
void		index_stk(t_stack *stk);

void		cutnstk(t_stack *a, t_stack *b, int n, int ab);

t_stack		sort_stk(t_stack a, t_func func);
void		sort_small(t_stack *stk, t_func func, int ab);
void		sort_huge(t_stack *a, t_func func);

#endif