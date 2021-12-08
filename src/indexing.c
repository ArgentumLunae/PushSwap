/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indexing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/24 15:17:24 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/11/30 11:16:45 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/pushswap.h"
#include <stdlib.h>
#include <unistd.h>

t_branch	*new_branch(t_branch *parent, t_element *elem)
{
	t_branch	*branch;

	branch = malloc(sizeof(t_branch));
	if (!branch)
		found_error(ERR_MALLOC);
	branch->elem = elem;
	branch->parent = parent;
	branch->left = NULL;
	branch->right = NULL;
	return (branch);
}

void	place_branch(t_branch *parent, t_element *elem)
{
	if (!parent)
		found_error(ERR_MALLOC);
	if (elem->content < parent->elem->content)
	{
		if (!parent->left)
			parent->left = new_branch(parent, elem);
		else
			place_branch(parent->left, elem);
	}
	else
	{
		if (!parent->right)
			parent->right = new_branch(parent, elem);
		else
			place_branch(parent->right, elem);
	}
}

t_branch	*build_tree(t_element *top)
{
	t_element	*elem;
	t_branch	*root;

	elem = top;
	root = new_branch(NULL, elem);
	elem = elem->next;
	while (elem)
	{
		place_branch(root, elem);
		elem = elem->next;
	}
	return (root);
}

void	index_tree(t_branch *branch, int *index)
{
	if (branch->left)
		index_tree(branch->left, index);
	else
	{
		branch->elem->index = *index;
		(*index)++;
	}
	if (branch->left)
	{
		branch->elem->index = *index;
		(*index)++;
	}
	if (branch->right)
		index_tree(branch->right, index);
}

void	index_stk(t_stack *stk)
{
	t_branch	*tree;
	int			index;

	tree = build_tree(stk->top);
	index = 0;
	index_tree(tree, &index);
}
