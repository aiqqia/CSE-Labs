import socket

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

udp_host = socket.gethostname()
udp_port = 12345

print('Do Ctrl+c to exit the program!!')
while True:
	message = input('Type some text to send => ')
	s.sendto(message.encode(),(udp_host,udp_port))
	print('1. Client Sent: ',message)
	data = s.recv(1024)
	print('2. Client Recieved: ', data.decode())