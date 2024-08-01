/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:48 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 01:38:36 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

static void __print_export__(t_node *head);


void export(t_command *cmd)
{
	if (empty(cmd->args))
	{
		print_list_custom(shell->export, __print_export__);
		return ;
	}

	// print_list(cmd->args);
	t_node *arg = cmd->args->head;

	while (arg)
	{
		__export_from_string__(arg->val);
		arg = arg->next;
	}

}

int __export_from_string__(char *expr)
{
	if (!expr) return -1;

	a_matrix arr = __split_include_delimiters(expr, '=');

	a_list tokens = make_list_from_matrix(arr);

	// a_list tokens = make_list_from_string(expr, "=", all);

	if (empty(tokens)) return -1;

	if (!is_name(tokens->head->val))
	{
		__perror("export: not a valid identifier");
		return -1;
	}

	if (size(tokens) >= 2) 
	{
		char *val = (tokens->head->next->next) ? tokens->head->next->next->val : "\0";
		return export_update(shell, tokens->head->val, val);
	}

	else
	{
		__unset__(shell, tokens->head->val);
		push_back(shell->export, tokens->head->val);
	}

	return 0;
}

int export_update(t_shell *shell, t_list_value key, t_list_value val)
{
	if (!shell || !key) return -1;
	
	if (!is_name(key))
	{
		__perror("export: not a valid identifier");
		return -1;
	}

	__unset__(shell, key);
	
	string res = __strappend(__make_string_empty(), key, "=", val);

	push_back(shell->export, res);
	
	if (val)
	{
		push_back(shell->env, res);
		
		if (list_value_same(key, "PATH")) shell->path = make_path(shell);
	}
	
	return 0;
}


static void __print_export__(t_node *head)
{
	if (!head) return;

	printf("%s", declarex);

	char *s = head->val;

	while (*s && *s != '=')
	{
		printf("%c", *s);
		++s;
	}
	if (*s == '=')
	{
		printf("%c", *(s++));
		printf("\"");
		while (*s)
		{
			printf("%c", *s);
			++s;
		}
		printf("\"");
	}
	printf("\n");
}
