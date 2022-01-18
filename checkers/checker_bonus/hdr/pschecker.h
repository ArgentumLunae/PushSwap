/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pschecker.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/06 13:33:00 by mteerlin      #+#    #+#                 */
/*   Updated: 2022/01/18 16:37:27 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSCHECKER_H
# define PSCHECKER_H

typedef enum e_error
{
	ERR_NOT_INT,
	ERR_MALLOC,
	ERR_INT_OVER,
	ERR_DOUBLES
}	t_error;

typedef enum e_ab
{
	A,
	B,
	SIM
}	t_ab;

typedef struct s_elem
{
	int				content;
	int				index;
	struct s_elem	*next;
}	t_elem;

typedef struct s_stk
{
	t_elem	*top;
	t_elem	*bot;
	int		size;
}	t_stk;

typedef void	(*t_func)(t_stk *stk[2], int type);

void	found_error(int errcode);
int		check_arg(char *arg);
void	check_doubles(int new, t_elem *stk);

t_elem	*stknew(int content);
t_elem	*stklast(t_elem *stk);
void	stkadd_back(t_elem **stk, t_elem *new);
void	stkclear(t_stk *stk[2]);

t_elem	*pop_elem(t_stk *stk);
void	push_elem(t_elem *elem, t_stk *stk);

void	swap_stk(t_stk *stk[2], int type);
void	push_stk(t_stk	*stk[2], int type);
void	rotate_stk(t_stk *stk[2], int type);
void	rev_rotate_stk(t_stk *stk[2], int type);

t_stk	*build_stk(int argc, char **argv);
t_stk	*init_stk(void);

void	index_stk(t_stk *stk);
int		is_sorteda(t_stk *stk);
int		is_sortedb(t_stk *stk);

#endif