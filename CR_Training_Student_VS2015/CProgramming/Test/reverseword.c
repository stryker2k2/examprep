#include <windows.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////////
// Test 2: For this task, you will receive a pointer to NULL terminated string: 
//		   The objective will be to fix the sentence by reversing every occurence of
//         "drow" with "word"
//
// Expected Return Values:
//		- the task is successful: should return ERROR_SUCCESS (0).
//		- provided parameters are bad: should return ERROR_INVALID_PARAMETER (87)
//		- the word "drow" is not part of 'sentence': should return ERROR_NOT_FOUND (1168)
/////////////////////////////////////////////////////////////////////////////////////////////

int reverseWord(char *sentence)
{
	int success = 9999;
    int bool = 0;

    printf("Original Sentence: \"%s\"\n", sentence);

	if (sentence != NULL)
	{
        //TODO
		int len = strlen(sentence);
        //size_t len = strlen(sentence);
        char* newsentence = sentence;							// REMEMBER: you can't do 'strlen(newsentence)' on a 'char newsentence[64]'... it MUST be a 'char*'

        if(strstr(sentence, "drow") != NULL)
        {
			//printf("Contains drow\n");
			char* ptr = strstr(sentence, "drow");
			//printf("Pointer: %s\n", ptr);
			
			memcpy(newsentence, sentence, ptr - sentence);
			//printf("NewStr: %s\n", newsentence);
			memcpy(newsentence + (ptr - sentence), "word", 4);
			//printf("NewStr: %s\n", newsentence);

			bool = 1;
        }

        if(bool == 1)
        {            
            //printf("New Sentence: \"%s\"\n", newsentence);
            success = 0;
            strcpy(sentence, newsentence);
        }
        else
        {
            //printf("New Sentence: \"%s\"\n", newsentence);
            //printf("No \'y\' found!\n");
            success = 1168;
        }
    }

	else
    {
        //printf("Sentence is NULL\n");
        success = 87;
    }

	return success;
}