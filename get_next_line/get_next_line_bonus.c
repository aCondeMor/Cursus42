/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:12:43 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/23 00:17:04 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *line_read)
{
	char	*buffer;
	int		ret;
	char	*tmp;

	ret = -1;
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	while ((!ft_strchr(line_read, '\n')) && (ret != 0))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{	
			free(buffer);
			return (0);
		}
		tmp = line_read;
		line_read = ft_strjoin(line_read, buffer);
		free (tmp);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	if (buffer)
		free(buffer);
	return (line_read);
}

char	*check_line(char *line_read)
{
	char		*line_aux;

	line_aux = ft_substr(line_read, 0, ft_strlen(line_read));
	free(line_read);
	line_read = NULL;
	if (line_aux[0] == '\0')
	{
		free(line_aux);
		return (NULL);
	}
	return (line_aux);
}

char	*set_line_read(char * line_read)
{
	char		*tmp;

	tmp = line_read;
	line_read = ft_substr(line_read, ft_strlen(line_read) - ft_strlen((ft_strchr(line_read, '\n'))) + 1,
				ft_strlen(line_read));
	free(tmp);
	return (line_read);
}

char	*get_next_line(int file)
{
	char		*line_aux;
	static char	*line_read[4096] = {0};

	line_aux = NULL;
	if (file > 4095 || BUFFER_SIZE <= 0 || read(file, 0, 0) < 0)
		return (NULL);
	line_read[file] = read_file(file, line_read[file]);
	if (!ft_strchr(line_read[file], '\n'))
	{
		line_aux = check_line(line_read[file]);
		line_read[file] = NULL;
		return (line_aux);
	}
	if (line_read[file][0] != '\0')
	{
		line_aux = ft_substr(line_read[file], 0, ft_strlen(line_read[file])
				- ft_strlen((ft_strchr(line_read[file], '\n'))) + 1);
		line_read[file] = set_line_read(line_read[file]);
	}
	else
		free(line_read[file]);
	return (line_aux);
}

/*
char	*get_next_line(int file)
{
	char		*line_aux;
	static char	*line_read[4096] = {0};

	if (file > 4095 || BUFFER_SIZE <= 0 || read(file, 0, 0) < 0)
		return (NULL);
	line_read[file] = read_file(file, line_read[file]);
	if (!line_read[file])
	{
		free(line_read[file]);
		line_read[file] = NULL;
		return (NULL);
	}
	if (!ft_strchr(line_read[file], '\n'))
	{
		line_aux = check_line(line_read[file]);
		line_read[file] = NULL;
		free(line_read[file]);
		return (line_aux);
	}
	line_aux = ft_substr(line_read[file], 0, ft_strlen(line_read[file])
			- ft_strlen((ft_strchr(line_read[file], '\n'))) + 1);
	line_read[file] = ft_strchr(line_read[file], '\n') + 1;
	return (line_aux);
}
*/