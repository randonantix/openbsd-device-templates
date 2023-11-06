#!/usr/local/bin/python3

# See https://peps.python.org/pep-0333/#middleware-components-that-play-both-sides
from server.server import app # Assume app is your WSGI application object
from cgi import WSGIServer

WSGIServer(app).run()
