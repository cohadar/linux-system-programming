#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

static const char *S1 = "trla baba lan\n";
static const char *S2 = "da joj prođe dan\n";

int main() {
	int n, fd;
	fd = open("baba.txt", O_WRONLY|O_CREAT|O_TRUNC|O_APPEND, 0644);
	if (fd < 0) { perror("open"); return 1; }
	n = write(fd, S1, strlen(S1));
	if (n < 0) { perror("write(S1)"); return 1; }
	n = write(fd, S2, strlen(S2));
	if (n < 0) { perror("write(S2)"); return 1; }
	return 0;
}
