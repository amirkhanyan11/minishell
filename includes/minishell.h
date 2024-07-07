/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:12:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/07 23:07:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <cocobolo.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_shell t_shell;

struct s_shell
{
    t_list  *history;  
    t_list  *env;
};


// displays
void display_prompt();
void display_history(t_shell * shell);


// shell lifecycle
t_shell *make_shell(char **env);
void __t_shell__(t_shell **shellptr);


// builtins
void pwd(t_shell *shell __attribute__((unused)));






#endif // MINISHELL_H