#include <Windows.h>
#include <gmock\gmock.h>
#include "RunCode.h"
#include "TestCode.h"

int main(int argc, char** argv, char** envp)
{
	int status = ERROR_SUCCESS;

	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}