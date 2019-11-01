#include <gmock\gmock.h>
#include <Windows.h>
#include "RunCode.h"
#include "TestCode.h"

static char* corrected[] = {
	"this string has a bad word",
	"this is also a , unlike the first string",
	"another one,  a great one, and not really like the last two.",
};

static char* stringlist[] = {
	"this string has a bad drow",
	"this is also a string, unlike the first string, has a good word",
	"another one, not a great one, and not really like the last two.",
	"a third string!",
	NULL,
};

TEST(TestSetTwo, ReverseWordTest_correct_a_word)
{
	char buf[MAX_PATH + 1] = { 0 };
	_snprintf(buf, MAX_PATH, "%s", stringlist[0]);

	ASSERT_EQ(ERROR_SUCCESS, reverseWord(buf));
	ASSERT_EQ(ERROR_SUCCESS, strcmp(buf, corrected[0]));
}

TEST(TestSetTwo, ReverseWordTest_bad_input)
{
	ASSERT_EQ(ERROR_INVALID_PARAMETER, reverseWord(NULL));
}

TEST(TestSetTwo, ReverseWordTest_item_not_found)
{
	char buf[MAX_PATH + 1] = { 0 };
	_snprintf(buf, MAX_PATH, "%s", stringlist[1]);
	ASSERT_EQ(ERROR_NOT_FOUND, reverseWord(buf));
}