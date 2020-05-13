#include <stdio.h>
#include <string.h>

void return_input(char *buffer1)
{
	char buffer2[30];

	//gets(buffer2);
	strcpy(buffer2, buffer1);
	printf("%s\n", buffer2);
}

int main(int argc, char **argv)
{
	return_input(argv[1]);

	return 0;
}
