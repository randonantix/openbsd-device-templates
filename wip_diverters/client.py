#!/usr/local/bin/python3
# https://pypi.org/project/paho-mqtt/
import google.protobuf.json_format as json_format
import paho.mqtt.client as mqtt
import paho.mqtt.publish as publish
from threading import Timer
import random
import subprocess
#import proto.divert_pb2 as divert_pb2
import divert_pb2
#from socket import gethostbyaddr
import socket
# https://www.openbsd.org/faq/pf/tables.html
# https://stackoverflow.com/questions/89228/how-do-i-execute-a-program-or-call-a-system-command

def divert(src_port=0, dst_port=0, src_host=None, dst_host=None):
    return divert_pb2.DivertMessage(src_port=src_port, dst_port=dst_port, src_host=src_host, dst_host=dst_host);

print(divert())

def to_json(pb_message):
    return json_format.MessageToJson(pb_message)

def from_json(json_str, type):
    return json_format.Parse(json_str, type())

print(to_json(divert(src_port=14758, dst_port=443, src_host="172.16.207.99", dst_host="34.107.24.111")))
print(from_json('{"src_host":"192.168.9.9"}', divert_pb2.DivertMessage))


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    #client.subscribe("$SYS/#")
    client.subscribe("test")
    #client.subscribe("paho/test/single")
    client.subscribe("paho/test/single/response")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    payload = str(msg.payload.decode("utf-8"))
    #print(msg.topic+" "+payload)

    # TODO: Also need to keep track of IPs/ports to de-dedupe them
    if msg.topic == "paho/test/single/response":
        parts = payload.split()
        cmd = parts[0]
        ip = parts[1]
        if cmd == "allow":
            # TODO: change firewall rule to allow using pftabled
            # need to copy over pftabled.h.c and use it from the python client
            # basically send a datagram to the socket from this decision point.
            # Also make rules in pf.conf that reference the tables
            # Does pf support rules with time limits? (e.g., 15 minutes)
            # doas pfctl -t blocked -T add 34.107.243.93
            # query an IP
            # doas pfctl -t blocked -T show | grep 34.107.243.93
            # doas pfctl -t blocked -T delete 34.107.243.93
            hostname = "unknown hostname"
            try:
                hostname = socket.gethostbyaddr(ip)[0]
            except socket.error as err:
                print("gethostbyaddr error: " + str(err))
                pass
            print("FIREWALL allowed " + ip + " @ " + hostname)
        else:
            print("FIREWALL blocked " + ip)
        return
    
    # TODO: this is fake simulation and should go on another client
    #if msg.topic == "paho/test/single":
    #    times = [1,2,3,4,5,6]
    #    time = random.choice(times)
    #    t = Timer(time, publish_fake_response)
    #    t.start()

def publish_fake_response():
    choices = ["allow", "block"]
    response = random.choice(choices)
    publish.single("paho/test/single/response", response, hostname="127.0.0.1")


client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("127.0.0.1", 1883, 60)

# Blocking call that processes network traffic, dispatches callbacks and
# handles reconnecting.
# Other loop*() functions are available that give a threaded interface and a
# manual interface.
client.loop_forever()

