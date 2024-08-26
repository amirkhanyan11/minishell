/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:48:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/26 17:30:49 by aamirkha         ###   ########.fr       */
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
