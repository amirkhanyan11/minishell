/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 20:00:40 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// move to separate dir
t_matrix __attribute__((warn_unused_result))  make_matrix_from_string(char *s, char c)
{
	return __split(s, c);
}

t_matrix  __attribute__((warn_unused_result)) make_matrix_copy(t_matrix other)
{
	if (!other) return NULL;

	size_t i = 0;
	while (other[i]) i++;

	t_matrix res = malloc(i + 1);
	res[i] = NULL;

	i = 0;
	while(other[i])
	{
		res[i] = __strdup(other[i]);
		i++;
	}
	return res;
}
