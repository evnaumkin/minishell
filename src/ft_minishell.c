/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:28:29 by llornel           #+#    #+#             */
/*   Updated: 2022/02/14 23:05:39 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_readline(char *name)
{
	char	*input;
	int		ret;
	//t_token	*token;

	while (true)
	{
		input = readline(name);
		if (input == NULL)
			return (ft_exit_error((void *)input, EXIT_CTRL_D));
		if (ft_strlen(input) == 0)
			continue ;
		add_history(input);
		ret = ft_lexer(input);
		if (ret == EXIT_FAILURE)
			return (ft_exit_error((void *)input, EXIT_FAILURE));
		ft_memdel((void *)input);
		ft_lstclear(&g_params.listtok, &ft_memdel);
	}
	return (EXIT_SUCCESS);
}



void	ft_env_sort_print(t_env	*env)
{
	char	**tabenv;

	tabenv = ft_env_to_tab(env);
	ft_tabsort(tabenv);
	ft_tabprint(tabenv);
	ft_tabfree(tabenv);
}

int	ft_minishell(int argc, char **argv, char **envp)
{
	int		ret;
	//t_env	*env;
	//char	**tabenv;

	(void)argc;
	(void)argv;
	(void)envp;

	//ret = ft_env_init(&g_params.env, envp);
	//ft_env_iter(g_params.env, &ft_env_print);
	//printf("size=%d\n", ft_env_size(g_params.env));
	//ft_env_iter(g_params.env, &ft_env_print);
	ret = ft_readline(PROMPT);
	if (ret != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	// env = ft_env_find(g_params.env, "PWD");
	// if (env != NULL)
	// {
	// 	printf("find: %s=%s\n", env->key, env->value);
	// 	//ft_env_remove(g_params.env, env->key);
	// }
	// ft_env_set(g_params.env, "PWD", getcwd(NULL, 0));
	// ft_env_set(g_params.env, "VAR1", "School21");
	// ft_env_set(g_params.env, "VAR2", "");
	// ft_env_set(g_params.env, "VAR1", NULL);
	// ft_env_set(g_params.env, "VAR3", NULL);
	// ft_env_set(g_params.env, "VAR3", "VAR3_");
	// ft_env_set(g_params.env, "VAR3", NULL);
	// ft_env_set(g_params.env, "VAR3", "");
	//ft_env_iter(g_params.env, &ft_env_print);
	//ft_env_sort_print(g_params.env);
	//ft_tabsort(tabenv);
	//ft_tabprint(tabenv);
	// ft_tabfree(tabenv);
	//printf("size=%d\n", ft_env_size(g_params.env));
	//bool	ft_env_remove(t_env **env, char *key)
	return (EXIT_SUCCESS);
}
