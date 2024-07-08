/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:43:01 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 15:46:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *read_line(void)
{
	display_prompt();
	return readline(NULL);
}
