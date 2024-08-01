/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_predicates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:10:16 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 22:10:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"

bool less(t_val a, t_val b)
{
	return (a < b);
}

bool greater(t_val a, t_val b)
{
	return (a > b);
}

bool equal(t_val a, t_val b)
{
	return (a == b);
}
