/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_optional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:08:16 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:06:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cocobolo.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

t_optional	make_optional(void)
{
	t_optional	obj;

	obj.has_value = false;
	obj.value = 0;
	return (obj);
}

#pragma GCC diagnostic pop
