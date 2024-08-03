/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:30:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/03 15:53:28 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HEADER_H
# define BST_HEADER_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct tree_node	tree_node;
typedef struct t_tree		t_tree;
typedef char				*t_treeval;

typedef void				(*fptr)(tree_node *);
typedef bool				(*t_cmp)(t_treeval, t_treeval);

struct						t_tree
{
	tree_node				*root;
	t_cmp 					less;
};

enum e_e_e
{
	pair_key = 0,
	pair_val = 1
};

tree_node					*make_tree_node(t_treeval key, t_treeval val);
void						tree_update(t_tree *tree, t_treeval key,
								t_treeval val);
void						preorder(t_tree *tree, fptr foo);
void						inorder(t_tree *tree, fptr foo);
void						postorder(t_tree *tree, fptr foo);
void						tree_pop(t_tree *tree, t_treeval key);
bool						tree_empty(t_tree *tree);
t_treeval					get_val(t_tree *tree, t_treeval key);
tree_node					*tree_find(t_tree *tree, t_treeval key);
tree_node 					*tree_find_if(t_tree *tree, t_treeval key, t_cmp p);
t_tree						*make_tree(t_cmp less);
void						delete_node(tree_node *node);
void						tree_clear(t_tree **treeptr);
void						swap_content(tree_node *lhv, tree_node *rhv);
tree_node					*find_max(t_tree *tree);
tree_node					*find_min(t_tree *tree);
tree_node					*__find_max__(tree_node *root);
tree_node					*__find_min__(tree_node *root);
void						print_tree_preorder(t_tree *tree);
void						print_tree_inorder(t_tree *tree);
void						print_tree_postorder(t_tree *tree);
void 						print_tree_preorder_custom(t_tree *tree, fptr foo);
void 						print_tree_inorder_custom(t_tree *tree, fptr foo);
void 						print_tree_postorder_custom(t_tree *tree, fptr foo);
void						treeval_copy(tree_node *lhv, tree_node *rhv);
void						treeval_move(tree_node *lhv, tree_node *rhv);
void						__treeval_copy__(t_treeval *lhv, t_treeval *rhv);
void						__treeval_move__(t_treeval *lhv, t_treeval *rhv);
t_tree 						*make_tree_copy(t_tree *other);
t_tree						*make_tree_from_matrix(t_treeval *arr, t_cmp less);
size_t 						tree_size(t_tree *tree);



//predicates
bool tree_value_same(t_treeval lhv, t_treeval rhv);
bool tree_value_contains(t_treeval lhv, t_treeval rhv);


struct						tree_node
{
	t_treeval				key;
	t_treeval				val;
	tree_node				*right;
	tree_node				*left;
};

#endif // BST_HEADER_H
