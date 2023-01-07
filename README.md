FakeNFS
---

### What?

This registers NFS service on port 2049, both tcp and udp with rpcbind without NFS running locally on the host.

### Why?

When running Ceph using cephadm rpcbind is not supported. Some software, such as xen server or xcp-ng support NFS v4+ but check the host with rpcinfo prior to connecting. This step is unneccessary for NFS v4+ but prevents some applications from connecting. This is meant to strictly make applications happy in that scenario.

### Config

If your port number varies, don't need TCP or UDP you can modify the `2049` or comment out one of the registrations as appropriate. 

If anyone stumbles upon this and needs it customizable open an issue and I can look into adding parameters to the command so you don't need to recompile.