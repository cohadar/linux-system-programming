#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	char *file_name = "njak.txt";
	char *buff = malloc(8192);
	int fd = open(file_name, O_RDWR | O_CREAT, 0644);
	if (fd == -1) {
		sprintf(buff, "open[%s]", file_name);
		perror(buff);
		printf("%x %x\n", O_RDWR, O_RDWR | O_CREAT);
		exit(1);
	}
	printf("ok\n");
	return 0;
}
