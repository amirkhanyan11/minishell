/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:16:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 01:33:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

size_t __strcmp(const char *lhv, const char *rhv)
{
    if (!lhv || !rhv) return (!lhv && !rhv);
    
    while (*lhv || *rhv)
    {
        if ((const unsigned char)(*lhv) != (const unsigned char)(*rhv)) break;
        
        lhv++;
        rhv++;
    }

    return ((const unsigned char)(*lhv) - (const unsigned char)(*rhv));
}

bool __strcmp_weak__(const char *lhv, const char *rhv)
{
    if (!lhv || !rhv) return (!lhv && !rhv);

    while (*lhv && *rhv)
    {
        if ((const unsigned char) *lhv != (const unsigned char) *rhv) return false;
        lhv++;
        rhv++;
    }

    return true;
}