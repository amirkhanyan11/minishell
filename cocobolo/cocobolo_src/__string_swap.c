/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __string_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:18:47 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 20:25:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void __string_swap(char **lhv, char **rhv)
{
	if (!lhv || !rhv) return;

	char *tmp = NULL;

	__string_move(&tmp, lhv);
	__string_move(lhv, rhv);
	__string_move(rhv, &tmp);
}
