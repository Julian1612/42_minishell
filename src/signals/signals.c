/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:35 by jschneid          #+#    #+#             */
/*   Updated: 2022/12/29 14:16:04 by dgross           ###   ########.fr       */
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

void	ft_signal_handler(int sig)
{
	if (sig == 2)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
}

void	ft_signal_heredoc(int sig)
{
	if (sig == 2)
	{
		close(STDIN_FILENO);
		write(1, "\n", 1);
		return ;
	}
}
