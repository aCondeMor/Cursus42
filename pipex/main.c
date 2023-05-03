/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/04/30 23:32:10 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void static	ft_son(t_pipex input)
{
	close (input.fd[0]);
	dup2(input.fdin, STDIN_FILENO);
	dup2 (input.fd[1], STDOUT_FILENO);
	close (input.fd[1]);
	close (input.fdin);
	if (execve(input.path1, input.command1, input.env) < 0)
		ft_iswrong("command not found, revisa parametros1");
}

void static	ft_son2(t_pipex input)
{
	waitpid (0, NULL, 0);
	close(input.fd[1]);
	dup2 (input.fd[0], STDIN_FILENO);
	dup2(input.fdout, STDOUT_FILENO);
	close (input.fd[0]);
	close (input.fdout);
	if (execve(input.path2, input.command2, input.env) < 0)
		ft_iswrong("command not found, revisa parametros2");
}

int	ft_pipe(t_pipex input)
{
	int	pid[2];
	int	success;

	if (pipe(input.fd) == -1)
		ft_iswrong("error creando pipe");
	pid[0] = fork();
	if (pid[0] < 0)
		ft_iswrong("error en el fork de son1");
	else if (pid[0] == 0)
		ft_son(input);
	else
	{
		close(input.fd[1]);
		pid[1] = fork();
		if (pid[1] < 0)
			ft_iswrong("error en el fork de son2");
		else if (pid[1] == 0)
			ft_son2(input);
		close(input.fd[0]);
	}
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &success, 0);
	if (WIFEXITED(success) != 0)
		exit(WEXITSTATUS(success));
	exit(1);
}

void	freezear(char **in)
{
	while (*in)
	{
		free(*in);
		in++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	in;
	char	*temp;

	in.fdin = 0;
	if (ft_checkargs(argc, argv, &in) == 0)
	{
		in.command1 = ft_checkcom(argv[2]);
		in.command2 = ft_checkcom(argv[3]);
		temp = ft_checkenv(env, in.command1[0]);
		in.path1 = ft_strjoin(temp, in.command1[0]);
		free(temp);
		temp = ft_checkenv(env, in.command2[0]);
		in.path2 = ft_strjoin(temp, in.command2[0]);
		free(temp);
		in.env = env;
		ft_pipe(in);
		freezear(in.command1);
		freezear(in.command2);
		free(in.path1);
		free(in.path2);
		free(in.command1);
		free(in.command2);
	}
	else
		exit (1);
}
