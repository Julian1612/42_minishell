/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:35 by dgross            #+#    #+#             */
/*   Updated: 2022/11/27 10:30:31 by dna              ###   ########.fr       */
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
	char 	**path;
	char	*file;
	char	*cmd;
	char	**cmd_str;
	char	*flag;
	int		exit_status;
	char	**envp;
	char	*new_var;
}t_koopa;

// https://github.com/dqtvictory/42-Garbage-Collector/blob/main/DOCUMENTATIONS.md gucken ob wir das implementieren oder selber irgendwie her coden
// hab ne idee easy gc idee würde aber glaube sehr viel leistung ziehen weil nur am ende oder exit gefreed wird

#endif
