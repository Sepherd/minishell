/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:54:42 by ohassyao          #+#    #+#             */
/*   Updated: 2023/01/15 11:34:44 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//da popolare man mano con gli errori
void	*ft_error(int error, char *str)
{
	if (error == 1)
		printf("\e[31mminishell\033[0m: %s: command not found\n", str);
	return (NULL);
}
