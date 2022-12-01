#include "minishell.h"
#include <stdio.h>
#include <stdlib.h> // malloc

static t_data	*ft_newlist(void);

static t_data	*lastnode(t_data *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	init_envp(t_koopa *shell, char **envp)
{
	int					i;

	i = -1;
	shell->envp = ft_calloc(ft_ptrcnt(envp) + 1, sizeof(char *));
	if (shell->envp == NULL)
		return (-1);
	while (envp[++i] != NULL)
		shell->envp[i] = ft_strdup(envp[i]);
	shell->envp[i] = NULL;
	return (0);
}

static void	add_back(t_data **lst, t_data *list)
{
	t_data	*b;

	b = NULL;
	if (*lst == NULL)
		*lst = list;
	else
	{
		b = lastnode(*lst);
		b->next = list;
	}
}

static int	init_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		add_back(&data, ft_newlist());
		i++;
	}
	return (1);
}

static t_data	*ft_newlist(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->cmd_name = NULL;
	data->cmd_line = NULL;
	data->operator = 0;
	data->pipe = false;
	data->argc = 0;
	data->next = NULL;
	return (data);
}

static int put_input(t_data *data)
{
	data->cmd_name = NULL;
	data->cmd_line = ft_split("Makefile", ' ');
	data->operator = '<';
	data->pipe = false;
	data->argc = 1;
	data = data->next;
	data->cmd_name = "cat";
	data->cmd_line = ft_split("cat", ' ');
	data->operator = '|';
	data->pipe = true;
	data->argc = 1;
	data = data->next;
	data->cmd_name = "grep";
	data->cmd_line = ft_split("grep @", ' ');
	data->operator = 9;
	data->pipe = true;
	data->argc = 1;
	data = data->next;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_koopa	*shell;
	t_data	*data;

	shell = malloc(sizeof(t_koopa));
	data = malloc(sizeof(t_data));
	init_envp(shell, envp);
	init_cmd(data);
	put_input(data);
	ft_execute(shell, data);
	argc = 0;
	argv = NULL;
	envp = NULL;
	return (0);
}

//< Makefile cat | grep @ > out