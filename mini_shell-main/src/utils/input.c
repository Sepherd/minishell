/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:05 by arecce            #+#    #+#             */
/*   Updated: 2023/01/18 18:53:40 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_input(t_prompt *p)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (str_isalpha(p->cmd))
		p->cmds = ft_split(p->cmd, ' ');
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
 