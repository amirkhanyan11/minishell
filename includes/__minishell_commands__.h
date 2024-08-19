/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_commands__.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:04:32 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:42:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_COMMANDS___H
# define __MINISHELL_COMMANDS___H

# include "__minishell_typedefs__.h"
# include "minishell.h"
# include <cocobolo.h>

struct				s_command
{
	t_shell *shell					__attribute__((deprecated));
	char *name						__attribute__((deprecated));
	t_list *options					__attribute__((deprecated));
	t_list *args					__attribute__((deprecated));

	t_cmd_container *container		__attribute__((deprecated));

	t_eval eval						__attribute__((deprecated));

	int redirection					__attribute__((deprecated));
	t_descriptor *descriptors		__attribute__((deprecated));
};

struct				s_cmd_container
{
	t_shell			*shell;
	t_command		**arr;
	size_t			size;
	size_t			current_cmd_index;
};

t_command			*make_command(t_list *tokens, t_cmd_container *container,
						t_shell *shell) __attribute__((warn_unused_result));
t_cmd_container		*make_cmd_container(char *raw_cmd,
						t_shell *shell) __attribute__((warn_unused_result));
void				__t_command__(t_command **cmdptr);
void				__t_cmd_container__(t_cmd_container **cmdsptr);

#endif // __MINISHELL_COMMANDS___H
