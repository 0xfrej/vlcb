#pragma once

#define _DEFINE_PACKET_EXPAND(x) x
#define _DEFINE_PACKET_CONCAT3(a, b, c) a##b##c
#define _DEFINE_PACKET_CONCAT4(a, b, c, d) a##b##c##d

#define _DEFINE_PACKET_NAME(sock, name)                                        \
  _DEFINE_PACKET_CONCAT3(VlcbNet, sock, name)

#define _DEFINE_PACKET_METHOD(ns, name, suffix)                                \
  _DEFINE_PACKET_CONCAT4(ns, _, name, suffix)

#define DEFINE_PACKET_DATA(ns, sock, pktT, name, ...)                          \
  typedef struct {                                                             \
    __VA_ARGS__                                                                \
  } _DEFINE_PACKET_NAME(sock, name);                                           \
  void _DEFINE_PACKET_METHOD(ns, name, _Serialize)(                            \
      pktT *const packet, _DEFINE_PACKET_NAME(sock, name) data);               \
  _DEFINE_PACKET_NAME(sock, name)                                              \
  _DEFINE_PACKET_METHOD(ns, name, _Deserialize)(const pktT *const packet);

#define DEFINE_PACKET_WO_DATA(ns, sock, pktT, name)                            \
  inline void _DEFINE_PACKET_METHOD(ns, name, _Serialize)(pktT *const packet);
