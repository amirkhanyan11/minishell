/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:41:51 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/03 17:10:36 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool is_alpha(const char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool is_digit(const char c)
{
    return (c >= '0' && c <= '9');
}

bool is_name_part(const char c)
{
    return (c == '_' || is_alpha(c) || is_digit(c));
}

bool is_redirection(char * val)
{
    return (list_value_same(val, "<") || list_value_same(val, ">"));
}

bool is_quote(char *s)
{
	return list_value_same(s, "\'") || list_value_same(s, "\"");
}

bool is_name(char *s)
{
    if (!s || (*s != '_' && !is_alpha(*s))) return false;

    ++s;

    while (*s)
    {
        if (!is_name_part(*s)) return false;
        ++s;
    }
    return true;
}
