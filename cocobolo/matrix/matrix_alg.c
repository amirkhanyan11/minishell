/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:59:12 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/14 16:37:18 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

size_t matrix_size(t_matrix arr)
{
	if (!arr) return 0;

	size_t i = 0;
	while (arr[i]) i++;

	return i;
}

void print_matrix(t_matrix arr)
{
	if (!arr) return ;

	size_t i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
