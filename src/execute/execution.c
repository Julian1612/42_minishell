/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:13:09 by dgross            #+#    #+#             */
/*   Updated: 2022/11/26 01:23:51 by dna              ###   ########.fr       */
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
		// so gehts nicht weil ich = noch drin habe
		// gucken ob man einfach envp passen kann
		// dann kann man pipex lösung nehmen
		shell->path = ft_split(getenv("PATH"), ':');
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
			close(fd{1});
		}
	}
}

// nachmal gucken wir man das mit strncmp macht weil kannst auch 10000 leerzeichen haben und am ende pwd und es sollte funktionieren 
int ft_execute_builtins(t_koopa *shell)
{
	if (ft_strncmp(shell->cmd, "cd", /*infinit*/))
		ft_cd();
	else if (ft_strncmp(shell->cmd, "echo", /*infinit*/))
		ft_echo();
	else if (ft_strncmp(shell->cmd, "env", /*infinit*/))
		ft_env();
	else if (ft_strncmp(shell->cmd, "exit", /*infinit*/))
		ft_exit();
	else if (ft_strncmp(shell->cmd, "export", /*infinit*/))
		ft_export();
	else if (ft_strncmp(shell->cmd, "pwd", /*infinit*/))
		ft_pwd();
	else if (ft_strncmp(shell->cmd, "unset", /*infinit*/))
		ft_unset();	
}

int	ft_execute(t_koopa *shell)
{
	int tmp_fd;

	tmp_fd = dup(STDIN_FILENO);
	ft_redirection();
	if (/*check if cmd is a builtin*/)
		ft_execute_builtin(shell);
	else
		ft_execute_cmd(shell);
}
