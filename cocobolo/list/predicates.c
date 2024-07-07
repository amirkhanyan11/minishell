/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:30:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 01:38:40 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

bool list_value_same(t_list_value lhv, t_list_value rhv)
{
    if (!lhv || !rhv) return (!lhv && !rhv);
    
    return (__strcmp(lhv, rhv) == 0);
}

bool list_value_contains(t_list_value lhv, t_list_value rhv)
{
    if (!lhv || !rhv) return (!lhv && !rhv);

    return (__strstr(lhv, rhv) != NULL);
}