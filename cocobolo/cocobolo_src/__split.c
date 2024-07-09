/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:21:48 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 19:49:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

static size_t	_count_words(char const *s, char const c);
static size_t	_current_len(char const **str, char const c);
static t_matrix _allocate(char const *str, char const c, size_t const SIZE);
static void		_skip_(char const **str, char const c);

t_matrix  __attribute__((warn_unused_result))  __split(char const *s, char c)
{
	if (!s)
		__exit("nullptr passed to __split");
	return (_allocate(s, c, _count_words(s, c)));
}

static	size_t	_count_words(char const *s, char const c)
{
	size_t	words;
	short	flag;

	words = 0;
	flag = 0;
	_skip_(&s, c);
	while (*s)
	{
		if (*s != c)
			flag = 1;
		else if (*s == c && flag)
		{
			words++;
			flag = 0;
		}
		s++;
	}
	return (flag + words);
}

static	size_t	_current_len(char const **str, char const c)
{
	size_t	len;

	len = 0;
	while (**str && **str != c)
	{
		len++;
		(*str)++;
	}
	return (len);
}

static void	_skip_(char const **str, char const c)
{
	while (**str && **str == c)
		(*str)++;
}

static	t_matrix    _allocate(char const *str, char const c, size_t const SIZE)
{
	t_matrix    arr;
	char	*tmp;
	size_t	current_len;
	size_t	i;

	arr = (char **)__malloc((SIZE + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[SIZE] = NULL;
	i = 0;
	while (i < SIZE)
	{
		_skip_(&str, c);
		tmp = (char *)str;
		current_len = _current_len(&str, c);
		arr[i] = (char *)__malloc(current_len + 1);
        arr[i][current_len] = '\0';

        int j = 0;
        while (j < current_len)
        {
            arr[i][j] = tmp[j];
            j++;
        }

		i++;
	}
	return (arr);
}
