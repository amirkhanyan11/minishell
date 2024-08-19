/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:30:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:08:00 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_tree_node	t_tree_node;
typedef struct s_tree		t_tree;
typedef char				*t_treeval;

typedef void				(*t_fptr)(t_tree_node *);
typedef bool				(*t_cmp)(t_treeval, t_treeval);

typedef enum e_color
{
	BLACK,
	RED
}							t_color;

struct						s_tree
{
	t_tree_node				*root;
	t_tree_node				*nil;
	t_cmp					less;
};

struct						s_tree_node
{
	t_treeval				key;
	t_treeval				val;
	t_tree_node				*right;
	t_tree_node				*left;
	t_tree_node				*p;
	t_color					color;
};

enum						e_e_e
{
	pair_key = 0,
	pair_val = 1
};

void						left_rotate(t_tree *tree, t_tree_node *z);
void						right_rotate(t_tree *tree, t_tree_node *z);
t_tree_node					*make_tree_node(t_treeval key, t_treeval val,
								t_tree_node *nil, t_color color);
void						delete_node(t_tree_node *node);
t_tree						*make_tree(t_cmp less);
t_tree						*make_tree_copy(t_tree *other);
void						tree_update(t_tree *tree, t_treeval key,
								t_treeval val);
void						tree_remove(t_tree *tree, t_treeval key);
t_tree_node					*tree_find(t_tree *tree, t_treeval key);
size_t						tree_height(t_tree *tree);
t_tree_node					*find_max(t_tree *tree);
t_tree_node					*find_min(t_tree *tree);
t_tree_node					*__find_max__(t_tree *tree, t_tree_node *root);
t_tree_node					*__find_min__(t_tree *tree, t_tree_node *root);
t_treeval					get_val(t_tree *tree, t_treeval key);
void						preorder(t_tree *tree, t_fptr foo);
void						inorder(t_tree *tree, t_fptr foo);
void						postorder(t_tree *tree, t_fptr foo);
bool						tree_empty(t_tree *tree);
void						tree_clear(t_tree **treeptr);
void						print_tree_preorder(t_tree *tree);
void						print_tree_inorder(t_tree *tree);
void						print_tree_postorder(t_tree *tree);
void						print_tree_preorder_custom(t_tree *tree,
								t_fptr foo);
void						print_tree_inorder_custom(t_tree *tree, t_fptr foo);
void						print_tree_postorder_custom(t_tree *tree,
								t_fptr foo);
void						treeval_copy(t_tree_node *lhv, t_tree_node *rhv);
void						treeval_move(t_tree_node *lhv, t_tree_node *rhv);
void						__treeval_copy__(t_treeval *lhv, t_treeval *rhv);
void						__treeval_move__(t_treeval *lhv, t_treeval *rhv);
t_tree						*make_tree_from_matrix(t_treeval *arr, t_cmp less);
size_t						tree_size(t_tree *tree);
void						_delete_fixup(t_tree *tree, t_tree_node *x);

void						__print_key__(t_tree_node *root);
// x
// void						swap_content(t_tree_node *lhv, t_tree_node *rhv);
// t_tree_node 					*tree_find_if(t_tree *tree, t_treeval key,
// t_cmp p);

// predicates
bool						tree_value_same(t_treeval lhv, t_treeval rhv);
bool						tree_value_contains(t_treeval lhv, t_treeval rhv);

#endif // TREE_H
