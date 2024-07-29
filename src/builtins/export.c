/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:48 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 16:59:00 by aamirkha         ###   ########.fr       */
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

int __export_from_string__(char *val)
{
	if (!val) return -1;

	a_matrix arr = __split_include_delimiters(val, '=');

	a_list tokens = make_list_from_matrix(arr);

	dollar_sign_resolver(tokens);

	if (!is_name(tokens->head->val))
	{
		__perror("export: not a valid identifier");
		return -1;
	}

	__unset__(tokens->head);

	string res = __make_string_from_list(tokens);

	push_back(shell->export, res);

	if (NULL != find_range(tokens, "=", list_value_same))
	{
		push_back(shell->env, res);

		if (0 == __strcmp(tokens->head->val, "PATH") && size(tokens) >= 3) shell->path = make_path(shell);
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
