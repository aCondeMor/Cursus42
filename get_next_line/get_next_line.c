/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:12:43 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/09 17:48:28 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		cont;

	cont = 0;
	if (!str)
		return (0);
	while (str[cont] != '\0')
	{
		cont++;
	}
	return (cont);
}

void	*ft_bzero(void *str, size_t n)
{
	size_t		cont;

	if (!str)
		return (0);
	cont = 0;
	while (cont < n)
	{
		*(unsigned char *)(str + cont) = '\0';
		cont++;
	}
	return (str);
}

char	*read_file(int fd, char *line_read)
{
	char	*buffer;
	int		stop;
	int		ret;

	stop = 0;
	ret = -1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(line_read, '\n') && (ret != 0))
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{	
			free(buffer);
			return (0);
		}
		line_read = ft_strjoin(line_read, buffer);
	}
	free(buffer);
	return (line_read);
}

char	*check_line(char *line_read)
{
	char		*line_aux;

	line_aux = ft_substr(line_read, 0, ft_strlen(line_read));
	line_read = NULL;
	free(line_read);
	if (line_aux[0] == '\0')
	{
		free(line_aux);
		free(line_read);
		return (NULL);
	}
	return (line_aux);
}

char	*get_next_line(int file)
{
	char		*line_aux;
	static char	*line_read;

	if (file < 0 || BUFFER_SIZE <= 0 || read(file, 0, 0) < 0)
		return (NULL);
	line_read = read_file(file, line_read);
	if (!line_read)
	{
		free(line_read);
		line_read = NULL;
		return (NULL);
	}
	if (!ft_strchr(line_read, '\n'))
	{
		line_aux = check_line(line_read);
		line_read = NULL;
		free(line_read);
		return (line_aux);
	}
	line_aux = ft_substr(line_read, 0, ft_strlen(line_read)
			- ft_strlen((ft_strchr(line_read, '\n'))) + 1);
	line_read = ft_strchr(line_read, '\n') + 1;
	return (line_aux);
}
