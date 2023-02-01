/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:05 by arecce            #+#    #+#             */
/*   Updated: 2023/02/01 19:21:50 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_input(t_prompt *p)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	//if (str_isalpha(p->cmd))
	p->cmds = ft_split(p->cmd, ' ');
	while (p->cmds[i])
	{
		if (!count_quotes(p->cmds[i]))
		{
			printf("ERROR! At least one pending quote.\n");
			break ;
		}
		i++;
	}
	p->cmds[0] = ft_strtrim(p->cmds[0], "\"\'");
}

void	get_input(t_prompt *p)
{
	if (ft_strlen(p->cmd) != 0)
	{
		add_history(p->cmd);
		split_input(p);
		// p->cmds = ft_split(p->cmd, ' ');
		exect(p);
	}
}
 