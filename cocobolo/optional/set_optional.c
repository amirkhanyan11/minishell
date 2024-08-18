/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_optional.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:17:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:06:01 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cocobolo.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	set_optional(t_optional *optional, t_optional_value val)
{
	optional->value = val;
	optional->has_value = true;
}

#pragma GCC diagnostic pop
