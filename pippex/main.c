/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/09 17:16:31 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pippex.h"

int	main()
{
	int		fd[2];
	int		pid;
	char	buf[10];
	int		num;

	num = 0;
	if (pipe(fd) == -1)
		return 1;
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]); // cerramos lectura
		dup2(fd[1], STDOUT_FILENO);
		execve()
		execve("./","ping -c 5 google.com", NULL); //Revisar esta parte
		close (fd[1]); // cerramos escritura
		//hijo
	}
	else if (pid < 0)
		return 2;
	else 
	{
		close(fd[1]); // cerramos escritura
		dup2(fd[1], STDIN_FILENO);
		execve("./","grep rtt",NULL);
		close (fd[0]); // cerramos lectura
	}	//padre
}
