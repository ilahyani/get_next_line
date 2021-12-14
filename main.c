#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main() {
	int	fd;

	fd = open("gnlTester/files/41_no_nl", O_RDWR);
	printf("1: %s", get_next_line(fd));
	printf("2: %s", get_next_line(fd));
//	printf("\n");
//	printf("3: %s", get_next_line(fd));
	/*printf("4: %s", get_next_line(fd));
	printf("5: %s", get_next_line(fd));
	printf("6: %s", get_next_line(fd));
	printf("7: %s", get_next_line(fd));
	printf("8: %s", get_next_line(fd));
	printf("9: %s", get_next_line(fd));
	printf("10: %s", get_next_line(fd));
	*/
	return (0);
}
