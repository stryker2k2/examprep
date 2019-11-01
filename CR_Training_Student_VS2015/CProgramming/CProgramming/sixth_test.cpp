#include <Windows.h>
#include <stdio.h>
#include <iostream>

#include <gmock\gmock.h>
#include "TestCode.h"

/*
const char* DLL_PATH = "\\LinkedListTest.dll";
char separatedAlphabet[] = "a,b,c,d,e,f";
const char* correctAlphabet = "fedcba";
typedef plist(__cdecl *PROCADDR1)(void);
typedef pnode(__cdecl *PROCADDR2)(pnode);
typedef void(__cdecl *PROCADDR3)(plist, char);
typedef char* (__cdecl *PROCADDR4)(pnode);

TEST(TestSetSix, correctSizeTest) {
	size_t correctLen = strlen(correctAlphabet);
	ASSERT_EQ(correctLen, determineSize(separatedAlphabet)) << "Incorrect size";
}

TEST(TestSetSix, createTest) {
	plist nodeList = createList();
	ASSERT_EQ(NULL, nodeList->head) << "Node list not initialized correctly";
}

TEST(TestSetSix, appendTest) {
	HMODULE linkedList;
	PROCADDR1 createTestList;
	PROCADDR2 nodeCheck;
	plist nodeList;
	pnode firstNode, secondNode;

	linkedList = LoadLibrary(DLL_PATH);
	if (linkedList != NULL) {
		createTestList = (PROCADDR1)GetProcAddress(linkedList, "CreateListHead");
		nodeCheck = (PROCADDR2)GetProcAddress(linkedList, "NodeCheck");
		if (createTestList != NULL) {
			nodeList = createTestList();
			firstNode = appendNode(nodeList, 'a');
			ASSERT_EQ('a', firstNode->letter) << "Incorrect data in first node";
			ASSERT_EQ(NULL, nodeCheck(firstNode)) << "Incorrect next pointer";
			secondNode = appendNode(nodeList, 'b');
			ASSERT_EQ('b', secondNode->letter) << "Incorrect data in second node";
			ASSERT_EQ(firstNode, nodeCheck(secondNode)) << "New node does not link to correct node";
			ASSERT_EQ(firstNode, nodeCheck(nodeList->head)) << "Head node does not point at correct node";
			FreeLibrary(linkedList);
		}
	}
	else {
		//printf("Could not load Test DLL\n");
	}
}

TEST(TestSetSix, insertTest) {
	HMODULE linkedList;
	PROCADDR1 createTestList;
	PROCADDR2 nodeCheck;
	PROCADDR3 addNode;
	plist nodeList;
	pnode firstNode;
	int i;

	linkedList = LoadLibrary(DLL_PATH);
	if (linkedList != NULL) {
		createTestList = (PROCADDR1)GetProcAddress(linkedList, "CreateListHead");
		nodeCheck = (PROCADDR2)GetProcAddress(linkedList, "NodeCheck");
		addNode = (PROCADDR3)GetProcAddress(linkedList, "AddNode");
		if (createTestList != NULL) {
			nodeList = createTestList();
			for (i = 0; i < 5; i++) {
				addNode(nodeList, 'a');
			}
			firstNode = insertNode(nodeList, 'b', 2);
			pnode current = nodeList->head->next;
			ASSERT_EQ(firstNode, nodeCheck(current)) << "Node not in correct position";
			ASSERT_EQ('b', firstNode->letter) << "Incorrect data";
			FreeLibrary(linkedList);
		}
	}
	else {
		//printf("Could not load Test DLL\n");
	}
}

TEST(TestSetSix, removeTest) {
	HMODULE linkedList;
	PROCADDR1 createTestList;
	PROCADDR2 nodeCheck;
	PROCADDR3 addNode;
	plist nodeList;
	int i;
	char buf[2];
	char data;

	linkedList = LoadLibrary(DLL_PATH);
	if (linkedList != NULL) {
		createTestList = (PROCADDR1)GetProcAddress(linkedList, "CreateListHead");
		nodeCheck = (PROCADDR2)GetProcAddress(linkedList, "NodeCheck");
		addNode = (PROCADDR3)GetProcAddress(linkedList, "AddNode");
		if (createTestList != NULL) {
			nodeList = createTestList();
			for (i = 4; i >= 0; i--) {
				_itoa(i, buf, 10);
				addNode(nodeList, *buf);
			}
			pnode current = nodeList->head->next;
			pnode nextCurrent = current->next->next;
			data = removeNode(nodeList, 2);
			ASSERT_EQ(nextCurrent, nodeCheck(current)) << "Node not removed";
			ASSERT_EQ('3', nextCurrent->letter) << "Incorrect data";
			FreeLibrary(linkedList);
		}
	}
	else {
		//printf("Could not load Test DLL\n");
	}
}

TEST(TestSetSix, letterListTest) {
	char separatedAlphabet[] = "a,b,c,d,e,f";
	HMODULE linkedList;
	PROCADDR4 walkTestList;
	pnode headNode;
	char* output;

	headNode = letterList(separatedAlphabet);
	linkedList = LoadLibrary(DLL_PATH);
	if (linkedList != NULL) {
		walkTestList = (PROCADDR4)GetProcAddress(linkedList, "WalkList");
		if (walkTestList != NULL) {
			output = walkTestList(headNode);
			ASSERT_EQ(strcmp(correctAlphabet, output), 0) << "Incorrect return string";
			FreeLibrary(linkedList);
		}
	}
	else {
		//printf("Could not load Test DLL\n");
	}
}
*/