/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:17:34 by ohassyao          #+#    #+#             */
/*   Updated: 2023/02/02 12:37:35 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

//int	g_last_exit_status = 0;
void	exect(t_prompt *prompt);

void	ft_free_all(t_prompt *prompt)
{
	t_env	*next;
	t_env	*current;

	current = prompt->env;
	while (current != NULL)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
	free(prompt->cmd);
	free(prompt->cmds);
}

void	ft_exit(t_prompt *prompt)
{
	ft_free_all(prompt);
	exit(0);
}

void	*pwdman(void *key, void *value, t_prompt *prompt)
{
	if (ft_strcmp(key, "PWD"))
	{
		if (ft_strcmp(value, getcwd(NULL, 0)))
			ft_printf("%s\n", value);
		else
		{
			prompt->env->value = getcwd(NULL, 0);
			ft_printf("%s\n", prompt->env->value);
		}
	}
	return (0);
}

void	ft_dquote(t_prompt *p)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		waitpid(pid, NULL, 0);
	else
	{
		p->pid = pid - 1;
		while ((p->cmd = readline("dquote> ")) != NULL)
		{
			add_history(p->cmd);
			p->cmds = ft_split(p->cmd, ' ');
			exect(p);
		}
	}
	return ;
}

void	exect(t_prompt *prompt)
{
	char	cwd[500];
	char	*home_dir;

	home_dir = getenv("HOME");
	if (prompt->cmd[0] == 0)
		return ((void)(1));
	if (ft_strcmp(prompt->cmds[0], "pwd"))
	{
		ft_enviter(prompt, pwdman);
		free(prompt->cmd);
	}
	else if (ft_strcmp(prompt->cmds[0], "cd")
		|| ft_strcmp(prompt->cmds[0], "\"cd\"")
		|| ft_strcmp(prompt->cmds[0], "\'cd\'"))
	{
		if (prompt->cmds[1] == 0)
		{
			if (chdir(home_dir) != 0)
				perror("cd");
		}
		else if (chdir(prompt->cmds[1]) != 0)
			perror("cd");
		free(prompt->cmd);
	}
	else if (ft_strcmp(prompt->cmds[0], "export"))
	{
		if (prompt->cmds[1] == NULL)
			ft_enviter(prompt, ft_export_print);
		else
			ft_export(prompt);
	}
	else if (ft_strcmp(prompt->cmds[0], "unset"))
	{
		if (prompt->cmds[1] == NULL)
			ft_error(1, "unset");
		else
			ft_unset(prompt);
	}
	else if (ft_strcmp(prompt->cmds[0], "echo"))
		ft_echo(prompt);
	else if (ft_strcmp(prompt->cmds[0], "exit"))
		ft_exit(prompt);
	else if (ft_strcmp(prompt->cmds[0], "env"))
		ft_enviter(prompt, ft_envprint);
	else
		ft_error(1, prompt->cmds[0]);
}

int	main(int argc, char **argv, char **env)
{
	t_prompt	prompt;
	// pid_t		pid;
	char		cwd[500];
	char		*home_dir;

	prompt = ft_init_prompt(argv, env);
	home_dir = getenv("HOME");
	// pid = fork();
	// if (pid == -1)
	// 	return (1);
	// if (pid == 0)
	// 	waitpid(pid, NULL, 0);
	// else
	// {
	// 	prompt.pid = pid - 1;
	// 	while (1)
	// 	{
	// 		// out = readline("minishell$ ");
	// 		prompt.cmd = readline("minishell$ ");
	// 		add_history(prompt.cmd);
	// 		// execve("/bin/bash", argv, env);
	// 		//prompt.cmds = ft_split(prompt.cmd, '"');
	// 		prompt.cmds = ft_split(prompt.cmd, ' ');
	// 		exect(&prompt);
	// 	}
	// }
	exit(0);
}

