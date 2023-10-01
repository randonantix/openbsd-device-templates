# openbsd-device-templates

Templates for setting up OpenBSD for different device type configurations. Intended to be used for quickly setup on VMs.

## Getting started

1. Import one of the VM appliance templates into VirtualBox or VMWare. VirtualBox note: When importing, rename the VM and also choose the "generate new mac addresses for all adapters" option.

- [Router (2 network interfaces)](https://drive.google.com/file/d/1ArJHvuf3_sf0qmMnhBYmmEvdYIGIImvX/view?usp=drive_link) (user:obsd, password:openbsd)

- [Desktop/admin device (1 network interface)](https://drive.google.com/file/d/1n-Di5mn6PbEydKYyifEfaGm6NWGzIdYa/view?usp=drive_link) (user:obsd, password:openbsd)

2. For the router, go to the VM's settings page before starting it and make sure the second network adapter is set to NAT (VirtualBox) or "Internet Sharing" (VMWare)

3. Boot the machines and change the `root` and `user` passwords:

```
doas passwd obsd
doas passwd root
```

4. Get these templates:

```
doas pkg_add -v git
git clone https://github.com/randonantix/openbsd-device-templates.git
cd openbsd-device-templates
```

5. Copy the files to their corresponding location in the filesystem

6. By default the network adapters are set to use DHCP. Get their IP addresses and update files:

```
$ ifconfig

# For the router, modify `/etc/dhcpd.conf` and `/var/unbound/etc/unbound.conf` to use the subnet from the `/etc/hostname.em1` interface.

## For the desktop/admin, `/etc/hostname.em0` should be on the same subnet as `/etc/hostname.em1` from the router. Update `/etc/resolv.conf` to use the router as the DNS resolver too:

$ doas route nameserver em0 <ROUTER_EM1_INTERFACE_IP>
```

8. The desktop should be routing through the router VM now. Verify by going to the router and checking `pflog` and visiting a website from Chrome on the desktop.

```
tcpdump -n -e -ttt -i pflog0
```





## Below here does not work yet

0. Router VM is expected to have 2 network adapters: `em0` as bridged adapter so it gets an IP on the LAN and `em1` as a "NAT" adapter. The `unbound.conf` file needs to reflect these networks, as well as potentially `pf.conf`, depending on your `pf.conf` rules.
1. Make sure doas.conf has been configured first
2. Change variables for IP networks in configure.sh

```
doas pkg_add -v git
git clone https://github.com/randonantix/openbsd-device-templates.git
cd openbsd-device-templates
sh ./configure.sh --config router

```
