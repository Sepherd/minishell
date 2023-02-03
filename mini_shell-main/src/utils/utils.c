/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:06:10 by ohassyao          #+#    #+#             */
/*   Updated: 2023/02/02 12:39:03 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *out, char *str)
{
	int	i;
	int	k;
	// int	lenout;
	// int	lenstr;

	i = 0;
	k = 0;
	// lenstr = ft_strlen(str);
	// lenout = ft_strlen(out);
	// if (lenout != lenstr)
	// 	return (0);
	while (out[i])
	{
		if (out[i] == '\'' || out[i] == '\"')
		{
			i++;
			continue ;
		}
		else if (out[i] != str[k])
			return (0);
		i++;
		k++;
	}
	return (1);
}
