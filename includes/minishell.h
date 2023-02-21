/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:39:39 by dgross            #+#    #+#             */
/*   Updated: 2023/02/21 09:49:08 by dna              ###   ########.fr       */
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
	int				redir;
	struct s_data	*next;
}				t_data;

typedef struct s_koopa
{
	t_data		*head;
	char		**envp;
	char		**path;
	char		*line;
	char		*file;
	int			inter;
	int			fd[2];
	int			exit_code;
	int			tmp_stdout;
	int			tmp_stdin;
	int			redirect;
	int			skip;
	int			out;
	int			in;
	int			heredoc_file;
	int			exit;
	int			nbr;
}t_koopa;

////////////////////////////////////////
////////		BUILTINS		////////
////////////////////////////////////////

void	ft_exit(t_koopa *shell, char **cmd_line, int print);
int		ft_cd(t_koopa *shell, t_data *data, char **path);
int		ft_echo(char **cmd_line);
int		ft_env(t_koopa *shell);
int		ft_export(t_koopa *shell, char **cmd_line);
int		ft_pwd(void);
int		ft_unset(t_koopa *shell, char **cmd_line);
char	**to_double(char *str);

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
char	*take_var_name(int i, int offset, t_exp *exp);
int		ft_append_outfile(t_koopa *shell, t_data *data);
int		ft_redirect_heredoc(t_koopa *shell);
int		ft_redirect_outfile(t_koopa *shell, t_data *data);
int		ft_redirect_infile(t_koopa *shell, t_data *data);
void	close_fd(t_koopa *shell);
void	close_pipe(t_koopa *shell);
void	open_pipe(t_koopa *shell);
int		is_builtin(t_data *data);
////////////////////////////////////////
////////		  HEREDOC  		////////
////////////////////////////////////////

int		ft_heredoc(t_koopa *shell, t_data *data);
char	*ft_expand_heredoc(t_koopa *shell, char *heredoc);
void	count_pipes(t_koopa *shell, t_data *table);
////////////////////////////////////////
////////	  REDIRECTION  		////////
////////////////////////////////////////

int		ft_redirection(t_koopa *shell, t_data *data);
int		check_for_heredoc(t_koopa *shell, t_data *table);
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
void	skip_operator(char *str, int *i, int *counter);
void	skip_nbrs(char *str, int *i, int *counter);
void	skip_whitespace(char *str, int *i);
void	skip_str(char *str, int *i, int *counter);
void	skip_quotes(char *str, int *i, int *counter);
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

//parser
t_data	*parser(char **token_arr);
int		append_node(t_data **head, char **token_arr, int *i,
			int (*init)(t_data *, char **, int *));
t_data	*create_node(char **token_arr, int *i,
			int (*init)(t_data *, char **, int *));
int		init_content(t_data *node, char **token_arr, int *i);
int		redir_check(char **token_arr, int i);

// redir_handler
int		handle_redir(t_data *node, char **token_arr, int *i);
int		init_redir(t_data *node, char **token_arr, int *i);
int		init_data(t_data *node, char **token_arr, int *i);
int		init_null(t_data *node, char **token_arr, int *i);

// command_handler
int		handle_cmd(t_data *node, char **token_arr, int *i);
int		get_op(char **token_arr, int i);
int		count_cmd(char **token_arr, int i);

// command_counter
int		c_cmd(t_data **node, char **token_arr, int i);
int		append_redir(t_data **head, char **token_arr,
			int *i, int (*init)(t_data *, char **, int *));

// inittialize_command.c
int		init_cmd(t_data *node, char **token_arr, int *i);
int		init_cmd_line(t_data *node, char **token_arr, int *i, int num_cmd);
int		get_pipe_nbr(char **token_arr, int i);

////////////////////////////////////////
////////		SYNTAX	 		////////
////////////////////////////////////////

void	choose_error(int error_code);
int		catch_one(char **token_arr, int arr_len);
int		catch_two(char **token_arr, int i);
int		syntax_check(char **token_arr);
#endif
