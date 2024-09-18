/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:12:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/18 22:46:03 by aamirkha         ###   ########.fr       */
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
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>

#ifdef __linux__
# include <bits/sigaction.h>
#endif // __linux__

# define DECLAREX "declare -x "
# define HEREDOC ".__heredoc__.txt"
# define SPECIAL_SYMBOLS "<>| \'\"()"
# define SELF_MERGEABLE_TOKENS "<>|"
# define PIPE_MAX 2
# define HEREDOC_MAX 16


# define LOG_SEPARATOR "\n\n\n-------------------------------------------------\n\n\n"

# define MINISHELL_PROMPT "\033[1;35m\e[3mminishell\033[1;32m > $ \033[0m"
// # define MINISHELL_PROMPT "\033[1;32m\e[3mmox\033[1;32m > $ \033[0m"

struct				s_shell
{
	t_tree			*env;
	t_tree			*export;
	t_list			*history;

	t_descriptor	*stddesc;
	t_cmd_container	*container;
	t_set			*quoted_tokens;

	t_fd			logfile;
	char			*prompt;
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
t_fd				open_file(char *filename, int options);
int					redirect(t_node *token, t_cmd_container *container);
void				eval_wrapper(t_command *cmd, t_eval_opcode opcode);

// find predicates
bool				__cmd_exists__(const char *path, const char *name);

// name predicates
bool				is_quote(char *s);
bool				is_single_redirection(char *val);
bool				is_redirection(const char *val);
bool				is_name(char *s);
bool				is_alpha(const char c);
bool				is_digit(const char c);
bool				is_name_part(const char c);
bool				not_name_part(char c);

bool				is_quoted_token(t_set *set, t_node *token);

// lifecycle
t_tree				*make_export(t_shell *shell)
					__attribute__((warn_unused_result));
t_shell				*make_shell(char **env) __attribute__((warn_unused_result));
void				make_shlvl(t_shell *shell);
t_fd				make_heredoc(char *eof, t_shell *shell,
						bool is_quoted) __attribute__((warn_unused_result));
t_list				*get_path(t_shell *shell)
					__attribute__((warn_unused_result));
t_descriptor		*make_descriptors(void) __attribute__((warn_unused_result));
t_descriptor		*make_stddesc(void) __attribute__((warn_unused_result));
void				__t_shell__(t_shell *shell);

t_fd 				make_logfile(t_shell *shell) __attribute__((warn_unused_result));

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
char				*_getcwd(t_shell *shell) __attribute__((warn_unused_result));
int					set_eval_to_prog_i_love_norminette(t_command *cmd);
int					__unset_var__(t_shell *shell, t_list_value val);
void				unset_var(t_shell *shell, t_list_value key);
void				set_exit_status(int status);
int					get_exit_status(void);
void				set_exit_status_no_of(int status);
int					invalid_option(t_command *cmd);

void				remove_spaces(t_shell *shell, t_list *tokens);

int					pipe_parse(t_list *tokens, t_shell *shell);
int					redirection_parse(t_list *tokens, t_shell *shell);
void				save_token(t_shell *shell, t_node *address);

// builtin utils
void				update_pwd(t_shell *shell, char *oldpwd);
void				__cd_one_arg__(t_command *cmd);
void				_chdir(t_command *cmd, const char *path, int *status);
void				__cd_no_arg__(t_command *cmd);
bool				last_nl(t_node *const node);
void				echo_arglist(t_list *arglist);
bool				not_n_predicate(char c);
bool				is_n(char *opt);
int					__export_from_string__(char *expr, t_shell *shell);
char				*get_pid(t_shell *shell)
					__attribute__((warn_unused_result));

// name_lookup utils
t_list				*get_cwd_files();
int					absolute_path_lookup(t_command *cmd);
int					quote_parse(t_list *tokens);
bool				not_space(t_node *node);
bool				is_redir(t_node *node);
void				erase_quotes(t_list *tokens);
bool				is_quote_node(t_node *const node);
void				mark_quoted_tokens(t_shell *shell, t_list *tokens);

// signals
void				set_signals_interactive(void);
void				set_signals_noninteractive(void);
void				disable_echoctl(void);
void				ignore_sigquit(void);
void				signal_print_newline(int __attribute__((unused)) signal);
void				signal_reset_prompt(int __attribute__((unused)) sig);

// wildcard
char				*contains_it(char *dirname, char *req);
char				*starts_with(char *dirname, char *req);
char				*ends_with(char *dirname, char *req);
t_list				*get_cwd_files(void);
void				wildcard_resolve(t_list *tokens, t_shell *shell);
void				substitute_args(t_node *wildcard_node, t_list *args, t_list *survived);

int					preprocess_redirections(t_list *tokens, t_cmd_container *container);
int					preprocess_redirections_the_good_part(t_cmd_container *container, t_list *tokens, t_node *token);

t_fd				get_next_fd(t_cmd_container *container);
size_t				get_next_fd_idx(t_cmd_container *container);

int					pop_redirections(t_command *cmd, t_list *tokens, t_cmd_container *container);
size_t				count_pipes(t_list *tokens, t_shell *shell);
t_node				*find_next_pipe(t_node *first, t_list *tokens, t_shell *shell);
int					parenthesis_parse(t_list *tokens);

bool				is_closing_parenthesis(const char * val);
bool				is_opening_parenthesis(const char * val);
bool				is_opening_parenthesis_node(t_node * const node);
bool				is_closing_parenthesis_node(t_node * const node);
void				subshell_eval(t_list *tokens, t_node *token, t_shell *shell);

#endif // MINISHELL_H

