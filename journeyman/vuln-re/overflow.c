#include <stdio.h>
#include <string.h>

void return_input(char *buffer1)
{
	char buffer2[9];

	//gets(buffer2);
	strcpy(buffer2, buffer1);
	printf("%s\n", buffer2);
}

int main(int argc, char **argv)
{
	return_input(argv[1]);

	return 0;
}

/// TO COMPILE: ///
//
// c:\> gcc -mpreferred-stack-boundary=2 -ggdb overflow.c -o overflow.exe
// c:\> gcc -fno-stack-protector -m32 overflow.c -o overflow.exe
//
///////////////////
