/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:48:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/30 20:20:15 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_cwd_files(void)
{
	DIR				*dir;
	struct dirent	*dp;
	t_list			*res;

	res = make_list();
	dir = opendir(".");
	if (dir == NULL)
		return (NULL);
	dp = readdir(dir);
	while (dp != NULL)
	{
		push_back(res, dp->d_name, NULL);
		dp = readdir(dir);
	}
	closedir(dir);
	return (res);
}

void substitute_args(t_node *wildcard_node, t_list *args)
{
	t_list *dir = get_cwd_files();
	t_node *w_node = dir->tail;
	while(w_node)
	{
		list_insert(args, wildcard_node, w_node->val);
		w_node = w_node->prev;

	}
	list_clear(&dir);
}

void arg_eval(t_command *cmd)
{
	int i = 0;
	t_node *wild = cmd->args->head;

	wild = find_if(cmd->args->head, cmd->args->tail, is_wildcard);

	while(wild)
	{
		t_node *save = wild->next;
		substitute_args(wild, cmd->args);
		pop(cmd->args, wild);
		wild = save;
		wild = find_if(wild, cmd->args->tail, is_wildcard);
	}
}
