/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:35 by dgross            #+#    #+#             */
/*   Updated: 2022/11/24 15:46:54 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define True 1
# define False 0

#include "libft.h"
/// @brief Main struct for Minishell
typedef struct s_koopa
{
	char	*str;
	int 	argc;
	char	**cmd_str;
	char	*flag;
	int		exit_status;
	char	**envp;
}t_koopa;


#endif
