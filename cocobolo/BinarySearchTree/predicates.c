/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:15:01 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 20:48:38 by marikhac         ###   ########.fr       */
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
