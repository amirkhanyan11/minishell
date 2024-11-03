/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:43:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/11/03 16:40:08 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ast_eval(t_ast *ast)
{
	t_authorized_fds	fds;

	if (!ast)
		return ;
	fds.stdin.fd = ast->shell->stddesc->stdin;
	fds.stdin.author = NULL;
	fds.stdout.fd = ast->shell->stddesc->stdout;
	fds.stdout.author = NULL;
	eval_dfs(ast->root, ast, fds);
	while (-1 != wait(NULL))
		;
	dup2(ast->shell->stddesc->stdin, STDIN_FILENO);
	dup2(ast->shell->stddesc->stdout, STDOUT_FILENO);
	dup2(ast->shell->stddesc->stderr, STDERR_FILENO);
	if (0 == access(HEREDOC, F_OK))
		unlink(HEREDOC);
}

int	eval_dfs(t_ast_node *root, t_ast *ast, t_authorized_fds fds)
{
	t_authorized_fds	newfds;

	if (!root)
		return (1);
	if (root->type == AND)
		return (eval_dfs(root->left, ast, fds) && eval_dfs(root->right, ast, fds));
	else if (root->type == OR)
		return (eval_dfs(root->left, ast, fds) || eval_dfs(root->right, ast, fds));
	else if (root->type == PIPE)
		return (ast_handle_pipe(root, ast, fds));
	else if (root->type == CMD)
		return (ast_prehandle_cmd(root, ast, fds));
	else
	{
		newfds = redirect(root, fds);
		if (newfds.stdin.fd != -1 && newfds.stdout.fd != -1)
			return (eval_dfs(root->left, ast, newfds));
		return (1);
	}
}


bool	__that_damn_condition__(t_ast_node *root)
{
	return (!root->p || root->p->type != REDIRECTION
		|| root->p->redirection_type != redirect_in);
}
