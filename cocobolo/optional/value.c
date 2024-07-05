/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:19:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 19:55:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cocobolo.h"

t_optional_value	value(const t_optional *optional)
{
	if (has_value(optional))
		return (optional->value);
	__exit("Bad optional access");
}

t_optional_value	value_or(const t_optional *optional, t_optional_value val)
{
	if (has_value(optional))
		return (optional->value);
	return (val);
}
