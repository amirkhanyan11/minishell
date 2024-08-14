/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:09:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/14 16:37:37 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

static int __partition__(t_matrix arr, int low, int high, str_binary_predicate cmp)
{
	int i = low - 1;
	int j = low;

	while (j < high)
	{
		if (cmp(arr[j], arr[high]))
		{
			__string_swap(&arr[++i], &arr[j]);
		}
		j++;
	}
	__string_swap(&arr[++i], &arr[high]);
	return i;
}

static void __matrix_qsort__(t_matrix arr, int low, int high, str_binary_predicate cmp)
{
	if (low > high) return;

	int pivot = __partition__(arr, low, high, cmp);
	__matrix_qsort__(arr, low, pivot - 1, cmp);
	__matrix_qsort__(arr, pivot + 1, high, cmp);
}

void matrix_sort(t_matrix arr, str_binary_predicate cmp)
{
	if (!arr) return ;

	if (!cmp) cmp = string_less;

	__matrix_qsort__(arr, 0, matrix_size(arr) - 1, cmp);

}
