
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
	{
		printf("soos\n");
		*lst = list;
	}
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
	while (i != 6)
	{
		add_back(&data, ft_newlist());
		i++;
	}
	return (1);
}

static t_data	*ft_newlist(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->cmd_name = NULL;
	data->cmd_line = NULL;
	data->operator = 0;
	data->next = NULL;
	return (data);
}

static int put_input1(t_data *data)
{
	data->cmd_name = "ls";
	data->cmd_line = ft_split("ls -l", ' ');
	data->operator = PIPE;
	data = data->next;
	data->cmd_name = "cat";
	data->cmd_line = ft_split("cat -e", ' ');
	data->operator = CMD;
	data = data->next;
	data->cmd_name = "out";
	data->cmd_line = ft_split("out", ' ');
	data->operator = OUT;
	data = data->next;
	data->cmd_name = "out1";
	data->cmd_line = ft_split("out1", ' ');
	data->operator = OUT;
	data = data->next;
	data->cmd_name = "out2";
	data->cmd_line = ft_split("out2", ' ');
	data->operator = OUT;
	data = data->next;
	data->cmd_name = "out3";
	data->cmd_line = ft_split("out3", ' ');
	data->operator = OUT;
	data = data->next;
	data->cmd_name = "out4";
	data->cmd_line = ft_split("out4", ' ');
	data->operator = OUT;
	data = data->next;
	return (0);
}

//static int put_input2(t_data *data)
//{
//	data->cmd_name = "cd";
//	data->cmd_line = ft_split("cd src", ' ');
//	data->operator = CMD;
//	return (0);
//}

//static int put_input3(t_data *data)
//{
//	data->cmd_name = "cd";
//	data->cmd_line = ft_split("cd builtins", ' ');
//	data->operator = CMD;
//	return (0);
//}

//static int put_input4(t_data *data)
//{
//	data->cmd_name = "env";
//	data->cmd_line = ft_split("env", ' ');
//	data->operator = CMD;
//	return (0);
//}

// static int put_input4(t_data *data)
// {
// 	data->cmd_name = "out";
// 	data->cmd_line = ft_split("out", ' ');
// 	data->operator = OUT;
// 	return (0);
// }

int	main(int argc, char **argv, char **envp)
{
	t_koopa	*shell;
	t_data	*data;

	shell = ft_calloc(1, sizeof(t_koopa));
	data = ft_calloc(1, sizeof(t_data));
	init_envp(shell, envp);
	init_cmd(data);
	put_input1(data);
	ft_execute(shell, data);
	//printf("-----------------------------------------------------------\n");
	//put_input2(data);
	//ft_execute(shell, data);
	//printf("-----------------------------------------------------------\n");
	//put_input3(data);
	//ft_execute(shell, data);
	//printf("-----------------------------------------------------------\n");
	//put_input4(data);
	//ft_execute(shell, data);
	argc++;
	(void) argv;
	(void)envp;
	return (0);
}
