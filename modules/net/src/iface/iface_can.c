#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "iface_can_svc.c"
#include "iface_vlcb.h"
#include "vlcb/net/adapter.h"
#include "vlcb/net/wire.h"
#include "vlcb/net/iface.h"
#include "vlcb/net/packet/vlcb.h"
#include "vlcb/net/socket.h"
#include "vlcb/platform/log.h"

void ProcessCanPacket(VlcbNetIface *const iface, VlcbNetAdptPkt *pkt,
                      vlcb_clock now) {
  VlcbNetSocketListIter iter = vlcb_net_sock_list_GetIterator(iface->sockets);
  while (vlcb_net_sock_list_iter_HasNext(&iter)) {
    VlcbNetSocketHandle sock = vlcb_net_sock_list_iter_Next(&iter);
    VlcbNetWireEndpointHandle endpoint = sock->WireEndpoint(sock);
    CanSvcEventConsume(endpoint, (CanSvcEvent){
                                     .type = CAN_PKT_INGEST,
                                     .data.ingest.pkt = pkt,
                                 });

    CanSvcProcess(iface, endpoint, now);
  }

  if (pkt->meta.can.isRtr) {
    return;
  }

  if (pkt->payloadLen < 1) {
    VLCBLOG_INFO("malformed packet, payload is less than 1 bytes long");
    return;
  }

  VlcbNetAdptPayload *payload = &pkt->payload;
  VlcbOpCode opc = *payload[0];
  // TODO: should we validate opcodes?
  // {
  // int err = vlcb_defs_OpcodeFromByte(*payload[0], &opc);
  // if (err != 0) {
  //   VLCBLOG_ERROR("invalid opcode, dropping packet");
  //   return;
  // }
  // }
  VlcbNetPacket vlcb_pkt;
  {
    VlcbNetPacketConstructErr err;
    err = vlcb_net_pkt_New(opc, pkt->payloadLen,
                           (VlcbNetPayload *)(payload + 1), &vlcb_pkt);
    if (err != VLCB_NET_PKT_CONSTRUCT_ERR_OK) {
      VLCBLOG_ERROR(vlcb_net_pkt_ConstructErrToStr(err));
      return;
    }
  }

  ProcessVlcbPacket(iface, &vlcb_pkt);
}

VlcbNetAdptErr DispatchCanPacket(VlcbNetIface *const iface,
                                 const VlcbNetPacket *const packet) {
  VlcbNetAdptPkt adpt_pkt;

  adpt_pkt.medium = VLCB_MEDIUM_CAN;
  adpt_pkt.meta.can.isRtr = false;
  adpt_pkt.payloadLen = 1 + packet->payloadLen;

  if (packet->payloadLen) {
    memcpy(&adpt_pkt.payload + 1, packet->payload, packet->payloadLen);
  }

  VlcbNetAdptErr err = _INTERFACE_PTR_CALL(iface->adpt, SendPkt, &adpt_pkt);

  return err;
}
