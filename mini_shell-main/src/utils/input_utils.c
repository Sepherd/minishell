/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:03:36 by arecce            #+#    #+#             */
/*   Updated: 2023/01/19 18:46:48 by arecce           ###   ########.fr       */
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
		if (str[i] == "\'")
			sgl++;
		else if (str[i] == "\"")
			dbl++;
		i++;
	}
	if ((dbl % 2 == 0 && sgl == 0) || (sgl % 2 == 0 && dbl == 0))
		return (1); //ignora le virgolette
	else if ((dbl % 2 == 0 && sgl == 1) || (sgl % 2 == 0 && dbl == 1))
		return (2); //quote position
	else if ((dbl == 1 && sgl == 0) || (dbl == 0 && sgl == 1))
		return (3); //dbquote
}
