/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_predicates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:52:17 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 18:52:50 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <cocobolo.h>

bool tree_value_same(t_treeval lhv, t_treeval rhv)
{
    if (!lhv || !rhv) return (!lhv && !rhv);

    return (__strcmp(lhv, rhv) == 0);
}

bool tree_value_contains(t_treeval lhv, t_treeval rhv)
{
    if (!lhv || !rhv) return (!lhv && !rhv);

    return (__strstr(lhv, rhv) != NULL);
}
