#include <gmock\gmock.h>
#include <Windows.h>
#include "RunCode.h"
#include "TestCode.h"

static char* corrected[] = {
	"this is a string",
	"this is also a , unlike the first string",
	"another one,  a great one, and not really like the last two.",
};

static char* stringlist[] = {
	"thiy iy a ytring",
	"this is also a string, unlike the first string",
	"another one, not a great one, and not really like the last two.",
	"a third string!",
	NULL,
};

TEST(TestSetOne, ChangeLetterTest_correct_a_letter)
{
	char buf[MAX_PATH + 1] = { 0 };
	_snprintf(buf, MAX_PATH, "%s", stringlist[0]);

	ASSERT_EQ(ERROR_SUCCESS, changeLetterInString(buf));
	ASSERT_EQ(ERROR_SUCCESS, strcmp(buf, corrected[0]));
}

TEST(TestSetOne, ChangeLetterTest_bad_input)
{
	ASSERT_EQ(ERROR_INVALID_PARAMETER, changeLetterInString(NULL));
}

TEST(TestSetOne, ChangeLetterTest_item_not_found)
{
	char buf[MAX_PATH + 1] = { 0 };
	_snprintf(buf, MAX_PATH, "%s", stringlist[1]);

	ASSERT_EQ(ERROR_NOT_FOUND, changeLetterInString(buf));
}