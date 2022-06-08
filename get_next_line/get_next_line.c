#include "get_next_line.h"

char	*read_file(int fd, char *line_read)
{
	char	*buffer;
	int		stop;

	stop = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while ((stop == 0) && (read(fd, buffer, BUFFER_SIZE) > 0))
	{
		line_read = ft_strjoin(line_read, buffer);
		if (ft_strchr(line_read, '\n'))
			stop = 1;

		printf("line_read intermedio es: %s\n", line_read);	
	}
	//line_read = ft_strjoin(line_read, buffer);
	return (line_read);
}

char *get_next_line(int file)
{
	char	*line_aux;
	int		stop;
	static char	*line_read;

	line_aux = malloc(1);
	line_aux = NULL;
	if (file < 0 || BUFFER_SIZE <= 0 || read(file, 0, 0) < 0)
		return (NULL);
	if (!line_read)
	{
		line_read = malloc(1);
		line_read[0] = '\0';
	}
	if (!ft_strchr(line_read, '\n'))
	{
		line_read = read_file(file, line_read);
		if (!ft_strchr(line_read, '\n'))
		{
			line_aux = ft_substr(line_read, 0, ft_strlen(line_read));
			//free(line_read);
			return (line_aux);
		}
	}
	line_aux = ft_substr(line_read, 0, ft_strlen(line_read) - ft_strlen((ft_strchr(line_read, '\n'))));
	line_read = ft_strchr(line_read, '\n') + 1;
	return (line_aux);
}

/*
char	*ft_open(char *filename)
{
	int fd1;
	char *table;
	
	fd1 = open(filename, O_RDONLY);
	table = get_next_line(fd1);
	printf("la linea leida es: %s\n", table);
	table = get_next_line(fd1);
	printf("la linea leida es: %s\n", table);
	table = get_next_line(fd1);
	printf("la linea leida es: %s\n", table);
	table = get_next_line(fd1);
	printf("la linea leida es: %s\n", table);
	table = get_next_line(fd1);
	printf("la linea leida es: %s\n", table);
	table = get_next_line(fd1);
	printf("la linea leida es: %s\n", table);
	table = get_next_line(fd1);
	printf("la linea leida es: %s\n", table);
	close(fd1);
	return (table);
}


int main()
{
	char	*filename;
	char	*dicts;
	
	filename = "test1.txt";
	dicts = ft_open(filename);
}
*/