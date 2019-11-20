#include <windows.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////////
// Test 5: For this task, you will receive a pointer to NULL terminated string: 
//		   The objective will be to insert the missing word into the sentence.
//         "O'er the land of the <insert> and the home of the brave."
//			The word "free" is missing and needs to be inserted
//
// Expected Return Values:
//		- the task is successful: should return ERROR_SUCCESS (0).
//		- provided parameters are bad: should return ERROR_INVALID_PARAMETER (87)
/////////////////////////////////////////////////////////////////////////////////////////////
int insertWord(char *sentence, int sentenceLength, char *word, int wordLength, int loc)
{
    int success = 9999;

    if(sentence != NULL && sentenceLength != 0)
    {
        char str1[32];
        char str2[32];
        int x = 0;
        for (int i = 0; i <= sentenceLength; i++)
        {
            if (i < loc)
            {
                str1[i] = sentence[i];
            }
            else if (i == loc)
            {
                str1[i] = '\0';                          // REMEMBER the NULL TERMINATOR!
            }
            else if (i > loc && i < sentenceLength)
            {                
                str2[x] = sentence[i];
                x++;
                //printf("ping");
            }
            else
            {
                str2[x] = '\0';
            }
        }
        printf("str1 is: %s\n", str1);
        printf("word is: %s\n", word);
        printf("str2 is: %s\n", str2);
        strcat(str1, word);
        strcat(str1, str2);        

        memcpy(sentence, str1, sentenceLength + wordLength);
        success = 0;
    }

    else
    {
        printf("Sentence is NULL\n");
        success = 87;
    }

	return success;
}