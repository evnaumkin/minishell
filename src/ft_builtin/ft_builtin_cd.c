/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:57:57 by llornel           #+#    #+#             */
/*   Updated: 2022/02/19 21:27:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_env(char *name, char*path)
{
	if (path == NULL && name != NULL)
	{
		ft_putstr_fd(STDERR, ERR_PROMPT);
		ft_putstr_fd(STDERR, "cd: ");
		ft_putstr_fd(STDERR, name);
		ft_putendl_fd(STDERR, " not set");
		return (EXIT_FAILURE);
	}
	else if (ft_strlen(path) > 0 && chdir(path) == -1)
	{
		ft_putstr_fd(STDERR, ERR_PROMPT);
		ft_putstr_fd(STDERR, "cd: ");
		ft_putstr_fd(STDERR, path);
		ft_putendl_fd(STDERR, ": " ERR_MSG_NO_FILE_OR_DIR);
		//ft_memdel(path);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_move_path(t_env *env, char *path, char *oldpath, bool print)
{
	char	*cwd;

	if (chdir(path) == -1)
		return (EXIT_FAILURE);
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		ft_free_set((void **)&oldpath, ft_strjoin(oldpath, "/"));
		cwd = ft_strjoin(oldpath, path);
	}
	ft_env_set(env, "PWD", cwd);
	ft_env_set(env, "OLDPWD", oldpath);
	ft_free_set((void **)&g_params.pwd, ft_strdup(cwd));
	//ft_memdel(g_params.pwd);
	//g_params.pwd = ft_strdup(cwd);
	if (print)
		ft_putendl_fd(STDOUT, cwd);
	//ft_memdel(path);
	//ft_memdel(oldpath);
	ft_memdel(cwd);
	return (EXIT_SUCCESS);
}

static int	ft_cd_home(t_env *env)
{
	int		ret;
	char	*newpath;
	char	*oldpath;

	ft_putendl_fd(STDOUT, "ft_cd_home");
	newpath = ft_env_get(env, "HOME");
	ret = ft_check_env("HOME", newpath);
	if (ret != EXIT_SUCCESS)
		return (ret);
	if (ft_strlen(newpath) == 0)
	{
		ft_memdel(newpath);
		newpath = ft_strdup(g_params.pwd);
	}
	oldpath = ft_env_get(env, "PWD");
	ft_env_set(env, "PWD", newpath);
	ft_env_set(env, "OLDPWD", oldpath);
	ft_memdel(g_params.pwd);
	g_params.pwd = ft_strdup(newpath);
	ft_memdel(newpath);
	ft_memdel(oldpath);
	return (EXIT_SUCCESS);
}

static int	ft_cd_dash(t_env *env)
{
	int		ret;
	char	*newpath;
	char	*oldpath;

	ft_putendl_fd(STDOUT, "ft_cd_dash");
	oldpath = ft_env_get(env, "OLDPWD");
	ret = ft_check_env("OLDPWD", oldpath);
	if (ret != EXIT_SUCCESS)
		return (ret);
	if (ft_strlen(oldpath) == 0)
	{
		ft_memdel(oldpath);
		oldpath = ft_strdup(g_params.pwd);
	}
	newpath = ft_env_get(env, "PWD");
	ft_env_set(env, "PWD", oldpath);
	ft_env_set(env, "OLDPWD", newpath);
	ft_memdel(g_params.pwd);
	g_params.pwd = ft_strdup(oldpath);
	ft_memdel(newpath);
	ft_memdel(oldpath);
	return (EXIT_SUCCESS);
}

static int	ft_cd_tilde(t_env *env, char *arg)
{
	char	*homepath;
	char	*newpath;
	char	*oldpath;

	ft_putendl_fd(STDOUT, "ft_cd_tilde");
	homepath = ft_env_get(env, "HOME");
	if (homepath == NULL)
		homepath = ft_strdup(g_params.pwd);
	if (ft_strncmp(arg, "/", 1) == 0)
		newpath = ft_strjoin(homepath, arg + 2);
	else
		newpath = ft_strdup(arg);
	ft_memdel(homepath);
	if (newpath == NULL)
		return (EXIT_FAILURE);
	oldpath = ft_env_get(env, "PWD");
	ft_env_set(env, "PWD", newpath);
	ft_env_set(env, "OLDPWD", oldpath);
	ft_memdel(g_params.pwd);
	g_params.pwd = ft_strdup(newpath);
	ft_memdel(newpath);
	ft_memdel(oldpath);
	return (EXIT_SUCCESS);
}

static int	ft_cd_path(t_env *env, char *arg)
{
	int		ret;
	char	*oldpath;
	char	*oldpwd;

	(void)env;
	(void)arg;

	ft_putendl_fd(STDOUT, "ft_cd_path");
	oldpath = ft_env_get(env, "PWD");
	oldpwd = ft_env_get(env, "OLDPWD");
	ft_printf("CWD=%s\n", getcwd(NULL, 0));
	ft_printf("HOME=%s\n", getenv("HOME"));
	ft_printf("PWD=%s\n", oldpath);
	ft_printf("OLDPWD=%s\n", oldpwd);
	ret = ft_move_path(env, arg, oldpath, false);
	if (ret != EXIT_SUCCESS)
		ret = ft_check_env(NULL, arg);
	ft_memdel(oldpath);
	ft_memdel(oldpwd);
	return (ret);
}

static int	ft_cd_cdpath(t_env *env, char *arg, char *cdpath)
{
	char 	**paths;
	char	*oldpath;
	char	*oldpwd;
	char	*path;
	int		i;
	int		ret;

	(void)env;
	(void)arg;
	(void)cdpath;

	ft_printf("ft_cd_cdpath\n");
	oldpath = ft_env_get(env, "PWD");
	oldpwd = ft_env_get(env, "OLDPWD");
	ft_printf("arg=%s\n", arg);
	ft_printf("CWD=%s\n", getcwd(NULL, 0));
	ft_printf("HOME=%s\n", getenv("HOME"));
	ft_printf("OLDPWD=%s\n", oldpwd);
	ft_printf("PWD=%s\n", oldpath);

	ret = ft_move_path(env, arg, oldpath, false);
	if (ret != EXIT_SUCCESS)
	{
		paths = ft_split(cdpath, ':');
		if (paths == NULL)
			return (EXIT_FAILURE);
		ft_tabprint(paths);
		i = 0;
		while (paths[i])
		{
			path = ft_strdup(paths[i]);
			ft_free_set((void **)&path, ft_strjoin(path, "/"));
			ft_free_set((void **)&path, ft_strjoin(path, arg));
			//ft_printf("path=%s\n", path);
			ret = ft_move_path(env, path, oldpath, true);
			if (ret == EXIT_SUCCESS)
				break ;
			i++;
		}
		if (ret != EXIT_SUCCESS)
			ret = ft_check_env(NULL, path);
		ft_memdel(path);
		ft_tabfree(paths);
	}
	ft_memdel(oldpath);
	ft_memdel(oldpwd);
	return (ret);
}

int		ft_builtin_cd(char **argv, t_env *env)
{
	int		ret;
	char	*arg;
	char	*cdpath;

	// ft_env_set(g_params.env, "PWD", getcwd(NULL, 0));
	if (argv == NULL || env == NULL)
		return (EXIT_FAILURE);
	ft_printf("argv[0]=%s\n", argv[0]);
	ft_printf("argv[1]=%s\n", argv[1]);
	ret = EXIT_SUCCESS;
	arg = ft_strdup(argv[1]);
	if (arg == NULL)
		ret = ft_cd_home(env);
	else if (ft_strcmp(arg, "-") == 0)
		ret = ft_cd_dash(env);
	else if (ft_strcmp(arg, "~") == 0)
		ret = ft_cd_tilde(env, arg);
	else
	{
		cdpath = ft_env_get(env, "CDPATH");
		ft_printf("cdpath=%s\n", cdpath);
		if (cdpath != NULL && (ft_strncmp(arg, "/", 1) != 0))
			ret = ft_cd_cdpath(env, arg, cdpath);
		else
			ret = ft_cd_path(env, arg);
		ft_memdel(cdpath);
	}
	ft_memdel(arg);
	return (ret);
}