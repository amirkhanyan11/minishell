/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:16:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/07 16:22:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

bool __strcmp(const char *lhv, const char *rhv)
{
    if (!lhv || !rhv) return (!lhv && !rhv);
    
    while (*lhv || *rhv)
    {
        if (*lhv != *rhv) break;
        
        lhv++;
        rhv++;
    }

    return (*lhv == *rhv);
}