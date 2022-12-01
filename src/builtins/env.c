/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:49 by dgross            #+#    #+#             */
/*   Updated: 2022/12/01 16:10:19 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	ft_env(t_koopa *shell)
{
	int	i;

	i = -1;
	while (shell->envp[++i] != NULL)
		printf("%s\n", shell->envp[i]);
	return (0);
}
