/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/03/07 00:15:27 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_iswrong(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}

int	ft_checkargs(int argc, char **argv, t_pipex *in)
{
	int	flag;

	flag = 0;
	if (!(argc == 5))
	{
		flag++;
		ft_putstr_fd("Numero de argumentos incorrecto\n", 2);
	}
	else
	{
		(*in).fdin = open(argv[1], O_RDONLY);
		(*in).fdout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if ((*in).fdin < 0)
	{
		flag++;
		ft_iswrong("El archivo de entrada no se puede encontrar\n");
	}
	if ((*in).fdout < 0)
	{
		flag++;
		ft_iswrong("El archivo de salida no se puede crear\n");
	}
	return (flag);
}

char	**ft_checkcom(char *arg_in)
{
	if (!arg_in)
		return (NULL);
	return (ft_split(arg_in, ' '));
}

char	*ft_findpath(char **env, char *argument)
{
	char	*temp;
	char	*temp2;

	if ((!env) || (!argument) || (!*env))
		return (NULL);
	temp = ft_strjoin ("/", argument);
	while (*env)
	{
		temp2 = ft_strjoin(*env, temp);
		if (!access(temp2, F_OK))
		{
			free(temp);
			free(temp2);
			return (ft_strjoin(*env, "/"));
		}
		else
		{
			env++;
			free (temp2);
		}
	}
	ft_iswrong("El comando introducido no esta en ningun path de env");
	return (NULL);
}

char	*ft_checkenv(char **env, char *argv)
{
	char	*path_list;
	char	**temp;

	if ((!env) || (!argv) || (!*env))
		ft_iswrong("Argumentos vacios");
	while ((ft_strncmp("PATH=", *env, 5)))
	{
		if (!*env)
			ft_iswrong("No hay PATH en tu env");
		env++;
	}
	//Ojo con el split que puedes estar haciendo un malloc sin free
	path_list = ft_substr(*env, 5, ft_strlen(*env) - 6);
	temp = ft_split(path_list, ':');
	free(path_list);
	path_list = ft_findpath(temp, argv);
	freezear(temp);
	free(temp);
	return (path_list);
}
