#pragma once

#define DEFINE_PACKET_DATA(ns, sock, name, pktT, ...) \
  typedef struct { \
  __VA_ARGS__ \
  } VlcbNet##sock##name; \
  void ns##_##name##_Serialize(pktT *const packet, VlcbNet##sock##name data); \
  VlcbNet##sock##name ns##_##name##_Deserialize(const pktT *const packet);
