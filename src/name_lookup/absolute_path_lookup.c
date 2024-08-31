/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path_lookup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:44:46 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/31 20:08:26 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	absolute_path_lookup(t_command *cmd)
{
	DIR				*dir;
	struct dirent	*dp;

	char * pathname = __strdup(cmd->name);

	char *t = pathname + __strlen(pathname) - 1;
	char * filename = NULL;

	while (t != pathname && *t != '/') t--;

	if (t != pathname)
	{
		if (t == pathname + __strlen(pathname) - 1)
		{
			*t = '\0';
			filename = __strdup(pathname);
		}
		else
			filename = __strdup(t + 1);
		*t = '\0';
	}

	if (t == pathname || string_equal(pathname, filename))
	{
		filename = __strdup(pathname);
		free(pathname);
		pathname = __strdup(".");
	}

	dir = opendir(pathname);
	if (dir == NULL)
		return (-1);
	dp = readdir(dir);
	while (dp != NULL && !string_equal(dp->d_name, filename))
		dp = readdir(dir);

	if (dp->d_type == DT_DIR)
	{
		__va_perror(cmd->name, ": is a directory", NULL);
		set_exit_status(126);
	}
	else if (cmd->name[__strlen(cmd->name) - 1] == '/')
	{
		__va_perror(cmd->name, ": Not a directory", NULL);
		set_exit_status(126);
	}

	else
	{
		if (0 == access(cmd->name, F_OK | X_OK))
			return (set_eval_to_prog_i_love_norminette(cmd));
		if (0 == access(cmd->name, F_OK))
			__va_perror(cmd->name, ": Permission denied", NULL);
		else
			__va_perror(cmd->name, ": No such file or directory", NULL);
	}

	closedir(dir);
	__delete_string(&filename);
	__delete_string(&pathname);
	return (-1);
}
