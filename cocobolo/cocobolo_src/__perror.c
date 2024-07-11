/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __perror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:56:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 17:57:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void __perror(char * err)
{
	if (err)
	{
		write(STDERR_FILENO, err, __strlen(err));
		write(STDERR_FILENO, "\n", 2);
	}
}
