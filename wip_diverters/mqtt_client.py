#!/usr/local/bin/python3
# https://pypi.org/project/paho-mqtt/
import paho.mqtt.client as mqtt
import paho.mqtt.publish as publish
from threading import Timer
import random
import ast
import json

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    #client.subscribe("$SYS/#")
    client.subscribe("test")
    client.subscribe("paho/test/single")
    #client.subscribe("paho/test/single/response")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    payload = str(msg.payload.decode("utf-8"))
    print(msg.topic+" "+payload)

    # TODO: Also need to keep track of IPs/ports to de-dedupe them

    if msg.topic == "paho/test/single/response":
        if payload == "allow":
            # TODO: change firewall rule to allow using pftabled
            # need to copy over pftabled.h.c and use it from the python client
            # basically send a datagram to the socket from this decision point.
            # Also make rules in pf.conf that reference the tables
            # Does pf support rules with time limits? (e.g., 15 minutes)
            print("allowed")
        else:
            print("blocked")
        return

    # TODO: this is fake simulation and should go on another client
    if msg.topic == "paho/test/single":
        #parts = payload.split()
        #print(parts)
        #ip = parts[0]
        data = json.loads(payload)
        #print("data: " + data)
        # TODO: why is this type str??
        #print(type(data))
        # Convert to dict
        data = ast.literal_eval(data)
        #print("ast data: " + str(data))
        #print(type(data))
        publish_fake_response(data.get("dst_host"))
        #times = [1,2,3,4,5,6]
        #times = [2]
        #time = random.choice(times)
        #t = Timer(time, publish_fake_response, args=ip)
        #t.start()

#def publish_fake_response(ip, kwargs):
def publish_fake_response(ip):
    choices = ["allow", "block"]
    response = random.choice(choices) + " " + ip
    print("ADMIN DEVICE responding with: " + response)
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
