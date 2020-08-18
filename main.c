#include <stdio.h>
#include "get_next_line.h"

int		main(void)
{
	int	fd;
	char **line;
	int size;

	line = malloc(sizeof(char*) * 10);
	// OPEN THE FILE
	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("\033[1;31mCould not open file\n");
		return 1;
	}
	else
	{
		printf("file opened, fd = %d\n", fd);
		size = 1;
		while (size > 0)
		{
			size = get_next_line(fd, &line[0]);
			if (!size)
				break;
			printf("size = %d\n", size);
			printf("line = %s<\n", line[0]);
		}
		printf("size = %d\n", size);
		printf("line = %s<\n", line[0]);
	}
	return (0);
}
