# openbsd-device-templates

Templates for setting up OpenBSD for different device type configurations. Intended to be used for quickly setup on VMs.

## Getting started

0. Router VM is expected to have 2 network adapters: `em0` as bridged adapter so it gets an IP on the LAN and `em1` as a "NAT" adapter. The `unbound.conf` file needs to reflect these networks, as well as potentially `pf.conf`, depending on your `pf.conf` rules.
1. Make sure doas.conf has been configured first
2. Change variables for IP networks in configure.sh

```
doas pkg_add -v git
git clone https://github.com/randonantix/openbsd-device-templates.git
cd openbsd-device-templates
sh ./configure.sh --config router

```