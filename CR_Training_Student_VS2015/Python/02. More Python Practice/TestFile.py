#!/usr/bin/env python

import os, subprocess
from collections import OrderedDict

"""
# Given a folder directory, build a dictionary that contains the file path as a key and files
# contained in it as the values in a list.
# example:  on the desktop, Folder1 contains two jpegs and another folder named Folder2. Folder2 has two txt files.
# The dictionary would look like 
	file_dict = {'desktop\Folder1': ['my_jpg1','my_jpg2'], 'desktop\Folder1\Folder2': ['my_txt1','my_txt2']}
"""
def first_test(folder_path):
	file_dict = {}
	ord_dict = OrderedDict()
	temp_dict = {}
	answer = "{'TestFolder', ['TestPic5.jpg']), ('TestFolder\\TestFolder1', ['TestDoc1.txt', 'TestDoc2.txt', 'TestPic1.jpg', 'TestPic2.jpg']), ('TestFolder\\TestFolder2', ['TestDoc3.txt', 'TestPic3.jpg']), ('TestFolder\\TestFolder2\\Testfolder3', ['4.jpg', 'TestDoc4.txt']}"
	#print(folder_path)
	#i = 0


	for dir, subdir, file in os.walk('TestFolder'):
		file_dict.update({dir: file})
		#ord_dict.update({dir: file})
		#file_dict[dir] = [file]
		#file_dict.update({dir: file})
		#file_dict[dir] = file
		#file_dict[i] = {dir: file}
		#print("print: {0}: {1}".format(dir, file))
		#print("dict: {0}\n".format(file_dict))
	#print file_dict
	#print sorted(file_dict.items())
	#print ord_dict
	#print answer


	#for i in sorted(file_dict):
		#print (i, file_dict[i])
		#temp_dict.update({i: file_dict[i]})
		#answer += str(("'{0}': {1}, ".format(i, file_dict[i])))

	#print "{{{0}}}".format(answer)
	#print file_dict

	#for i in sorted(file_dict.keys()):
		#print("dict[{0}]: {1}".format(i, file_dict[i]))

	#print "\nfile_dict: {0}".format(file_dict)

	#return "{{{0}}}".format(answer)
	#return sorted(file_dict.items())
	#return file_dict
	return file_dict


"""
# Provided a command line string (e.g., something like 'ipconfig'), execute the operation, and
# save the results to a txt file with the name given
"""
def second_test(cmdline, filename):

	path = './file9.txt'
	mode = 0o666
	flags = os.O_RDWR | os.O_CREAT

	#print "cmd : {0}".format(cmdline)
	#print "file: {0}".format(filename)

	proc = subprocess.check_output("ipconfig")

	f = os.open("ipconfig.txt", flags, mode)
	os.write(f, proc)
	os.close(f)

	#print proc

	return

#first_test("TestFolder")
