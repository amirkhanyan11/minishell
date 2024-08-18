/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __atoi_vol_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:17:17 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:18:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void	_skip_spaces(char const **const str)
{
	while (**str && (**str == ' ' || **str == '\n' || **str == '\t'))
		(*str)++;
}

int	_is_digit(char const c)
{
	return (c >= '0' && c <= '9');
}

int	_is_sign(char const c)
{
	return (c == '+' || c == '-');
}

long long	_process(long long res, char const c)
{
	return ((10 * res) + (c - '0'));
}

bool	_non_digit(char c)
{
	return (!_is_digit(c));
}
