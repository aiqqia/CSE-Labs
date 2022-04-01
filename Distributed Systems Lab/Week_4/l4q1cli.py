import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

udp_host = socket.gethostname()
udp_port = 12345

msg = "Hello UDP Server!"
print("UDP target IP: ", udp_host)
print("UDP target Port: ", udp_port)

sock.sendto(msg.encode(), (udp_host, udp_port))
msgFromServer = sock.recvfrom(1024)
msg = "Message from Server {}".format(msgFromServer[0])
print(msg)