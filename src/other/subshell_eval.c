/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_eval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:32:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/18 23:28:30 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define SUBSHELL_FILE "./src/subshell/.__subshell__file.txt"

void subshell_eval(t_list *tokens, t_node *token, t_shell *shell)
{
	if (!tokens || !token || !shell)
		return ;

	t_fd		pid;
	t_fd		fd;
	t_matrix	t_env;
	char		*cmd[3];

	cmd[0] = "./src/subshell/subshell";
	cmd[1] = __strtrim(token->val, "$(");
	cmd[1][__strlen(cmd[1]) - 1] = '\0';
	cmd[2] = NULL;
	t_env = NULL;
	pid = __fork();

	fd = open_file(SUBSHELL_FILE, O_CREAT | O_RDWR | O_TRUNC);
	if (pid == 0)
	{
		t_env = make_matrix_from_tree(shell->env);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		execve(cmd[0], cmd, t_env);
		list_clear(&tokens);
		__t_shell__(shell);
		matrix_clear(&t_env);
		__delete_string(&cmd[1]);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	matrix_clear(&t_env);

	char *line = get_next_line(fd);
	__delete_string(&token->val);
	token->val = __make_string_empty();
	while (line)
	{
		token->val = __strappend(token->val, line, NULL);
		__delete_string(&line);
		line = get_next_line(fd);
	}
	token->val[__strlen(token->val) - 1] = '\0';
	__delete_string(&line);
	__delete_string(&cmd[1]);
	get_next_line(-1);
	close(fd);
	unlink(SUBSHELL_FILE);
}
