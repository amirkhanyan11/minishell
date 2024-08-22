/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:40:09 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 20:14:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_shlvl(t_shell *shell)
{
	t_treeval	shlvl_old;
	t_optional	lvl;
	char		*shlvl;

	shlvl_old = get_val(shell->export, "SHLVL");
	lvl = __atoi(shlvl_old);
	shlvl = __itoa(value_or(&lvl, 0) + 1);
	export_update(shell, "SHLVL", shlvl);
	__delete_string(&shlvl);
}
