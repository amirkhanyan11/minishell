/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:19:00 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 21:14:41 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list * __result_use_check tokenize(char * raw_cmd)
{
	if (!raw_cmd) __exit("empty command");

	return make_list_from_string(raw_cmd, ' ', all);
}
