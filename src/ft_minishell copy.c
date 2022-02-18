/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:28:29 by llornel           #+#    #+#             */
/*   Updated: 2022/02/14 23:02:33 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_params_init(t_params *params)
{
	t_env	*env;
	t_token	*token;

	params = (t_params *)malloc(sizeof(t_params));
	if (params == NULL)
		return (FAILURE);
	env = (t_env *)malloc(sizeof(t_env));
	if (env == NULL)
		return (FAILURE);
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (FAILURE);
	params->env = env;
	params->token = token;
	params->exit_status = 0;
	params->sigint = 0;
	params->sigquit = 0;
	params->pid = 0;
	return (SUCCESS);
}

char	**ft_init_env(char **envp)
{
	char	**tmp;

	tmp = ft_tabdup(envp);
	if (tmp == NULL)
		return (NULL);
	ft_tabsort(tmp);
	return (tmp);
}

int	ft_readline(void)
{
	char	*str;
	int		ret;
	t_token	*token;

	while (true)
	{
		str = readline("minishell$ ");
		if (str == NULL)
			return (ft_exit_error((void *)str, EXIT_CTRL_D));
		if (ft_strlen(str) == 0 || ft_strisempty(str))
			continue ;
		add_history(str);
		ret = ft_lexer(str, &token);
		if (ret == EXIT_FAILURE)
			return (ft_exit_error((void *)str, EXIT_FAILURE));
		ft_memdel((void *)str);
	}
	return (ft_exit_error((void *)str, EXIT_FAILURE));
}

int	ft_minishell(int argc, char **argv, char **envp)
{
	int		ret;
	//t_params	params;
	char	**tabenv;
	//t_env	*env;

	(void)argc;
	(void)argv;
	(void)envp;

	// env = (t_env *)malloc(sizeof(t_env));
	// if (env == NULL)
	// 	return (FAILURE);
	// ret = ft_params_init(&params);
	// if (ret != SUCCESS)
	// 	return (FAILURE);
	// env = (&params)->env;
	ret = ft_env_init(&g_params.env, envp);
	if (ret != SUCCESS)
		return (FAILURE);
	//g_params.env = env;
	//printf("size=%d\n", ft_env_size(env));
	ft_env_iter(g_params.env, &ft_env_print);
	tabenv = ft_env_to_tab(g_params.env);
	ft_tabsort(tabenv);
	ft_tabprint(tabenv);
	ft_tabfree(tabenv);
	ft_env_clear(&g_params.env, &free);
	return (SUCCESS);
}

int	ft_minishell1(int argc, char **argv, char **envp)
{
	char	**tabenv;
	//char	*str;

	(void)argc;
	(void)argv;
	(void)envp;

	tabenv = ft_init_env(envp);
	if (tabenv == NULL)
		return (FAILURE);
	ft_tabprint(tabenv);
	if (ft_readline() == FAILURE)
		return (FAILURE);
	ft_tabfree(tabenv);
	//pause();
	return (SUCCESS);
}

int	ft_minishell2(int argc, char **argv, char **envp)
{
	char	**tabenv;
	int		i;
	int		size;

	(void)argc;
	(void)argv;
	(void)envp;

	if (envp == NULL)
		return (FAILURE);
	size = 0;
	while (envp[size])
	{
		//printf("%d. %s\n", size, envp[size]);
		size++;
	}
	printf("size = %d.\n", size);
	tabenv = (char **)malloc(sizeof(char *) * (size + 1));
	if (tabenv == NULL)
		return (FAILURE);
	i = 0;
	while (envp[i])
	{
		printf(">> %d. %s\n", i, envp[i]);
		tabenv[i] = ft_strdup(envp[i]);
		printf("<< %d. %s\n", i, tabenv[i]);
		i++;
	}
	tabenv[i] = NULL;
	// tabenv = ft_tabdup(envp);
	// if (tabenv == NULL)
	// 	return (FAILURE);
	i = 0;
	// while (tabenv[i])
	// {
	// 	printf("%d. %s\n", i, tabenv[i]);
	// 	i++;
	// }
	while (tabenv[i])
	{
		printf("%d.\n", i);
		printf("%s.\n", tabenv[i]);
		//printf("%d. %s\n", i, tabenv[i]);
		//ft_memdel(tab[i]);
		//ft_strdel(&tabenv[i]);
		i++;
	}
	//ft_memdel(tab);
	//free(tabenv);
	return (SUCCESS);
}
