/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:12:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 18:48:23 by aamirkha         ###   ########.fr       */
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
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>

# define declarex "declare -x "
# define heredoc  ".__heredoc__.txt"

typedef struct s_shell t_shell;
typedef struct s_command t_command;
typedef struct s_cmd_container t_cmd_container;
typedef struct s_descriptor t_descriptor;
typedef int	   t_file;

# define a_cmd_container t_cmd_container * __dtor(__t_cmd_container__)

enum e_
{
	in = 0,
	out = 1,
	redirect_in = 2,
	redirect_out = 4,
	redirect_heredoc = 8
};

struct s_shell
{
    t_list  	  *history;
    t_list  	  *env;
    t_list  	  *export;
	t_list		  *path;

	t_descriptor *stddesc;

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

	int 	redirection;
	t_descriptor *descriptors;

	bool resolved;
};

struct s_cmd_container
{
	t_command **arr;
	size_t size;
};

// displays
void display_prompt();
void display_history();

//	reading input
char	*read_line(void);

// execution
void 		 eval(t_cmd_container *cmds, size_t i);
void 		 eval_prog(t_file *pipe, t_cmd_container *cmds, size_t i);
void 		 set_descriptors(t_command * cmd);
void 		 reset_descriptors(t_command * cmd);

// execution helpers
int		    export_update(t_shell *shell, t_list_value key, t_list_value val);
char 		*get_value(t_list *list, char *target) __result_use_check;
void 		resolve(t_node *t, t_list *tokens);
char 		*get_key(t_list_value line)  __result_use_check;
int 		cmd_lookup(t_command *cmd);
t_file 		open_file(char *filenae, int options);
int 		redirect(t_node *token, t_command *cmd);

// parsing
t_list 		 *tokenize(char * raw_cmd) __result_use_check;
t_list 		 *preprocess(t_list *tokens) __result_use_check ;
void 		 dollar_sign_resolver(t_list *tokens);
int 		 redirection_resolver(t_list *tokens, t_command *cmd);

void 		 merge_tokens(t_list *tokens);
void 		 merge_redirections(t_list *tokens);


// find predicates
bool __contains_as_key__(char *line, char *target);
bool __cmd_exists__(t_list_value path, t_list_value name);

// name predicates
bool is_redirection(char * val);
bool is_name(char *s);
bool is_alpha(const char c);
bool is_digit(const char c);
bool is_name_part(const char c);

// lifecycle
t_list 		 *make_export(t_shell *shell) __result_use_check;
t_shell 	 *make_shell(char **env) __result_use_check;
void		 make_shlvl(t_shell *shell);
t_file		 make_heredoc(char *eof);
t_matrix 	 make_matrix_from_string(char *s, char *set) __result_use_check;
t_matrix 	 make_matrix_copy(t_matrix other) __result_use_check;
t_matrix  	 make_matrix_from_list(t_list *list)  __result_use_check;
t_cmd_container *make_cmd_container(char * raw_cmd) __result_use_check;
t_command 	 *make_command(t_list *tokens) __result_use_check;
t_list 		 *make_path(t_shell *shell) __result_use_check;
t_descriptor *make_descriptors() __result_use_check;
t_descriptor *make_stddesc() __result_use_check;
void 		 __t_command__(t_command **cmdptr);
void 	 	 __t_shell__(t_shell * shell);
void 		 __t_cmd_container__(t_cmd_container ** cmdsptr);

// builtins
void cd(t_command *cmd);
void pwd();
void env();
void unset(t_command *cmd);
void export(t_command *cmd);
void echo(t_command *cmd);

// other
int __export_from_string__(char *val);
char *  __pwd__() __result_use_check;
void __unset__(t_shell *shell, t_list_value val);

// signals
// void	set_signals_interactive(void);
// void	set_signals_noninteractive(void);

#endif // MINISHELL_H
