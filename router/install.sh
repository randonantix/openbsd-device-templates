# TODO: copy these files 

```
doas ksh -c "echo 'net.inet.ip.forwarding=1' >> /etc/sysctl.conf"
doas ksh -c "echo 'net.inet6.ip6.forwarding=1' >> /etc/sysctl.conf"
# OR echo "net.inet.ip.forwarding=1" | doas tee -a /etc/sysctl.conf

doas rcctl enable dhcpd
doas rcctl set dhcpd flags em1

doas cp /var/unbound/etc/unbound.conf /var/unbound/etc/unbound.conf.orig
# ! Do some stuff to copy the file
doas touch /var/unbound/etc/unbound.log
doas rcctl enable unbound
doas rcctl start unbound
# ? https://www.reddit.com/r/openbsd/comments/4405cq/rcctl_start_unbound_fails/
# /usr/sbin/unbound-checkconf && echo success
# doas rcctl get unbound
# ? https://serverfault.com/questions/699094/unbound-nsd-returning-servfail-resolving-local-lan-dns-nsd-alone-works-fine

doas cp /etc/pf.conf /etc/pf.conf.orig
# ! Do some stuff to copy the file
doas pfctl -f /etc/pf.conf
```
