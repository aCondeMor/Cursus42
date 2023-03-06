/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/03/07 00:19:04 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_pipex
{
	int		fd[2];
	char	**command1;
	char	**command2;
	char	*path1;
	char	*path2;
	char	**env;
	int		fdin;
	int		fdout;
}	t_pipex;

void	ft_iswrong(char *error);
int		ft_checkargs(int argc, char **argv, t_pipex *in);
char	**ft_checkcom(char *arg_in);
char	*ft_findpath(char **env, char *argument);
char	*ft_checkenv(char **env, char *argv);
void	freezear(char **in);

#endif