/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:04:12 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 17:32:37 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void matrix_clear(t_matrix *arrptr)
{
	if (!arrptr) return ;
    t_matrix arr = *arrptr;

	if (!arr) return ;

    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    *arrptr = NULL;
}
