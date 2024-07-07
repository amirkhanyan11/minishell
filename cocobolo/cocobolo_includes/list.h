/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:51:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/07 14:33:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include <cocobolo.h>
typedef struct s_node   t_node;
typedef struct s_list   t_list;
typedef char * 		 	t_list_value;
typedef void (*t_list_Upredicate) (t_node * const);
typedef void (*f_push) (t_list *const, const t_list_value);


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

#define push_back(list, ...)  __va_push__(__single__push_back__, list, __VA_ARGS__, NULL)
#define push_front(list, ...)  __va_push__(__single__push_front__, list, __VA_ARGS__, NULL)
void __attribute__((sentinel))  __va_push__(f_push f, t_list *const list, ...);

void __single__push_back__(t_list *const list, const t_list_value x);
void __single__push_front__(t_list *const list, const t_list_value x);

// void 	push_front(t_list *const list, const t_list_value x);
// void 	push_back(t_list *const list, const t_list_value x);
// void push_back(t_list *const list, const t_list_value x, ...);

void 	pop_front(t_list *const list);
void 	pop_back(t_list *const list);
t_list  *make_list() __attribute__((malloc));
t_node  *make_node(const t_list_value x) __attribute__((malloc));
void 	print_list(t_list *list) __attribute__((nonnull));
void 	list_clear(t_list **list) __attribute__((nonnull));

//traverse
void 	preorder_traverse (t_node *head, t_list_Upredicate f);
void 	reverse_preorder_traverse (t_node *head, t_list_Upredicate f);

void 	postorder_traverse (t_node *head, t_list_Upredicate f);
void 	reverse_postorder_traverse (t_node *head, t_list_Upredicate f);

#endif // LIST_H
