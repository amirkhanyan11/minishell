/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_desciptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:09:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/25 17:50:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_descriptor * __result_use_check make_descriptors(int x, int y, int z)
{
	t_descriptor *descriptor = __malloc(sizeof(t_descriptor));
	descriptor->stdout = x;
	descriptor->stdin = y;
	descriptor->stderr = z;


	return descriptor;
}
