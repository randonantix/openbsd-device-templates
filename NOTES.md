<!-- TODO: Ubuntu desktop does not show as behind Mullvad VPN on VM. Why??
 I'm connected via my phone hotspot. Does the vmnet not route through VPN?
  Or does the "NAT" option cause it to connect to other networks?
  Does the openbsd router need to be connected via wireguard too? Need to get
  that VPN mesh up! In the meantime, it can connect to my Dallas Linode
 -->

DEFINE the threat model

AND requirements

- NO Cloud messaging - this is why I'm looking into mesh vpn
- ZeroTrust architecture
- Rapid, secure provisioning
- Secure key management, not exposed to the internet
- allow/deny requests later - make permanent or temp rules like uBlock Origin
- DNS blocking
- easy firewall config UI
- little to no frameworks and JS (esp no JS frameworks)
- great documentation! Especially if building with no frameworks
- Can we use VMs running from one machine to be "trusted"?
- Make the tech stack appealing for devs
- Metrics and data monitoring
- Alerting
- Look into UDP boundaries protection. This is how mesh vpns are working (not wireguard only, but the others) using NAT traversal and not opening ports on firewall. Seems like a potential future vector to exploits
- acme certificate management
- API firewall https://github.com/wallarm/api-firewall
- https://www.ntop.org/products/traffic-analysis/ntop/ and n2n mesh vpn
- copy gl.inet UI and API https://dev.gl-inet.com/router-4.x-api/
- https://github.com/gl-inet/docs4.x
- gRPC communication?

https://zchee.github.io/golang-wiki/OpenBSD/#ulimits-etcloginconf

https://stackoverflow.com/questions/29447931/golang-cgi-on-apache
https://stackoverflow.com/questions/25325054/run-an-exe-file-on-apache

https://stackoverflow.com/questions/10036238/deploying-go-web-applications-with-apache

https://pkg.go.dev/net/http/fcgi

```
package main

import (
    "fmt"
    "net/http"
    "net/http/fcgi"
)

func hello(w http.ResponseWriter, r *http.Request) {
    fmt.Fprintf(w, "Hello from Go!")
}

func main() {
    http.HandleFunc("/", hello)
    fcgi.Serve(nil, nil)
}
```

https://github.com/idaunis/mod_go

Boot

- change hostname
- change DNS name (dev.local)
  - change nameservers `doas route nameserver em0 172.16.225.129`
- change root password
  - openbsd
- change user password
- change timezone - UTC
- change eth1 subnet
  - match subnet in unbound.conf and pf.conf
- IPV6???
- fix vlan0?

script

- doas.conf
- update kshrc and exrc

- install git
- install and setup wireguard
- let's encrypt/ add DNS entries

- provision another device
  - adds child openbsd vms on this device?

NEXT

- on device1 clone
  - copy github keys over to dev machine
  - create install.sh script to install/copy the files and tools
  - install script will need to point hostname.em0 to subnet on router
- on router clone

  - copy router/dns files over
  - create install.sh script to install/copy the files and tools
  - install script will need to change networks in unbound.conf and pf.conf to hostname.em1 (and possibly em0 for pf.conf)

- on dev VM

  - install mosquitto/or mqttrs
  - test networking
  - install packages for rust
  - basic webfiles
  - vpn/wireguard mesh

  THE VPN/MESH UI + DNS is critical. This is basically Tailscale. Also needs the iOS Android apps in order to import the configs. But, not really because we can use the Wireguard app for now. That can read QR codes.

  - Also need a Linux app for phones like PinePhone or even Ubuntu Touch (ha)

  - Can we start automating VMs to start building a VPS hosting platform?

  - Could we use httpd to as a proxy/web filter/web firewall to provide security layer if we write our own web server in Rust or Go?

## This means you need to run `doas rdate time.cloudflare.com`

https://cdn.openbsd.org/pub/OpenBSD/7.3/packages/amd64/: TLS handshake failure: ocsp verify failed: ocsp response not current

<!-- TODO: Any web pages served need to be protected via strict-csp
https://web.dev/articles/strict-csp
https://medium.com/@nrshahri/csp-cra-324dd83fe5ff
https://developers.google.com/web/fundamentals/security/csp/

Images/file uploads should be served from a different domain than scripts
 -->
