#include <windows.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////////
// Test 4: For this task, you will receive a pointer to NULL terminated string: 
//		   The objective will be to concatenate sentence1 and sentence2
//         sentence1 will hold the concatenated strings
//
// Expected Return Values:
//		- the task is successful: should return ERROR_SUCCESS (0).
//		- provided parameters are bad: should return ERROR_INVALID_PARAMETER (87)
/////////////////////////////////////////////////////////////////////////////////////////////

int combineStrings(char *sentence1, int sentence1Length, char *sentence2, int sentence2Length, int bufferSize)
{
	int success = 9999;
    int bool = 0;

    if(sentence1 != NULL && sentence1Length != 0 && sentence2 != NULL && sentence2Length != 0)
    {
        if (sentence1Length + sentence2Length > bufferSize)
        {
            printf("Status: Too big for the buffer\n");
            success = 87;
        }
        else
        {
            printf("Status: Concatenating Sentences\n");
            strcat(sentence1, sentence2);
            bool = 1;
            success = 0;
        }

    }
    
    else
    {
        printf("Status: Something is NULL or ZERO\n");
        bool = 0;
        success = 87;
    }
    

	return success;
}