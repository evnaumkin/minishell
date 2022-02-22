/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 04:42:07 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 04:56:45 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_list_to_tab(t_list *lst)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (lst)
	{
		tab[i] = ft_strdup(lst->content);;
		lst = lst->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
