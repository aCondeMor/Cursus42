/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/14 15:48:25 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_checkargs(int argc,char **argv)
{
	//TODO: revisar que los argumentos son 4 y demas casuisticas
}

char **ft_checkcom(char *arg_in)
{
	//TODO: recoger todos los args en un valist, separandolos por espacios
}

char *ft_checkenv(char **env, char *argv)
{
	//TODO: revisar en el path donde esta la carpeta a buscar
}

int ft_son(int fd, char **arg, char *path)
{
	close(fd[0]); // cerramos lectura
	dup2(fd[1], STDOUT_FILENO);
	close (fd[1]); // cerramos escritura
	return (execve(path, arg, NULL)); //Revisar esta parte
}

int ft_father(int fd, char **argv, char *path)
{
		close(fd[1]); // cerramos escritura
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]); // cerramos lectura
		return (execve(path, arg, NULL)); //Revisar esta parte
}

int ft_pipe(int fd, char **arg1, char *path1, char **arg2, char *path2)
{
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
		ft_son(fd, arg1, path1);
	else if (pid < 0)
		return 2;
	else 
		ft_father(fd, arg2, path2);//padre
	return (0);
}

int	main(int argc,char **argv, char **env)
{
	int		fd[2];
	int		pid;
	int		num;
	char	**command1;
	char	**command2;
	char	*path1;
	char	*path2;
	//TODO: crear una estructura de datos para los comandos y los paths

	if (ft_checkargs(argc, argv) == 0)
	{
		command1 = ft_checkcom(argv[2]);
		command2 = ft_checkcom(argv[3]);
		path1 = ft_checkenv(env,command1[0]);
		path2 = ft_checkenv(env,command2[0]);
		ft_pipe(fd, command1, path1, command2, path2);
	}
}
