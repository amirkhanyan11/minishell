/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:36:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 19:40:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
#define SET_H

#include "tree.h"
#include <cocobolo.h>

#define scoped_set t_set * __attribute__((cleanup(set_clear)))

typedef struct s_set t_set;

struct s_set
{
	t_tree *tree;
};

t_set *make_set();
void set_clear(t_set **setptr);
void set_insert(t_set *set, char *val);
void set_remove(t_set *set, char *val);
size_t set_count(t_set *set, char *val);



#endif // SET_H
