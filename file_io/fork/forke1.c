#include <stdio.h>
#include <unistd.h>

int main() {
	int x = 10;

	if (fork() == 0) {
 	   x = 20;
	   printf("Child x = %d\n", x);
	}  else  {
	   printf("Parent x = %d\n", x);
	}

	return 0;
}

