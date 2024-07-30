/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:50:12 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 14:34:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// void	disable_echoctl(void)
// {
// 	struct termios	term;

// 	if (tcgetattr(STDIN_FILENO, &term) != 0)
// 		return ;
// 	term.c_lflag &= ~(ECHOCTL);
// 	tcsetattr(STDIN_FILENO, TCSANOW, &term);
// }

// void	signal_print_newline(int signal)
// {
// 	(void)signal;
// 	write(1, "\n", 1);
// 	rl_on_new_line();
// }

// void	ignore_sigquit(void)
// {
// 	struct sigaction	act;

// 	memset(&act, 0, sizeof(act));
// 	act.sa_handler = SIG_IGN;
// 	sigaction(SIGQUIT, &act, NULL);
// }

// void	signal_reset_prompt(int sig)
// {
// 	(void)sig;
// 	write(1, "\n", 1);
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// }

// void	set_signals_interactive(void)
// {
// 	struct sigaction	act;

// 	ignore_sigquit();
// 	memset(&act, 0, sizeof(act));
// 	act.sa_handler = &signal_reset_prompt;
// 	sigemptyset(&act.sa_mask);
// 	act.sa_flags = SA_RESTART;
// 	sigaction(SIGINT, &act, NULL);
// 	disable_echoctl();
// }

// void	set_signals_noninteractive(void)
// {
// 	struct sigaction	act;

// 	memset(&act, 0, sizeof(act));
// 	act.sa_handler = &signal_print_newline;
// 	sigemptyset(&act.sa_mask);
// 	act.sa_flags = SA_RESTART;
// 	sigaction(SIGINT, &act, NULL);
// 	sigaction(SIGQUIT, &act, NULL);
// 	disable_echoctl();
// }
