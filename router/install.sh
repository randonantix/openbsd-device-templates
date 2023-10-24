#!/bin/ksh

# Get IP addresses of the interfaces based on the "Flags" column
# https://man.openbsd.org/route#RTF_PROTO1
EXT_IF=$(route -n show -inet | grep em0 | grep UCn | tr -s ' ' | cut -d ' ' -f 2)
EXT_IF6=$(route -n show -inet6 | grep em0 | grep UCn | tr -s ' ' | cut -d ' ' -f 2 | cut -d '%' -f 1)

INT_IF=$(route -n show -inet | grep em1 | grep UCn | tr -s ' ' | cut -d ' ' -f 2)
INT_IF6=$(route -n show -inet6 | grep em1 | grep UCn | tr -s ' ' | cut -d ' ' -f 2 | cut -d '%' -f 1)

# This is IPv4 only
EXT_BCAST=$(route -n show -inet | grep em0 | grep UHb | tr -s ' ' | cut -d ' ' -f 1)
INT_BCAST=$(route -n show -inet | grep em1 | grep UHb | tr -s ' ' | cut -d ' ' -f 1)
EXT_SUBNET=$(route -n show -inet | grep em0 | grep UCn | tr -s ' ' | cut -d ' ' -f 1 | sed 's/\/24/.0\/24/')
INT_SUBNET=$(route -n show -inet | grep em1 | grep UCn | tr -s ' ' | cut -d ' ' -f 1 | sed 's/\/24/.0\/24/')

GATEWAY=$(route -n show -inet | grep em0 | grep default | tr -s ' ' | cut -d ' ' -f 2)
GATEWAY6="fe80::1%em0"

NAMESERVER=$(grep nameserver /etc/resolv.conf | cut -d ' ' -f 2 | head -1)
HAS_IP6=false
IP4_FORWARD_ENABLED=$(grep "net.inet.ip.forwarding=1" /etc/sysctl.conf)
IP6_FORWARD_ENABLED=$(grep "net.inet6.ip6.forwarding=1" /etc/sysctl.conf)

echo "EXT_IF=${EXT_IF}"
echo "EXT_IF6=${EXT_IF6}"
echo "INT_IF=${INT_IF}"
echo "INT_IF6=${INT_IF6}"
echo "EXT_BCAST=${EXT_BCAST}"
echo "INT_BCAST=${INT_BCAST}"
echo "EXT_SUBNET=${EXT_SUBNET}"
echo "INT_SUBNET=${INT_SUBNET}"
echo "GATEWAY=${GATEWAY}"
echo "GATEWAY6=${GATEWAY6}"
echo "NAMESERVER=${NAMESERVER}"

if [[ ! -z ${EXT_IF6} ]]; then
  echo "IPv6 supported"
	HAS_IP6=true
  echo "HAS_IP6=${HAS_IP6}"
fi

# TODO: probably need to read and ask if they want to support IP6?
if [ -z ${IP4_FORWARD_ENABLED} ]; then
  echo "Need to enable IP forwarding"
  # doas ksh -c "echo 'net.inet.ip.forwarding=1' >> /etc/sysctl.conf"
  echo 'net.inet.ip.forwarding=1'
else
  echo "IPv4 forwarding already enabled"
fi

# TODO: this second check is not working
if ${HAS_IP6} && test -z ${IP6_FORWARD_ENABLED}; then
  # doas ksh -c "echo 'net.inet6.ip6.forwarding=1' >> /etc/sysctl.conf"
  echo 'net.inet6.ip6.forwarding=1'
else
  echo "IPv6 forwarding already enabled"
fi

dnstls='y'

echo -n "Would you like to use DNS-over-TLS? (y/N) [${dnstls}]: "; read dnstls_input?

[[ "${dnstls_input}" = '' ]] && dnstls_input=${dnstls}

echo "Entered: ${dnstls_input}"


# TODO: copy these files 

```
# TODO: only do once - store "first_run" in a dot file?
doas ksh -c "echo 'net.inet.ip.forwarding=1' >> /etc/sysctl.conf"
doas ksh -c "echo 'net.inet6.ip6.forwarding=1' >> /etc/sysctl.conf"
# OR echo "net.inet.ip.forwarding=1" | doas tee -a /etc/sysctl.conf

doas rcctl enable dhcpd
doas rcctl set dhcpd flags em1

doas cp /var/unbound/etc/unbound.conf /var/unbound/etc/unbound.conf.orig
# TODO: prompt to add DNS over TLS and if so, what servers, ip6, etc
# ! if ip6
doas sed -i 's/#do-ip6: no/do-ip6: yes/' /var/unbound/etc/unbound.conf
# ! Do some stuff to copy the file
#doas touch /var/unbound/etc/unbound.log
doas rcctl enable unbound
doas rcctl start unbound
# ? https://www.reddit.com/r/openbsd/comments/4405cq/rcctl_start_unbound_fails/
# /usr/sbin/unbound-checkconf && echo success
# doas rcctl get unbound
# ? https://serverfault.com/questions/699094/unbound-nsd-returning-servfail-resolving-local-lan-dns-nsd-alone-works-fine

doas cp /etc/pf.conf /etc/pf.conf.orig
# ! Do some stuff to copy the file
doas pfctl -f /etc/pf.conf

# https://www.openbsd.org/faq/pf/ftp.html#client
# enable FTP proxy for pkg_add with strict pf rules
doas rcctl enable ftpproxy
doas rcctl set ftpproxy flags "-vv -D6"
doas rcctl start ftpproxy

```

# TODO: This doesn't work in ksh
# also need IPv6 interface addresses - also needs to be one time thing
doas /usr/bin/sed '/server:/a\
        interface: 172.16.207.3 #em1
        outgoing-interface: 192.168.xx.xxx # em0
        access-control: 172.16.207.0/24 allow
        do-not-query-localhost: no
' /var/unbound/etc/unbound.conf


# TODO: Needs -i to write inline
doas perl -pse -i 'if($n>0) {s{#forward-zone:}{--$n ? $& : "forward-zone:"}ge}' -- -n=1 /var/unbound/etc/unbound.conf
# find . -type f -print | xargs perl -pi.bak -e 's/http\:\/\/www\.oldwebaddress\.com\/techblog/https\:\/\/github\.com\/myname/g'
# https://unix.stackexchange.com/questions/617626/how-do-we-use-sed-to-replace-specific-line-with-a-string-variable



# NFS
# https://blog.strus.guru/2021/10/containerized-development-environment-on-openbsd-with-podman/
doas rcctl enable portmap nfsd mountd statd
# /etc/exports
#/var/www -network=172.16.225.1 -mask=255.255.255.0
doas rcctl start portmap nfsd mountd statd
# https://www.cyberciti.biz/faq/apple-mac-osx-nfs-mount-command-tutorial/
#showmount -e 172.16.225.131
#sudo mount -o resvport,rw -t nfs 172.16.225.131:/var/www /private/nfs/odesktop 
