#!/usr/local/bin/python3
import json
import socket
import sys
import paho.mqtt.publish as publish
import ast

def splitkeep(s, delimiter):
    split = s.split(delimiter)
    return [substr + delimiter for substr in split[:-1]] + [split[-1]]

def create_socket():
    try:
        global host
        global port
        global s
        host = "127.0.0.1"
        port = 9999
        s = socket.socket()

    except socket.error as msg:
        print("Socket creation error: " + str(msg))

def bind_socket():
    try:
        global host
        global port
        global s
        print("Binding port: " + str(port))

        s.bind((host, port))
        s.listen(5)

    except socket.error as msg:
        print("Socket bind error: " + str(msg))

def socket_accept():
    conn, address = s.accept()
    print("Connection has been established | " + " IP: " + address[0] + " | Port: " + str(address[1]))
    #send_commands(conn)
    recv_data(conn)
    conn.close()

def recv_data(conn):
    global host
    while True:
        conn.send(str.encode("ok"))
        #data = str(conn.recv(1024), "utf-8")
        data = conn.recv(1024)
        msg = data.decode("utf-8")
        # TODO: sometimes the msg is repeated which causes issues decoding to pb/json/dict
        # Example:
        # {"src_host": "34.117.237.239", "src_port": 443, "dst_host": "172.16.207.141", "dst_port": 23715}{"src_host": "172.16.207.141", "src_port": 23715, "dst_host": "34.117.237.239", "dst_port": 443}{"src_host": "172.16.207.141", "src_port": 23715, "dst_host": "34.117.237.239", "dst_port": 443}
        print("ALERTING DEVICE raw msg: " + msg)
        # TODO: publish as protobuf/json, parsing the IPs and ports. Then client can do stuff
        # TODO: taking first element of split is not great because they may not all be dupes
        # E.g., {"src_host": "34.149.100.209", "src_port": 443, "dst_host": "172.16.207.141", "dst_port": 35318}{"src_host": "172.16.207.141", "src_port": 35318, "dst_host": "34.149.100.209", "dst_port": 443}
        json_msg = json.dumps(splitkeep(msg, '}')[0], sort_keys=True)
        print("ALERTING DEVICE json_msg: " + str(json_msg))
        # msg_dict = ast.literal_eval(json.loads(json_msg))
        # try:
        #     print("hostname: " + socket.gethostbyaddr(msg_dict.get("dst_host"))[0])
        # except socket.error as err: 
        #     print("error: " + str(err))
        #     pass

        publish.single("paho/test/single", json_msg, hostname=host)
        #print("python received: ", data, end="")

def send_commands(conn):
    while True:
        cmd = input()
        if cmd == 'quit':
            conn.close()
            s.close()
            sys.exit()
        if len(str.encode(cmd)) > 0:
            conn.send(str.encode(cmd))
            client_response = str(conn.recv(1024), "utf-8")
            print(client_response, end="")

def main():
    create_socket()
    bind_socket()
    socket_accept()


main()


