#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char *file_name = "njak.txt";
	char *buff = malloc(8192);
	int fd = open(file_name, O_RDONLY);
	if (fd == -1) {
		sprintf(buff, "open[%s]", file_name);
		perror(buff);
		exit(1);
	}
	ssize_t err = read(fd, buff, 8192);
	if (err == -1) {
		sprintf(buff, "read[%s]", file_name);
		perror(buff);
		exit(1);
	}
	printf("%s", buff);
	return 0;
}
