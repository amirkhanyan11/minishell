/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_predicates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:41:51 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/24 18:08:11 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool is_alpha(const char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool is_digit(const char c)
{
    return (c >= '0' && c <= '9');
}

// bool is_var()