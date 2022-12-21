/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:35 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/21 15:46:45 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>

void	ft_set_termianl(void)
{
	struct termios	new_settings;

	if (tcgetattr(STDIN_FILENO, &new_settings))
	{
		if(isatty(STDIN_FILENO) == 1)
			printf("kekw\n");
	}
	new_settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &new_settings))
	{
		//kp einfach nichts oder so kp
	}
}

void	ft_signal_handler(int sig, siginfo_t *siginfo, void *ignore)
{
	(void) siginfo;
	(void) ignore;
	if (sig == 2)
	{
		write(1, "\n", 2);
		rl_on_new_line();
		rl_clear_history();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
	else if (sig == 3)
		rl_redisplay();
}
