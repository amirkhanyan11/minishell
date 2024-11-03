/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:21:35 by aamirkha          #+#    #+#             */
/*   Updated: 2024/11/03 16:15:13 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ast_adjust(t_ast *ast);

t_ast	*make_ast(char *line, t_shell *shell)
{
	t_list	*tokens;
	t_ast	*ast;
	t_cmd	**arr;
	int		i;

	tokens = preprocess(tokenize(line), shell);
	if (empty(tokens))
		return (NULL);
	ast = make_ast_skeleton(tokens, shell);
	arr = make_cmd_arr(tokens, shell);
	i = 0;
	while (arr[i])
		i++;
	i--;
	while (i >= 0)
		insert_cmd_node(ast, make_cmd_node(arr[i--]));
	ast_adjust(ast);
	ast_balance(ast, tokens);
	ast->last_process_cmd = find_last_process_cmd(ast->root);
	ast->last_cmd = find_last_cmd(ast);
	free(arr);
	list_clear(&tokens);
	return (ast);
}

static void	ast_adjust(t_ast *ast)
{
	t_ast_node	*node;

	node = ast->root;
	while (node && node->left)
	{
		if (node->type == REDIRECTION && node->left
			&& ((node->redirection_type & (redirect_heredoc | redirect_in)
					&& node->left->type == PIPE) || node->left->type == AND
				|| node->left->type == OR))
		{
			ast_rrotate(ast, node, node->left);
			node = node->p;
		}
		node = node->left;
	}
}
