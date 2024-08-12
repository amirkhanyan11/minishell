/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __atoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:02:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/06/25 13:20:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cocobolo.h"

#define ATOL_MAX 922337203685477580

static void	_skip_spaces(char const **const str)
{
	while (**str && (**str == ' ' || **str == '\n' || **str == '\t'))
		(*str)++;
}

static int	_is_digit(char const c)
{
	return (c >= '0' && c <= '9');
}

static int	_is_sign(char const c)
{
	return (c == '+' || c == '-');
}

static long long	_process(long long res, char const c)
{
	return ((10 * res) + (c - '0'));
}

t_optional	__atoi(char const *str)
{
	long long	num;
	short		sign;
	t_optional	res;

	if (NULL == str) __exit("nullptr passed to __atoi");

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


static bool	_non_digit(char c)
{
	return !_is_digit(c);
}

t_optional	__atol_strict(char const *str)
{
	if (NULL == str) __exit("nullptr passed to __atoi_strict");

	char *t_str = (char*)str;

	if (_is_sign(t_str[0])) t_str++;

	if (*__strchr_p(t_str, _non_digit) != '\0') return make_optional();

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
		const char lim = (sign == -1) ? '8' : '7';
		if (num > ATOL_MAX || (num == ATOL_MAX && *str > lim)) return make_optional();
		num = _process(num, *str);
		str++;
	}
	num *= sign;
	set_optional(&res, num);
	return (res);
}
