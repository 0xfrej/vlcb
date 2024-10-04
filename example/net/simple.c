#include "net/socket/datagram.h"
#include "vlcb.h"
#include "../adapter/dummy_adapter.c"

void doSomethingWithMySocket(VlcbNetSocketDatagram *sock);

int main(void) {
  // Init the dev driver
  CanDevice candev = {};
  // Upcast to the interface type
  VlcbNetAdpt netdev = avr_can_Upcast(&candev);

  // Create RX and TX buffers for socket we will use. Each large enough for 32
  // packets. This macro creates one buffer of given packet size, on stack.
  //
  // Note: you don't have to use this macro, it's made only for ease of use;
  // this will create a variable to hold the actual data named `data_sock_rx`
  // amd `data_sock_tx` respectively and the packet buffer structures for each
  // buffer with the given names `sock_rx` and `sock_tx`
  VLCB_SOCK_DGRAM_BUF(sock_rx, 32);
  VLCB_SOCK_DGRAM_BUF(sock_tx, 32);

  // Create the socket
  VlcbNetSocketDatagram sock =
      vlcb_net_sock_dgram_New(&sock_rx, &sock_tx);

  // Create socket list
  VLCB_NET_SOCK_LIST(sockets, 1);

  VlcbNetIface iface = vlcb_net_iface_New(&netdev, &sockets);

  while (1) {
    vlcb_net_iface_Poll(&iface);
    // todo: handle poll result

    doSomethingWithMySocket(&sock);
  }
  return 0;
}

void doSomethingWithMySocket(VlcbNetSocketDatagram *sock) {
  // Do stuff here
}
