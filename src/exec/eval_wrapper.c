/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:39:26 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 17:23:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void eval_wrapper(t_command *cmd, t_eval_opcode opcode)
{
	set_descriptors(cmd);

	if (code_cd == opcode) __cd__(cmd);

	else if (code_echo == opcode) __echo__(cmd);

	else if (code_env == opcode) __env__(cmd);

	else if (code_export == opcode) __export__(cmd);

	else if (code_history == opcode) __history__(cmd);

	else if (code_pwd == opcode) __pwd__(cmd);

	else if (code_unset == opcode) __unset__(cmd);

	else if (code_program == opcode) __eval_prog__(cmd);

}
