import sys
import threading
import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 7777
try:
    s.bind((host, port))
except socket.error as msg:
    print("bind failed" + str(msg))
    sys.exit()
s.listen(10)
process_sockets_list = []
process_list = []
neighbor_list = []
msg_token = ""
def recv_message(conn):
    while True:
        try:
            received = conn.recv(1024)
            msg_token = received.decode('utf-8')
            print("received token: " + msg_token)
        except:
            continue
        if "Coordinator: " in msg_token :
            le=msg_token.split()
            leader=le[1]
        process_index = process_sockets_list.index(conn)
        if len(process_sockets_list)==process_index+1 :
            to_process=0
        else :
            to_process=process_index+1
        try :
            process_sockets_list[to_process].send(received)
            print("sending :" + received.decode('utf-8'))
        except :
            if process_list[to_process]!=leader :
                process_sockets_list[to_process+1].send(received)
                print("sending :" + received.decode('utf-8'))
            process_sockets_list[to_process].close()
            process_sockets_list.remove(process_sockets_list[to_process])
            process_list.remove(process_list[to_process])
            continue

while True:
    try:
        connection, addr = s.accept()
        process_sockets_list.append(connection)
        recv_process_id = connection.recv(1024)
        from_to_process = recv_process_id.decode('utf-8')
        process_list.append(from_to_process)
        print("Process: " + from_to_process)
        start_thread = threading.Thread(target=recv_message, args=(connection,))
        start_thread.start()
    except socket.error as msg:
        print("thread failed"+msg)

connection.close()
s.close()