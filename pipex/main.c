/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/15 20:22:04 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_checkargs(int argc)
{
	if (argc == 3)
		return (0);
	else
		return (1);
}

char **ft_checkcom(char *arg_in)
{
	if (!arg_in)
		return (NULL);
	return (ft_split(arg_in, ' '));
}
char *ft_findpath(char **env,char *argument)
{
	char	*temp;

	if ((!env) || (!argument) || (!*env))
		return (NULL);
	temp = ft_strjoin("/",argument);
	while (*env)
	{
		if (!access(ft_strjoin(*env,temp), F_OK))
		{
			free(temp);
			return (*env);	
		}
		else
			env++;
	}
	return (NULL);
}
char *ft_checkenv(char **env, char *argv)
{
	char	*path_list;

	if ((!env) || (!argv) || (!*env))
		return (NULL);
	while ((ft_strncmp("PATH=", *env, 5)))
	{
		if (!*env)
			return (NULL);
		env++;	
	}
	//Ojo con el split que puedes estar haciendo un malloc sin free
	path_list = ft_substr(*env, 5, ft_strlen(*env) - 6);
	return (ft_findpath(ft_split(path_list, ':'), argv));
}

int ft_son(int *fd, char **arg, char *path,  char **env)
{
	close(fd[0]); // cerramos lectura
	dup2(fd[1], STDOUT_FILENO);
	close (fd[1]); // cerramos escritura
	return (execve(path, arg, env)); //Revisar esta parte
}

int ft_father(int *fd, char **argv, char *path, char **env)
{
		close(fd[1]); // cerramos escritura
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]); // cerramos lectura
		printf("llegaste?");
		return (execve(path, argv, env)); //Revisar esta parte
}

int ft_pipe(int *fd, char **arg1, char *path1, char **arg2, char *path2, char **env)
{
	int	pid;
	
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
		ft_son(fd, arg1, path1, env);
	else if (pid < 0)
		return (2);
	else 
		ft_father(fd, arg2, path2, env);//padre
	return (0);
}

int	main(int argc,char **argv, char **env)
{
	int		fd[2];
	char	**command1;
	char	**command2;
	char	*path1;
	char	*path2;
	//TODO: crear una estructura de datos para los comandos y los paths

	if (ft_checkargs(argc) == 0)
	{
		command1 = ft_checkcom(argv[1]);
		command2 = ft_checkcom(argv[2]);
		path1 = ft_checkenv(env,command1[0]);
		path2 = ft_checkenv(env,command2[0]);
		//revisar a partir de aqui, lo anterior funciona
		ft_pipe(fd, command1, path1, command2, path2, env);
	}
}
