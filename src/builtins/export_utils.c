/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:01:15 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/22 13:07:52 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool not_equal_sign(t_node *const node)
{
	return node && !string_equal(node->val, "=");
}

int __export_from_string__(char *expr, t_shell *shell) // export ==========
{
	if (!expr || !shell) return -1;

	scoped_list tokens = make_list_from_string(expr, "=", all);

	if (empty(tokens)) return -1;

	t_node *lhv = front(tokens);

	if (lhv->val[__strlen(lhv->val) - 1] == '+')
	{
		lhv->val[__strlen(lhv->val) - 1] = '\0';
		char *old_val = get_val(shell->export, lhv->val);

		if (old_val == NULL) old_val = "";

		list_insert(tokens, lhv->next, old_val);
	}

	if (!is_name(lhv->val) || NULL == find_if(lhv, back(tokens), not_equal_sign))
	{
		scoped_string str = __make_string("export: `", expr, "\': not a valid identifier");
		__perror(str);
		return -1;
	}

	if (shell->container && shell->container->size > 1) return 0;

	if (size(tokens) >= 2)
	{
		scoped_string val = __make_string_from_list(lhv->next->next, back(tokens));
		if (val == NULL) val = __make_string_empty();
		return export_update(shell, lhv->val, val);
	}
	else
	{
		unset_var(shell, lhv->val);
		tree_update(shell->export, lhv->val, NULL);
	}

	return 0;
}
