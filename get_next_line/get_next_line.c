#include "get_next_line.h"

char *get_next_line(int file)
{
	int		i;
	char	*buffer;
	char	*line_aux;
	int		stop;
	static char	*line_read;

	i = 0;
	stop = 0;
	line_aux = malloc(1);
	line_read = malloc(1);
	line_aux = NULL;
	line_read = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if ((read(file, &buffer, BUFFER_SIZE) != 0) && (stop == 0))
	{
		line_read = ft_strjoin(line_read, buffer);
		if (ft_strchr(line_read, '\n'))
		{
			stop = 1;
			line_aux = ft_substr(line_read, 0, ft_strlen(line_read) - ft_strlen((ft_strchr(line_read, '\n'))) - 1);
			line_read = ft_strchr(line_read, '\n');
			printf("line read es:%s\n", line_read);
			printf("line aux es:%s\n", line_aux);
		}
	}
	return (line_aux);
}


char	*ft_open(char *filename)
{
	int fd1;
	char *table;
	
	fd1 = open(filename, O_RDONLY);
	table = get_next_line(fd1);
	printf("la linea leida es: %s\n", table);
	close(fd1);
	return (table);
}


int main()
{
	char	*filename;
	char	*dicts;
	
	filename = "test.txt";
	dicts = ft_open(filename);
}
