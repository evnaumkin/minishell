/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 01:00:40 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 12:29:50 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_str_print(char *str)
{
	if (str == NULL)
		return ;
	ft_putstr("declare -x ");
	ft_putstr(str);
	ft_putstr("\n");
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

void	ft_env_sort_print(t_env	*env)
{
	char	**tabenv;
	int		i;

	tabenv = ft_env_to_tab(env);
	if (tabenv == NULL)
		return ;
	ft_tabsort(tabenv);
	i = 0;
	while (tabenv[i])
	{
		// ft_putnbr_fd(STDOUT, i);
		// ft_putstr_fd(STDOUT, ". ");
		// ft_putendl_fd(STDOUT, tabenv[i]);
        ft_str_print(tabenv[i]);
		i++;
	}
	//ft_tabprint(tabenv);
	ft_tabfree(tabenv);
}
