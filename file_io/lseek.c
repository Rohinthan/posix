#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("test.txt", O_RDONLY);

	lseek(fd, 6, SEEK_SET);

	char buffer[10];
	int n = read(fd, buffer, 5);

	write(1, buffer, n);

	close(fd);
	return 0;
}


/*

what does :

if file --> Hello file

	skip first 6 bytes --> start from " File "

lseek() structure

	off_t lseek(int fd, off_t offset, int whence);

whence			meaning

SEEK_SET		from start

SEEK_CUR		from current

SEEK_END		from end

*/
