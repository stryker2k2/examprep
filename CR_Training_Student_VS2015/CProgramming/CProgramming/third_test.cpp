#include <gmock\gmock.h>
#include "RunCode.h"
#include "TestCode.h"


static int mlist[] = {
	10,
	NULL,
	20,
	89,
};

static char* unpackedBuf[] = {
	"this is the first string",
	"second string, so terrible.",
	"last, but not least!",
};

static char* packedBuf[] = {
	"~bcy*cy*~bo*lcxy~*y~xcdm",
};


TEST(TestSetThree, ObfuscateStringTest_obfuscate_first)
{
	char buf[MAX_PATH + 1] = { 0 };
	_snprintf(buf, MAX_PATH, "%s", unpackedBuf[0]);

	ASSERT_EQ(ERROR_SUCCESS, obfuscateString(buf, mlist[0]));
	ASSERT_EQ(ERROR_SUCCESS, strcmp(packedBuf[0], buf));
}

TEST(TestSetThree, ObfuscateStringTest_bad_input)
{
	ASSERT_EQ(ERROR_INVALID_PARAMETER, obfuscateString(NULL, mlist[0]));
	ASSERT_EQ(ERROR_INVALID_PARAMETER, obfuscateString(unpackedBuf[0], NULL));
}