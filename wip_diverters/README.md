# Steps to run a simulated server/client

0. Make sure MQTT is installed and configured

1. Make sure `/etc/pf.conf` has rules for allowing `divert` and MQTT. For example:

```

# This is so we can track HTTP traffic from the browser through divert
pass out log quick on $int_if proto tcp to port { http, https }

pass in log on $int_if proto tcp from $int_net to $int_if port  { 1883, 8883 }

# Divert test (only diverts HTTP(S) right now)
# NOTE: Once divert reinjects back to kernel, no other pf rules apply. PUT LAST
pass in log quick on $int_if inet proto tcp to port 80 divert-packet port 700
pass in log quick on $int_if inet proto tcp to port 443 divert-packet port 700

```

2. Make sure divert.c has been compiled

```
$ cc divert.c -o test_divert
```

3. Run MQTT socket server `server.py`

```
$ ./server.py
```

4. Run our compiled `test_divert` tool to divert to port in `server.py` as root. Note: `server.py` must be running first. If you kill `server.py`, you will need to restart the divert tool, too.

```
$ doas ./test_divert
```

5. Run the fake MQTT client `mqtt_client.py`, making sure to adjust the IP address to the address of the MQTT server

```
$ ./mqtt_client.py
```

6. Visit a web page from a machine that will route web traffic through our router (i.e., this host)

7. You should see traffic/packet info generting in the terminals
