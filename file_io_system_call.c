#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int fd = creat("text3.txt",0644);
	printf("File created successfully \n");
	close(fd);
	return 0;
}
