/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:27:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 17:56:31 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_exit_status;


static int tune_k(char c, size_t *i, size_t *k);
static void make_prefix_postfix(char *s, size_t k, size_t i, t_pair *data);
static char * set_val(char *s, size_t i, t_shell *shell, char **_val) __result_use_check;
static void foo(char **s, size_t *i, t_pair *data, t_shell *shell);
static bool p(char c);

char *resolve(char *t_val, t_shell *shell)
{
	size_t i = 0;
	char *s = __strdup(t_val);
	t_pair data;
	while (s[i] && s[i + 1])
	{
		if (s[i] == '$')
			foo(&s, &i, &data, shell);
		i++;
	}
	free(t_val);
	return s;
}

static void foo(char **s, size_t *i, t_pair *data, t_shell *shell)
{
	char *val;
	scoped_string _val;

	_val = NULL;
	size_t k = __strchr_p((*s) + (*i) + 1, p) - (*s);
	if (tune_k((*s)[(*i) + 1], &(*i), &k) == 1)
		return;
	make_prefix_postfix((*s), k, (*i), data);
	char c = (*s)[k];
	(*s)[k] = '\0';
	val = set_val((*s), (*i), shell, &_val);
	(*s)[k] = c;
	if (!val) val = data->second;
	(*i) += __strlen(val) - 1;
	data->first = __strappend(data->first, val, (*s) + k);
	free((*s));
	(*s) = data->first;
	__delete_string(&data->second);
}

static int tune_k(char c, size_t *i, size_t *k)
{
	if (c == '?' || c == '$')
		++(*k);

	if (is_digit(c))
		(*k) = 2;
	else if (*k == 1)
	{
		(*i)++;
		return 1;
	}
	return 0;
}


static char * set_val(char *s, size_t i, t_shell *shell, char **_val)
{
	if (string_equal(s + i, "$?"))
	{
		*_val = __itoa(g_exit_status);
		return *_val;
	}
	else if (string_equal(s + i, "$$"))
	{
		*_val = get_pid(shell);
		return *_val;
	}
	else if (is_digit(*(s + i + 1)))
		return "";
	return get_val(shell->export, s + i + 1);
}

static void make_prefix_postfix(char *s, size_t k, size_t i, t_pair *data)
{
	data->first = __strdup(s);
	data->second = __strdup(s + k);
	data->first[i] = '\0';
}

static bool p(char c)
{
	return !is_name_part(c);
}
