/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:12:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 21:04:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <cocobolo.h>
# include <stdio.h>
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
};

// displays
void display_prompt();
void display_history(t_shell * shell);

//	reading input
char	*read_line(void);

// execution
t_list 		 *tokenize(char * raw_cmd) __attribute__((warn_unused_result));
t_list 		 *preprocess(t_list *tokens, t_shell * shell) __attribute__((warn_unused_result)) ;

// execution helpers
char 		*pick(t_list *list, char *target) __attribute__((warn_unused_result));
void 		resolve(t_node *token, t_shell *shell);

// lifecycle
t_list 		 *make_export(t_shell *shell) __attribute__((warn_unused_result));
t_shell 	 *make_shell(char **env) __attribute__((warn_unused_result));
t_matrix 	 make_matrix_from_string(char *s, char c) __attribute__((warn_unused_result));
t_matrix 	 make_matrix_copy(t_matrix other) __attribute__((warn_unused_result));
t_command 	 *make_command(char * raw_cmd, t_shell * shell) __attribute__((warn_unused_result));
t_list 		 *make_path(t_shell *shell) __attribute__((warn_unused_result));
t_descriptor *make_descriptors() __attribute__((warn_unused_result));
void 	 	 __t_shell__(t_shell **shellptr);
void 		 __t_command__(t_command **cmdptr);

// builtins
void pwd(t_shell *shell __attribute__((unused)));
void export(t_shell *shell);
void echo(t_command *cmd);





#endif // MINISHELL_H
