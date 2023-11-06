# https://peps.python.org/pep-0333/#the-application-framework-side
def app(environ, start_response):
    """Simplest possible application object"""
    status = '200 OK'
    response_headers = [('Content-type', 'text/plain')]
    start_response(status, response_headers)
    return ['Hello WWW world!\n']
