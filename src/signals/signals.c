/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:35 by jschneid          #+#    #+#             */
/*   Updated: 2023/01/06 10:47:46 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h> // write
#include <signal.h> // signal
#include <termios.h> // tcgetattr, tcsetattr

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

void	ft_signal_handler(int sig)
{
	if (sig == 2)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 1;
		return ;
	}
}

void	ft_signal_heredoc(int sig)
{
	if (sig == 2)
	{
		close(STDIN_FILENO);
		write(1, "\n", 1);
		g_exit_status = 1;
		return ;
	}
}
