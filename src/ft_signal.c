/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:00:32 by llornel           #+#    #+#             */
/*   Updated: 2022/02/16 02:58:11 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_rl(char *in, char *out, int fd, bool newline)
{
	if (in != NULL)
	{
		ft_putstr_fd(fd, in);
		ft_putstr_fd(fd, ": ");
	}
	if (out != NULL)
		ft_putstr_fd(fd, out);
	ft_putendl_fd(fd, "");
	if (newline)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_handler_sigint(int sig)
{
	(void)sig;
	ft_putendl_fd(STDOUT, "");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_echoctl_off(void)
{
	struct termios	attr;

	if (isatty(STDIN_FILENO))
	{
		tcgetattr(STDIN_FILENO, &attr);
		//attr.c_lflag &= ~ISIG;
		attr.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &attr);
	}
	else if (isatty(STDOUT_FILENO))
	{
		tcgetattr(STDOUT_FILENO, &attr);
		attr.c_lflag = attr.c_lflag & ~ECHOCTL;
		tcsetattr(STDOUT_FILENO, TCSANOW, &attr);
	}
	else if (isatty(STDERR_FILENO))
	{
		tcgetattr(STDERR_FILENO, &attr);
		attr.c_lflag = attr.c_lflag & ~ECHOCTL;
		tcsetattr(STDERR_FILENO, TCSANOW, &attr);
	}
}

void	ft_signal_init(void)
{
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		ft_fail("signal SIGQUIT error: ");
	if (signal(SIGINT, ft_handler_sigint) == SIG_ERR)
		ft_fail("signal SIGINT error: ");
}
