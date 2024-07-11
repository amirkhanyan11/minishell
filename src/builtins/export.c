/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:13:48 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 21:35:06 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

static void __print_export__(t_node *head);

static int __export_arg_resolver__(t_node *arg)
{
	if (!arg || !arg->val) return -1;

	t_matrix __dtor(__matrix_clear) arr = __split_include_delimiters(arg->val, '=');

	t_list * __dtor(list_clear) tokens = make_list_from_matrix(arr);

	dollar_sign_resolver(tokens);


	if (tokens->head->val[0] >= '0' && '9' >= tokens->head->val[0])
	{
		__perror("./minishell: export: not a valid identifier");
		return -1;
	}

	__unset__(tokens->head);

	char * __dtor(__delete_string) res = __make_string_from_list(tokens);

	push_back(shell->export, res);

	if (NULL != find(tokens, "=", list_value_same)) push_back(shell->env, res);

	return 0;
}

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
		__export_arg_resolver__(arg);
		arg = arg->next;
	}

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
