# Needed stats for dashboard

- CPU usage
  - How many cores does the user have?
  - How to retrieve information for different cores and architectures
  - Finding the mean and average
- GPU usage
  - How to find which GPUs are connected to your hardware?
  - What is the capability of those GPUs?
  - How would you calculate the work / throughput of a GPU?
  - How would you expand it multiple GPUs on a single machine?
- Memory
  - Which memory is important to me?
  - What are these partitions and loops?
  - How much memory do we overall have?
  - How would you consider memory together?
  - How would you see and look at all the partitions on any given machine?
  - How to differentiate between actual memory and swap memory?
- Disk usages
  - Which paritions are allocated where?
  - How to get back information for each of the disk storage devices on your machine?
- Networking information
  - Receiving data
  - Sending data
  - Internet speed, download + upload
- List of current drivers
  - How to get information about all the drivers present on the machine and OS? From a software and hardware perspective as well
- System information
  - Architecture
  - How many Processors / Cores, and what model
  - OS currently working
  - hostname
  - platform
  - distribution name

## CPU usage [Reference List]

- See /sys/devices/system/cpu , 

## GPU usage

- See here [GPU programming wit CPP](https://linuxhint.com/gpu-programming-cpp/)
- Also [Linux commands to display your hardware information](https://opensource.com/article/19/9/linux-commands-hardware-information)

## Networking

- Related information to research for
  - TCP vs UDP
  - Bandwidth
  - Network interface
    - lo, ethos5, 
  - VPNs
  - Network bridges
  - IFB devices
  - Bond interfaces 
  - IP Traffic
  - Total IPv6 traffic
  - IP Packets ( `noRoutes`, `InNoRoutes`)
  - RST, Userclosed `TCPAbortOnClose`
  - Sockets
  - TCP, `baddata`, `userclosed`
  - Broadcasts, 
    - IP Broadcast bandwidth
    - IP Broadcast packets
  - Multicast
    - IP Multicast bandwidth
  - ECP
  - Network Interfaces
    - `docker0`, `wlp3s0`
  - Firewall ( netfilter )

## Disk Usage

- `systemd services`, `cpu`, `mem`, `swap`, `disk`
- `cpu`, Systemd Services CPU utilization 
- `mem`, Systemd Services Used Memory Without Cache
- `swap`, Systemd Services Swap Memory Used
- `disk`, Systemd Services Throttle Disk Read Bandwidth (services.throttle_io_read)
- 

### References

- Errors encountered during the reception of IP packets. noroutes (InNoRoutes) counts packets that were dropped because there was no route to send them. truncated (InTruncatedPkts) counts packets which is being discarded because the datagram frame didn't carry enough data. checksum (InCsumErrors) counts packets that were dropped because they had wrong checksum.
- Explicit Congestion Notification (ECN) is a TCP extension that allows end-to-end notification of network congestion without dropping packets. ECN is an optional feature that may be used between two ECN-enabled endpoints when the underlying network infrastructure also supports it.
