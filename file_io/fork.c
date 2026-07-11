#include <stdio.h>
#include <unistd.h>

int main() {
	fork();
	printf("hello\n");
	return 0;
}


/*

fork()

Your program can dublicate itself to confuse you how its create twist

This function confuse the new programmer to call itself 2 processes

	* Parent
	* Child

so output be like

hello

hello  <-- this

*/
