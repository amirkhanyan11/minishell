/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:19:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 18:47:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SIZE 4096

void __pwd__(t_command *cmd)
{
	eval_wrapper(cmd, _pwd);
}

void pwd(t_command *cmd)
{
	scoped_string path = _getcwd();

    printf ("%s\n", path);
}

char * _getcwd()
{
   	char * path = __malloc(SIZE + 1);
	getcwd(path, SIZE);
	return path;
}
