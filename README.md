# openbsd-device-templates

Templates for setting up OpenBSD for different device type configurations. Intended to be used for quickly setup on VMs.

## Getting started

1. Import one of the VM appliance templates into VirtualBox or VMWare. VirtualBox note: When importing, rename the VM and also choose the "generate new mac addresses for all adapters" option.

<!-- TODO: Add how to import appliance -->

<!-- TODO: Need to add shared private network in VMWare or VirtualBox
https://www.youtube.com/watch?v=kdfUZYFY7f0
 -->

- [Router (2 network interfaces)](https://drive.google.com/file/d/1ArJHvuf3_sf0qmMnhBYmmEvdYIGIImvX/view?usp=drive_link) (user:obsd, password:openbsd)

- [Desktop/admin device (1 network interface)](https://drive.google.com/file/d/1n-Di5mn6PbEydKYyifEfaGm6NWGzIdYa/view?usp=drive_link) (user:obsd, password:openbsd)

2. For the router, go to the VM's settings page before starting it and make sure the second network adapter is set to "Internal Network" (VirtualBox) or "Private to my <DEVICE>" (VMWare)

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

# TODO

Build a proxy tool using "break and inspect" that can manage multiple identies, check for PII and let you know eg. if you're about to sign in or access a website from a different identity or an IP address linked to another identity

Layer 7 WAF (or other application) firewall - like something that protects a monero port, etc, using relayd

https://man.openbsd.org/carp

https://www.tumfatig.net/2021/self-host-a-password-manager-on-openbsd/
https://www.tumfatig.net/2020/a-mesh-vpn-using-openbsd-and-wireguard/
https://www.tumfatig.net/2019/automated-openbsd-deployment-on-vmd8/
https://www.tumfatig.net/2011/back-to-the-sea-the-certificate-authority-ca-episode-iv/
https://www.ventoy.net/en/index.html

https://www.shibboleth.net/products/ SSO works with https://www.seafile.com/en/product/private_server/
https://www.sparkleshare.org
https://hub.docker.com/r/pydio/cells/
https://pydio.com/en/download

Tray application example:
https://github.com/syncthing/syncthing-macos
https://github.com/syncthing/syncthing
