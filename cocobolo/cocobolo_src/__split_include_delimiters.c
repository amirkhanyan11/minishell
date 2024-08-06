/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __split_include_delimiters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:52:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:18:02 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

t_matrix  __split_include_delimiters(char const *s, char c)
{
	if (!s) return NULL;

	char set[2] = {c, '\0'};

	t_matrix __dtor(__matrix_clear) arr = __split(s, set);

	size_t SIZE = __matrix_size(arr) * 2 - 1;

	if (s[__strlen(s) - 1] == c) SIZE++;

	t_matrix res = malloc(sizeof(char *) * (SIZE + 1));

	res[SIZE] = NULL;

	size_t i = 0;
	size_t j = 0;

	while (arr[j])
	{
		res[i] = __strdup(arr[j]);
		if (i + 1 < SIZE)
		{
			res[i + 1] = __malloc(2);
			res[i + 1][0] = c;
			res[i + 1][1] = '\0';
		}
		i += 2;
		j++;
	}
	return res;
}
