/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:30:29 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 01:41:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char	*__strstr(char *haystack, char *needle)
{
    int i = 0;
    
    if (!haystack || !needle) return (NULL);

    while (haystack[i])
    {
        if (__strcmp_weak__(haystack + i, needle) == true) return haystack + i;
        i++;
    }
    return NULL;
}