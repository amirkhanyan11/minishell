/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:18:41 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:06:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cocobolo.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

bool	has_value(const t_optional *optional)
{
	return (optional->has_value);
}

#pragma GCC diagnostic pop
