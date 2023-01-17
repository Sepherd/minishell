/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:06:10 by ohassyao          #+#    #+#             */
/*   Updated: 2023/01/16 11:01:33 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *out, char *str)
{
	int	i;
	int	lenout;
	int	lenstr;

	i = 0;
	lenstr = ft_strlen(str);
	lenout = ft_strlen(out);
	if (lenout != lenstr)
		return (0);
	while (i < lenout)
	{
		if (out[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}







