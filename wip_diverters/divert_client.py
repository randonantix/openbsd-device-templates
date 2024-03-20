#!/usr/local/bin/python3
import socket
import os
import subprocess

# TODO: need to listen on the socket that divert.c will send to
s = socket.socket()
host = '127.0.0.1'
port = 9998

s.connect((host, port))

while True:
    data = s.recv(1024)
    if data[:2].decode("utf-8") == 'cd':
        os.chdir(data[3:].decode("utf-8"))

    if len(data) > 0:
        # cmd = subprocess.Popen(data[:].decode("utf-8"),shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.PIPE)
        # output_byte = cmd.stdout.read() + cmd.stderr.read()
        # output_str = str(output_byte,"utf-8")
        # currentWD = os.getcwd() + "> "
        # s.send(str.encode(output_str + currentWD))
        output_str = data.decode("utf-8")
        s.send(str.encode("ok"))
        print("from python: " + output_str)


