/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:12:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 20:04:37 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <cocobolo.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_shell t_shell;
typedef struct s_command t_command;
typedef struct s_descriptor t_descriptor;
typedef int	   t_file;

struct s_shell
{
    t_list  	  *history;
    t_list  	  *env;
    t_list  	  *export;
	t_list		  *path;

	t_descriptor *sysdescriptors;
	t_descriptor *descriptors;

	int			 status;
};

struct s_descriptor
{
	t_file stdout;
	t_file stdin;
	t_file stderr;
};

struct s_command
{
    t_shell *shell;
	char 	*name;
	t_list  *options;
    t_list 	*args;

	bool resolved;
};

// displays
void display_prompt();
void display_history();

//	reading input
char	*read_line(void);

// execution
void 	     eval(t_command *cmd, char **env);

// execution helpers
char 		*get_value(t_list *list, char *target) __result_use_check;
void 		resolve(t_node *token, t_shell *shell);
char 		*get_key(t_list_value line)  __result_use_check;
void 		cmd_lookup(t_command *cmd);

// parsing
t_list 		 *tokenize(char * raw_cmd) __result_use_check;
t_list 		 *preprocess(t_list *tokens, t_shell * shell) __result_use_check ;

// lifecycle
t_list 		 *make_export(t_shell *shell) __result_use_check;
t_shell 	 *make_shell(char **env) __result_use_check;
t_matrix 	 make_matrix_from_string(char *s, char c) __result_use_check;
t_matrix 	 make_matrix_copy(t_matrix other) __result_use_check;
t_matrix  	 make_matrix_from_list(t_list *list)  __result_use_check;
t_command 	 *make_command(char * raw_cmd, t_shell * shell) __result_use_check;
t_list 		 *make_path(t_shell *shell) __result_use_check;
t_descriptor *make_descriptors() __result_use_check;
void 	 	 __t_shell__(t_shell **shellptr)  __attribute__((destructor));
void 		 __t_command__(t_command **cmdptr);

// builtins
void pwd();
void export();
void echo(t_command *cmd);





#endif // MINISHELL_H
