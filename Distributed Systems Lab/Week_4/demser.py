import socket

#host = socket.gethostname()
host = '172.16.58.44'
port = 3000
s = socket.socket()
s.bind((host, port))
s.listen(5)
conn, addr = s.accept()
print(conn, addr)
data = conn.recv(1024)
print(data)
conn.close()