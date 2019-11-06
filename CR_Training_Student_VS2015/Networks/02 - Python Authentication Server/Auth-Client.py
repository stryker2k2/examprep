"""
The file server communicates with a client in the following way:

1. After connecting to the client, the server sends a welcome message (Please enter credentials)

2. The server waits for the client to send 1.) the length of the user name first, 2. )followed by an authentication token 
	that contains the user name and passcode packed in a struct (in that order)
	
3. If the client authenticates correctly, the server will send a successful authencation message. If the client
	sends incorrect login info, the server will send a message back indicating what is wrong, followed by the welcome
	message again
	
4. Once the client authenticates, the server will send a list of files available for download

5. The client must send a number indicating which file it wants to download 
(hint: the server does not tell you what to name the file when you receive it)

6. Once the server receives the file selection from the client, it sends the client the size of the file and then
	immediately starts sending the file in small chunks.


NOTE: Please use either one of the usernames/passwords below
'user1': 91827364
'user2': 19283746
'user3': 46372819

ip address is 'localhost'
port is 2058
"""
import socket
import sys
import struct
import os

user1 = {'user1': 91827364}
user2 = {'user2': 19283746}
user3 = {'user3': 46372819}

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect(('127.0.0.1', 2058))


def print_data():
    data_rcv = sock.recv(1024)
    print "[-] {0}".format(data_rcv)


def download_file(format):
    fname = 'download'
    fullname = fname + '.' + format

    try:
        with open(fullname, 'wb') as txt:
            len = sock.recv(256)
            while True:
                data = sock.recv(int(len))
                if not data:
                    break
                txt.write(data)
        print("[*] {0} successfully downloaded with a length of {1} characters!".format(fullname, len))
    except Exception:
        print("[!] Error receiving file.  Please try again.")


def connect():
    print("[*] Sending Length")
    sock.send("5")

    my_struct = struct.pack('5s i', 'user1', 91827364)
    print("[*] Sending User1 Struct")
    sock.send(my_struct)

    print_data()


def main():
    print_data()
    connect()

    print_data()

    answer = input("[>] Your Selection: ")
    sock.send(str(answer))

    if answer == 2:         # Option to download Lighthouse.jpg
        download_file("jpg")
    elif answer == 4:       # Option to download randomText.txt
        download_file("txt")

    sock.close()


if __name__ == "__main__":
    main()










'''
def dead_code():            # how to use repr()
    #print repz_buff
    split = repz_buff.split('\'')
    print "split 1: {0}".format(split[1])
    split_size = len(split[1])
    print "size of split 1: {0}".format(split_size)
    final = (buffer[split_size:])

    with open("final_test.txt", 'wb') as finalTxt:
        finalTxt.write(final)
    finalTxt.close()

    print '[*] {0} received!'.format(fname)
'''