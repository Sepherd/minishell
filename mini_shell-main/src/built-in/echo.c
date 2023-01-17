/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:31:09 by ohassyao          #+#    #+#             */
/*   Updated: 2023/01/16 19:22:58 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_containdollaro(char *parolina)
{
	int	i;

	i = 0;
	while (parolina[i] != 0)
	{
		if (parolina[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void	ft_ohassyao(void *key, void *value, t_prompt *prompt)
{
	if (ft_strcmp(key, prompt->tmp))
		ft_printf("%s", prompt->env->value);
}

void	ft_mardolin(t_prompt *p, char *parolina, int parlen)
{
	int	i;

	i = 0;
	p->tmp = (char *)malloc(parlen + 1);
	while (i < parlen)
	{
		p->tmp[i] = parolina[p->tmppos++];
		i++;
	}
	p->tmp[i] = 0;
	ft_enviter(p, ft_ohassyao);
	free(p->tmp);
}

void	ft_mtoia(t_prompt *p, char *parolina)
{
	int		j;

	p->tmppos = 0;
	while (parolina[p->tmppos] != 0)
	{
		if (parolina[p->tmppos] == '$')
		{
			if (parolina[++p->tmppos] == '\0')
				ft_printf("%c", parolina[p->tmppos - 1]);
			else
			{
				j = ft_strlen(parolina);
				ft_mardolin(p, parolina, j);
			}
		}
		else
			ft_printf("%c", parolina[p->tmppos++]);
	}
}

void	ft_echo(t_prompt *prompt)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (prompt->cmds[i])
	{
		if (prompt->cmds[i][0] == '-' && prompt->cmds[i][1] == 'n')
			newline = 0;
		else if (prompt->cmds[i][0] == '$' && prompt->cmds[i][1] == '$')
		{
			printf("%d\n", prompt->pid);
			newline = 0;
		}
		else if (ft_containdollaro(prompt->cmds[i]))
			ft_mtoia(prompt, prompt->cmds[i]);
		else
			ft_printf("%s ", prompt->cmds[i]);
		i++;
	}
	if (newline)
		ft_printf("\n");
}
