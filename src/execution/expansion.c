/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dna <dna@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:36:52 by dgross            #+#    #+#             */
/*   Updated: 2022/12/11 09:18:45 by dna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// remove quots
// variable expansion
// tilde expansion
// substitution

// static void	remove_quots(t_data *data)
// {
// 	// neue struct erstellen
// 	// typ ermitteln
// 	// und ' " entfernen
// }

// int	ft_expand(t_koopa *shell, t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (data != NULL)
// 	{
// 		//remove quots
// 		while (data->cmd_line != NULL)
// 		{
// 			if (data->cmd_line[i][j] == '\"' || data->cmd_line[i][j] == '\'')
// 				remove_quots();
// 		}
// 		//replace $
// 		data = data->next;
// 	}
// 	return (0);
// }
