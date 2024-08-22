/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:36:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 21:33:00 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "tree.h"
# include <cocobolo.h>

typedef struct s_set	t_set;

struct					s_set
{
	t_tree				*tree;
};

t_set					*make_set(void);
void					set_clear(t_set **setptr);
void					set_insert(t_set *set, char *val);
void					set_remove(t_set *set, char *val);
size_t					set_count(t_set *set, char *val);

#endif // SET_H
