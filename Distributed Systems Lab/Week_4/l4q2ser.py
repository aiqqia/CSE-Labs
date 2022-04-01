import socket

serversocket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

udp_host = socket.gethostname()
udp_port = 12345

serversocket.bind((udp_host,udp_port))
print('Do Ctrl+c to exit the program!!')
while True:
	print("####### Server is listening ###########")
	data,addr = serversocket.recvfrom(1024)
	print('2. Server Recieved: ', data.decode())
	message = input('Type some text to send => ')
	serversocket.sendto(message.encode(),addr)
	print('1. Server Sent:', message)