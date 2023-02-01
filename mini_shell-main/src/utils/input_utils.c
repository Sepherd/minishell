/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:03:36 by arecce            #+#    #+#             */
/*   Updated: 2023/02/01 19:16:26 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	str_isalpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

// int	quote_position(char	*str, char c, char d) // verifica se la prima quote e l'ultima sono dello stesso tipo
// {
// 	int	i;
// 	int	k;
// 	int	t;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 		{
// 			while (str[++i])
// 			{
// 				if (str[i] == d)
// 					k = i;
// 				if (str[i] == c)
// 					t = i;
// 			}
// 		}
// 		i++;
// 	}
// 	if (t < k)
// 		return (0);
// 	return (1);
// }

int	count_quotes(char *str)
{
	int	i;
	int	dbl;
	int	sgl;

	i = 0;
	dbl = 0;
	sgl = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			sgl++;
		else if (str[i] == '\"')
			dbl++;
		i++;
	}
	if ((dbl % 2 == 0 && sgl == 0) || (sgl % 2 == 0 && dbl == 0))
		return (1);
	else if (dbl % 2 != 0 || sgl % 2 != 0)
		return (0);
}	
