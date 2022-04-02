from socket import socket


import socket

host = socket.gethostname()
port = 12345
sock = socket.socket()
sock.bind((host, port))

sock.listen(5)
conn,addr = sock.accept()
print('Got connection from ', addr[0], '(', addr[1], ')')
print('Thank you for connecting')
while(True):
    data = conn.recv(1024)
    if not data: break
    conn.sendall(data)
conn.close()