#include <windows.h>
#include <stdio.h>

////////
// For this task, you will receive a pointer to NULL terminated string: 
// The objective will be to fix any words incorrectly spelled words by replacing
// every occurence of the letter 'y' with 's'.
////////
// If successful: return 0
// If params bad: return 87
// If no 'y':     return 1168
////////

int changeLetterInString(char *sentence)
{    
	int success = 9999;
    int bool = 0;

    printf("Original Sentence: \"%s\"\n", sentence);

    if (sentence != NULL)
    {
        //TODO
        int len = strlen(sentence);
        char newsentence[15];

        //printf("Sentence is not NULL\n");
        //printf("String Length is: %d\n", len);

        for(int i = 0; i < strlen(sentence); i++)
        {
            //printf("%c\n", sentence[i]);
            if (sentence[i] == 'y')
            {
                bool = 1;
                newsentence[i] = 's';
            }
            else
            {
                newsentence[i] = sentence[i];
            }
            
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