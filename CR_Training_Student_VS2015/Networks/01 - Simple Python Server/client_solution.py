import socket, sys, os

answer = ''

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect(('127.0.0.1', 6880))

data_rcv = sock.recv(64)
print("## Press 'x' to close ##")

while data_rcv != '':
    print data_rcv
    answer = raw_input("[>] Your Answer: ")
    if answer == "x" or len(answer) <= 0:
        sock.close()
        data_rcv = ''
    else:
        sock.send(answer)
        data_rcv = ''
        data_rcv = sock.recv(64)
sock.close()

# york: 2058
# rackley: austin
# hughes: 90 IOS
# dupont: spurs
# witter: texas