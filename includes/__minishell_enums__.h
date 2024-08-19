/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_enums__.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:00:33 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:22:36 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_ENUMS___H
# define __MINISHELL_ENUMS___H

enum	e_rdr
{
	in = 0,
	out = 1,
	redirect_in = 2,
	redirect_out = 4,
	redirect_heredoc = 8
};

enum	e_eval_opcode
{
	_cd,
	_echo,
	_env,
	_export,
	_history,
	_pwd,
	_unset,
	_program,
	_msh_exit
};

#endif // __MINISHELL_ENUMS___H
