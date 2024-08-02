/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __string_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:17:12 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 20:18:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void __string_move(char **lhv, char **rhv)
{
	if (!lhv || !rhv || *lhv == *rhv) return;

	__delete_string(lhv);
	*lhv = *rhv;
	*rhv = NULL;
}
