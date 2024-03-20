# Next steps

- [x] Check code into OHSNAP repo
- [ ] Improve documentation for how to set up VMs and pf
- [ ] Define payload format
- [ ] Keep track of IPs/ports to dedupe requests to change firewall/notifs
- [ ] Integrate pftabled to use our block tables
- [ ] SNI extraction
- [ ] Support time-based controls
- [ ] Use different 'admin' machine to send the allow/block requests
- [ ] Develop UI that can demo payloads to allow/block from admin machine
- [ ] Enable authentication and authorization flows
- [ ] Enable TLS for MQTT messages
- [ ] Check in source code
- [ ] Document machine setup/steps to create dev environment
- [ ] Daemonize these tools
- [ ] Support IPv6
- [ ] Handle other/all ports in pf.conf
- [ ] Look into QUIC in order to not be susceptible to middle boxes
- [ ] Do geoip lookups especially when/if rDNS/SNI is not helpful
- [ ] Integrate protobufs in C/C++ code. Or, write python C wrapper for divert socket - https://docs.python.org/3/library/socket.html#socket.PF_DIVERT may be available soon? - Check out https://cython.org/ or https://docs.python.org/3.10/library/ctypes.html - https://stackoverflow.com/questions/1942298/wrapping-a-c-library-in-python-c-cython-or-ctypes - https://cffi.readthedocs.io/en/latest/
- [ ] Get DNS/SNI sniffing working. BUT DNS seems potentially useless: - print(socket.gethostbyaddr("34.117.237.239"))
      ('239.237.117.34.bc.googleusercontent.com', [], ['34.117.237.239'])
