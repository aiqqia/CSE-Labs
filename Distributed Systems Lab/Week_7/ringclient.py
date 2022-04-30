import socket
import threading
import time
import sys
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
to_port = 7777
s.connect((host, to_port))
my_id = str(sys.argv[1])
s.send(my_id.encode('utf-8'))
leader="-1"
def initiate_election(s):
    time.sleep(1)
    s.send(my_id.encode('utf-8'))
    print("token sent: " + my_id)
    print("Election initiated")


def Ring_Election_Algorithm(s):
    while True:
        global leader
        try:
            s.settimeout(15)
            received = s.recv(1024)
            s.settimeout(None)
            received_token_list = received.decode('utf-8')
        except socket.timeout:
            leader = "0"
            initiate_election(s)
            continue
        if my_id in received_token_list and "Coordinator: " not in received_token_list and "hello" not in received_token_list:
            leader = max(received_token_list)
            forwarding_leader = "Coordinator: " + leader
            time.sleep(1)
            s.send(forwarding_leader.encode('utf-8'))
        elif my_id not in received_token_list and "Coordinator: " not in received_token_list and "hello" not in received_token_list :
            print("rec tok: " + received_token_list)
            leader = "0"
            received_token_list = received_token_list + " " + my_id
            time.sleep(1)
            s.send(received_token_list.encode('utf-8'))
            print("adding token: " + received_token_list)
        elif ("hello" in received_token_list or "Coordinator: " in received_token_list )and leader=="-1":
            leader="0"
            initiate_election(s)
        elif "Coordinator: " in received_token_list and leader not in received_token_list :
            print(received_token_list)
            le=received_token_list.split()
            leader=le[1]
            time.sleep(1)
            s.send(received_token_list.encode('utf-8'))
        else :
            if leader=="-1" or leader=="0":
                continue
            else :
                print(received_token_list)
                communicate = "hello" + " from " + my_id
                time.sleep(1)
                s.send(communicate.encode('utf-8'))
                continue


recv_thread = threading.Thread(target=Ring_Election_Algorithm, args=(s,))
recv_thread.start()
recv_thread.join()
s.close()