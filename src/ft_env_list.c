/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:32:33 by llornel           #+#    #+#             */
/*   Updated: 2022/02/14 22:33:11 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_size(t_env *env)
{
	int	size;

	size = 0;
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}

t_env	*ft_env_new(char *key, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (NULL);
	env->key = key;
	env->value = value;
	env->next = NULL;
	return (env);
}

t_env	*ft_env_last(t_env *env)
{
	while (env)
	{
		if (env->next == NULL)
			break ;
		env = env->next;
	}
	return (env);
}

t_env	*ft_env_find(t_env *env, char *key)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env);
		env = env->next;
	}
	return (NULL);
}

bool	ft_env_remove(t_env *env, char *key)
{
	t_env *tmp;

	if (env == NULL || key == NULL)
		return (false);
	if (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			tmp = env->next;
			ft_env_del(env, &ft_memdel);
			env = tmp;
			return (true);
		}
	}
	while (env && env->next)
	{
		tmp = env->next->next;
		if (!ft_strcmp(env->next->key, key))
		{
			ft_env_del(env->next, &ft_memdel);
			env->next = tmp;
			return (true);
		}
		env = env->next;
	}
	return (false);
}

char	*ft_env_get(t_env *env, char *key)
{
	t_env 	*tmp;
	char 	*value;

	if (env == NULL || key == NULL)
		return (false);
	tmp = ft_env_find(env, key);
	if (tmp == NULL || tmp->value == NULL)
		return (false);
	//ft_printf("tvalue=%s\n", tmp->value);
	value = ft_strdup(tmp->value);
	//ft_printf("value=%s\n./mi", *value);
	if (value == NULL)
		return (NULL);
	return (value);
}

bool	ft_env_set(t_env *env, char *key, char *value)
{
	t_env 	*tmp;
	t_env	*new;
	char 	*tmp_value;

	if (env == NULL || key == NULL)
		return (false);
	tmp = ft_env_find(env, key);
	if (tmp)
	{
		tmp_value = tmp->value;
		if (value != NULL)
		{
			tmp->value = ft_strdup(value);
			ft_memdel(tmp_value);
		}
		return (true);
	}
	else
	{
		new = ft_env_new(ft_strdup(key), ft_strdup(value));
		if (new == NULL)
			return (false);
		ft_env_add_back(&env, new);
		return (true);
	}
	return (false);
}

void	ft_env_add_front(t_env **env, t_env *new)
{
	if (*env == NULL)
	{
		*env = new;
		return ;
	}
	if (new == NULL)
		return ;
	new->next = *env;
	*env = new;
}

void	ft_env_add_back(t_env **env, t_env *new)
{
	t_env	*last;

	if (env == NULL)
		return ;
	if (*env)
	{
		last = ft_env_last(*env);
		last->next = new;
	}
	else
		*env = new;
}

void	ft_env_del(t_env *env, void (*del)(void*))
{
	if (env == NULL || del == NULL)
		return ;
	if (env)
	{
		(*del)(env->key);
		(*del)(env->value);
		free(env);
	}
}

void	ft_env_clear(t_env **env, void (*del)(void*))
{
	t_env	*next;

	if (env == NULL || del == NULL)
		return ;
	while (*env)
	{
		next = (*env)->next;
		ft_env_del(*env, del);
		*env = next;
	}
}

void	ft_env_iter(t_env *env, void (*f)(t_env *))
{
	if (env == NULL || f == NULL)
		return ;
	while (env)
	{
		(*f)(env);
		env = env->next;
	}
}

void	ft_env_print(t_env *env)
{
	if (env == NULL)
		return ;
	ft_putstr("declare -x ");
	ft_putstr(env->key);
	if (env->value)
	{
		ft_putstr("=");
		ft_putstr("\"");
		ft_putstr(env->value);
		ft_putstr("\"");
	}
	ft_putstr("\n");
}
