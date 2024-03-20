#!/usr/bin/perl
print "Content-type: text/html\n\n";
print "Hello, World.";

# TODO: what next? how to run a python script and load py-pf?
# https://github.com/randonantix/pfweb
# https://github.com/openbsd/src/blob/master/sbin/pfctl/pfctl.c
# https://github.com/dotpy/py-pf
# https://pypi.org/project/fastcgi/
# https://www.reddit.com/r/openbsd/comments/gbmsb0/python_virtual_environment/
# https://docs.python.org/3/library/venv.html
# https://stackoverflow.com/questions/42661771/how-to-get-mod-wsgi-to-pick-up-my-virtualenv

# ?? socketserver https://pypi.org/project/fastcgi/
#with TCPServer(('localhost',1234), TestHandler) as srv:
#    srv.handle_request()
