/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:15:20 by ohassyao          #+#    #+#             */
/*   Updated: 2023/01/17 19:15:06 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define CD "'cd'"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_prompt
{
	pid_t			pid;
	t_env			*env;
	char			*cmd;
	char			*tmp;
	int				tmppos;
	char			**cmds;
	int				infile;
	int				outfile;
	int				errfile;
}			t_prompt;

enum	e_errors
{
	comnotfound = 1
};

/* Initialize prompt struct after the start*/
t_prompt	ft_init_prompt(char **argv, char **env);
void		ft_init_vars(t_prompt *prompt, char *str, char **argv, char **env);

// built-in
void		*ft_export_print(void *key, void *value, t_prompt *prompt);
void		ft_export(t_prompt *prompt);
void		*ft_envcreate(void *key, void *value, t_prompt *prompt);
t_env		*ft_envlast(t_env *lst);
void		ft_envadd_back(t_env **lst, t_env *new);
void		ft_enviter(t_prompt *prompt, void *f(void *, void *, t_prompt *));
void		*ft_envprint(void *key, void *value, t_prompt *prompt);
void		ft_unset(t_prompt *prompt);
void		ft_echo(t_prompt *prompt);
void		ft_dquote(t_prompt *p);
int			ft_setenv(const char *name, const char *val, int rep, t_env **env);
int			ft_unsetenv(const char *name, t_env **env);
void		get_input(t_prompt *p);
int			str_isalpha(t_prompt *p);

// utils
int			ft_strcmp(char *out, char *str);
void		ft_exit(t_prompt *prompt);

/* Prints a custom error message to standard error */
void		*ft_error(int error, char *str);

/* Get pid information */
void		ft_getpid(t_prompt *p);

//cimitero
//char		*ft_getenv(t_prompt *prompt, char *var);
#endif
