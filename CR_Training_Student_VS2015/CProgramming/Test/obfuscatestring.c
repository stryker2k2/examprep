#include <windows.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////////
// Test 3: For this task, you will receive a pointer to NULL terminated string: 
//		   The objective will be to obfuscate the sentence by "ZORing" (XORing) each byte with the
//         given key
//
// Expected Return Values:
//		- the task is successful: should return ERROR_SUCCESS (0).
//		- provided parameters are bad: should return ERROR_INVALID_PARAMETER (87)
//
// Answer is:
//      - ~bcy*cy*~bo*lcxy~*y~xcdm
/////////////////////////////////////////////////////////////////////////////////////////////

int obfuscateString(char *sentence, char key)
{
	int success = 9999;
    int bool = 0;
    printf("Original Sentence: \"%s\"\n", sentence);
    printf("Original Key: '%d'\n", (int)key);

    if(sentence != NULL)
    {
        int len = strlen(sentence);
        char newstring[len];
        
        //printf("Original Hex Sentence:\t\"%p\"\n", sentence);
        //printf("Original Hex Key:\t'0X%X'\n", (int)key);
        
        for (int i = 0; i < len; i++)
        {
            //printf("Value %d is '%c' which is '%p' in hex and '%p' in xor hex which is '%c' in ASCII\n", i, sentence[i], sentence[i], sentence[i] ^ key, sentence[i] ^ key);
                    
            newstring[i] = sentence[i] ^ key;
        }

        memcpy(sentence, newstring, len);

        success = 0;
    }

    else
    {
        success = 87;
    }
    




    //Obfuscate String Test - Success

    //Obfuscate String Test - Bad Input

	return success;
}