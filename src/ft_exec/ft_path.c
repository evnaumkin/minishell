/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:10:07 by llornel           #+#    #+#             */
/*   Updated: 2022/02/20 03:34:50 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_path_join(const char *s1, const char *s2)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(s1, "/");
	path = ft_strjoin(tmp, s2);
	ft_memdel(tmp);
	return (path);
}

char	**ft_get_args(const char *cmd)
{
	char	**args;

	if (cmd == NULL)
		return (NULL);
	args = ft_split(cmd, ' ');
	if (args == NULL || *args == NULL)
		return (NULL);
	return (args);
}

static char	*ft_parse_path(char *path, const char *cmd)
{
	char	**dir;
	char	*curr;
	//char	*tmp;
	int		i;

	dir = ft_split(path, ':');
	if (dir == NULL)
		return (NULL);
		//ft_handle_error("ERROR: PATH is empty.");
	i = 0;
	curr = NULL;
	while (dir[i])
	{
		curr = ft_path_join(dir[i], (char *)cmd);
		//tmp = ft_strjoin(dir[i], "/");
		//curr = ft_strjoin(tmp, (char *)cmd);
		//ft_strdel(&tmp);
		if (access(curr, X_OK) != -1)
			break ;
		ft_strdel(&curr);
		i++;
	}
	ft_tabfree(dir);
	return (curr);
}

char	*ft_get_path(char **env, char *cmd)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_parse_path(env[i] + 5, cmd);
			if (path == NULL)
			{
				//return (ft_syntax_error(EXIT_SYNTAX_ERROR, ERR_MSG_SYNTAX_TOKEN));

				ft_putstr_fd(STDERR, "Error: ");
				ft_putstr_fd(STDERR, cmd);
				ft_putstr_fd(STDERR, ": command not found ");
				//ft_handle_error("");
			}
		}
		i++;
	}
	return (path);
}


char	*ft_check_dir(char *name, char *cmd)
{
	DIR				*dir;
	struct dirent	*item;
	char			*path;

	path = NULL;
	dir = opendir(name);
	if (dir == NULL)
		return (NULL);
	//return (ft_syntax_error(errno, ERR_MSG_NO_FILE_OR_DIR));
	while ((item = readdir(dir)))
	{
		if (ft_strcmp(item->d_name, cmd) == 0)
			path = ft_path_join(name, item->d_name);
	}
	closedir(dir);
	return (path);
}
