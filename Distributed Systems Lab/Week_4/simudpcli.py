import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

udp_host = socket.gethostname()
udp_port = 12345

msg = "UDP Program!"
print("UDP target IP: ", udp_host)
print("UDP target Port: ", udp_port)

sock.sendto(msg.encode(), (udp_host, udp_port))
