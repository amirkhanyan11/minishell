/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:45:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 22:44:35 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_set	*make_set(void)
{
	t_set	*set;

	set = (t_set *)__malloc(sizeof(t_set));
	set->tree = make_tree(string_less);
	return (set);
}
