#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main() {
	int	fd;

	fd = open("gnlTester/files/nl", O_RDWR);
	printf("1: %s", get_next_line(fd));
	printf("2: %s", get_next_line(fd));
	return (0);
}
