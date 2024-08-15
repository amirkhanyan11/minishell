/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_commands__.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:04:32 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/15 19:23:09 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_COMMANDS___H
#define __MINISHELL_COMMANDS___H

#include "minishell.h"

struct s_command
{
    t_shell *shell;
	char 	*name;
	t_list  *options;
    t_list 	*args;

	t_cmd_container *container;

	t_eval 		eval;

	int 		 redirection;
	t_descriptor *descriptors;

};

struct s_cmd_container
{
	t_shell *shell;
	t_command **arr;
	size_t size;
	size_t current_cmd_index;
};

t_command 	 	*make_command(t_list *tokens, t_cmd_container *container, t_shell *shell) __result_use_check;
t_cmd_container *make_cmd_container(char * raw_cmd, t_shell *shell) __result_use_check;
void 			 __t_command__(t_command **cmdptr);
void 		 	__t_cmd_container__(t_cmd_container ** cmdsptr);

#endif // __MINISHELL_COMMANDS___H
