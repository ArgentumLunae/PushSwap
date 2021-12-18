/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_structs.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 11:26:32 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/12/18 15:07:49 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRUCTS_H
# define PS_STRUCTS_H

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

#endif