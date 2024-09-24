#include "../../src/network/socket/datagram.h"
#include "../../src/vlcb.h"

// Dummy device driver
typedef struct {
} CanDevice;

VlcbNetDevErr can_dev_receive(CanDevice *const self,
                              VlcbNetDevPacket *const packet) {
  return VLCB_NET_DEV_ERR_OK;  // Stubs to satisfy the compiler
}

VlcbNetDevErr can_dev_send(CanDevice *const self,
                           const VlcbNetDevPacket *const packet) {
  return VLCB_NET_DEV_ERR_OK;  // Stub to satisfy the compiler
}

VlcbNetDevCaps can_dev_caps(const CanDevice *const self) {
  return (VlcbNetDevCaps){.medium = VLCB_MEDIUM_CAN};
}

// Implement trait and upcast to super type for CanDevice dummy driver
vlcb_impl_net_dev(CanDevice, avr_can, can_dev_send, can_dev_receive,
                  can_dev_caps);

void doSomethingWithMySocket(VlcbNetDatagramSocket *sock);

int main(void) {
  // Init the dev driver
  CanDevice candev = {};
  // Upcast to the interface type
  VlcbNetDev netdev = avr_can_Upcast(&candev);

  // Create RX and TX buffers for socket we will use. Each large enough for 32
  // packets. This macro creates one buffer of given packet size, on stack.
  //
  // Note: you don't have to use this macro, it's made only for ease of use;
  // this will create a variable to hold the actual data named `data_sock_rx`
  // amd `data_sock_tx` respectively and the packet buffer structures for each
  // buffer with the given names `sock_rx` and `sock_tx`
  VLCB_DATAGRAM_SOCK_BUF(sock_rx, 32);
  VLCB_DATAGRAM_SOCK_BUF(sock_tx, 32);

  // Create the socket
  VlcbNetDatagramSocket sock =
      vlcb_net_sock_NewDatagramSocket(&sock_rx, &sock_tx);

  VlcbNetDevHwAddr hw_addr = vlcb_net_dev_hw_addr_NewCanId(
      vlcb_defs_NewCanId(120));  // Random example id, in real app this would be
                                 // fetched from a storage
  VlcbNodeAddr node_addr =
      vlcb_defs_NewNodeAddr(512);  // Random example id, in a real app this
                                   // would be fetched from a storage

  VlcbNetIface iface = vlcb_net_iface_New(hw_addr, node_addr);
  // Bind the device
  vlcb_net_iface_Bind(&iface, &netdev);

  // todo: register the net dev listeners

  // Create socket list
  VLCB_NET_SOCK_LIST(sockets, 1);

  // upcast the datagram socket to the interface and insert it's pointer to the
  // list
  VlcbNetSocket sock_upcast = vlcb_net_sock_datagram_Upcast(&sock);
  vlcb_net_sock_list_Insert(&sockets, &sock_upcast);

  while (1) {
    vlcb_net_iface_Poll(&iface, &sockets);
    // todo: handle poll result

    doSomethingWithMySocket(&sock);
  }

  return 0;
}

void doSomethingWithMySocket(VlcbNetDatagramSocket *sock) {
  // Do stuff here
}
