#include <iostream>
#include <rpc/pmap_clnt.h>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {

  // command line arguments
   po::options_description desc("Allowed options");

   desc.add_options()
    ("help", "produce help message")
    ("port", po::value<int>()->default_value(2049), "nfs port")
    ("version", po::value<int>()->default_value(4), "nfs version")
    ("udp", po::value<bool>()->default_value(true), "true/false if nfs supports udp")
    ("tcp", po::value<bool>()->default_value(true), "true/false if nfs supports tcp")
    ("remove", po::value<bool>()->default_value(false), "should remove current registration");


   po::variables_map opts;
   po::store(po::parse_command_line(argc, argv, desc), opts);
   
   try {
      po::notify(opts);
   } catch (std::exception& e) {
      std::cerr << "Error: " << e.what() << "\n";
      return 1;
   }

   bool remove = opts["remove"].as<bool>(); // should remove current registration

   int port = opts["port"].as<int>(); // port nfs is running on
   int version = opts["version"].as<int>(); // version of NFS
   bool hasUDP = opts["udp"].as<bool>(); // if NFS supports UDP
   bool hasTCP = opts["tcp"].as<bool>();; // if NFS supports TCP

   if(remove) {
      std::cout << "Deactivating PORT: " << port << " VERSION: " << version << "\n";

      pmap_unset (100003, version);

   } else {
      std::cout << "Activating PORT: " << port << " VERSION: " << version << " TCP: " << (hasTCP ? "YES" : "NO") << " UDP: " <<  (hasUDP ? "YES" : "NO") << "\n";

      if(hasUDP) {
         pmap_set (100003, version, (u_long)IPPROTO_UDP, port);
      }

      if(hasTCP) {
         pmap_set (100003, version, (u_long)IPPROTO_TCP, port);
      }
   }

   


   std::cout << "Success\n";

   return 0;
}
