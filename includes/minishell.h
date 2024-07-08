/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:12:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 22:35:45 by aamirkha         ###   ########.fr       */
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
	t_list		  *path;

	t_descriptor *sysdescriptors;
	t_descriptor *descriptors;
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
    t_matrix args;
};

// displays
void display_prompt();
void display_history(t_shell * shell);

//	reading input
char	*read_line(void);

// lifecycle
t_shell 	 *make_shell(char **env);
void 	 	 __t_shell__(t_shell **shellptr);
t_matrix 	 make_matrix_from_string(char *s, char c);
t_matrix 	 make_matrix_copy(t_matrix other);
t_command 	 *make_command(char * raw_cmd);
void 		 __t_command__(t_command **cmdptr);
t_descriptor *make_descriptors();

// builtins
void pwd(t_shell *shell __attribute__((unused)));
void export(t_shell *shell);





#endif // MINISHELL_H
