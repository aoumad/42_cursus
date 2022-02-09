#### 1. How the virtual machine work? 
A virtual machine (VM) is a virtual environment that works like a computer inside of a computer. It will run on an isolated partition of its host computer with its own resources of CPU power, memory, an operating system, and other resources. Virtualization uses software to simulate virtual hardware that allows multiple VMs to run on a single machine. The physical machine is known as the host while the VMs running on it are called guests. This process is managed by software known as a hypervisor.

 ### 2.How do Virtual Machines work? 

Virtualization allow us share a system with multiple virtual environments. The hypervisor manages the hardware system and separate the physical resources from the virtual environments. **The resources are managed following the needs, from the host to the guests.** When an user from a VM do a task that requires additional resources from the physical environment, the hypervisor manages the request so that the guest OS could access the resources of the physical environment. Once we know how they work, it is a good idea to see all the advantages we get from using virtual machines: - Different guest machines hosted on our computer **can run different operating systems**, so we will have different OS working on the same machine. - They provide an environment in which **to safely test unstable programs** to see if they will affect the system or not. - We get **better use of shared resources.** - We **reduce costs** by reducing physical architecture. - They are **easy to implement** because they provide mechanisms to clone a virtual machine to another physical device. 

#### 3. What is the purpose of virtual machines?

 The main purpose of VMs is to operate multiple operating systems at the same time, from the same piece of hardware. Without virtualization, operating multiple systems — like Windows and Linux — would require two separate physical units. 

#### 4. If you chose Debian, Then what is the difference between aptitude and apt?

 - In Debian-based OS distributions, the default package manager we can use is dpkg. This tool allows us to install, remove and manage programs on our operating system. However, in most cases, these programs come with a list of dependencies that must be installed for the main program to function properly. One option is to manually install these dependencies. However, APT (Advanced Package Tool), which is a tool that uses dpkg, can be used to install all the necessary dependencies when installing a program. So now we can install a useful program with a single command. - APT (Advanced Packaging Tool) can work with different back-ends and fron-ends to make use of its services. One of them is apt-get, which allows us to install and remove packages. Along with apt-get, there are also many tools like apt-cache to manage programs. In this case, apt-get and apt-cache are used by apt. Thanks to apt we can install .deb programs easily and without worrying about dependencies. But in case we want to use a graphical interface, we will have to use aptitude. Aptitude also does better control of dependencies, allowing the user to choose between different dependencies when installing a program. - The most obvious difference is that aptitude provides a terminal menu interface (much like Synaptic in a terminal), whereas apt-get does not. - Apart from main difference being that Aptitude is a high-level package manager while APT is lower-level package manager which can be used by other higher-level package managers - While apt lacks UI, Aptitude has a text-only and interactive UI - Aptitude has a better package management than apt - More: [https://www.tecmint.com/difference-between-apt-and-aptitude/](https://www.tecmint.com/difference-between-apt-and-aptitude/)

 #### 5. What APPArmor is?

 AppArmor provides **Mandatory Access Control (MAC) security**. In fact, **AppAmor allows the system administrator to restrict the actions that processes can perform**. For example, if an installed application can take photos by accessing the camera application, but the administrator denies this privilege, the application will not be able to access the camera application. If a vulnerability occurs (some of the restricted tasks are performed), AppArmor blocks the application so that the damage does not spread to the rest of the system. In AppArmor, **processes are restricted by profiles**. Profiles can work in complain-mode and in enforce-mode. In enforce mode, AppArmor prohibits applications from performing restricted tasks. In complain-mode, AppArmor allows applications to do these tasks, but creates a registry entry to display the complaint.

 #### 6. What SSH is?

 SSH or **Secure Shell** is a **remote administration protocol that allows users to control and modify their servers** over the Internet thanks to an authentication mechanism. Provides a mechanism to authenticate a user remotely, transfer data from the client to the host, and return a response to the request made by the client. SSH was created as an alternative to Telnet, which does not encrypt the information that is sent. **SSH uses encryption techniques** to ensure that all client-to-host and host-to-client communications are done in encrypted form. One of the advantages of SSH is that a user using Linux or MacOS can use SSH on their server to communicate with it remotely through their computer's terminal. Once authenticated, that user will be able to use the terminal to work on the server. The command used to connect to a server with ssh is: ``` ssh {username}@{IP_host} -p {port} ``` There are three different techniques that SSH uses to encrypt: - **Symmetric encryption:** a method that uses the same secret key for both encryption and decryption of a message, for both the client and the host. Anyone who knows the password can access the message that has been transmitted. - **Asymmetric encryption:** uses two separate keys for encryption and decryption. These are known as the public key and the private key. Together, they form the public-private key pair. - **Hashing:** another form of cryptography used by SSH. Hash functions are made in a way that they don't need to be decrypted. If a client has the correct input, they can create a cryptographic hash and SSH will check if both hashes are the same. 

#### 7. What LVM is?

 **LVM (Logical Volume Manager)** is an **abstraction layer between a storage device and a file system**. We get many advantages from using LVM, but the main advantage is that we have much more flexibility when it comes to managing partitions. Suppose we create four partitions on our storage disk. If for any reason we need to expand the storage of the first three partitions, we will not be able to because there is no space available next to them. In case we want to extend the last partition, we will always have the limit imposed by the disk. In other words, we will not be able to manipulate partitions in a friendly way. Thanks to LVM, all these problems are solved.
  By using LVM, **we can expand the storage of any partition** (now known as a logical volume) whenever we want without worrying about the contiguous space available on each logical volume. We can do this with available storage located on different physical disks (which we cannot do with traditional partitions). We can also move different logical volumes between physical devices. Of course, **services and processes will work the same way they always have**.
  But to understand all this, we have to know: 
  - **Physical Volume (PV):** physical storage device. It can be a hard disk, an SD card, a floppy disk, etc. This device provides us with storage available to use. 
  - **Volume Group (VG):** to use the space provided by a PV, it must be allocated in a volume group. It is like a virtual storage disk that will be used by logical volumes. VGs can grow over time by adding new VPs.
 - **Logical volume (LV):** these devices will be the ones we will use to create file systems, swaps, virtual machines, etc. If the VG is the storage disk, the LV are the partitions that are made on this disk.

 #### 8. How to implement UFW with SSH 

**UFW (Uncomplicated Firewall)** is a software application responsible for ensuring that the system administrator can **manage iptables in a simple way**. Since it is very difficult to work with iptables, UFW provides us with an interface to modify the firewall of our device **(netfilter)** without compromising security. Once we have UFW installed, we can choose which ports we want to allow connections, and which ports we want to close. This will also be very useful with SSH, greatly improving all security related to communications between devices. 

#### 9. What is Cron and what is wall?

 Once we know a little more about how to build a server inside a Virtual Machine (remember that you also have to look in other pages apart from this README), we will see two commands that will be very helpful in case of being system administrators. These commands are: - **Cron:** Linux task manager that allows us to execute commands at a certain time. We can automate some tasks just by telling cron what command we want to run at a specific time. For example, if we want to restart our server every day at 4:00 am, instead of having to wake up at that time, cron will do it for us. - **Wall:** command used by the root user to send a message to all users currently connected to the server. If the system administrator wants to alert about a major server change that could cause users to log out, the root user could alert them with wall.
 
 #### 10. What is a server?
A server is a piece of computer hardware or software (computer program) that provides functionality for other programs or devices, called "clients". This architecture is called the client–server model. Servers can provide various functionalities, often called "services", such as sharing data or resources among multiple clients, or performing computation for a client.  
A server is a computer or system that provides resources, data, services, or programs to other computers, known as clients, over a network.

#### 11.  What is TTY mode?
When requiretty is set, sudo must be run from a logged-in terminal session (a tty). This prevents sudo from being used from daemons or other detached processes like cronjob or web server plugins. It also means you can't run it directly from an ssh call without setting up a terminal session.

This can prevent certain kinds of escalation attacks. For example, if I have a way to modify the crontab for a user who has NOPASSWD sudo permissions, I could use that to kick off a job as root. With requiretty, I can't do that...

#### 11.  What is ports?
A port is a virtual point where network connections start and end. Ports are software-based and managed by a computer's operating system. Each port is associated with a specific process or service.

**12. Explain what "cron" is.**

-   Linux task manager that allows us to execute commands at a certain time. We can automate some tasks just by telling cron what command we want to run at a specific time. For example, if we want to restart our server every day at 4:00 am, instead of having to wake up at that time, cron will do it for us.
-   The cron command line utility, also known as cron job is a job scheduler on unix-like operating systems.
----------------------------------------------------------------------------------------------------------------
Let’s look at some of the formats and rules to follow when editing sudoers:

All lines starting with # are comments:

root ALL=(ALL:ALL) ALL – this line means that the root user has unlimited privileges and can run any command on the system.

%admin ALL=(ALL) ALL – the % sign specifies a group. Anyone in the admin group has the same privileges as of root user.

%sudo   ALL=(ALL:ALL) ALL – all users in the sudo group have the privileges to run any command
Another line of interest is #includedir /etc/sudoers.d, this means we can add configurations to the file sudoers.d and link it here.
