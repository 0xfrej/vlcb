#pragma once

#include <stdint.h>

/**
 * MERG Module types
 */
typedef uint8_t VlcbMergModuleType;
enum VlcbMergModuleType {
  /**
   * default for SLiM nodes
   */
  VLCB_MERG_MODULE_SLIM = 0,

  /**
   * Solenoid point driver
   */
  VLCB_MERG_MODULE_CANACC4 = 1,

  /**
   * Motorised point driver
   */
  VLCB_MERG_MODULE_CANACC5 = 2,

  /**
   * 8 digital outputs
   */
  VLCB_MERG_MODULE_CANACC8 = 3,

  /**
   * Control panel switch/button encoder
   */
  VLCB_MERG_MODULE_CANACE3 = 4,

  /**
   * 8 digital inputs
   */
  VLCB_MERG_MODULE_CANACE8C = 5,

  /**
   * 64 led driver
   */
  VLCB_MERG_MODULE_CANLED = 6,

  /**
   * 64 led driver (multi leds per event)
   */
  VLCB_MERG_MODULE_CANLED64 = 7,

  /**
   * 12v version of CANACC4
   */
  VLCB_MERG_MODULE_CANACC4_2 = 8,

  /**
   * CANCAB hand throttle
   */
  VLCB_MERG_MODULE_CANCAB = 9,

  /**
   * CANCMD command station
   */
  VLCB_MERG_MODULE_CANCMD = 10,

  /**
   * 8 servo driver (on canacc8 or similar hardware)
   */
  VLCB_MERG_MODULE_CANSERVO = 11,

  /**
   * BC1a command station
   */
  VLCB_MERG_MODULE_CANBC = 12,

  /**
   * RPI and RFID interface
   */
  VLCB_MERG_MODULE_CANRPI = 13,

  /**
   * Turntable controller (turntable end)
   */
  VLCB_MERG_MODULE_CANTTCA = 14,

  /**
   * Turntable controller (control panel end)
   */
  VLCB_MERG_MODULE_CANTTCB = 15,

  /**
   * Handset controller for old BC1a type handsets
   */
  VLCB_MERG_MODULE_CANHS = 16,

  /**
   * Track occupancy detector
   */
  VLCB_MERG_MODULE_CANTOTI = 17,

  /**
   * 8 inputs 8 outputs
   */
  VLCB_MERG_MODULE_CAN8I8O = 18,

  /**
   * Canservo with servo position feedback
   */
  VLCB_MERG_MODULE_CANSERVO8C = 19,

  /**
   * RFID input
   */
  VLCB_MERG_MODULE_CANRFID = 20,

  VLCB_MERG_MODULE_CANTC4 = 21,

  /**
   * 16 inputs
   */
  VLCB_MERG_MODULE_CANACE16C = 22,

  /**
   * 8 way I/O
   */
  VLCB_MERG_MODULE_CANIO8 = 23,

  VLCB_MERG_MODULE_CANSNDX = 24,

  /**
   * Ethernet interface
   */
  VLCB_MERG_MODULE_CANETHER = 25,

  /**
   * Multiple aspect signalling for CANLED module
   */
  VLCB_MERG_MODULE_CANSIG64 = 26,

  /**
   * Multiple aspect signalling for CANACC8 module
   */
  VLCB_MERG_MODULE_CANSIG8 = 27,

  /**
   * Conditional event generation
   */
  VLCB_MERG_MODULE_CANCOND8C = 28,

  /**
   * Control panel 32/32
   */
  VLCB_MERG_MODULE_CANPAN = 29,

  /**
   * Newer version of CANACE3 firmware
   */
  VLCB_MERG_MODULE_CANACE3C = 30,

  /**
   * Control panel 64/64
   */
  VLCB_MERG_MODULE_CANPANEL = 31,

  /**
   * Multiple I/O – Universal CANMIO firmware
   */
  VLCB_MERG_MODULE_CANMIO = 32,

  /**
   * Multiple IO module 16 inputs emulating CANACE8C on CANMIO hardware
   */
  VLCB_MERG_MODULE_CANACE8MIO = 33,

  /**
   * Solenoid driver module
   */
  VLCB_MERG_MODULE_CANSOL = 34,

  /**
   * Universal CANBIP firmware - Bipolar IO module with additional 8 I/O pins
   * (CANMIO family)
   */
  VLCB_MERG_MODULE_CANBIP = 35,

  /**
   * Solenoid driver module with additional 6 I/O pins (CANMIO family)
   */
  VLCB_MERG_MODULE_CANCDU = 36,

  /**
   * CANACC4 firmware ported to CANCDU
   */
  VLCB_MERG_MODULE_CANACC4CDU = 37,

  /**
   * CAN to MiWi base station
   */
  VLCB_MERG_MODULE_CANWI_BASE = 38,

  /**
   * Wireless cab using MiWi protocol
   */
  VLCB_MERG_MODULE_WI_CAB = 39,

  /**
   * CAN to WiFi connection with Withrottle to CBUS protocol conversion
   */
  VLCB_MERG_MODULE_CANWI_FI = 40,

  /**
   * Turntable controller configured using FLiM
   */
  VLCB_MERG_MODULE_CANFTT = 41,

  /**
   * Handset (alternative to CANCAB)
   */
  VLCB_MERG_MODULE_CANHNDST = 42,

  /**
   * Touchscreen handset
   */
  VLCB_MERG_MODULE_CANTCHNDST = 43,

  /**
   * multi-channel RFID reader
   */
  VLCB_MERG_MODULE_CANRFID8 = 44,

  /**
   * either a 2ch or 8ch RFID reader
   */
  VLCB_MERG_MODULE_CANMCH_RFID = 45,

  /**
   * a Raspberry Pi based module for WiFi
   */
  VLCB_MERG_MODULE_CANPI_WI = 46,

  /**
   * DC train controller
   */
  VLCB_MERG_MODULE_CAN4DC = 47,

  /**
   * Nelevator controller
   */
  VLCB_MERG_MODULE_CANELEV = 48,

  /**
   * 128 switch inputs
   */
  VLCB_MERG_MODULE_CANSCAN = 49,

  /**
   * 16MHz 25k80 version of CANSERVO8c on CANMIO hardware
   */
  VLCB_MERG_MODULE_CANMIO_SVO = 50,

  /**
   * 16MHz 25k80 version of CANACE8MIO on CANMIO hardware
   */
  VLCB_MERG_MODULE_CANMIO_INP = 51,

  /**
   * 16MHz 25k80 version of CANACC8 on CANMIO hardware
   */
  VLCB_MERG_MODULE_CANMIO_OUT = 52,

  /**
   * 16MHz 25k80 version of CANACC5 on CANBIP hardware
   */
  VLCB_MERG_MODULE_CANBIP_OUT = 53,

  /**
   * DCC stop generator
   */
  VLCB_MERG_MODULE_CANASTOP = 54,

  /**
   * CANCMD with on board 3A booster
   */
  VLCB_MERG_MODULE_CANCSB = 55,

  /**
   * Magnet on Track detector
   */
  VLCB_MERG_MODULE_CANMAG = 56,

  /**
   * 16 input equivaent to CANACE8C
   */
  VLCB_MERG_MODULE_CANACE16CMIO = 57,

  /**
   * CBUS module based on Raspberry Pi
   */
  VLCB_MERG_MODULE_CANPI_NODE = 58,

  /**
   * 25K80 version of CANLED64 (IHart and MB)
   */
  VLCB_MERG_MODULE_CANDISP = 59,

  /**
   * Compute Event processing engine
   */
  VLCB_MERG_MODULE_CANCOMPUTE = 60,

  /**
   * Read/Write from/to RC522 RFID tags
   */
  VLCB_MERG_MODULE_CANRC522 = 61,

  /**
   * 8 inputs module (2g version of CANACE8c) (Pete Brownlow)
   */
  VLCB_MERG_MODULE_CANINP = 62,

  /**
   * 8 outputs module (2g version of CANACC8) (Pete Brownlow)
   */
  VLCB_MERG_MODULE_CANOUT = 63,

  /**
   * Extended CANMIO (24 I/O ports) (Pete Brownlow)
   */
  VLCB_MERG_MODULE_CANXIO = 64,

  /**
   * DC cab
   */
  VLCB_MERG_MODULE_CANCABDC = 65,

  /**
   * DC Railcom detector/reader
   */
  VLCB_MERG_MODULE_CANRCOM = 66,

  /**
   * MP3 sound player in response to events (eg: station announcements) (Duncan
   * Greenwood)
   */
  VLCB_MERG_MODULE_CANMP3 = 67,

  /**
   * Addressed RGB LED driver (Duncan Greenwood)
   */
  VLCB_MERG_MODULE_CANXMAS = 68,

  /**
   * Servo setting box (Duncan Greenwood)
   */
  VLCB_MERG_MODULE_CANSVOSET = 69,

  /**
   * DC Command station
   */
  VLCB_MERG_MODULE_CANCMDDC = 70,

  /**
   * Text message display
   */
  VLCB_MERG_MODULE_CANTEXT = 71,

  /**
   * Signal controller
   */
  VLCB_MERG_MODULE_CANASIGNAL = 72,

  /**
   * DCC cab with slider control (Dave Radcliffe)
   */
  VLCB_MERG_MODULE_CANSLIDER = 73,

  /**
   * DC ATC module (Dave Harris)
   */
  VLCB_MERG_MODULE_CANDCATC = 74,

  /**
   * Logic module using and/or gates (Phil Silver)
   */
  VLCB_MERG_MODULE_CANGATE = 75,

  /**
   * Q series PIC input module (Ian Hart)
   */
  VLCB_MERG_MODULE_CANSINP = 76,

  /**
   * Q series PIC input module (Ian Hart)
   */
  VLCB_MERG_MODULE_CANSOUT = 77,

  /**
   * Q series PIC input module (Ian Hart)
   */
  VLCB_MERG_MODULE_CANSBIP = 78,

  /**
   * Message buffer (Phil Silver)
   */
  VLCB_MERG_MODULE_CANBUFFER = 79,

  /**
   * Lever frame module (Tim Coombs)
   */
  VLCB_MERG_MODULE_CANLEVER = 80,

  /**
   * Kit 110 Arduino shield test firmware
   */
  VLCB_MERG_MODULE_CANSHIELD = 81,

  /**
   * 4 inputs 4 outputs (Arduino module)
   */
  VLCB_MERG_MODULE_CAN4IN4OUT = 82,

  /**
   * CANCMD with built in booster (Simon West)
   */
  VLCB_MERG_MODULE_CANCMDB = 83,

  /**
   * neopixel driver (Jon Denham)
   */
  VLCB_MERG_MODULE_CANPIXEL = 84,

  /**
   * Cab2 with pot or encoder (Simon West hardware, Jon Denham new C firmware)
   */
  VLCB_MERG_MODULE_CANCABPE = 85,

  /**
   * Smart train detector (Michael Smith)
   */
  VLCB_MERG_MODULE_CANSMARTTD = 86,

  /**
   * All VLCB modules have the same ID
   */
  VLCB_MERG_MODULE_VLCB = 252,

  /**
   * Software nodes
   */
  VLCB_MERG_MODULE_CAN_SW = 255,

  /**
   * Empty module, bootloader only
   */
  VLCB_MERG_MODULE_EMPTY = 254,

  /**
   * USB interface
   */
  VLCB_MERG_MODULE_CANUSB = 253,
};
