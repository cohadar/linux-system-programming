#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd = creat("njak.txt", 0644);
	if (fd == -1) {
		perror("open[njak.txt]");
	}
	char *text = "trla baba lan\nda joj prodje dan.\n";
	ssize_t nw = write(fd, text, strlen(text));
	if (nw == -1) {
		perror("write");
	} 
	return 0;
}