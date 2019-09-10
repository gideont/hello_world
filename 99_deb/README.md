# How to create the deb package

This demostrate a hello world structure for creating debian deb package.
To create the deb package, issue the below command:

~~~~
dpkg-deb --build helloworld
~~~~

## Install the deb package

Move/Copy the generated helloworld.deb to target system, then issue the below command to install:

~~~~
dpkg -i helloworld
~~~~

## Detailed Steps

1. mkdir -p helloworld/DEBIAN
2. mkdir -p helloworld/usr/local/bin
3. cp /usr/local/bin/hello helloworld/usr/local/bin/
4. chmod +x helloworld/usr/local/bin/hello
5. Create a file 'control' in the DEBIAN directory
6. [optional] create a file 'postinst' in the DEBIAN directory.  It will run after the installation is complete.
7. Create the package: `dpkg-deb --build helloworld`


### control
~~~~
Package: helloworld
Version: 0.1
Maintainer: Gideon Tsang
Architecture: armhf
Description: hello world deb
~~~~
