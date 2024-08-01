/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:11:19 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 21:51:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void display_prompt()
{
    // printf(ITALIC_ON PURPLE"minishell"GREEN  " $ > " RESET ITALIC_OFF);
    printc("minishell", __italic__, __purple__);
    printc(" $ > ", __italic__, __green__);
}
