/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:19:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:49:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SIZE 4096

void pwd(t_command *cmd)
{
	scoped_string path = __pwd__();

    printf ("%s\n", path);
}

char * __pwd__()
{
   	char * path = __malloc(SIZE + 1);
	getcwd(path, SIZE);
	return path;
}
