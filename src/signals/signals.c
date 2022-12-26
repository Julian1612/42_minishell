/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:35 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/26 21:50:45 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>

void	ft_terminal(int num)
{
	struct termios	settings;

	tcgetattr(STDIN_FILENO, &settings);
	if (num == 1)
	{
		settings.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &settings);
	}
	if (num == 0)
		tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

void	ft_signal_handler(int sig, siginfo_t *siginfo, void *ignore)
{
	(void) siginfo;
	(void) ignore;
	if (sig == 2)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
	else if (sig == 3)
		rl_redisplay();
}

void	ft_signal_heredoc(int sig, siginfo_t *siginfo, void *ignore)
{
	(void) siginfo;
	(void) ignore;
	if (sig == 2)
	{
		close(STDIN_FILENO);
		write(1, "\n", 1);
		return ;
	}
	else if (sig == 3)
		rl_redisplay();
}
