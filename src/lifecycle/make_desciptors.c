/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_desciptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:09:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 16:45:52 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_descriptor * __result_use_check make_descriptors()
{
	static int __fd = 999;
	t_descriptor *descriptor = __malloc(sizeof(t_descriptor));
	descriptor->stdout = ++__fd;
	descriptor->stdin = ++__fd;
	descriptor->stderr = ++__fd;


	return descriptor;
}

t_descriptor * __result_use_check make_stddesc()
{
	t_descriptor *res = make_descriptors();
	res->stdout = dup(STDOUT_FILENO);
	res->stdin =  dup(STDIN_FILENO);
	res->stderr = dup(STDERR_FILENO);


	return res;
}