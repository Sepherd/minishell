/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:35:52 by ohassyao          #+#    #+#             */
/*   Updated: 2023/01/16 11:00:34 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_enviter(t_prompt *prompt, void *f(void *, void *, t_prompt *))
{
	t_env	*head;

	head = prompt->env;
	while (prompt->env != NULL)
	{
		f(prompt->env->key, prompt->env->value, prompt);
		prompt->env = prompt->env->next;
	}
	prompt->env = head;
}

void	*ft_envprint(void *key, void *value, t_prompt *prompt)
{
	(void)prompt;
	printf("\033[32m%s\033[0m = %s\n", key, value);
	return (0);
}

int	ft_setenv(const char *name, const char *val, int rep, t_env **env)
{
	t_env	*current;
	t_env	*prev;
	t_env	*new_env;

	current = *env;
	prev = NULL;
	while (current != NULL)
	{
		if (strcmp(current->key, name) == 0)
		{
			if (rep)
			{
				free(current->value);
				current->value = strdup(val);
				return (0);
			}
			else
				return (1);
		}
		prev = current;
		current = current->next;
	}
	new_env = (t_env *)malloc(sizeof(t_env));
	new_env->key = strdup(name);
	new_env->value = strdup(val);
	new_env->next = *env;
	*env = new_env;
	return (0);
}

int	ft_unsetenv(const char *name, t_env **env)
{
	t_env	*current;
	t_env	*prev;

	current = *env;
	prev = NULL;
	while (current != NULL)
	{
		if (strcmp(current->key, name) == 0)
		{
			if (prev == NULL)
				*env = current->next;
			else
				prev->next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}
