#include "get_next_line.h"

static int	count_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_join(char *str, char buff)
{
	int	len;
	int	i;
	char	*join;

	i = 0;
	len = count_str(str);
	join = malloc(sizeof(char) * len + 2);
	if (join == NULL)
		return (NULL);
	while (i < len)
	{
		join[i] = str[i];
		i++;
	}
	join[len] = buff;
	join[len + 1] = '\0';
	return (join);
}

char	*get_next_line(int fd)
{
	ssize_t	size;
	char	buff[2];
	char	*line;
	char	*aux;
	int		cont;

	if (read(fd, buff, 0) == -1 || fd < 0)
		return (NULL);
	size = read(fd, buff, 1);
	if (size == 0 || size == -1)
		return (NULL);
	buff[1] = '\0';
	line = "";
	cont = 0;
	while (size > 0)
	{
		aux = line;
		line = ft_join(aux, buff[0]);
		if (cont != 0)
			free(aux);
		if (line == NULL)
			return (NULL);
		if (buff[0] == '\n')
			return (line);
		size = read(fd, buff, 1);
		if (size == 0 || buff[0] == '\0')
			return (line);
		if (size == 0)
			return (NULL);
		buff[1] = '\0';
		cont++;
	}
	return (line);
}
