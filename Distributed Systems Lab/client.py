import socket

host = socket.gethostname()
port = 12345

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect((host, port))

while True:
    msg = input("Enter a message to send: ")
    sock.send(msg.encode())
    data = sock.recv(1024)
    print("Server sent: ", data.decode())