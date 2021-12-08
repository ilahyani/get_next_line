#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main() {
	int	fd;

	fd = open("test.txt", O_CREAT | S_IRWXU);
	printf("|%s|\n", get_next_line(fd));
	return (0);
}
