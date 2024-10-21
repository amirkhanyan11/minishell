/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:12:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 16:04:11 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "__minishell_commands__.h"
# include "__minishell_enums__.h"
# include "__minishell_ast__.h"
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

// # ifdef __linux__
// # include <bits/sigaction.h>
// # endif // __linux__

# define DECLAREX "declare -x "
# define HEREDOC ".__heredoc__.txt"
# define SPECIAL_SYMBOLS "<>| \'\"&()"
# define SELF_MERGEABLE_TOKENS "<>|"
# define PIPE_MAX 2
# define HEREDOC_MAX 16

# define MINISHELL_PROMPT "\033[1;35m\e[3mminishell\033[1;32m > $ \033[0m"

struct				s_shell
{
	t_tree			*env;
	t_tree			*export;

	t_descriptor	*stddesc;
	t_set			*quoted_tokens;
	t_set			*dollar_tokens;
	t_tree			*orig_values;

	t_ast			*ast;

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

void				__minishell__(int ac, char **av, char **env);

void				__redirect_out__(t_authorized_fds *newfds, t_ast_node *r);
void				__redirect_in__(t_authorized_fds *newfds, t_ast_node *r);
// execution
void				eval(t_cmd *cmd);
void				eval_prog_core(t_cmd *cmd);

// execution helpers
int					export_update(t_shell *shell, t_list_value key,
						t_list_value val);
char				*resolve(char *t_val,
						t_shell *shell) __attribute__((warn_unused_result));
int					cmd_lookup(t_cmd *cmd);
t_fd				open_file(char *filename, int options);
t_authorized_fds	redirect(t_ast_node *r, t_authorized_fds oldfds);

// find predicates
bool				__cmd_exists__(const char *path, const char *name);

int					killall(t_ast *ast);

// name predicates
bool				find_addr(t_set *set, t_listnode *token);
char				*get_orig_val(t_listnode *token, t_shell *shell);
void				save_orig_value(t_listnode *address, t_shell *shell);

int					process_infile(t_ast_node *r);
int					process_outfile(t_ast_node *r);
int					process_append(t_ast_node *r);
int					process_heredoc(t_ast_node *r, t_shell *shell);

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
void				__cmd_arr__(t_cmd **arr);

t_fd				make_logfile(t_shell *shell)
					__attribute__((warn_unused_result));
void				waitcmd(pid_t pid, int *x);

// builtins
void				cd(t_cmd *cmd);
void				pwd(t_cmd *cmd);
void				env(t_cmd *cmd);
void				unset(t_cmd *cmd);
void				export(t_cmd *cmd);
void				echo(t_cmd *cmd);
void				msh_exit(t_cmd *cmd);
void				errcmd(t_cmd *cmd);

void				eval_prog(t_cmd *cmd);

// other
char				*_getcwd(t_shell *shell)
					__attribute__((warn_unused_result));
int					set_eval_to_prog_i_love_norminette(t_cmd *cmd);
int					__unset_var__(t_shell *shell, t_list_value val);
void				unset_var(t_shell *shell, t_list_value key);
void				set_exit_status(int status);
int					get_exit_status(void);
void				set_exit_status_no_of(int status);
int					invalid_option(t_cmd *cmd);

void				remove_spaces(t_shell *shell, t_list *tokens);

bool				keyword_parse(t_list *tokens, t_shell *shell);
bool				redirection_parse(t_list *tokens, t_shell *shell);
void				save_token(t_set *set, t_listnode *address);
void				recover_variables(t_list *tokens, t_shell *shell);

// builtin utils
void				builtin_preeval(t_cmd *cmd);

void				update_pwd(t_shell *shell, char *oldpwd);
void				__cd_one_arg__(t_cmd *cmd);
void				_chdir(t_cmd *cmd, const char *path, int *status);
void				__cd_no_arg__(t_cmd *cmd);
bool				last_nl(t_listnode *const node);
void				echo_arglist(t_list *arglist);
bool				not_n_predicate(char c);
bool				is_n(char *opt);
int					__export_from_string__(char *expr, t_shell *shell);
char				*get_pid(t_shell *shell)
					__attribute__((warn_unused_result));

// name_lookup utils
t_list				*get_cwd_files(void);
int					absolute_path_lookup(t_cmd *cmd);
int					quote_parse(t_list *tokens);
bool				not_space(t_listnode *node);

void				erase_quotes(t_list *tokens);
void				mark_quoted_tokens(t_shell *shell, t_list *tokens);

// signals
void				signals_enable(void);
void				signals_disable(void);
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
void				substitute_args(t_listnode *wildcard_node, t_list *args,
						t_list *survived);

int					pop_redirections(t_list *partition, t_shell *shell);
bool				parenthesis_parse(t_list *tokens, t_shell *shell);

bool				syntax_analysis(t_list *tokens, t_shell *shell);

t_list				*make_partition(t_shell *shell, t_listnode *first,
						t_listnode *last) __attribute__((warn_unused_result));
t_cmd				**make_cmd_arr(t_list *tokens, t_shell *shell)
					__attribute__((warn_unused_result));

// list extensions
size_t				shcount_if(t_listnode *first, t_listnode *last,
						bool (*p)(t_listnode *, t_shell *), t_shell *shell);
size_t				shremove_if(t_list *list,
						bool (*p)(t_listnode *, t_shell *), t_shell *shell);
t_listnode			*shfind_if(t_listnode *first, t_listnode *last,
						bool (*p)(t_listnode *, t_shell*), t_shell *shell);
t_listnode			*shrfind_if(t_listnode *first, t_listnode *last,
						bool (*p)(t_listnode *, t_shell*), t_shell *shell);

#endif // MINISHELL_H
