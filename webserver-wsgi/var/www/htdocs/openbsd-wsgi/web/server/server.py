# https://peps.python.org/pep-0333/#the-application-framework-side
# TODO: Now how to get py-pf here??
# TODO: how to run this without losing chroot???
#import pf

# Load packet filter to be used in views
#packetfilter = pf.PacketFilter()

def app(environ, start_response):
    """Simplest possible application object"""
    status = '200 OK'
    response_headers = [('Content-type', 'text/plain')]
    start_response(status, response_headers)
    # TODO: this not working as permission is being denied to /dev/pf
    # PFFW is using pfctl commands instead. What can be done?
    # py-pf last says tested with 7.0, but now running tests has the permission error too
    # Is it allowed to get access /dev/pf from the web interface?
    # using doas.conf did not work as of yet
    #  TODO: next step, make a simple script to run only one command and get access to /dev/pf
    #       Make it in python, perl and C. See which one works
    #       Also, will creating an app that is running from DIVERT be accessible instead?
    #       How will we be able to write new rules? Write to config file and use pfctl to reload?
    # Also look into WSGI with Perl - PSGI
    #return [packetfilter.get_status()]
    return ['Hello PF world!\n']

# Get divert code running on firewall
# in diverted to app, get sockets working and MQTT publisher (can it just call mosquitto_pub)
# web client mosquitto_sub/pub


# ! Next steps
# web client mosquitto_sub/pub
# endpoint to call pfctl commands on event
# desktop MQTT client that shows notification
# mqtt publisher that triggers notif on block
# deamons using pftabled and pf-diverters
# use client examples from pftabled to trigger a rule change
# Make sure those still work (ie. no pf permissions issues)!! ^^^
# Still need to figure out the DNS bullshit, but it should be user configurable (no DNS, remote DNS, (and if we can get it working later, local DNS only)?
# the UDP socket is not really protected, so def need an authz layer

def modify(m):
    l = list(m)
    l[0] = l[0] ^ 1
    return bytes(l)
