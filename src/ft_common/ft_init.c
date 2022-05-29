/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:27 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 14:34:25 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shlvl_error(int shlvl)
{
	printf("%s: warning: ", ERR_PROMPT);
	printf("shell level (%d) too high resetting to 1\n", shlvl);
}

void	ft_init_shell_level(int change)
{
	char	*value;
	int		shlvl;

	value = ft_var_get(g_params.vars, "SHLVL");
	if (ft_strlen(value) == 0)
		shlvl = 0;
	else if (!ft_strisdigit(value))
		shlvl = 0;
	else
		shlvl = ft_atoi(value);
	if (shlvl < SHLVL_MIN)
		shlvl = -1;
	shlvl = shlvl + change;
	if (shlvl >= SHLVL_MAX)
	{
		ft_shlvl_error(shlvl);
		shlvl = 1;
	}
	g_params.shlvl = shlvl;
	ft_strset((void **)&value, ft_itoa(shlvl));
	ft_var_set_export(g_params.vars, "SHLVL", value);
	ft_memdel(value);
}

int	ft_get_exit_status(void)
{
	return (g_params.exit_status);
}

void	ft_set_exit_status(int ret)
{
	g_params.exit_status = ret;
}

int	ft_params_init(char **envp)
{
	int			ret;

	ret = ft_vars_init(&g_params.vars, envp);
	if (ret != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ft_init_shell_level(1);
	g_params.pwd = getcwd(NULL, PATH_MAX);
	g_params.oldpwd = (char *) NULL;
	g_params.echoctl_flag = ft_check_echoctl(STDOUT);
	g_params.heredoc_status = 0;
	g_params.exit_status = 0;
	g_params.exit_immediately = 0;
	g_params.sigint = 0;
	g_params.sigquit = 0;
	g_params.pid = 0;
	ft_var_remove(g_params.vars, "OLDPWD");
	ft_var_set_export(g_params.vars, "OLDPWD", g_params.oldpwd);
	ft_var_set_export(g_params.vars, "PWD", g_params.pwd);
	return (EXIT_SUCCESS);
}
