/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:22:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 21:54:37 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool __contains_as_key__(char *line, char *target);

// if successes returns malloced string
char * __attribute__((warn_unused_result)) get_value(t_list *list, char *target)
{
	if (!list || !target) return NULL;

	t_node *node = find(list, target, __contains_as_key__);

	if (!node) return NULL;

	char *res = node->val;

	while (*res && *res != '=') res++;

	if (*res == '\0') return NULL;

	return __strdup(res + 1);
}

static bool __contains_as_key__(char *line, char *target)
{
	char * key = get_key(line);

	bool res = (0 == __strcmp(key, target));

	free(key);

	return res;
}
