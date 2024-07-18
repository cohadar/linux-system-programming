#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define N 256
static char buf[N];

int main() {
	int n, fd;
	fd = open("baba", O_RDONLY);
	/* printf("%ld\n", sizeof(buf)); */
	if (fd < 0) {
		perror("open");
		return -1;
	}
	while ((n = read(fd, buf, 20)) > 0) {
		puts("===");
		buf[n] = '\0';
		puts(buf);
		puts("---");
	}
	if (n < 0) {
		perror("read");
		return -1;
	}
	puts("The End.");
	return 0;
}
