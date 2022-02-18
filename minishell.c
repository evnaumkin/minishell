/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:10:24 by llornel           #+#    #+#             */
/*   Updated: 2022/02/16 02:53:49 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_params	g_params = {};

static int	ft_handle_cmd(char *str)
{
	//int		ret;
	char	**args;

	args = ft_split_sep(str, " \t\n");
	if (args == NULL)
		return (EXIT_FAILURE);
	//ft_tabprint(args);
	//ft_split_free(args)
	ft_tabfree(args);
	return (EXIT_SUCCESS);
}

static int	ft_handle_args(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "-c") != 0)
	{
		ft_putstr_fd(STDERR, ERR_PROMPT);
		ft_putstr_fd(STDERR, argv[1]);
		ft_putendl_fd(STDERR, ": invalid option");
		ft_putendl_fd(STDERR, "Usage: minishell [option] ...");
		ft_putendl_fd(STDERR, "minishell options: -c command");
		return (EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		ft_putstr_fd(STDERR, ERR_PROMPT);
		ft_putstr_fd(STDERR, argv[1]);
		ft_putendl_fd(STDERR, ": option requires an argument");
		return (EXIT_FAILURE);
	}
	//ft_putendl_fd(STDERR, argv[2]);
	//ret = ft_handle_test(argv[2]);
	//ret = lexer(argv[2]);
	//free_envv(get_envv());
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int	ret;
	int	mode;

	mode = 0;
	if (argc != 1)
	{
		ret = ft_handle_args(argc, argv);
		if (ret != EXIT_SUCCESS)
			return (ret);
		mode = 1;
	}
	ft_signal_init();
	ft_echoctl_off();
	ret = ft_params_init(envp);
	if (ret != EXIT_SUCCESS)
		return (ret);
	//mode = 2;
	if (mode == 0)
		ret = ft_minishell(argc, argv, envp);
	else if (mode == 1)
		ret = ft_handle_cmd(argv[2]);
	else
		ret = ft_handle_test(argv[2]);
	ft_free();
	return (ret);
}
