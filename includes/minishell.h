/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:39:39 by dgross            #+#    #+#             */
/*   Updated: 2023/01/06 13:46:32 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE 1
# define FALSE -1
# define ERROR -1

# define CMD 0
# define PIPE 1
# define IN 2
# define OUT 3
# define APPEND 4
# define HEREDOC 5
# define CHILD 6
# define BUILTIN 7

////---------GLOBAL---------//
int	g_exit_status;

typedef struct s_exp
{
	char	*line;
	int		squo;
	int		dquo;
	int		len;
	int		content_len;
}			t_exp;

typedef struct s_data
{
	char			*cmd_name;
	char			**cmd_line;
	int				operator;
	struct s_data	*next;
}				t_data;

/// @brief Main stuct
typedef struct s_koopa
{
	t_data		*head;
	char		**envp;
	char		**path;
	char		*line;
	char		*file;
	int			fd[2];
	int			exit_code;
	int			tmp_stdout;
	int			tmp_stdin;
	int			redirect;
	int			skip;
	int			out;
	int			in;
	int			exit;
}t_koopa;

void	list_test(t_data *cmd_list);
////////////////////////////////////////
////////		BUILINTS		////////
////////////////////////////////////////

void	ft_exit(t_koopa *shell, char **cmd_line);
int		ft_cd(t_koopa *shell, char **path);
int		ft_echo(char **cmd_line);
int		ft_env(t_koopa *shell);
int		ft_export(t_koopa *shell, char **cmd_line);
int		ft_pwd(void);
int		ft_unset(t_koopa *shell, char **cmd_line);

////////////////////////////////////////
////////		execution		////////
////////////////////////////////////////

void	ft_execute_cmd(t_koopa *shell, t_data *data);
void	write_to(t_koopa *shell, t_data *data);
void	ft_cmd(t_koopa *shell, t_data *data);
void	pipe_cmd(t_koopa *shell, t_data *data);
char	*double_to_str(t_data *data);
char	*get_variable(t_exp *exp, int *idx);
int		ft_execute_builtin(t_koopa *shell, t_data *data);
int		ft_execute(t_koopa *shell, t_data *data);
int		ft_expand(t_koopa *shell, t_data *data);
int		ft_is_end(int c);
int		init_exp(t_exp *exp, t_data *data);
int		replace(t_data *data, t_exp *exp);
int		ft_check_char(int c);
void	get_exit_status(t_koopa *shell);
void	handle_null(t_koopa *shell, t_data *data);
int		ft_isspace(int c);

////////////////////////////////////////
////////		  HEREDOC  		////////
////////////////////////////////////////

int		ft_heredoc(t_koopa *shell, t_data *data);
char	*ft_expand_heredoc(t_koopa *shell, char *heredoc);

////////////////////////////////////////
////////	  REDIRECTION  		////////
////////////////////////////////////////

int		ft_redirection(t_koopa *shell, t_data *data);
int		check_for_heredoc(t_koopa *shell, t_data *tabel);
int		reset_redir(t_koopa *shell, t_data *data);

////////////////////////////////////////
////////		  UTILS  		////////
////////////////////////////////////////

char	**ft_arrdup(char **old);
void	free_double(char **double_pointer);
char	*ft_getenv(t_koopa *shell, char *name);
int		ft_name_len(char *variable);
char	*ft_addchar(char *str, char c);

////////////////////////////////////////
////////		 SIGNALS  		////////
////////////////////////////////////////

void	ft_signal_handler(int sig);
void	ft_signal_heredoc(int sig);
void	ft_terminal(int num);
void	ft_signals(void);

////////////////////////////////////////
////////		 ERROR	 		////////
////////////////////////////////////////

int		print_error(char *failed_cmd, char	*failed_arg, char *reason);
int		garbage_bin(char *cmd);
void	check_typ_of_error(char	*cmd);

////////////////////////////////////////
////////		 FREE	 		////////
////////////////////////////////////////

void	free_data(t_data *head);
void	free_shell(t_koopa *head);

////////////////////////////////////////
////////		 LEXER	 		////////
////////////////////////////////////////

char	**tokenizer(char *str);
int		token_counter(char *str);
void	skip_opperator(char *str, int *i, int *counter);
void	skip_nbrs(char *str, int *i, int *counter);
void	skip_whitespace(char *str, int *i);
void	skip_str(char *str, int *i, int *counter);
void	skip_qoutes(char *str, int *i, int *counter);
int		str_len_counter(char *str, int *j);
int		opp_len_counter(char *str, int *j);
int		nbr_len_counter(char *str, int *i);
int		get_token_length(char *str, int *j);
void	cpy_token(char *str, char *token_arr, int token_len, int start_copy);
int		quote_len_counter(char *str, int *j);
int		init_arr(char **token_arr, char *str, int *j, int *i);
int		ft_check_after(int c);

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
int		count_cmd(char **token_arr, int i);
void	init_node_null(t_data *node);
void	arr_test(char **arr);

#endif
