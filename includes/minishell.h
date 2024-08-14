/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:12:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/14 21:20:25 by aamirkha         ###   ########.fr       */
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

# include "__minishell_typedefs__.h"
# include "__minishell_commands__.h"
# include "__minishell_enums__.h"
# include "__minishell_lexer__.h"

# define declarex "declare -x "
# define heredoc  ".__heredoc__.txt"
# define special_symbols "<>| \'\""
# define self_mergeable_tokens "<>|"
# define PIPE_MAX 2

# define minishell_prompt PURPLE ITALIC_ON"minishell" GREEN " > $ " RESET


# define scoped_cmd_container t_cmd_container * __dtor(__t_cmd_container__)

struct s_shell
{
    t_tree  	  *env;
    t_tree  	  *export;
    t_list  	  *history;

	t_descriptor  	*stddesc;
	t_cmd_container *container;

	int			 status;
};

struct s_descriptor
{
	t_fd stdout;
	t_fd stdin;
	t_fd stderr;
};

//	reading input
char	*read_line(char *);

// execution
void 		 eval(t_cmd_container *cmds);
void 		 set_descriptors(t_command * cmd);
void 		 reset_descriptors(t_command * cmd);
void 		 eval_prog(t_command *cmd);
// void 		 __eval_prog__deprecated__(t_fd *pipe, t_command * cmd);

// execution helpers
int		    export_update(t_shell *shell, t_list_value key, t_list_value val);
char 		*resolve(char *t_val, t_shell *shell) __result_use_check;
int 		cmd_lookup(t_command *cmd);
t_fd 		open_file(char *filenae, int options);
int 		redirect(t_node *token, t_command *cmd);
void 		eval_wrapper(t_command *cmd, t_eval_opcode opcode);

// find predicates
bool __cmd_exists__(t_list_value path, t_list_value name);

// name predicates
bool is_quote(char *s);
bool is_single_redirection(char * val);
bool is_redirection(char * val);
bool is_name(char *s);
bool is_alpha(const char c);
bool is_digit(const char c);
bool is_name_part(const char c);

// lifecycle
t_tree		 *make_export(t_shell *shell) __result_use_check;
t_shell 	 *make_shell(char **env) __result_use_check;
void		 make_shlvl(t_shell *shell);
t_fd		 make_heredoc(char *eof, t_shell *shell) __result_use_check;
t_list 		 *get_path(t_shell *shell) __result_use_check;
t_descriptor *make_descriptors() __result_use_check;
t_descriptor *make_stddesc() __result_use_check;
void 	 	 __t_shell__(t_shell * shell);

// matrix


// builtins
void cd(t_command *cmd);
void pwd(t_command *cmd);
void env(t_command *cmd);
void unset(t_command *cmd);
void export(t_command *cmd);
void echo(t_command *cmd);
void history(t_command *cmd);
void msh_exit(t_command *cmd);

void __cd__(t_command *cmd);
void __pwd__(t_command *cmd);
void __env__(t_command *cmd);
void __unset__(t_command *cmd);
void __export__(t_command *cmd);
void __echo__(t_command *cmd);
void __history__(t_command *cmd);
void __eval_prog__(t_command *cmd);
void __exit__(t_command *cmd);

// other
static int __export_from_string__(char *expr, t_shell *shell);
char *  _getcwd() __result_use_check;
int 	unset_var(t_shell *shell, t_list_value val);
void 	set_exit_status(int status);
void __exit_nb__(const int status, char * err) __dead2;
int invalid_option(t_command *cmd);

int pipe_parse(t_list *tokens);
int redirection_parse(t_list *tokens);

// signals
void	set_signals_interactive(void);
void	set_signals_noninteractive(void);

#endif // MINISHELL_H
