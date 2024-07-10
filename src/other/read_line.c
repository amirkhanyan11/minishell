/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:43:01 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 15:22:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define prompt PURPLE ITALIC_ON"minishell" GREEN " > $ " RESET

char *read_line(void)
{
	return readline(prompt);
}
