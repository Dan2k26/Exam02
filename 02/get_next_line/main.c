#include "get_next_line.h"
#include <fcntl.h>
# include <stdio.h>

int	main(void)
{
	int		fd;
	char	*archive;
	fd = open("fichero", O_RDONLY);
	archive = get_next_line(0);
	while (archive)
	{
		free(archive);
		printf("Archivo: %s", archive);
		archive = get_next_line(0);
	}
	free(archive);
    close(fd);
	//system("\nleaks -q gnl.out");
	return (0);
}