#ifndef BST_HEADER_H
# define BST_HEADER_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct tree_node	tree_node;
typedef struct t_tree		t_tree;
typedef int	   t_val;

typedef void				(*fptr)(tree_node *);

struct						t_tree
{
	tree_node				*root;
};

void						preorder(t_tree *tree, fptr foo);
void						inorder(t_tree *tree, fptr foo);
void						postorder(t_tree *tree, fptr foo);
void						insert_node(t_tree *tree, int val);
void 						node_clear(t_tree *tree, const int val);
bool						tree_empty(t_tree *tree);
tree_node					*make_tree_node(const int val);
tree_node					*search(t_tree *tree, int val);
t_tree						*make_tree(void);
t_tree						*make_tree_from_array(int *arr, const int size);
void						delete_node(tree_node *node);
void						tree_clear(t_tree **treeptr);
void						swap_val(tree_node *lhv, tree_node *rhv);
tree_node					*find_max(t_tree *tree);
tree_node					*find_min(t_tree *tree);
tree_node					*__find_max__(tree_node *root);
tree_node					*__find_min__(tree_node *root);
void 						print_preorder(t_tree *tree);
void 						print_inorder(t_tree *tree);
void 						print_postorder(t_tree *tree);
bool 						less(t_val a, t_val b);
bool 						greater(t_val a, t_val b);
bool 						equal(t_val a, t_val b);


struct						tree_node
{
	t_val						val;
	tree_node				*right;
	tree_node				*left;
};

#endif // BST_HEADER_H
