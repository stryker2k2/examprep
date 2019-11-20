#include <windows.h>
#include <stdio.h>
#include "header.h"

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

static char* unpackedBuf[] = 
{
	"this is the first string",
	"second string, so terrible.",
	"last, but not least!",
};

static int mlist[] = 
{
	10,
	(int)NULL,
	20,
	89,
};

static char* stringlist04[] = 
{
	"this is a string",
	" and this is the string to concatenate",
	" and this is another string but way to long to fit into the buffer",
	"this is a string and this is the string to concatenate",
	NULL,
};

static char* addStr[] = 
{
	" free ",
	NULL,
	"this",
	"nope",
	"string",
	"not",
};

static char* removed[] = 
{
	"O'er the land of the and the home of the brave.",
	"this is also a , unlike the first string",
	"another one,  a great one, and not really like the last two.",
};

int testOne()
{
    int ret = 9999;

    printf("\n////TEST ONE - CHANGE LETTER////\n");

    char buf[MAX_PATH + 1] = {0};

    // Change Letter Test - Correct a Letter
    _snprintf(buf, MAX_PATH, "%s", stringlist01[0]);    
    ret = changeLetterInString(buf);
    printf("Return is: %d [Success]\n", ret);
    printf("Buffer is now: %s\n\n", buf);

    // Change Letter Test - Invalid Parameter
    _snprintf(buf, MAX_PATH, "%s", NULL);
    ret = changeLetterInString(NULL);
    printf("Return is: %d [Invalid Parameter]\n", ret);
    printf("Buffer is now: %s\n\n", buf);

    // Change Letter Test - Item Not Found
    _snprintf(buf, MAX_PATH, "%s", stringlist01[1]); 
    ret = changeLetterInString(buf);
    printf("Return is: %d [Item Not Found]\n", ret);
    printf("Buffer is now: %s\n\n", buf);
    
}

int testTwo()
{
    int ret = 9999;

    printf("\n////TEST TWO - REVERSE WORD////\n");

    char buf[MAX_PATH + 1] = {0};

    // Reverse Word Test - Correct a Word
    _snprintf(buf, MAX_PATH, "%s", stringlist02[0]);
    ret = reverseWord(buf);
    printf("Return is: %d [Success]\n", ret);
    printf("Buffer is now: %s\n\n", buf);

    // Reverse Word Test - Invalid Parameter
    _snprintf(buf, MAX_PATH, "%s", NULL);
    ret = reverseWord(NULL);
    printf("Return is: %d [Invalid Parameter]\n", ret);
    printf("Buffer is now: %s\n\n", buf);

    //Reverse Word Test - Item Not Found
    _snprintf(buf, MAX_PATH, "%s", stringlist02[1]);
    ret = reverseWord(buf);
    printf("Return is: %d [Item Not Found]\n", ret);
    printf("Buffer is now: %s\n\n", buf);

}

int testThree()
{
    int ret = 9999;

    printf("\n////TEST THREE - OBFUSCATE STRING////\n");

    char buf[MAX_PATH + 1] = { 0 };

    //Obfuscate String Test - Success
    _snprintf(buf, MAX_PATH, "%s", unpackedBuf[0]);
    ret = obfuscateString(buf, mlist[0]);
    printf("Return is: %d [Success]\n", ret);
    printf("Buffer is now: %s\n\n", buf);

    //Obfuscate String Test - Invalid Parameter
    _snprintf(buf, MAX_PATH, "%s", NULL);
    ret = obfuscateString(NULL, mlist[0]);
    printf("Return is: %d [Invalid Parameter]\n", ret);
    printf("Buffer is now: %s\n\n", buf);
}

int testFour()
{
    int ret = 9999;

    printf("\n////TEST FOUR - COMBINE STRINGS////\n");

    //Combine Strings Test - Success
    char buf1[65] = { 0 };
    _snprintf(buf1, 60, "%s", stringlist04[0]);
	int bufLength = strlen(buf1);
	int stringlist04Length1 = strlen(stringlist04[1]);
    ret = combineStrings(buf1, bufLength, stringlist04[1], stringlist04Length1, sizeof(buf1));
    printf("Return is: %d [Success]\n", ret);
    printf("Buffer is now: %s\n\n", buf1);


    //Combine Strings Test - Invalid Parameter
    char buf2[60] = { 0 };
	_snprintf(buf2, 60, "%s", stringlist04[0]);
    int stringlist04Length0 = strlen(stringlist04[0]);
	int stringlist04Length2 = strlen(stringlist04[2]);
    _snprintf(buf2, MAX_PATH, "%s", NULL);

    ret = combineStrings(NULL, bufLength, stringlist04[0], stringlist04Length0, sizeof(buf2));
    printf("Return is: %d [Invalid Parameter]\n", ret);
    printf("Buffer is now: %s\n\n", buf2);

    ret = combineStrings(buf2, bufLength, NULL, stringlist04Length0, sizeof(buf2));
    printf("Return is: %d [Invalid Parameter]\n", ret);
    printf("Buffer is now: %s\n\n", buf2);

    ret = combineStrings(buf2, bufLength, stringlist04[2], stringlist04Length2, sizeof(buf2));
    printf("Return is: %d [Invalid Parameter]\n", ret);
    printf("Buffer is now: %s\n\n", buf2);
}

int testFive()
{
    int ret = 9999;

    printf("\n////TEST FIVE - INSERT WORD////\n");

    //Combine Strings Test - Success
	char buf[MAX_PATH + 1] = { 0 };
	_snprintf(buf, MAX_PATH, "%s", removed[0]);
	int bufLength = strlen(buf);
	int addStrLength = strlen(addStr[0]);
    ret = insertWord(buf, bufLength, addStr[0], addStrLength, (int)20);
    printf("Return is: %d [Success]\n", ret);
    printf("Buffer is now: %s\n\n", buf);

    //Combine Strings Test - Invalid Parameter
    _snprintf(buf, MAX_PATH, "%s", NULL);
    ret = insertWord(NULL, 0, addStr[0], addStrLength, (int)21);
    printf("Return is: %d [Invalid Parameter]\n", ret);
    printf("Buffer is now: %s\n\n", buf);

    //Combine Strings Test - Invalid Parameter
    _snprintf(buf, MAX_PATH, "%s", NULL);
    ret = insertWord(NULL, 0, addStr[1], addStrLength, (int)21);
    printf("Return is: %d [Invalid Parameter]\n", ret);
    printf("Buffer is now: %s\n\n", buf);
}

int main()
{
    testOne();    

    testTwo();

    testThree();

    testFour();

    testFive();

    return 0;
}


// Compile: c:\> gcc *.h *.c -o testcode.exe