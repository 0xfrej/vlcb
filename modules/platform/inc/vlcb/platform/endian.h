#pragma once

#include <stdint.h>

// Convert 32-bit integer from host byte order to network byte order
static inline uint32_t vlcb_htonl(uint32_t hostlong) {
  // Check if the system is little-endian
  if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) {
    // Swap byte order for little-endian systems
    return ((hostlong & 0xFF000000) >> 24) | ((hostlong & 0x00FF0000) >> 8) |
           ((hostlong & 0x0000FF00) << 8) | ((hostlong & 0x000000FF) << 24);
  } else {
    // On big-endian systems, no conversion is needed
    return hostlong;
  }
}

// Convert 16-bit integer from host byte order to network byte order
static inline uint16_t vlcb_htons(uint16_t hostshort) {
  // Check if the system is little-endian
  if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) {
    // Swap byte order for little-endian systems
    return ((hostshort & 0xFF00) >> 8) | ((hostshort & 0x00FF) << 8);
  } else {
    // On big-endian systems, no conversion is needed
    return hostshort;
  }
}

// Convert 32-bit integer from network byte order to host byte order
static inline uint32_t vlcb_ntohl(uint32_t netlong) {
  // The implementation is the same as htonl (reversed operation)
  return vlcb_htonl(netlong);
}

// Convert 16-bit integer from network byte order to host byte order
static inline uint16_t vlcb_ntohs(uint16_t netshort) {
  // The implementation is the same as htons (reversed operation)
  return vlcb_htons(netshort);
}
