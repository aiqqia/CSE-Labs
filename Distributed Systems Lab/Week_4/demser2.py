import socket

host = '172.16.58.44'
port = 3000
s = socket.socket()
s.bind((host, port))
s.listen(5)
conn, addr = s.accept()
print(conn, addr)
while True:
    data = conn.recv(1024)
    if data.find('exit'):
        break
    print("The sender sent : ", str(data))
    msg = input("Enter a message to send")
    if msg.find('exit'):
        break
    conn.sendall(msg.encode())
conn.close()