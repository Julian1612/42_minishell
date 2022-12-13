/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:35 by dgross            #+#    #+#             */
/*   Updated: 2022/12/12 19:13:06 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "stdbool.h"
# include <signal.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define CMD 0
# define PIPE 1
# define IN 2
# define OUT 3
# define APPEND 4
# define HEREDOC 5
# define EXPAND 6
# define SKIP 7

typedef struct s_exp
{
	char	*line;
	int		quote_typ;
	int		status;
}			t_exp;

/// @brief cmd/builtin linked list
typedef struct	s_data
{
	char			*cmd_name;	// Name of the function (example: echo)
	char			**cmd_line;	// The function with argument (example: 'echo' 'hallo')
	int				operator;	// Specifies the following operator (example: | or < or > or << or >>)
	struct s_data	*next;
}				t_data;

/// @brief Main stuct
typedef struct s_koopa
{
	int			fd[2];
	char		*line;
	int			exit_status;
	char		**envp;
	char		*file;
	int			in;
	int			out;
	int 		stdout1;
	char		**path;
	int			tmp_fd;
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
/// @param cmd_line the complete command
/// @return Returns success
int		ft_echo(char **cmd_line);
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
/// @return On success return 0, otherwise non-zero
int		ft_execute_builtin(t_koopa *shell, t_data *data);
/// @brief		Execute command
/// @param shell Main struct
/// @param data cmd/builtin struct to be executed
void	ft_execute_cmd(t_koopa *shell, t_data *data);
/// @brief		Execute the command line
/// @param shell Main struct
/// @param data cmd/builtin struct to be executed
/// @return returns the last execution status
int		ft_execute(t_koopa *shell, t_data *data);
/// @brief
/// @param shell
/// @param data
void	ft_redirection(t_koopa *shell, t_data *data);
void	write_to(t_koopa *shell, t_data *data);
void	ft_cmd(t_koopa *shell, t_data *data);
int		ft_expand(t_koopa *shell, t_data *data);
int		ft_heredoc(t_koopa *shell, t_data *data);
int		ft_isspace(int c);
void	init_exp(t_exp *exp, t_data *data);
char	*double_to_str(t_data *data);
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
void	free_double(char **double_pointer);

////////////////////////////////////////
////////		 SIGNALS  		////////
////////////////////////////////////////

/// @brief Handles siganls in the programm
/// @param sig
/// @param siginfo
/// @param ignore
void	ft_signal_handler(int sig, siginfo_t *siginfo, void *ignore);

/// @brief
/// @param
void	ft_set_termianl(void);

////////////////////////////////////////
////////		 LEXER	 		////////
////////////////////////////////////////

char	**tokenizer(char *str);
int		token_counter(char *str);
void	skip_opperator(char *str, int *i, int *counter);
void	skip_flags(char *str, int *i, int *counter);
void	skip_qoutes(char *str, int *i, int *counter);
void	skip_sqoutes(char *str, int *i, int *counter);
void	skip_dqoutes(char *str, int *i, int *counter);
void	skip_backslash(char *str, int *i, int *counter);
void	skip_nbrs(char *str, int *i, int *counter);
void	skip_whitespace(char *str, int *i);
void	skip_str(char *str, int *i, int *counter);
int		counter_str_len(char *str, int *j);
int		counter_flag_len(char *str, int *j);
int		counter_opp_len(char *str, int *j);
int		counter_nbrs_len(char *str, int *i);
int		get_token_length(char *str, int *j);
int		counter_dqoutes_len(char *str, int *j);
void	cpy_token(char *str, char *token_arr, int token_len, int start_copy);
int		counter_sqoutes_len(char *str, int *j);
int		counter_quote_len(char *str, int *j);
int		init_arr(char **token_arr, char *str, int *j, int *i);

////////////////////////////////////////
////////		PARSER	 		////////
////////////////////////////////////////

t_data	*parser(char **token_arr);
void	init_node_null(t_data *node);
void	init_list(t_data *head, char **token_arr);
t_data	*create_list(const int nbr_cmd);
int		cmd_counter(char **token_arr);
t_data	*create_list(const int nbr_cmd);
void	init_node_null(t_data *node);
t_data	*create_head(void);

#endif
