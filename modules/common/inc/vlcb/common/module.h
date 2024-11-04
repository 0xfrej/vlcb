#pragma once

#include <stdint.h>

typedef uint32_t VlcbModuleParamLoadAddr;
#define VLCB_MODULE_LOAD_ADDR_EMPTY (VlcbModuleParamLoadAddr)0

typedef char VlcbModuleParamCpuManuId[4];
#define VLCB_MODULE_CPU_MANUID_UNKNOWN                                         \
  (VlcbModuleParamCpuManuId){'?', '?', '?', '?'}

#define VLCB_VERSION(major, minor)                                             \
  (VlcbModuleVersion){.major = major, .minor = minor.beta = 0}
#define VLCB_VERSION_BETA(major, minor, beta)                                  \
  (VlcbModuleVersion) { .major = major, .minor = minor.beta = beta }

typedef struct {
  uint8_t major;
  char minor;
  uint8_t beta;
} VlcbModuleVersion;

typedef uint8_t VlcbServiceVersion;

/**
 * Error codes for #VLCB_OPC_COMMAND
 */
typedef uint8_t VlcbCommandError;
enum VlcbCommandError {
  /**
   * Invalid command
   */
  VLCB_CMDERR_INVALID_COMMAND = 1,

  /**
   * The mode is not currently in learn mode
   */
  VLCB_CMDERR_NOT_IN_LEARN_MODE = 2,

  /**
   * The mode is not currently in setup mode
   */
  VLCB_CMDERR_NOT_IN_SETUP_MODE = 3,

  /**
   * Too many events provisioned in module
   *
   * The event storage is exhausted
   */
  VLCB_CMDERR_TOO_MANY_EVENTS = 4,

  /**
   * No Event-Variable
   */
  VLCB_CMDERR_NO_EV = 5,

  /**
   * Invalid EV index
   */
  VLCB_CMDERR_INVALID_EV_INDEX = 6,

  /**
   * Invalid event
   */
  VLCB_CMDERR_INVALID_EVENT = 7,

  /**
   * Invalid event index
   */
  VLCB_CMDERR_INVALID_EVENT_INDEX = 8,

  /**
   * Invalid param index
   */
  VLCB_CMDERR_INVALID_PARAM_INDEX = 9,

  /**
   * Invalid NV index
   */
  VLCB_CMDERR_INVALID_NV_INDEX = 10,

  /**
   * Invalid EV value
   */
  VLCB_CMDERR_INVALID_EV_VALUE = 11,

  /**
   * Invalid NV value
   */
  VLCB_CMDERR_INVALID_NV_VALUE = 12,

  /**
   * Another module is already in learn mode
   *
   * Sent when module in learn mode sees NNLRN for different module (also exits
   * learn mode)
   */
  VLCB_CMDERR_ANOTHER_MODULE_IS_IN_LEARN_MODE = 13,
};

/**
 * @brief Module flags
 *
 * These flags are stored within the module parameter
 */
typedef uint8_t VlcbModuleFlags;
enum VlcbModuleFlags {
  /**
   * Module is a consumer of events
   */
  VLCB_MODULE_FLAG_EVENT_CONSUMER = 0x1,

  /**
   * Module is a producer of events
   */
  VLCB_MODULE_FLAG_EVENT_PRODUCER = 0x2,

  /**
   * Module is both a consumer and producer of events
   * This is a shorthand for `()
   */
  VLCB_MODULE_FLAG_EVENT_COMBI = 0x3,

  /**
   * Module is in Normal mode (VLCB) or FLiM (CBUS)
   */
  VLCB_MODULE_FLAG_NORMAL_MODE = 0x4,

  /**
   * Module supports the FCU bootloader protocol
   */
  VLCB_MODULE_FLAG_BOOTLOADER = 0x8,

  /**
   * Module can consume its own events
   */
  VLCB_MODULE_FLAG_CONSUME_OWN_EVENTS = 0x10,

  /**
   * Module is in learn mode
   */
  VLCB_MODULE_FLAG_LEARN_MODE = 0x20,

  /**
   * Module is VLCB compatible
   */
  VLCB_MODULE_FLAG_VLCB = 0x40,
};

/**
 * Module parameter indices
 *
 * These parameters are used for identifiying and correctly configuring modules
 * using the configuraiton tools.
 */
typedef uint8_t VlcbModuleParam;
enum VlcbModuleParam {
  /**
   * Number of parameters
   */
  VLCB_MODULE_PARAM_MODULE_PARAMETER_COUNT = 0,

  /**
   * Manufacturer id
   */
  VLCB_MODULE_PARAM_MODULE_MANUFACTURER = 1,

  /**
   * Minor version (single alphabetic character)
   */
  VLCB_MODULE_PARAM_MINOR_VERSION = 2,

  /**
   * Module type code
   */
  VLCB_MODULE_PARAM_MODULE_TYPE = 3,

  /**
   * Number of events supported
   */
  VLCB_MODULE_PARAM_MAX_EVENT_COUNT = 4,

  /**
   * Event variables per event
   */
  VLCB_MODULE_PARAM_EVENT_VARIABLE_COUNT = 5,

  /**
   * Number of Node variables
   */
  VLCB_MODULE_PARAM_NODE_VARIABLE_COUNT = 6,

  /**
   * Major version (numeric)
   */
  VLCB_MODULE_PARAM_MAJOR_VERSION = 7,

  /**
   * Node flags
   */
  VLCB_MODULE_PARAM_FLAGS = 8,

  /**
   * Processor type
   */
  VLCB_MODULE_PARAM_CPU_ID = 9,

  /**
   * Bus type
   */
  VLCB_MODULE_PARAM_BUS_TYPE = 10,

  /**
   * Load address, 4 bytes
   */
  VLCB_MODULE_PARAM_LOAD_ADDRESS = 11,

  /**
   * CPU manufacturer's id as read from the chip config space, 4 bytes
   * (should be taken from CPU at runtime to not be included in checksum)
   */
  VLCB_MODULE_PARAM_CPU_MANUFACTURER_ID = 15,

  /**
   * CPU manufacturer code
   */
  VLCB_MODULE_PARAM_CPU_MANUFACTURER = 19,

  /**
   * Beta revision (numeric), or 0 for release builds
   */
  VLCB_MODULE_PARAM_BETA_VERSION = 20,
};

/**
 * GRSP codes
 */
typedef uint8_t VlcbGenericResponseStatus;
enum VlcbGenericResponseStatus {
  /**
   * Success
   */
  VLCB_GENERIC_RESPONSE_STAT_OK = 0,

  /**
   * Invalid command
   */
  VLCB_GENERIC_RESPONSE_INVALID_COMMAND = 1,

  /**
   * The mode is not currently in learn mode
   */
  VLCB_GENERIC_RESPONSE_NOT_IN_LEARN_MODE = 2,

  /**
   * The mode is not currently in setup mode
   */
  VLCB_GENERIC_RESPONSE_NOT_IN_SETUP_MODE = 3,

  /**
   * Too many events provisioned in module
   *
   * The event storage is exhausted
   */
  VLCB_GENERIC_RESPONSE_TOO_MANY_EVENTS = 4,

  /**
   * No Event-Variable
   */
  VLCB_GENERIC_RESPONSE_NO_EV = 5,

  /**
   * Invalid EV index
   */
  VLCB_GENERIC_RESPONSE_INVALID_EV_INDEX = 6,

  /**
   * Invalid event
   */
  VLCB_GENERIC_RESPONSE_INVALID_EVENT = 7,

  /**
   * Invalid param index
   */
  VLCB_GENERIC_RESPONSE_INVALID_PARAM_INDEX = 9,

  /**
   * Invalid NV index
   */
  VLCB_GENERIC_RESPONSE_INVALID_NV_INDEX = 10,

  /**
   * Invalid EV value
   */
  VLCB_GENERIC_RESPONSE_INVALID_EV_VALUE = 11,

  /**
   * Invalid NV value
   */
  VLCB_GENERIC_RESPONSE_INVALID_NV_VALUE = 12,

  /**
   * Another module is already in learn mode
   *
   * Sent when module in learn mode sees NNLRN for different module (also exits
   * learn mode)
   */
  VLCB_GENERIC_RESPONSE_ANOTHER_MODULE_IS_IN_LEARN_MODE = 13,

  /**
   * Unknown non volatile memory type
   */
  VLCB_GENERIC_RESPONSE_STAT_UNKNOWN_NVM_TYPE = 254,

  /**
   * Invalid diagnostic
   */
  VLCB_GENERIC_RESPONSE_STAT_INVALID_DIAGNOSTIC = 253,

  /**
   * Invalid service
   */
  VLCB_GENERIC_RESPONSE_STAT_INVALID_SERVICE = 252,

  /**
   * Invalid parameter in command
   */
  VLCB_GENERIC_RESPONSE_STAT_INVALID_COMMAND_PARAMETER = 251,

  /**
   * Invalid Mode
   */
  VLCB_GENERIC_RESPONSE_STAT_INVALID_MODE = 250,
};

/**
 * Parameters to the MODE op-code
 *
 * Exclusive modes
 */
typedef uint8_t VlcbModuleMode;
enum VlcbModuleMode {
  /**
   * Uninitialized / factory settings
   */
  VLCB_MODULE_MODE_UNINITIALIZED = 255,

  /**
   * Set up mode
   */
  VLCB_MODULE_MODE_IN_SETUP = 0,

  /**
   * Normal operation mode
   */
  VLCB_MODULE_MODE_NORMAL = 1,

  /**
   * Turn on learn mode
   */
  VLCB_MODULE_MODE_ENABLE_LEARN_MODE = 8,

  /**
   * Turn off learn mode
   */
  VLCB_MODULE_MODE_DISABLE_LEARN_MODE = 9,

  /**
   * Turn on event acknowledgements
   */
  VLCB_MODULE_MODE_ENABLE_EVENT_ACK = 10,

  /**
   * Turn off event acknowledgements
   */
  VLCB_MODULE_MODE_DISABLE_EVENT_ACK = 11,

  /**
   * Turn on heartbeat
   */
  VLCB_MODULE_MODE_ENABLE_HEARTBEAT = 12,

  /**
   * Turn off heartbeat
   */
  VLCB_MODULE_MODE_DISABLE_HEARTBEAT = 13,

  /**
   * PIC Boot loader mode
   */
  VLCB_MODULE_MODE_BOOTLOADER = 14,
};

/**
 * VLCB Service Types
 */
typedef uint8_t VlcbServiceType;
enum VlcbServiceType {

  /**
   * Internal service.
   *
   * Can be used for implementing certain behaviors while
   * using the service pattern for the implementation.
   *
   * Will not be shown in list of services requested by RQSD.
   */
  VLCB_SVC_TYPE_INTERNAL = 0,

  /**
   * The minimum node service.
   *
   * All modules must implement this.
   */
  VLCB_SVC_TYPE_MINIMUM_NODE_SERVICE = 1,

  /**
   * The NV service.
   */
  VLCB_SVC_TYPE_NODE_VARIABLE = 2,

  /**
   * CAN service.
   *
   * Deals with CANID enumeration.
   */
  VLCB_SVC_TYPE_CAN_BUS = 3,

  /**
   * Old (CBUS) event teaching service.
   */
  VLCB_SVC_TYPE_LEGACY_EVENT_TEACHING = 4,

  /**
   * Event producer service.
   */
  VLCB_SVC_TYPE_EVENT_PRODUCER = 5,

  /**
   * Event comsumer service.
   */
  VLCB_SVC_TYPE_EVENT_CONSUMER = 6,

  /**
   * New event teaching service.
   */
  VLCB_SVC_TYPE_EVENT_TEACHING = 7,

  /**
   * Consume own events service.
   */
  VLCB_SVC_TYPE_CONSUME_OWN_EVENTS = 8,

  /**
   * Event acknowledge service.
   *
   * Useful for debugging event configuration.
   */
  VLCB_SVC_TYPE_EVENT_ACKNOWLEDGE = 9,

  /**
   * FCU/PIC bootloader service.
   */
  VLCB_SVC_TYPE_BOOTLOADER = 10,

  /**
   * Streaming (Long Messages) service.
   */
  VLCB_SVC_TYPE_STREAMING = 17,
};

