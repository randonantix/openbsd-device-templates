#!/usr/local/bin/python3
#/usr/bin/env python
#/htdocs/ohsnap-web/bin/python python
# ^ for virtualenv
#/var/www/htdocs/ohsnap-web/bin/python python

# See https://peps.python.org/pep-0333/#middleware-components-that-play-both-sides
from server.server import app # Assume app is your WSGI application object
from cgi import WSGIServer

WSGIServer(app).run()
#print("what the heck");
# TODO: I think the "no such file or directory" has to do with the virtual environment
# perl script is working, though it has no imports, etc, but also not virtual environment
# and I copied the modules into the chroot already
