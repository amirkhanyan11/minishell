/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_vol_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:53:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/01 01:25:01 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_signals_interactive(void)
{
	struct sigaction	act;

	ignore_sigquit();
	__memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_reset_prompt;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaction(SIGINT, &act, NULL);
	disable_echoctl();
}

void	set_signals_noninteractive(void)
{
	struct sigaction	act;

	__memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_print_newline;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	disable_echoctl();
}