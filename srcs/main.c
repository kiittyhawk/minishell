/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:29:50 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/03 19:13:13 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// t_env	*add_new_env(char *key, char *sep, char *val)
// {
// 	t_env	*tmp;

// 	tmp = (t_env *)malloc(sizeof(t_env));
// 	if (!tmp)
// 		exit(1);
// 	tmp->key = key;
// 	tmp->sep = sep;
// 	tmp->value = val;
// 	tmp->next = NULL;
// 	return (tmp);
// }

t_env	*init_elem(char *key, char *sep, char *val)
{
	t_env	*elem;

	elem = (t_env *)malloc(sizeof(t_env));
	if (!elem)
		return (NULL);
	elem->key = key;
	elem->sep = sep;
	elem->value = val;
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

void	add_env(char *env, t_env **envp)
{
	int		i;
	char	*key;
	char	*sep;
	char	*val;
	// t_env	*tmp;

	i = 0;
	sep = NULL;
	val = NULL;
	// tmp = *envp;
	while (env[i] && (env[i] == '_' || ft_isalnum(env[i])))
	{
		i++;
	}
	key = ft_substr(env, 0, i);
	// printf("key = %s\n", key);
	if (ft_strchr(env, '='))
	{
		sep = ft_substr(env, i, 1);
	}
	// printf("sep = %s\n", sep);
	if (env[i + 1])
	{
		val = ft_strdup(&env[i + 1]);
	}
	// printf("val = %s\n", val);
	add_elem(envp, init_elem(key, sep, val));
}

void	parse_env(char **env, t_all *data)
{
	int	i;
	t_all	*tmp;

	i = -1;
	tmp = data;
	while (env[++i])
	{
		// printf("%s\n", env[i]);
		add_env(env[i], data->env);
		tmp = data;
	}
	data = tmp;
}

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
	// int i = -1;
	// while(env[++i])
	// 	printf("%s\n", env[i]);
	t_all	*data;
	(void)av;

	init_struct(&data);
	if (ac != 1)
	{
		exit(0);
	}
	parse_env(env, data);
	shlvl_increment(*data->env);
	char	*line = "123 '$GDK_BACKEND' \"$GDK_BACKEND\"";
	int i = parser(line, data);
	return (i);
	// printf("%d\n", parser("     \n   ' dddd"));
	// print_env(&envp, "USER");
	// printf("key = %s sep = %s val = %s\n", envp->key, envp->sep, envp->value);
}
