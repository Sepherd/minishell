/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:02:42 by ohassyao          #+#    #+#             */
/*   Updated: 2023/01/17 17:34:39 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_init_vars(t_prompt *prompt, char *str, char **argv, char **env)
{
	int		mlen;
	char	**tmp;
	int		f;

	f = 0;
	mlen = ft_matrixlen(env);
	while (f < mlen)
	{
		tmp = ft_split(env[f], '=');
		ft_envcreate(tmp[0], tmp[0 + 1], prompt);
		f++;
	}
}

void	ft_getpid(t_prompt *p)
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		waitpid(pid, NULL, 0);
	else
	{
		p->pid = pid - 1;
		while (1)
		{
			p->cmd = readline("minishell$ ");
			get_input(p);
		}
	}
}

t_prompt	ft_init_prompt(char **argv, char **env)
{
	t_prompt	prompt;
	char		*str;

	str = NULL;
	prompt.cmds = NULL;
	ft_getpid(&prompt);
	ft_init_vars(&prompt, str, argv, env);
	return (prompt);
}
