#include <windows.h>
#include <stdio.h>

static char* stringlist01[] = 
{
	"thiy iy a ytring",
	"this is also a string, unlike the first string",
	"another one, not a great one, and not really like the last two.",
	"a third string!",
	NULL,
};

static char* stringlist02[] = 
{
	"this string has a bad drow",
	"this is also a string, unlike the first string, has a good word",
	"another one, not a great one, and not really like the last two.",
	"a third string!",
	NULL,
};

int testOne()
{
    int ret = 9999;

    printf("////TEST ONE////\n\n");

    ret = changeLetterInString(stringlist01[0]);
    printf("Return is: %d\n\n", ret);

    ret = changeLetterInString(NULL);
    printf("Return is: %d\n\n", ret);

    ret = changeLetterInString(stringlist01[1]);
    printf("Return is: %d\n\n", ret);
}

int testTwo()
{
    int ret = 9999;

    printf("////TEST TWO////\n\n");

    ret = reverseWord(stringlist02[0]);
    printf("Return is: %d\n\n", ret);

    ret = reverseWord(NULL);
    printf("Return is: %d\n\n", ret);

    ret = reverseWord(stringlist02[1]);
    printf("Return is: %d\n\n", ret);
}

int main()
{
    testOne();

    printf("Stringlist01[0] is now: %s\n", stringlist01[0]);

    testTwo();

    return 0;
}


// Compile: c:\> gcc *.c -o testcode.exe