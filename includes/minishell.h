/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:12:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:50:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "__minishell_commands__.h"
# include "__minishell_enums__.h"
# include "__minishell_lexer__.h"
# include "__minishell_typedefs__.h"
# include <cocobolo.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>

# define DECLAREX "declare -x "
# define HEREDOC ".__heredoc__.txt"
# define SPECIAL_SYMBOLS "<>| \'\""
# define SELF_MERGEABLE_TOKENS "<>|"
# define PIPE_MAX 2

# define MINISHELL_PROMPT "\033[1;35m\e[3mminishell\033[1;32m > $ \033[0m"

struct				s_shell
{
	t_tree			*env;
	t_tree			*export;
	t_list			*history;

	t_descriptor	*stddesc;
	t_cmd_container	*container;

	int				status;
};

struct				s_descriptor
{
	t_fd			stdout;
	t_fd			stdin;
	t_fd			stderr;
};

//	reading input
char				*read_line(char *s);

// execution
void				eval(t_cmd_container *cmds);
void				set_descriptors(t_command *cmd);
void				reset_descriptors(t_command *cmd);
void				eval_prog(t_command *cmd);
// void 			__eval_prog__deprecated__(t_fd *pipe, t_command * cmd);

// execution helpers
int					export_update(t_shell *shell, t_list_value key,
						t_list_value val);
char				*resolve(char *t_val,
						t_shell *shell) __attribute__((warn_unused_result));
int					cmd_lookup(t_command *cmd);
t_fd				open_file(char *filenae, int options);
int					redirect(t_node *token, t_command *cmd);
void				eval_wrapper(t_command *cmd, t_eval_opcode opcode);

// find predicates
bool				__cmd_exists__(t_list_value path, t_list_value name);

// name predicates
bool				is_quote(char *s);
bool				is_single_redirection(char *val);
bool				is_redirection(char *val);
bool				is_name(char *s);
bool				is_alpha(const char c);
bool				is_digit(const char c);
bool				is_name_part(const char c);

// lifecycle
t_tree				*make_export(t_shell *shell)
					__attribute__((warn_unused_result));
t_shell				*make_shell(char **env) __attribute__((warn_unused_result));
void				make_shlvl(t_shell *shell);
t_fd				make_heredoc(char *eof,
						t_shell *shell) __attribute__((warn_unused_result));
t_list				*get_path(t_shell *shell)
					__attribute__((warn_unused_result));
t_descriptor		*make_descriptors(void) __attribute__((warn_unused_result));
t_descriptor		*make_stddesc(void) __attribute__((warn_unused_result));
void				__t_shell__(t_shell *shell);

// matrix

// builtins
void				cd(t_command *cmd);
void				pwd(t_command *cmd);
void				env(t_command *cmd);
void				unset(t_command *cmd);
void				export(t_command *cmd);
void				echo(t_command *cmd);
void				history(t_command *cmd);
void				msh_exit(t_command *cmd);

void				__cd__(t_command *cmd);
void				__pwd__(t_command *cmd);
void				__env__(t_command *cmd);
void				__unset__(t_command *cmd);
void				__export__(t_command *cmd);
void				__echo__(t_command *cmd);
void				__history__(t_command *cmd);
void				__eval_prog__(t_command *cmd);
void				__exit__(t_command *cmd);

// other
static int			__export_from_string__(char *expr, t_shell *shell);
char				*_getcwd(void) __attribute__((warn_unused_result));
int					unset_var(t_shell *shell, t_list_value val);
void				set_exit_status(int status);
void				__exit_nb__(const int status,
						char *err) __attribute__((noreturn));
int					invalid_option(t_command *cmd);

int					pipe_parse(t_list *tokens);
int					redirection_parse(t_list *tokens);

// signals
void				set_signals_interactive(void);
void				set_signals_noninteractive(void);

#endif // MINISHELL_H
