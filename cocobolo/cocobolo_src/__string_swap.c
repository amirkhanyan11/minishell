/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __string_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:18:47 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:29:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void	__string_swap(char **lhv, char **rhv)
{
	char	*tmp;

	if (!lhv || !rhv)
		return ;
	tmp = NULL;
	__string_move(&tmp, lhv);
	__string_move(lhv, rhv);
	__string_move(rhv, &tmp);
}
