#include <iostream>
#include <rpc/pmap_clnt.h>

int main() {

   int port = 2049; // port nfs is running on
   int version = 4; // version of NFS
   bool hasUDP = true; // if NFS supports UDP
   bool hasTCP = true; // if NFS supports TCP

   if(hasUDP) {
      pmap_set (100003, version, (u_long)IPPROTO_UDP, port);
   }

   if(hasTCP) {
      pmap_set (100003, version, (u_long)IPPROTO_TCP, port);
   }

   std::cout << "Success";

   return 0;
}
