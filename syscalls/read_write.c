#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
static char buf[256];

int main() {
	int n;
	n = read(0, buf, 255);
	if (n < 0) {
		perror("read");
		return 1;
	}
	n = write(1, buf, strlen(buf));
	if (n < 0) {
		perror("write");
		return 1;
	}
	return 0;
}
