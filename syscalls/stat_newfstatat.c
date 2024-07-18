#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int
main(int argc, char *argv[])
{
	struct stat sb;
	if (stat("baba.txt", &sb) < 0) { perror("lstat"); return 1; }
	printf("[baba.txt] Last file modification: %s", ctime(&sb.st_mtime));
	return 0;
}

