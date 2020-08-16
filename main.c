#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line;
	char *buff;
	int	i;

	line = 0;
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while ((ret = get_next_line(fd, &buff)) > 0)
			{
				printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
				free(buff);
			}
			if (fd > 0 )
			{
				printf("End of %d file\n", i);
			}
			i++;
		}
//		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		close(fd);
	}
	if (argc == 1)
	{
		/* while ((ret = get_next_line(0, &buff)) > 0)
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("%d\n-----------\nError\n", ret);
		else if (ret == 0)
			printf("-----------\nEnd of stdin\n");  */
		printf("-----------\nError\n");
	}

/*	while (1)
	{

	}
*/
	return (0);
}
