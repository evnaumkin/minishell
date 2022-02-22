/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:32:55 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 13:04:52 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_unset(t_env *env, char *key)
{
    int		ret;

	ret = EXIT_SUCCESS;
	if (!ft_env_key_isvalid(key))
		ret = EXIT_BUILTIN;
	if (!ft_env_remove(env, key))
		ret = EXIT_FAILURE;
	return (ret);
}

int ft_builtin_unset(char **args, t_env *env)
{
	int		i;
	int		ret;

	if (args == NULL)
		return (EXIT_FAILURE);
	if (args[0] && !ft_strnstr(args[0], "unset", ft_strlen("unset")))
		return (EXIT_FAILURE);
	ret = EXIT_SUCCESS;
	i = 1;
	while (args[i])
	{
		// if (ft_env_name_isvalid(args[i]))
		// 	ft_env_remove(env, args[i]);
		if (ft_env_unset(env, args[i]) == EXIT_BUILTIN)
		{
			ft_fprintf(STDERR, "%sunset: `%s`: %s\n", ERR_PROMPT, args[i], ERR_MSG_IDENTIFIER);
			ft_set_errcode(EXIT_BUILTIN);
			//ret = EXIT_BUILTIN;
		}
		i++;
	}
	return (ret);
}
