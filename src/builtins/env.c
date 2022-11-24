/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:49 by dgross            #+#    #+#             */
/*   Updated: 2022/11/24 15:52:50 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_koopa *shell)
{
	int i;

	i = 0;
	while (shell->envp[i] != NULL)
	{
		printf("%s\n", shell->envp[i]);
		i++;
	}
	return (0); // ! exit status ! 
}
