/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __perror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:56:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:31:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

#define __PROJECT_NAME__ "minishell: "

void	__perror(char *err)
{
	if (err)
	{
		write(STDERR_FILENO, __PROJECT_NAME__, __strlen(__PROJECT_NAME__));
		write(STDERR_FILENO, err, __strlen(err));
		write(STDERR_FILENO, "\n", 2);
	}
}
