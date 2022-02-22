/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:05:51 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 03:06:49 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_env_ischar(int c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

bool	ft_env_key_isvalid(const char *str)
{
	int		i;

	if (str == NULL)
		return (false);
	if (ft_isdigit(str[0]) == 1)
		return (false);
	i = 0;
	while (str[i])
	{
		if (!ft_env_ischar(str[i]))
			return (false);
		i++;
	}
	return (true);
}

// bool	ft_env_key_isvalid(const char *str)
// {
// 	int		i;
// 	char	*tmp;
// 	char	*key;

// 	if (str == NULL)
// 		return (false);
// 	if (ft_isdigit(str[0]) == 1)
// 		return (false);
// 	tmp = ft_strchr(str, '=');
// 	if (tmp == NULL)
// 		key = ft_strdup(str);
// 	else
// 		key = ft_substr(str, 0, tmp - str);
// 	i = 0;
// 	while (key[i])
// 	{
// 		if (!ft_env_ischar(key[i]))
// 		{
// 			ft_memdel(key);
// 			return (false);
// 		}
// 		i++;
// 	}
// 	ft_memdel(key);
// 	return (true);
// }

int	ft_env_isvalid(const char *str)
{
	int		i;

	i = 0;
	if (ft_isdigit(str[i]) == 1)
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_env_ischar(str[i]))
			return (-1);
		i++;
	}
	if (str[i] != '=')
		return (2);
	return (1);
}

void	ft_env_parse(char *str, char **key, char **value)
{
	char	*tmp;

	tmp = ft_strchr(str, '=');
	if (tmp == NULL)
	{
		*key = ft_strdup(str);
		*value = NULL;
	}
	else
	{
		*key = ft_substr(str, 0, tmp - str);
		*value = ft_strdup(tmp + 1);
	}
}

char	**ft_env_to_tab(t_env *env)
{
	char	**tab;
	char	*str;
	int		size;
	int		i;

	tab = (char **)malloc(sizeof(char *) * (ft_env_size(env) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (env)
	{
		if (env->value)
			size = ft_strlen(env->key) + ft_strlen(env->value) + 3;
		else
			size = ft_strlen(env->key);
		str = (char *)malloc(sizeof(char) * (size + 1));
		if (str == NULL)
			return (NULL);
		ft_strncpy(str, env->key, size);
		if (env->value)
		{
			ft_strncat(str, "=\"", size);
			ft_strncat(str, env->value, size);
			ft_strncat(str, "\"", size);
		}
		tab[i] = str;
		env = env->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
