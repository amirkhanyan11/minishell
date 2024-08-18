/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __atoi_vol_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:16:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:24:13 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cocobolo.h"

#define ATOL_MAX 922337203685477580

t_optional	__atoi(char const *str)
{
	long long	num;
	short		sign;
	t_optional	res;

	num = 0;
	sign = 1;
	res = make_optional();
	_skip_spaces(&str);
	if (_is_sign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && _is_digit(*str))
	{
		num = _process(num, *str);
		str++;
	}
	num *= sign;
	set_optional(&res, num);
	if (num > INT_MAX || num < INT_MIN)
		return (make_optional());
	return (res);
}

static int	fill_number(long long *num, int sign, char const *str)
{
	char	lim;

	while (*str && _is_digit(*str))
	{
		if (sign == -1)
			lim = '8';
		else
			lim = '7';
		if (*num > ATOL_MAX || (*num == ATOL_MAX && *str > lim))
			return (-1);
		*num = _process(*num, *str);
		str++;
	}
	return (0);
}

t_optional	__atol_strict(char const *str)
{
	char		*t_str;
	long long	num;
	short		sign;
	t_optional	res;

	t_str = (char *)str;
	if (_is_sign(t_str[0]))
		t_str++;
	if (*__strchr_p(t_str, _non_digit) != '\0')
		return (make_optional());
	num = 0;
	sign = 1;
	res = make_optional();
	_skip_spaces(&str);
	if (_is_sign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (fill_number(&num, sign, str) == -1)
		return (make_optional());
	num *= sign;
	set_optional(&res, num);
	return (res);
}
