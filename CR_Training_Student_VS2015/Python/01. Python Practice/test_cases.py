import unittest
from test_module import testDir, chngLetters, correctSentences, reverseWords, obfuscatedStrings, combineSentences, key,\
    insertSentences, deleteWords, correctDict, ERROR_INVALID, ERROR_NOT_FOUND
import test_code

class TestDictionaryMethod(unittest.TestCase):
    def test_dictionary(self):
        output = test_code.FileDict(testDir)
        for key in output:
            output[key].sort()
        self.assertEqual(output, correctDict)

class TestChangeLetter(unittest.TestCase):
    def test_ChangeLetter(self):
        output = test_code.ChangeLetter(chngLetters['str1'], chngLetters['bad1'], chngLetters['good1'])
        self.assertEqual(output, correctSentences[0])
    def test_ChangeLetterBad(self):
        output = test_code.ChangeLetter(chngLetters['str2'], chngLetters['bad2'], chngLetters['good2'])
        self.assertEqual(output, ERROR_NOT_FOUND)
    def test_ChangeLetterNone(self):
        output = test_code.ChangeLetter('', 'a', 'x')
        self.assertEqual(output, ERROR_INVALID)

class TestReverseWord(unittest.TestCase):
    def test_ReverseWord(self):
        output = test_code.ReverseWord(reverseWords['str1'], reverseWords['bad1'])
        self.assertEqual(output, correctSentences[1])
    def test_ReverseWordBad(self):
        output = test_code.ReverseWord(reverseWords['str2'], reverseWords['bad2'])
        self.assertEqual(output, ERROR_NOT_FOUND)
    def test_ReverseWordNone(self):
        output = test_code.ReverseWord('', reverseWords['bad2'])
        self.assertEqual(output, ERROR_INVALID)

class TestObfuscateString(unittest.TestCase):
    def test_ObfuscateString(self):
        output = test_code.ObfuscateString(obfuscatedStrings[0], key[0])
        self.assertEqual(output, correctSentences[2])
    def test_ObfuscateStringNone(self):
        output = test_code.ObfuscateString(obfuscatedStrings[0], key[1])
        self.assertEqual(output, ERROR_INVALID)

class TestCombineStrings(unittest.TestCase):
    def test_CombineStrings(self):
        output = test_code.CombineStrings(combineSentences[0], combineSentences[1])
        self.assertEqual(output, correctSentences[3])
    def test_CombineStringsNone(self):
        output = test_code.CombineStrings('', combineSentences[1])
        self.assertEqual(output, ERROR_INVALID)

class TestInsertWord(unittest.TestCase):
    def test_InsertWord(self):
        output = test_code.InsertWord(insertSentences['str1'], insertSentences['ins1'], insertSentences['tgt1'])
        self.assertEqual(output, correctSentences[4])
    def test_InsertWordNone(self):
        output = test_code.InsertWord(insertSentences['str1'], '', insertSentences['tgt1'])
        self.assertEqual(output, ERROR_INVALID)

class TestDeleteWord(unittest.TestCase):
    def test_DeleteWord(self):
        output = test_code.DeleteWord(deleteWords['str1'], deleteWords['del1'])
        self.assertEqual(output, correctSentences[5])
    def test_DeleteWordBad(self):
        output = test_code.DeleteWord(deleteWords['str2'], deleteWords['del2'])
        self.assertEqual(output, ERROR_NOT_FOUND)