/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:40:09 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 01:51:52 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void make_shlvl(t_shell *shell)
{
    string shlvl_old = get_value(shell->export, "SHLVL");

	t_optional lvl = __atoi(shlvl_old);

	string shlvl = __itoa(value_or(&lvl, 0) + 1);

	export_update(shell, "SHLVL", shlvl);
}
