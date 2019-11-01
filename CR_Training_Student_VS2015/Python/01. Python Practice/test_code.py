import os
from test_module import ERROR_NOT_FOUND, ERROR_INVALID

# STUDENT SECTION

#Given a directory, traverse through all sub-directories and build a dictionary with the directory as the key and a list
#of the .txt files as the value
def FileDict(dir):
    tempDict = {}
    fileDict = {}
    fileDict_array = []

    '''
    for dirName, subdirList, fileList in os.walk("testFolder"):
        print("\ndirName: {0}".format(dirName))
        for sdName in subdirList:
            print("\nsdName: {0}".format(sdName))
            for fname in fileList:
                print("\nfname: {0}".format(fname))
    '''
    for dirName, subdirList, fileList in os.walk(dir):
        #print("\ndirName: {0}".format(dirName))
        fname_array = []
        for fname in fileList:
            if fname.find("txt") != -1:
                fname_array.append(fname)
        tempDict.update({dirName: fname_array})
    #print "\ntempDict: {0}".format(tempDict)
    #print "fileDict_answr: {0}".format(fileDict)

    #TODO - os.walk is nearly complete.  Focus on putting dirName and fname into fileDict{}
    #TODO - check on how to incorporate the \\ delimiters

        #fileDict.add(dirName)
    #print("\nfileDict: {0}".format(fileDict))

    return tempDict

#Given a string, find all occurrences of badLtr and replace them with goodLtr. If you cannot find any
#of badLtr, return ERROR_NOT_FOUND (-1). If an invalid string is passed in, return ERROR_INVALID (-2)
def ChangeLetter(inputStr, badLtr, goodLtr):
    outputStr = ''
    answer = ''

    #print("\n{0}".format(inputStr))
    #print("\n{0}".format(badLtr))
    #print("\n{0}".format(goodLtr))

    def replacer(ltr):
        if ltr == badLtr:
            return goodLtr
        else:
            return ltr

    if (inputStr == None or inputStr == ''):
        outputStr = '-2'
    elif inputStr.find(badLtr) == -1:
        outputStr = "-1"
    else:
        for letter in inputStr:
            #print(letter)
            answer += replacer(letter)
            #answer = ''.join("marco polo")
        outputStr = answer
        #print("\nanswer is: {0}".format(answer))

    return outputStr

#Given a string and a word, find the word in the sentence and reverse it. Return the corrected string if the word is
#found, or ERROR_NOT_FOUND if the word is not in the string, or ERROR_INVALID if a parameter is invalid
def ReverseWord(inputStr, revWord):
    outputStr = ''
    answer = ''

    if inputStr == None or inputStr == '':
        outputStr = '-2'    # ERROR_INVALID
    elif inputStr.find(revWord) == -1:
        outputStr = "-1"    # ERROR_NOT_FOUND
    else:
        i = len(revWord)
        while i > 0:
            #print "i: {0}".format(i)
            answer += revWord[i-1]
            i = (i - 1)
        #print "answer: {0}".format(inputStr.replace(revWord, answer))
        outputStr = inputStr.replace(revWord, answer)

    return outputStr

#Given a string and a key, XOR each letter with the key and return the string. If a parameter is invalid, return
#ERROR_INVALID
def ObfuscateString(inputStr, key):
    #print "\ninputStr is: {0}".format(inputStr)
    #print "key is: {0}".format(key)

    answer = ''

    i = 0

    if (key == None or key == 0):
        answer = '-2'
    else:
        while i < len(inputStr):
            iord = ord(inputStr[i])
            kord = ord(chr(key))
            s1 = iord ^ kord
            #print "i: {0} - k: {1} - s1: {2}".format(iord, kord, s1)
            answer += chr(s1)
            i += 1

    outputStr = answer

    #print("outputStr is: {0}".format(outputStr))

    return outputStr

#Given two strings, combine them and return the total string. If a parameter is invalid, return ERROR_INVALID
def CombineStrings(string1, string2):

    if ((string1 == None or string1 == '') or (string2 == None or string2 == '')):
        outputStr = '-2'
    else:
        outputStr = string1 + string2

    return outputStr

#Given a string, insert the given word behind the target word. For instance, if given the sentence "insert the here",
#with the word to be inserted as "word" and the target as "the", the final string should be "insert the word here".
#If any parameter is invalid, return ERROR_INVALID
def InsertWord(inputStr, word, target):

    #print "\ninputStr: " + inputStr
    #print "\nword: " + word
    #print "\ntarget: " + target

    if (word == None or word == ''):
        outputStr = '-2'
    else:
        answer = target + word
        #print "\nanswer: " + answer
        outputStr = inputStr.replace(target, answer)

    return outputStr

#Given a string and a word, delete the word from the string and return the modified string. If the target word cannot
#be found, return ERROR_NOT_FOUND.
def DeleteWord(inputStr, word):

    #print "\ninputStr: " + inputStr
    #print "\nword: " + word

    outputStr = ''
    answer = ''

    answer = inputStr.find(word)
    #print "\nanswer is: {0}".format(answer)
    if answer < 0:
        outputStr = '-1'
    else:
        # answer = target + word
        # print "\nanswer: " + answer
        outputStr = inputStr.replace(word, "")

    """
    if (word == None or word == ''):
        outputStr = '-1'
    else:
        #answer = target + word
        #print "\nanswer: " + answer
        outputStr = inputStr.replace(word, "")
    """

    return outputStr
