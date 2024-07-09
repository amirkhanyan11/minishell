/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_desciptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:09:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 20:00:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_descriptor * __attribute__((warn_unused_result)) make_descriptors()
{
	t_descriptor *descriptor = __malloc(sizeof(t_descriptor));
	dup2(STDOUT_FILENO, descriptor->stdout);
	dup2(STDIN_FILENO, descriptor->stdin);
	dup2(STDERR_FILENO, descriptor->stderr);

	return descriptor;
}
