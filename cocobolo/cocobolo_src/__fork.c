/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:01:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 16:02:58 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <cocobolo.h>

pid_t __fork(void)
{
	pid_t pid = fork();

	if (-1 == pid) __exit("fork error");

	return pid;
}
