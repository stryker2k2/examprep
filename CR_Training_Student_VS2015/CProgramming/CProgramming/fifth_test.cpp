#include <gmock\gmock.h>
#include <Windows.h>
#include "RunCode.h"
#include "TestCode.h"


static char* addStr[] = {
	" free ",
	NULL,
	"this",
	"nope",
	"string",
	"not",
};

static char* removed[] = {
	"O'er the land of the and the home of the brave.",
	"this is also a , unlike the first string",
	"another one,  a great one, and not really like the last two.",
};

static char* stringlist[] = {
	"O'er the land of the free and the home of the brave.",
	"this is also a string, unlike the first string",
	"another one, not a great one, and not really like the last two.",
	"a third string!",
	NULL,
};

TEST(TestSetFive, InsertWordTest_add_a_word)
{
	char buf[MAX_PATH + 1] = { 0 };
	_snprintf(buf, MAX_PATH, "%s", removed[0]);

	int bufLength = strlen(buf);
	int addStrLength = strlen(addStr[0]);

	ASSERT_EQ(ERROR_SUCCESS, insertWord(buf, bufLength, addStr[0], addStrLength, (int)20));
	ASSERT_EQ(ERROR_SUCCESS, strcmp(buf, stringlist[0]));
}


TEST(TestSetFive, InsertWordTest_bad_input)
{
	int addStrLength = strlen(addStr[0]);

	ASSERT_EQ(ERROR_INVALID_PARAMETER, insertWord(NULL, 0, addStr[0], addStrLength, (int)21));
	ASSERT_EQ(ERROR_INVALID_PARAMETER, insertWord(NULL, 0, addStr[1], addStrLength, (int)21));
}
