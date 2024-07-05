/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_optional.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:17:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 19:55:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cocobolo.h"

void	set_optional(t_optional *optional, t_optional_value val)
{
	optional->value = val;
	optional->has_value = true;
}
