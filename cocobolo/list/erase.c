/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:49:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/25 20:26:54 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t erase(t_list *list, t_node *first, t_node *last)
{
    if (empty(list) || !first || !last) return 0;

    size_t res = 0;

    while (first && first != last)
    {
        t_node *next = first->next;
        pop(list, first);
        first = next;
        res++;
    }
    pop(list, last);
    return res;
}