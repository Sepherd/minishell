/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:43:14 by ohassyao          #+#    #+#             */
/*   Updated: 2023/01/16 17:50:08 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_export_print(void *key, void *value, t_prompt *prompt)
{
	(void)prompt;
	printf("\033[32m declare -x %s\033[0m = \"%s\"\n", key, value);
	return (0);
}

void	ft_export(t_prompt *prompt)
{
	char	**tokens;

	tokens = ft_split(prompt->cmds[1], '=');
	if (tokens[1] == NULL)
	{
		ft_printf("Missing value for export. Usage: export VAR=value\n");
		return ;
	}
	ft_setenv(tokens[0], tokens[1], 1, &prompt->env);
}

void	*ft_envcreate(void *key, void *value, t_prompt *prompt)
{
	t_env	*tmp;

	tmp = (t_env *)malloc(sizeof(t_env));
	if (tmp == 0)
		return (0);
	tmp->key = key;
	tmp->value = value;
	ft_envadd_back(&prompt->env, tmp);
	return (0);
}

t_env	*ft_envlast(t_env *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_envadd_back(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (lst)
	{
		if (lst[0] == 0)
			lst[0] = new;
		else
		{
			temp = ft_envlast(lst[0]);
			temp->next = new;
		}
	}
}

void	ft_unset(t_prompt *prompt)
{
	char	*var_to_unset;

	var_to_unset = prompt->cmds[1];
	if (ft_unsetenv(var_to_unset, &prompt->env) == 0)
		ft_printf("Variable %s not found in environment\n", var_to_unset);
}
