/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __perror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:56:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 15:02:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

#define __project_name__ "minishell: "

void __perror(char * err)
{
	if (err)
	{
		write(STDERR_FILENO, __project_name__, __strlen(__project_name__));
		write(STDERR_FILENO, err, __strlen(err));
		write(STDERR_FILENO, "\n", 2);
	}
}
