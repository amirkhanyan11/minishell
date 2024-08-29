/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:48:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/29 16:50:50 by marikhac         ###   ########.fr       */
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

vo sub_args(t_list *args, t_node *curr)
{
	t_list *dir = get_cwd_files();
	t_list *
	// write a substitution



}


void arg_eval(t_command *cmd, t_shell *shell)
{
	int i = 0;
	t_list *args = cmd->args;
	t_node *fake = args->head;
	// t_list *dir = get_cwd_files();

	t_list *res;
	t_list *tmp;

	while(fake)
	{
		res = find_if(fake, args->tail, is_wildcard);
		if(res != NULL)
		{
			sub_args(fake, dir);
			// append single result in res list
			// __strstr(args[i], );
		}
		i++;
		eval(args);
	}
}
