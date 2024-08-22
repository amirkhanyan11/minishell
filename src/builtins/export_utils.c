/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:01:15 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/22 19:07:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	______i_a_g_t_c_i_m_p_f_n_________(char *expr, t_node **lhv,
				t_list *tokens, t_shell *shell);

static int	size_2(t_node *lhv, t_shell *shell, t_list *tokens);

static bool	not_equal_sign(t_node *const node)
{
	return (node && !string_equal(node->val, "="));
}

int	__export_from_string__(char *expr, t_shell *shell)
{
	scoped_list	tokens;
	t_node		*lhv;

	tokens = NULL;
	if (!expr || !shell)
		return (-1);
	tokens = make_list_from_string(expr, "=", all);
	if (empty(tokens))
		return (-1);
	lhv = front(tokens);
	if (______i_a_g_t_c_i_m_p_f_n_________(expr, &lhv, tokens, shell))
		return (-1);
	if (shell->container && shell->container->size > 1)
		return (0);
	if (size(tokens) >= 2)
		return (size_2(lhv, shell, tokens));
	else
	{
		unset_var(shell, lhv->val);
		tree_update(shell->export, lhv->val, NULL);
	}
	return (0);
}

static int	size_2(t_node *lhv, t_shell *shell, t_list *tokens)
{
	scoped_string	val;

	val = __make_string_from_list(lhv->next->next, back(tokens));
	if (val == NULL)
		val = __make_string_empty();
	return (export_update(shell, lhv->val, val));
}

static int	______i_a_g_t_c_i_m_p_f_n_________(char *expr, t_node **lhv,
		t_list *tokens, t_shell *shell)
{
	char	*old_val;

	if ((*lhv)->val[__strlen((*lhv)->val) - 1] == '+')
	{
		(*lhv)->val[__strlen((*lhv)->val) - 1] = '\0';
		old_val = get_val(shell->export, (*lhv)->val);
		if (old_val == NULL)
			old_val = "";
		list_insert(tokens, (*lhv)->next, old_val);
	}
	if (!is_name((*lhv)->val) || NULL == find_if((*lhv), back(tokens),
			not_equal_sign))
	{
		__va_perror("export: `", expr, "\': not a valid identifier");
		return (-1);
	}
	return (0);
}
