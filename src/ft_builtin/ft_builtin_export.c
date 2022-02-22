/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:43:04 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 13:07:12 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_export(t_env *env, char *str)
{
	char	*key;
	char	*value;
    int		ret;

	ret = EXIT_SUCCESS;
	ft_env_parse(str, &key, &value);
	if (!ft_env_key_isvalid(key))
		ret = EXIT_BUILTIN;
	if (!ft_env_set(env, key, value))
		ret = EXIT_FAILURE;
	ft_memdel(key);
	ft_memdel(value);
	return (ret);
}

int ft_builtin_export(char **args, t_env *env)
{
	int		i;
	int		ret;

	if (args == NULL)
		return (EXIT_FAILURE);
	if (args[0] && !ft_strnstr(args[0], "export", ft_strlen("export")))
		return (EXIT_FAILURE);
	if (args[1] == NULL)
		ft_env_sort_print(env);
	ret = EXIT_SUCCESS;
	i = 1;
	while (args[i])
	{
		//ret = ft_env_export(env, args[i]);
		if (ft_env_export(env, args[i]) == EXIT_BUILTIN)
		{
			ft_fprintf(STDERR, "%s export: `%s`: %s\n", ERR_PROMPT, args[i], ERR_MSG_IDENTIFIER);
			ret = EXIT_BUILTIN;
		}
		i++;
	}
	return (ret);
}
