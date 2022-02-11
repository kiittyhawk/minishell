/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:29:50 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/11 16:35:42 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	**init_env()
{
	t_env	**tmp;

	tmp = (t_env **)malloc(sizeof(t_env *));
	if (!tmp)
	{
		exit(1);
	}
	return (tmp);
}

t_env	*init_elem(char *key, char *sep, char *val)
{
	t_env	*elem;

	elem = (t_env *)malloc(sizeof(t_env));
	if (!elem)
		return (NULL);
	elem->key = key;
	elem->sep = sep;
	elem->value = val;
	elem->pos = 0;
	elem->next = NULL;
	return (elem);
}

void	add_elem(t_env **head, t_env *elem)
{
	t_env	*tmp;

	tmp = *head;
	if (*head)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		*head = elem;
}

/*принимает строку и добавляет ее к структуре envp*/
void	add_env(char *env, t_env **envp)
{
	int		i;
	char	*key;
	char	*sep;
	char	*val;

	i = 0;
	sep = NULL;
	val = NULL;
	while (env[i] && (env[i] == '_' || ft_isalnum(env[i])))
	{
		i++;
	}
	key = ft_substr(env, 0, i);
	if (ft_strchr(env, '='))
	{
		sep = ft_substr(env, i, 1);
	}
	if (env[i + 1])
	{
		val = ft_strdup(&env[i + 1]);
	}
	add_elem(envp, init_elem(key, sep, val));
}

/*перебирает переменные окружения и передает их парсеру*/
void	parse_env(char **env, t_all *data)
{
	int	i;
	t_all	*tmp;

	i = -1;
	tmp = data;
	while (env[++i])
	{
		add_env(env[i], data->env);
		tmp = data;
	}
	data = tmp;
}

/*выводит все содержимое из структуры envp*/
void	print_env(t_env **data, char *flag)
{
	t_env	*elem;

	elem = *data;
	if (!strcmp(flag, "all"))
	{
		while (elem)
		{
			printf("%s %s %s\n", elem->key, elem->sep, elem->value);
			elem = elem->next;
		}
	}
	else
	{
		while (elem->next)
		{
			if (!strcmp(elem->key, flag))
			{
				printf("%s %s %s\n", elem->key, elem->sep, elem->value);
			}
			elem = elem->next;
		}
	}
}

void	increment(t_env *envp)
{
	int	lvl;

	lvl = ft_atoi(envp->value) + 1;
	free(envp->value);
	envp->value = ft_itoa(lvl);
}

/*когда мы запускаем свой баш в системной баше, shlvl должен инкрементироваться*/
void	shlvl_increment(t_env *envp)
{
	t_env	*env;

	env = envp;
	while (env)
	{
		if (!ft_strcmp(env->key, "SHLVL"))
		{
			increment(env);
			break ;
		}
		env = env->next;
	}
}

void	init_struct(t_all **data)
{
	(*data) = (t_all *)malloc(sizeof(t_all));
	if (!(*data))
		return ;
	(*data)->env = (t_env **)malloc(sizeof(t_env *));
	(*data)->cmd = NULL;
	(*data)->cmd_count = 0;
	(*data)->err = 0;
}

int	main(int ac, char **av, char **env)
{
	t_all	*data;
	char	*buf;
	(void)av;

	init_struct(&data);
	buf = NULL;
	if (ac != 1)
	{
		exit(0);
	}
	parse_env(env, data);
	shlvl_increment(*data->env);
	while (1)
	{
		rl_on_new_line();
		if (buf)
		{
			free(buf);
			buf = NULL;
		}
		buf = readline("minishell>");
		if (buf)
			add_history(buf);
		if (parser(buf, data) == 0)
		{
			executor();
		}
	}
}
