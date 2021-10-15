#include "get_next_line.h"
#include <fcntl.h>
# include <stdio.h>

int	main(void)
{
	int		fd;
	char	*archive;
	
	//fd = open("fichero", O_RDONLY);
	fd = 0;
	archive = get_next_line(fd);
	while (archive)
	{
		free(archive);
		printf("%s", archive);
		archive = get_next_line(fd);
	}
	free(archive);
    close(fd);
	//system("\nleaks -q a.out");
	return (0);
}