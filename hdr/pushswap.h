/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:51:33 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/15 11:27:43 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "ps_structs.h"

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

int			cutnstk(t_stack *a, t_stack *b, int n, int ab);

t_stack		sort_stk(t_stack a, t_func func);
void		sort_small(t_stack *stk, t_func func, int ab);
void		sort_huge(t_stack *a, t_func func);

#endif