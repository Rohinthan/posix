//fork example 2 

#include <stdio.h>
#include <unistd.h>

int main() {
	fork();
	fork();
	printf(" Hi\n");
	return 0;
}


/*

Output belike 


hi
hi
hi
hi

Why ?
	Each fork() doubles processes;

1 -> 2 -> 4

if you add many its you own risk to overload  your system be carefulll !


USE :

* shells use this (like bash)

* servers - handle multiple clients

* background processes

*/


