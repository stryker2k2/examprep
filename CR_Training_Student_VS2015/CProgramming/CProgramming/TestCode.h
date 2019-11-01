#pragma once
#include <Windows.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct _node {
		char letter;
		struct _node* next;
	} node, *pnode;

	typedef struct _list {
		pnode head;
	} list, *plist;

	// Task One
	int changeLetterInString(char *sentence);

	// Task Two
	int reverseWord(char *sentence);

	// Task Three
	int obfuscateString(char *sentence, char key);

	// Task Four
	int combineStrings(char *sentence1, int sentence1Length, char *sentence2, int sentence2Length, int bufferSize);

	// Task Five
	int insertWord(char *sentence1, int sentence1Length, char *word, int wordLength, int position);

	// Task Six
	size_t determineSize(char* input);
	plist createList();
	pnode appendNode(plist nodeList, char nodeData);
	pnode insertNode(plist nodeList, char nodeData, int position);
	char removeNode(plist nodeList, int position);
	pnode letterList(char* input);

#ifdef __cplusplus
}
#endif