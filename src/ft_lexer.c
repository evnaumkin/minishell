/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:51:21 by llornel           #+#    #+#             */
/*   Updated: 2022/02/14 21:59:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parser(char **tab)
{
	int		ret;

	ret = 0;
	ft_tabprint(tab);
	return (ret);
}

t_list	*ft_parse_token(char *str, char *separator)
{
	t_list	*lst;
	char	*start;
	char	*tmp;

	lst = NULL;
	while (*str != '\0')
	{
		if (ft_strchr(separator, *str) != NULL)
		{
			//printf("sep=[%c]\n", *str);
			tmp = ft_substr(str, 0, 1);
			ft_lstadd_back(&lst, ft_lstnew(tmp));
			str++;
		}
		else
		{
			start = str;
			while (ft_strchr(separator, *str) == NULL)
				str++;
			tmp = ft_substr(start, 0, str - start);
			//printf("str=[%s]\n", tmp);
			ft_lstadd_back(&lst, ft_lstnew(tmp));
		}
	}
	return (lst);
}
void	ft_lstprint(void *ptr)
{
	printf("str=[%s]\n", (char *)ptr);
}

int	ft_lexer(char *str)
{
	//char	**tokens;
	//t_list	*listtok;
	int		ret = 0;

	if (str == NULL)
		ft_fail("ft_lexer : Invalid argument");
	if (ft_strisempty(str))
	{
		g_params.listtok = ft_lstnew(ft_strdup(str));
		return (ERR_CODE_INPUT_EMPTY);
	}
	//listtok = ft_parse_str(str, "\'\"\t\n\v\f\r <>|");
	g_params.listtok = ft_parse_token(str, "|&;<>(){}$`\\\"\' \t");
	ft_lstiter(g_params.listtok, &ft_lstprint);

	// if (!ft_check_quotes(*str) && set_rl(input, QUOTES, STDERR_FILENO, false))
	// 	continue ;
	// tokens = ft_split_sep(str, "|&;<>(){}$`\\\"\' \t");
	// if (tokens == NULL)
	// 	return (FAILURE);
	// ret = ft_parser(tokens);
	// ft_split_free(tokens);
	return (ret);
}
