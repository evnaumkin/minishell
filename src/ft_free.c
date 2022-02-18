/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:46:04 by llornel           #+#    #+#             */
/*   Updated: 2022/02/14 02:20:40 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_set(void **dst, void *src)
{
	//free(*dst);
	ft_memdel(*dst);
	*dst = src;
}

void	ft_free(void)
{
	ft_env_clear(&g_params.env, &ft_memdel);
}
