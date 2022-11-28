/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:35 by dgross            #+#    #+#             */
/*   Updated: 2022/11/28 15:45:14 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define True 1
# define False 0

#include "libft.h"
/// @brief Main struct for Minishell
typedef struct s_test
{
	int key;
}t_test;
typedef struct s_koopa
{
	char	*str;
	int 	argc;
	char 	**path;
	char	*file;
	char	*cmd;
	char	**cmd_str;
	char	*flag;
	int		exit_status;
	char	**envp;
	char	*var;
	t_test	*egal;
}t_koopa;

// https://github.com/dqtvictory/42-Garbage-Collector/blob/main/DOCUMENTATIONS.md gucken ob wir das implementieren oder selber irgendwie her coden
// hab ne idee easy gc idee würde aber glaube sehr viel leistung ziehen weil nur am ende oder exit gefreed wird

/// @brief		Searches in envp the variable name and returns the variable string, otherwise returns NULL
/// @param shell main struct
/// @param name name of the variable
/// @return	variable string, else NULL if not found
char	*ft_getenv(t_koopa *shell, char *name);

////////////////////////////////////////
////////		BUILINTS		////////
////////////////////////////////////////

int		ft_cd(t_koopa *shell);
int		ft_echo(t_koopa *shell);
int		ft_env(t_koopa *shell);
void	ft_exit(t_koopa *shell);
int		ft_export(t_koopa *shell);
int		ft_pwd(t_koopa *shell);
int		ft_unset(t_koopa *shell);

////////////////////////////////////////
////////		execution		////////
////////////////////////////////////////

////////////////////////////////////////
////////		  UTILS  		////////
////////////////////////////////////////


#endif
