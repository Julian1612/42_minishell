/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:04:24 by dgross            #+#    #+#             */
/*   Updated: 2022/11/26 15:27:42 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <unistd.h> // dup access fork
#include <stdlib.h> // 

// gucken ob es edgeses gibt mit getenv oder ob man einfach nur einmal am anfang envp in einen struct gibt
static void *get_path(t_koopa *shell)
{
	if (access(/*cmd path*/, F_OK) == -1)
	{
		// entwerder eine funktion schreiben die eine variable sucht und perfekt wieder gibt
		// ohne = also pur inhalt (wäre vllt gut für expansion)
		// oder pipex lösung
		shell->path = ft_split(/*envp*/, ':');
		if (shell->path == NULL)
		 	print_error();
		shell->file = create_path(shell, /*cmd*/);
		if (shell->file == NULL)
			printf_error();
	}
	else
		/*kommt drauf an wie der struct am ende aussieht
		entwerder return oder shell->file = cmd_path oder so*/
}

static char *create_path(t_koopa *shell, char *cmd)
{
	int i;

	i = -1;
	while (shell->path[++i])
	{
		shell->path[i] = ft_strjoin(shell->path[i], "/");
		shell->path[i] = ft_strjoin(shell->path[i], cmd);
		if (access(shell->path[i], F_OK) == 0)	
			return (shell->path[i]);
	}
	return (NULL);
}

// hier werden die cmd ausgeführt die keine builtins sind
// wenn eine | da ist wird gepiped 
// wie gesagt gucken ob man eine flag im struct hat oder manuell hier ist der funktion
// durch die cmd line geht die man durch den parser i guess bekommt
int ft_execute_cmd(t_koopa *shell)
{
	int fd[2];
	int	pid;

	while (/*kp später ändern :D sollange agrv nicht NULL ist oder so*/)
	{
		if (/*pipe flag oder string oder irgendwas zum checken ob man pipen muss*/)
			pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			get_path(shell);
			if (execve(shell->file, shell->cmd, shell->envp))
				printf_error();	
		}
		else
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
		}
	}
}