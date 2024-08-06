/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell__commands.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:04:32 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 19:05:28 by aamirkha         ###   ########.fr       */
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

	int 	redirection;
	t_descriptor *descriptors;

};

struct s_cmd_container
{
	t_command **arr;
	size_t size;
	size_t current_cmd_index;
};




#endif // __MINISHELL_COMMANDS___H
