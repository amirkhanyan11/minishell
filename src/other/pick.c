/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:22:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 20:37:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// if successes returns malloced string
char * __attribute__((warn_unused_result)) pick(t_list *list, char *target)
{
	if (!list || !target) return NULL;

	t_node *node = find(list, target, list_value_contains);

	if (!node) return NULL;

	char * res = NULL;

	while (*res && *res != '=') res++;

	if (*res == '\0') return NULL;

	return res + 1;
}
