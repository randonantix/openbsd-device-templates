"""
openbsd-wsgi
-----

openbsd-wsgi is an example python WSGI web application on OpenBSD.

The source is on `GitHub <https://github.com/randonantix/openbsd-device-templates>`_
"""
from setuptools import setup, find_packages

requires = [
    # 'py-pf>=0.1.7',
    ]

setup(name='openbsd-wsgi',
    version='0.1.0dev1',
    description='Simple web interface for the OpenBSD Packet Filter',
    long_description=__doc__,
    license='BSD',
    classifiers=[
        'Development Status :: 2 - Pre-Alpha',
        'License :: OSI Approved :: BSD License',
        'Natural Language :: English',
        'Intended Audience :: System Administrators',
        'Operating System :: POSIX :: BSD :: OpenBSD',
        'Programming Language :: Python :: 3',
        'Framework :: None',
        'Topic :: System :: Networking :: Firewalls'
    ],
    author='randonantix',
    author_email='106306957+randonantix@users.noreply.github.com',
    url='https://github.com/randonantix/openbsd-device-templates',
    packages=find_packages(),
    install_requires=requires,
    include_package_data=True,
    zip_safe=False
)
