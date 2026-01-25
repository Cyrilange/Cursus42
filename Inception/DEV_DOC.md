 Developer documentation This file must describe how a developer can:
◦ Set up the environment from scratch (prerequisites, configuration files, secrets).
◦ Build and launch the project using the Makefile and Docker Compose.
◦ Use relevant commands to manage the containers and volumes.
◦ Identify where the project data is stored and how it persists.

# General system requirements

To install Docker Desktop successfully, your Linux host must meet the following general requirements:

64-bit kernel and CPU support for virtualization.
KVM virtualization support. Follow the KVM virtualization support instructions to check if the KVM kernel modules are enabled and how to provide access to the KVM device.
QEMU must be version 5.2 or later. We recommend upgrading to the latest version.
systemd init system.
GNOME, KDE, or MATE desktop environments are supported but others may work.
For many Linux distributions, the GNOME environment does not support tray icons. To add support for tray icons, you need to install a GNOME extension. For example, AppIndicator.
At least 4 GB of RAM.
Enable configuring ID mapping in user namespaces, see File sharing. Note that for Docker Desktop version 4.35 and later, this is not required anymore.
Recommended: Initialize pass for credentials management.


---------------------------------------------------------------------------------------

## Set up 
for the subject we need to use a VM :
open the VM , create a new Vm with your settings and the image of your choice ( I took debian)
make your basic instalation , remenber to use sudo 

install docker 
install docker compose : 
create a makefile + a docker-compose.yml
create a source file, inside create the directories you need with each of them a Dockerfile

create a file .env so you can store your password and not push them, they need to stay private


commands you will need 
On the terminal write make 
It should make all the sub commands like build working so your project is running 
write docker ps to see if it is running and the title you need 

Build : docker compose build {$req}
        docker compose up -d {$req}




check docker : docker ps


test if up : docker logs -f {$req}



Delete container : docker compose down -v

if you do (  docker compose down -v && \ docker compose build --no-cache mariadb && \ docker compose up mariadb
) you will delete a container and start again .


Open a new terminal to connect to the data base : docker exec -it mariadb mysql -u root -p or docker exec -it mariadb mysql -u wp_user -p

to see what happen in our container : docker logs {$IMAGE}

when you are in other terminal you shall write sudo before docker ps
