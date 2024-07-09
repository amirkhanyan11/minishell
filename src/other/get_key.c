/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:44:02 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 21:49:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char * __attribute__((warn_unused_result)) get_key(t_list_value line)
{
	size_t offset = __strlen("declare -x ");

	return __strdup_until(line + offset, '=');
}
