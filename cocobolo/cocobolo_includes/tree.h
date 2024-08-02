/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:30:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 14:59:37 by aamirkha         ###   ########.fr       */
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
typedef char *	   			t_treeval;

typedef void				(*fptr)(tree_node *);

struct						t_tree
{
	tree_node				*root;
};

void						preorder(t_tree *tree, fptr foo);
void						inorder(t_tree *tree, fptr foo);
void						postorder(t_tree *tree, fptr foo);
void						insert_node(t_tree *tree, t_treeval val);
void 						node_clear(t_tree *tree,   t_treeval val);
bool						tree_empty(t_tree *tree);
tree_node					*make_tree_node(  t_treeval val);
tree_node					*tree_find(t_tree *tree, t_treeval val);
t_tree						*make_tree(void);
void						delete_node(tree_node *node);
void						tree_clear(t_tree **treeptr);
void						swap_val(tree_node *lhv, tree_node *rhv);
tree_node					*find_max(t_tree *tree);
tree_node					*find_min(t_tree *tree);
tree_node					*__find_max__(tree_node *root);
tree_node					*__find_min__(tree_node *root);
void 						print_tree_preorder(t_tree *tree);
void 						print_tree_inorder(t_tree *tree);
void 						print_tree_postorder(t_tree *tree);
bool 						less(t_treeval a, t_treeval b);
void 						treeval_copy(t_treeval *lhv, t_treeval *rhv);
void 						treeval_move(t_treeval *lhv, t_treeval *rhv);

t_tree						*make_tree_from_matrix(t_treeval *arr); // questionable

struct						tree_node
{
	t_treeval				 val;
	tree_node				*right;
	tree_node				*left;
};

#endif // BST_HEADER_H
