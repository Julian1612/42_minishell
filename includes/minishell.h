/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:35 by dgross            #+#    #+#             */
/*   Updated: 2022/11/30 16:23:06 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "stdbool.h"

# define TRUE 1
# define FALSE 0

/// @brief cmd/builtin linked list
typedef struct s_data
{
	char			*cmd_name;
	char			**cmd_line;
	char			operator;
	bool			pipe;
	int				argc;
	struct s_data	*next;
}t_data;

/// @brief Main stuct
typedef struct s_koopa
{
	char		*line;
	int			exit_status;
	char		**envp;
	char		*file;
	t_data		*data;
}t_koopa;

////////////////////////////////////////
////////		BUILINTS		////////
////////////////////////////////////////

/// @brief		Change the shell working directory
/// @param shell Main struct
/// @param path directory to change to, otherwise change to HOME
/// @return Returns 0 if the directory is changed, non-zero otherwise
int		ft_cd(t_koopa *shell, char *path);
/// @brief		Display a line of text
/// @param shell Main struct
/// @param cmd_line the complete command
/// @return Returns success
int		ft_echo(t_koopa *shell, char **cmd_line);
/// @brief		Display the environment list
/// @param shell Main struct
/// @return Returns 0 on success, non-zero otherwise
int		ft_env(t_koopa *shell);
/// @brief		Exit the minishell
/// @param shell Main struct
void	ft_exit(t_koopa *shell);
/// @brief		Export variables to the environment list
/// @param shell Main struct
/// @param variable the variable to export
/// @return Returns 0 on success, non-zero otherwise
int		ft_export(t_koopa *shell, char *variable);
/// @brief		Print the name of the current working directory
/// @param nothing
/// @return Returns 0 unless the current directory cannot be read.
int		ft_pwd(void);
/// @brief		Unset variable of the enviroment list
/// @param shell Main struct
/// @param variable the variable to unset
/// @return Returns 0 on success, non-zero otherwise
int		ft_unset(t_koopa *shell, char *variable);

////////////////////////////////////////
////////		execution		////////
////////////////////////////////////////

/// @brief		Execute builtins
/// @param shell Main struct
/// @param data cmd/builtin struct to be executed
void	ft_execute_builtins(t_koopa *shell, t_data *data);
/// @brief		Execute command
/// @param shell Main struct
/// @param data cmd/builtin struct to be executed
void	ft_execute_cmd(t_koopa *shell, t_data *data);
/// @brief		Execute the command line
/// @param shell Main struct
/// @param data cmd/builtin struct to be executed
/// @return returns the last execution status
int		ft_execute(t_koopa *shell, t_data *data);
////////////////////////////////////////
////////		  UTILS  		////////
////////////////////////////////////////

/// @brief		Count the length of give variable name
/// @param variable the variable to count the length from
/// @return On Success it returns the length of the variable name,
/// if it isn't a variable it returns -1
int		ft_name_len(char *variable);
/// @brief Get an environment variable
/// @param shell Main struct
/// @param name the name of the variable to look for
/// @return On success it returns the variable, otherwise NULL
char	*ft_getenv(t_koopa *shell, char *name);
/// @brief Free's the enviroment pointer
/// @param shell Main struct
void	free_envp(t_koopa *shell);

#endif
