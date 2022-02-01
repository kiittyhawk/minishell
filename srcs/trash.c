// int	quotes(char *cmd)
// {
// 	int	i;

// 	i = 0;
// 	while (cmd[i])
// 	{
// 		if (cmd[i] == '\'')
// 		{
// 			i++;
// 			while (cmd[i] && cmd[i] != '\'')
// 				i++;
// 			if (cmd[i] == '\0')
// 				return (1);
// 		}
// 		if (cmd[i] == '\"')
// 		{
// 			i++;
// 			while (cmd[i] && cmd[i] != '\"')
// 				i++;
// 			if (cmd[i] == '\0')
// 				return (2);
// 		}
// 		i++;
// 	}
// }

// void	skip_quotes(char *cmd, int *i)
// {
// 	if (cmd[*i] == '\"')
// 	{
// 		(*i)++;
// 		while (cmd[*i] && cmd[*i] != '\"')
// 			(*i)++;
// 	}
// 	if (cmd[*i] == '\'')
// 	{
// 		(*i)++;
// 		while (cmd[*i] && cmd[*i] != '\'')
// 			(*i)++;
// 	}
// }

// char	*cut(int i, int x, char *cmd)
// {
// 	char	*str;
// 	int		z;

// 	str = malloc((i + 1) * sizeof(char));
// 	z = 0;
// 	if (!str)
// 		return(1);
// 	while (x < i)
// 	{
// 		str[z] = cmd[x];
// 		z++;
// 		x++;
// 	}
// 	str[z] = '\0';
// 	return(str);
// }

// void	cut_commands(char *cmd)
// {
// 	int		i;
// 	int		x;
// 	int		z;
// 	char	**cmds;

// 	i = 0;
// 	x = 0;
// 	z = 0;
// 	cmds = 0;
// 	while (cmd[i])
// 	{
// 		skip_quotes(cmd, &i);
// 		if (cmd[i] == '|')
// 		{
// 			cmds[z] = cut(i, x, cmd);
// 			x = i + 1;
// 			z++;
// 		}
// 		i++;
// 	}
// 	cmds[z] = cut(i, x, cmd);
// 	i = 0;

// }

// void	parser(char *cmd)
// {
// 	int	err;

// 	err = quotes(cmd);
// 	if (err == 1)
// 		printf("%s\n", "Quotes not inclose");
// 	if (err == 2)
// 		printf("%s\n", "Double quotes not inclose");
// 	cut_commands(cmd);
// }

// void skip_spaces(char **line)
// {
// 	int	i;

// 	i = 0;
// 	while ((*line)[i])
// 	{
// 		if ((*line)[i] == '\t' || (*line)[i] == '\n')
// 		{
// 			(*line)[i] = ' ';
// 		}
// 		i++;
// 	}
// }
