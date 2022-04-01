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
    if str(data).find('exit') != -1:
        break
    print("The sender sent : ", str(data))
    msg = input("Enter a message to send : ")
    if msg.find('exit') != -1:
        break
    conn.sendall(str.encode(msg, encoding='utf-8'))
conn.close()