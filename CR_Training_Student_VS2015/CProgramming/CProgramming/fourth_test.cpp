#include <gmock\gmock.h>
#include "RunCode.h"
#include "TestCode.h"

static char* stringlist[] = {
	"this is a string",
	" and this is the string to concatenate",
	" and this is another string but way to long to fit into the buffer",
	"this is a string and this is the string to concatenate",
	NULL,
};


TEST(TestSetFour, CombineStringsTest_string_cat)
{
	char buf[65] = { 0 };
	_snprintf(buf, 60, "%s", stringlist[0]);

	int bufLength = strlen(buf);
	int stringlistLength = strlen(stringlist[1]);

	ASSERT_EQ(ERROR_SUCCESS, combineStrings(buf, bufLength, stringlist[1], stringlistLength, sizeof(buf)));
	ASSERT_EQ(ERROR_SUCCESS, strcmp(stringlist[3], buf));
}

TEST(TestSetFour, CombineStringsTest_bad_input)
{
	char buf[60] = { 0 };
	_snprintf(buf, 60, "%s", stringlist[0]);

	int bufLength = strlen(buf);
	int stringlistLength = strlen(stringlist[0]);
	int stringlistLength2 = strlen(stringlist[2]);

	ASSERT_EQ(ERROR_INVALID_PARAMETER, combineStrings(NULL, bufLength, stringlist[0], stringlistLength, sizeof(buf)));
	ASSERT_EQ(ERROR_INVALID_PARAMETER, combineStrings(buf, bufLength, NULL, stringlistLength, sizeof(buf)));
	ASSERT_EQ(ERROR_INVALID_PARAMETER, combineStrings(buf, bufLength, stringlist[2], stringlistLength2, sizeof(buf)));
}