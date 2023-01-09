FakeNFS
---

### What?

This registers NFS service on port 2049, both tcp and udp with rpcbind without NFS running locally on the host.

### Why?

When running Ceph using cephadm rpcbind is not supported. Some software, such as xen server or xcp-ng support NFS v4+ but check the host with rpcinfo prior to connecting. This step is unneccessary for NFS v4+ but prevents some applications from connecting. This is meant to strictly make applications happy in that scenario.

### Options

```
./fakenfs
  --port 2049
  --tcp true
  --udp true
  --version 4
```

To unregister

```
./fakenfs
  --port 2049
  --version 4
  --remove true
```

### Dependencies

```
sudo apt install libboost-program-options1.71.0
```

### Compiling

```
sudo apt install libboost-program-options-dev
```

```
g++ -m64 main.cpp -o fakenfs -lstdc++ -lboost_program_options
```