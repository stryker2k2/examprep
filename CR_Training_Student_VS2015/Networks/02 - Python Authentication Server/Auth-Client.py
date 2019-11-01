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

if __name__ == "__main__":


