/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:01:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:28:28 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t	__fork(void)
{
	pid_t	pid;

	pid = fork();
	if (-1 == pid)
		__exit("fork error");
	return (pid);
}
