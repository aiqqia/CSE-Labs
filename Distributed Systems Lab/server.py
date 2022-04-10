import socket

host = socket.gethostname()
port = 12345

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind((host, port))
sock.listen(5)
conn, addr = sock.accept()

while True:
    data = conn.recv(1024)
    print("Client sent: "+data.decode())
    msg = input("Enter message to send: ")
    conn.send(msg.encode())
