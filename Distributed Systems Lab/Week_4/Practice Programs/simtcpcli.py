import socket

host = socket.gethostname()
port = 12345
sock = socket.socket()
sock.connect((host, port))
sock.sendall(b'Welcome User1')
data = sock.recv(1024)
sock.close()
print(repr(data))