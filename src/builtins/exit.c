/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:43:52 by dgross            #+#    #+#             */
/*   Updated: 2022/11/24 15:13:31 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//kills the hole project
//just freeing everything and then exit
void	ft_exit(t_minishell *shell)
{
	exit(0); // exitstatus hab ich kp ob das immer 0 sein muss oder irgendwie 127 	
}
