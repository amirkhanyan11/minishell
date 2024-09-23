/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minishell_ast__.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:23 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 15:55:43 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHEL_AST___H
#define __MINISHEL_AST___H

#include "minishell.h"
#include "cocobolo.h"

typedef s_ast t_ast;
typedef s_ast_node t_ast_node;
typedef enum e_ast_node_type t_ast_node_type;

enum e_ast_node_type
{
	OR,
	AND,
	PIPE,
	CMD
};

struct s_ast
{
	t_node *root;
	t_shell *shell;
};

struct s_ast_node
{
	t_ast_node_type type;
	t_command 		*cmd_ptr;
	t_node 			*right;
	t_node 			*left;
	t_node 			*root;
};

#endif //__MINISHEL_AST___H
