# QEMU and chroot for Ubuntu-base

Below steps are using qemu for arm(64 bit) and chroot to emulate arm ubuntu on Intel(amd64) desktop.  My purpose of doing this is to make cross-compiling and poplulating rootfs easier and faster(hopefully).

### 1. Install QEMU user mode

Note that this "QEMU user mode" is different from "QEMU system mode" which boots the full OS.  User mode only allows chroot to to change root to Ubuntu ARM rootfs and execute ARM binaries. User mode does not need bootloader and kernels.

```console
# apt install qemu-user-static
```

### 2. Download the ubuntu-base 18.04 rootfs

Download the Ubuntu-base ARM64 rootfs and extract it to a directory(e.g. ubuntu_base)

```console
# zsync http://cdimage.ubuntu.com/ubuntu-base/releases/18.04/release/ubuntu-base-18.04.4-base-arm64.tar.gz.zsync
# mkdir ubuntu_base
# tar xvf ubuntu-base-18.04.4-base-arm64.tar.gz -C ubuntu_base
```

### 3. Share some resources from the host(Intel amd64) system.  

Bind mount the /dev, /tmp, /proc, and resolv.conf from the host.  e.g. sharing the host network such that network still works after chroot to Ubuntu ARM environment.

```console
# mount --bind /dev ubuntu_base/dev
# mount --bind /tmp ubuntu_base/tmp
# mount --bind /proc ubuntu_base/proc
# mount --bind /etc/resolv.conf ubuntu_base/etc/resolv.conf
```

### 4. Copy the qemu for ARM64 to the rootfs

```console
# cp /usr/bin/qemu-aarch64-static ubuntu_base/usr/bin
```

### 5. Finally, chroot to the rootfs and apt update

Use change root to jump into the Ubuntu-base rootfs.  Below example will also install gcc and compile a hello world in C to arm64 binary.

```console
# chroot ubuntu_base/
(inside chroot)
# apt update
Hit:1 http://ports.ubuntu.com/ubuntu-ports bionic InRelease
Hit:2 http://ports.ubuntu.com/ubuntu-ports bionic-updates InRelease
Hit:3 http://ports.ubuntu.com/ubuntu-ports bionic-backports InRelease
Hit:4 http://ports.ubuntu.com/ubuntu-ports bionic-security InRelease
Reading package lists... Done
Building dependency tree       
Reading state information... Done
# apt install gcc
Reading package lists... Done
Building dependency tree       
Reading state information... Done
Suggested packages:
  gcc-multilib autoconf automake libtool flex bison gdb gcc-doc
The following NEW packages will be installed:
  gcc
0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded.
Need to get 5,208 B of archives.
After this operation, 51.2 kB of additional disk space will be used.
Get:1 http://ports.ubuntu.com/ubuntu-ports bionic-updates/main arm64 gcc arm64 4:7.4.0-1ubuntu2.3 [5,208 B]
Fetched 5,208 B in 1s (4,142 B/s)
debconf: unable to initialize frontend: Dialog
debconf: (No usable dialog-like program is installed, so the dialog based frontend cannot be used. at /usr/share/perl5/Debconf/FrontEnd/Dialog.pm line 76, <> line 1.)
debconf: falling back to frontend: Readline
E: Can not write log (Is /dev/pts mounted?) - posix_openpt (19: No such device)
Selecting previously unselected package gcc.
(Reading database ... 20522 files and directories currently installed.)
Preparing to unpack .../gcc_4%3a7.4.0-1ubuntu2.3_arm64.deb ...
Unpacking gcc (4:7.4.0-1ubuntu2.3) ...
Setting up gcc (4:7.4.0-1ubuntu2.3) ...
# gcc hello.c -o hello
# file hello
hello: ELF 64-bit LSB shared object, ARM aarch64, version 1 (SYSV), dynamically linked, interpreter /lib/ld-, for GNU/Linux 3.7.0, BuildID[sha1]=cb2cb2261cf5301273db521b7632450cbf8e9ecb, not stripped
# ./hello 
Hello, World!
``` 
There, you installed gcc, downloaded other hello world examples, and compiled ARM64 binaries with all desktop's Intel cores!
