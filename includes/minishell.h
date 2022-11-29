/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:35 by dgross            #+#    #+#             */
/*   Updated: 2022/11/29 14:20:03 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# define TRUE 1
# define FALSE 0

typedef struct s_pipeline
{
	char	**path;
}t_pipeline;

typedef struct s_data
{
	char			*cmd;
	char			*flag;
	char			*arg;
	int				argc;
	struct s_data	*next;
}t_data;

typedef struct s_koopa
{
	char		*cmd_str;
	int			exit_status;
	char		**envp;
	t_data		*data;
	t_pipeline	*pipes;
}t_koopa;

// https://github.com/dqtvictory/42-Garbage-Collector/blob/main/DOCUMENTATIONS.md gucken ob wir das implementieren oder selber irgendwie her coden
// hab ne idee easy gc idee würde aber glaube sehr viel leistung ziehen weil nur am ende oder exit gefreed wird

/// @brief		Searches in envp the variable name and returns the variable string, 
///				otherwise returns NULL
/// @param shell main struct
/// @param name name of the variable
/// @return	variable string, else NULL if not found
char	*ft_getenv(t_koopa *shell, char *name);

////////////////////////////////////////
////////		BUILINTS		////////
////////////////////////////////////////

int		ft_cd(t_koopa *shell, t_data *data);
int		ft_echo(t_koopa *shell, t_data *data);
int		ft_env(t_koopa *shell);
void	ft_exit(t_koopa *shell);
int		ft_export(t_koopa *shell, t_data *data);
int		ft_pwd(void);
int		ft_unset(t_koopa *shell);

////////////////////////////////////////
////////		execution		////////
////////////////////////////////////////

int		ft_execute_builtins(t_koopa *shell, t_data *data);
int		ft_execute_cmd(t_koopa *shell);

////////////////////////////////////////
////////		  UTILS  		////////
////////////////////////////////////////

#endif
