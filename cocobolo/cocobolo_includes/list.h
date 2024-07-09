/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:51:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 19:01:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

# include <cocobolo.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node   t_node;
typedef struct s_list   t_list;
typedef char * 		 	t_list_value;
typedef void (*t_list_Upredicate) (t_node * const);
typedef bool (*t_list_Countpredicate) (t_list_value);
typedef bool (*t_list_Bpredicate_val)(t_list_value, t_list_value);
typedef void (*t_list_Apredicate_val)(size_t *, t_list_value);
typedef void (*f_push) (t_list *const, const t_list_value);
typedef t_list_value (*t_value_mutate)(t_list_value);

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

# define push_back(list, ...)  __unwrapped_push__(__single__push_back__, list, __VA_ARGS__, NULL)
# define push_front(list, ...)  __unwrapped_push__(__single__push_front__, list, __VA_ARGS__, NULL)
void __attribute__((sentinel))  __unwrapped_push__(f_push f, t_list *const list, ...);

void __single__push_back__(t_list *const list, const t_list_value x);
void __single__push_front__(t_list *const list, const t_list_value x);

// void 	push_front(t_list *const list, const t_list_value x);
// void 	push_back(t_list *const list, const t_list_value x);
// void push_back(t_list *const list, const t_list_value x, ...);

void 	pop_front(t_list *const list);
void 	pop_back(t_list *const list);

t_list  *make_list() __attribute__((malloc));
t_list 	*make_list_copy(t_list *other, t_value_mutate f) __attribute__((malloc));
t_list  *make_list_from_matrix(char **arr) __attribute__((malloc));
t_list  *make_list_from_string(char *s, const char c) __attribute__((malloc));
t_node  *make_node(const t_list_value x) __attribute__((malloc));

void 	print_list(t_list *list);
void 	print_list_enumerate(t_list *list);

//	algorithms
size_t size(t_list *list);
t_node *find(t_list *list, t_list_value target, t_list_Bpredicate_val cmp);
t_node *find_strict(t_list *list, t_list_value target, t_list_Bpredicate_val cmp);
size_t count(t_list *list, t_list_value val);
size_t count_if(t_list *list, t_list_Countpredicate p);
size_t accumulate(t_list *list, size_t sum_so_far, t_list_Apredicate_val p);

//	assumes each node's value is a malloced string
void 	list_clear(t_list **list);

//	traverse
void 	preorder_traverse (t_node *head, t_list_Upredicate f);
void 	reverse_preorder_traverse (t_node *head, t_list_Upredicate f);

void 	postorder_traverse (t_node *head, t_list_Upredicate f);
void 	reverse_postorder_traverse (t_node *head, t_list_Upredicate f);

// predicates
bool list_value_same(t_list_value lhv, t_list_value rhv);
bool list_value_contains(t_list_value lhv, t_list_value rhv);

#endif // LIST_H
