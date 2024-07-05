/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:51:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 22:26:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include <cocobolo.h>
typedef struct s_node   t_node;
typedef e_dir t_dir;
typedef struct s_list   t_list;
typedef int 			t_list_value;
typedef void (*t_list_Upredicate) (t_node * const);

enum e_dir
{
	forward,
	reverse
};

struct s_list
{
	t_node *head;
	t_node *tail;
};

struct s_node
{
	t_list_value val;
	t_node *next;
	t_node *prev;
};

void 	push_front(t_list *const list, const t_list_value x);
void 	push_back(t_list *const list, const t_list_value x);
t_list  *make_list();
t_node  *make_node(const t_list_value x);
void 	print_list(t_list *list);

//traverse
void 	preorder_traverse (t_node *head, t_list_Upredicate f);
void 	reverse_preorder_traverse (t_node *head, t_list_Upredicate f);

void 	postorder_traverse (t_node *head, t_list_Upredicate f);
void 	reverse_postorder_traverse (t_node *head, t_list_Upredicate f);

#endif // LIST_H
