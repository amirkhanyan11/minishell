/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:31:59 by aamirkha          #+#    #+#             */
/*   Updated: 2024/11/03 16:40:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ast_prehandle_cmd(t_ast_node *root, t_ast *ast, t_authorized_fds fds)
{
	t_ast_node	*par;
	bool		has_pipe_parent;
	int			x;

	par = root->p;
	has_pipe_parent = false;
	while (par)
	{
		if (par->type == PIPE)
		{
			has_pipe_parent = true;
			break ;
		}
		else if (par->type == OR || par->type == AND)
			break ;
		par = par->p;
	}
	if (!has_pipe_parent)
		wait(NULL);
	if (root->p && root->p->type != PIPE)
		set_descriptors(fds);
	x = (ast_handle_cmd(root));
	if (root->p && root->p->type != PIPE)
		reset_descriptors(ast->shell);
	return (x);
}

int	ast_handle_pipe(t_ast_node *root, t_ast *ast, t_authorized_fds fds)
{
	t_fd				pipes[PIPE_MAX];
	t_authorized_fds	new_fds;
	int					y;
	t_ast_node			*last;
	pid_t				x;

	if (pipe(pipes) == -1)
		return (killall(ast));
	dup2(pipes[out], STDOUT_FILENO);
	new_fds.stdin = fds.stdin;
	new_fds.stdout.fd = pipes[out];
	new_fds.stdout.author = root;
	eval_dfs(root->left, ast, new_fds);
	if (__that_damn_condition__(root))
		dup2(pipes[in], STDIN_FILENO);
	__va_close(&pipes[in], &pipes[out], NULL);
	dup2(fds.stdout.fd, STDOUT_FILENO);
	y = eval_dfs(root->right, ast, fds);
	last = find_last_process_cmd(root->right);
	if ((!root->p || root->p->type == AND || root->p->type == OR) && last)
	{
		waitcmd(last->cmd_ptr->pid, &x);
		return (!get_exit_status());
	}
	return (y);
}

int	ast_handle_cmd(t_ast_node *root)
{
	pid_t x;

	if (root->p && root->p->type == PIPE)
		root->cmd_ptr->forkable = true;
	cmd_runtime_init(root->cmd_ptr);
	root->cmd_ptr->eval(root->cmd_ptr);
	if ((!root->p || root->p->type == AND || root->p->type == OR)
		&& is_program(root->cmd_ptr))
	{
		x = 0;
		waitcmd(root->cmd_ptr->pid, &x);
	}
	return (!get_exit_status());
}
