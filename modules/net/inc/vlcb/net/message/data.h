#include "vlcb/common/can.h"
#include "vlcb/common/dcc.h"
#include "vlcb/common/event.h"
#include "vlcb/common/manufacturer.h"
#include "vlcb/common/module.h"
#include "vlcb/common/node.h"
#include "vlcb/common/opcode.h"
#include "vlcb/common/time.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * VlcbNetMsgDccReleaseSession
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_RELEASE_SESSION
 */
typedef struct {
  VlcbDccSessionNr session;
} VlcbNetMsgDccReleaseSession;

/**
 * VlcbNetMsgDccQueryLocoStatus
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_QUERY_LOCO_STATUS
 */
typedef struct {
  VlcbDccSessionNr session;
} VlcbNetMsgDccQueryLocoStatus;

/**
 * VlcbNetMsgDccSessionKeepAlive
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SESSION_KEEP_ALIVE
 */
typedef struct {
  VlcbDccSessionNr session;
} VlcbNetMsgDccSessionKeepAlive;

/**
 * VlcbNetMsgDebugMsg1
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DEBUG_MSG1
 */
typedef struct {
  uint8_t status;
} VlcbNetMsgDebugMsg1;

/**
 * VlcbNetMsgExtOpcode0
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE0
 */
typedef struct {
  uint8_t opcodeExtension;
} VlcbNetMsgExtOpcode0;

/**
 * VlcbNetMsgDccRequestNewSession
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_REQUEST_NEW_SESSION
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
} VlcbNetMsgDccRequestNewSession;

/**
 * VlcbNetMsgDccQueryConsist
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DCC_QUERY_CONSIST
 */
typedef struct {
  VlcbDccConsistId consist;
  uint8_t index;
} VlcbNetMsgDccQueryConsist;

/**
 * VlcbNetMsgSetNodeNumber
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_SET_NODE_NUMBER
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgSetNodeNumber;

/**
 * VlcbNetMsgDccAllocateLocoToActivity
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_ALLOCATE_LOCO_TO_ACTIVITY
 */
typedef struct {
  VlcbDccSessionNr session;
  uint8_t allocationCode;
} VlcbNetMsgDccAllocateLocoToActivity;

/**
 * VlcbNetMsgDccSetThrottleMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SET_THROTTLE_MODE
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccThrottleSpeedMode throttleMode;
  bool inServiceMode;
  bool inSoundControlMode;
} VlcbNetMsgDccSetThrottleMode;

/**
 * VlcbNetMsgDccConsistAddLoco
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_CONSIST_ADD_LOCO
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccConsistId consist;
} VlcbNetMsgDccConsistAddLoco;

/**
 * VlcbNetMsgDccConsistRemoveLoco
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_CONSIST_REMOVE_LOCO
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccConsistId consist;
} VlcbNetMsgDccConsistRemoveLoco;

/**
 * VlcbNetMsgDccSetLocoThrottle
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SET_LOCO_THROTTLE
 */
typedef struct {
  VlcbDccSessionNr session;
  uint8_t speed;
  VlcbDccLocoDirection direction;
} VlcbNetMsgDccSetLocoThrottle;

/**
 * VlcbNetMsgDccSetLocoFlags
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SET_LOCO_FLAGS
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccThrottleSpeedMode speedMode;
  bool lightsOn;
  VlcbDccLocoDirection direction;
  VlcbDccLocoState state;
} VlcbNetMsgDccSetLocoFlags;

/**
 * VlcbNetMsgDccLocoFunctionOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_LOCO_FUNCTION_ON
 */
typedef struct {
  VlcbDccSessionNr session;
  uint8_t functionNr;
} VlcbNetMsgDccLocoFunctionOn;

/**
 * VlcbNetMsgDccLocoFunctionOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_LOCO_FUNCTION_OFF
 */
typedef struct {
  VlcbDccSessionNr session;
  uint8_t functionNr;
} VlcbNetMsgDccLocoFunctionOff;

/**
 * VlcbNetMsgDccServiceModeStatus
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SERVICE_MODE_STATUS
 */
typedef struct {
  VlcbDccSessionNr session;
  /* @remark possible status values are unknown at the moment*/
  uint8_t status;
} VlcbNetMsgDccServiceModeStatus;

/**
 * VlcbNetMsgResetModuleToFactory
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_RESET_MODULE_TO_FACTORY
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgResetModuleToFactory;

/**
 * VlcbNetMsgRequestNewNodeNumber
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_REQUEST_NEW_NODE_NUMBER
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgRequestNewNodeNumber;

/**
 * VlcbNetMsgNodeNumberReleased
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_NUMBER_RELEASED
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgNodeNumberReleased;

/**
 * VlcbNetMsgNodeNumberAck
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_NODE_NUMBER_ACK
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgNodeNumberAck;

/**
 * VlcbNetMsgPutNodeIntoLearnMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_PUT_NODE_INTO_LEARN_MODE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgPutNodeIntoLearnMode;

/**
 * VlcbNetMsgReleaseNodeFromLearnMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_RELEASE_NODE_FROM_LEARN_MODE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgReleaseNodeFromLearnMode;

/**
 * VlcbNetMsgForgetAllLearnedEvents
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_FORGET_ALL_LEARNED_EVENTS
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgForgetAllLearnedEvents;

/**
 * VlcbNetMsgQueryAvailableEventSlots
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_AVAILABLE_EVENT_SLOTS
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgQueryAvailableEventSlots;

/**
 * VlcbNetMsgQueryAllLearnedEvents
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_ALL_LEARNED_EVENTS
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgQueryAllLearnedEvents;

/**
 * VlcbNetMsgQueryLearnedEventCount
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_LEARNED_EVENT_COUNT
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgQueryLearnedEventCount;

/**
 * VlcbNetMsgWriteAck
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_WRITE_ACK
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgWriteAck;

/**
 * VlcbNetMsgQueryNodeAccessoryData
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_NODE_ACCESSORY_DATA
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgQueryNodeAccessoryData;

/**
 * VlcbNetMsgQueryDeviceDataShortMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_DEVICE_DATA_SHORT_MODE
 */
typedef struct {
  VlcbNodeNumber dataNumber;
} VlcbNetMsgQueryDeviceDataShortMode;

/**
 * VlcbNetMsgRebootIntoBootloader
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_REBOOT_INTO_BOOTLOADER
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgRebootIntoBootloader;

/**
 * VlcbNetMsgForceCanEnumeration
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_FORCE_CAN_ENUMERATION
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgForceCanEnumeration;

/**
 * VlcbNetMsgRestartNode
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_RESTART_NODE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetMsgRestartNode;

/**
 * VlcbNetMsgExtOpcode1
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE1
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[1];
} VlcbNetMsgExtOpcode1;

/**
 * VlcbNetMsgDccSetLocoFunctions
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SET_LOCO_FUNCTIONS
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccLocoFunctionRange range;
  uint8_t functionStates;
} VlcbNetMsgDccSetLocoFunctions;

/**
 * VlcbNetMsgDccQueryLocoSession
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_QUERY_LOCO_SESSION
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
  VlcbDccSessionQueryMode mode;
} VlcbNetMsgDccQueryLocoSession;

/**
 * VlcbNetMsgDccCommandStationError
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_COMMAND_STATION_ERROR
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
  uint8_t errorCode;
} VlcbNetMsgDccCommandStationError;

/**
 * VlcbNetMsgCommandError
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_COMMAND_ERROR
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t errorCode;
} VlcbNetMsgCommandError;

/**
 * VlcbNetMsgAvailableEventSlots
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_AVAILABLE_EVENT_SLOTS
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t availableSlots;
} VlcbNetMsgAvailableEventSlots;

/**
 * VlcbNetMsgQueryNodeVariable
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_NODE_VARIABLE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t nodeVariableIndex;
} VlcbNetMsgQueryNodeVariable;

/**
 * VlcbNetMsgQueryLearnedEventByIndex
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_LEARNED_EVENT_BY_INDEX
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t eventIndex;
} VlcbNetMsgQueryLearnedEventByIndex;

/**
 * VlcbNetMsgQueryNodeParameterByIndex
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_NODE_PARAMETER_BY_INDEX
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t parameterIndex;
} VlcbNetMsgQueryNodeParameterByIndex;

/**
 * VlcbNetMsgLearnedEventCount
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LEARNED_EVENT_COUNT
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t learnedEventCount;
} VlcbNetMsgLearnedEventCount;

/**
 * VlcbNetMsgSetNodeCanId
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_SET_NODE_CAN_ID
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbCanId canId;
} VlcbNetMsgSetNodeCanId;

typedef uint8_t VlcbNetMsgModuleMode;
enum VlcbNetMsgModuleMode {
  VLCB_NET_DATA_MODULE_MODE_SETUP = 0,
  VLCB_NET_DATA_MODULE_MODE_NORMAL = 1,
};

/**
 * VlcbNetMsgChangeModuleMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_CHANGE_MODULE_MODE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbNetMsgModuleMode mode;
} VlcbNetMsgChangeModuleMode;

/**
 * VlcbNetMsgQueryServiceDiscovery
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_SERVICE_DISCOVERY
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
} VlcbNetMsgQueryServiceDiscovery;

/**
 * VlcbNetMsgExtOpcode2
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE2
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[2];
} VlcbNetMsgExtOpcode2;

/**
 * VlcbNetMsgDccSendRawPacket3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_RAW_PACKET3
 */
typedef struct {
  uint8_t repeatTimes;
  uint8_t data[3];
} VlcbNetMsgDccSendRawPacket3;

/**
 * VlcbNetMsgDccWriteCvByteInOpsMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_WRITE_CV_BYTE_IN_OPS_MODE
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  uint8_t value;
} VlcbNetMsgDccWriteCvByteInOpsMode;

/**
 * VlcbNetMsgDcWriteCvBitInOpsMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DC_WRITE_CV_BIT_IN_OPS_MODE
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  uint8_t value;
} VlcbNetMsgDcWriteCvBitInOpsMode;

/**
 * VlcbNetMsgDccReadCv
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DCC_READ_CV
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  /* @remark possible values unknown */
  uint8_t mode;
} VlcbNetMsgDccReadCv;

/**
 * VlcbNetMsgDccCvValue
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DCC_CV_VALUE
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  uint8_t value;
} VlcbNetMsgDccCvValue;

/**
 * VlcbNetMsgQueryDiagnosticData
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_DIAGNOSTIC_DATA
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
  uint8_t diagnosticCode;
} VlcbNetMsgQueryDiagnosticData;

/**
 * VlcbNetMsgSetNodeVariable
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_SET_NODE_VARIABLE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t nodeVariableIndex;
  uint8_t value;
} VlcbNetMsgSetNodeVariable;

/**
 * VlcbNetMsgLongEventAccessoryOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_ON
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgLongEventAccessoryOn;

/**
 * VlcbNetMsgLongEventAccessoryOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_OFF
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgLongEventAccessoryOff;

/**
 * VlcbNetMsgQueryLongEventAccessoryState
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_LONG_EVENT_ACCESSORY_STATE
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgQueryLongEventAccessoryState;

/**
 * VlcbNetMsgLongEventAccessoryStateOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgLongEventAccessoryStateOn;

/**
 * VlcbNetMsgLongEventAccessoryStateOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgLongEventAccessoryStateOff;

/**
 * VlcbNetMsgForgetLearnedEvent
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_FORGET_LEARNED_EVENT
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgForgetLearnedEvent;

/**
 * VlcbNetMsgLegacySetNodeVariable
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LEGACY_SET_NODE_VARIABLE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t nodeVariableIndex;
  uint8_t value;
} VlcbNetMsgLegacySetNodeVariable;

/**
 * VlcbNetMsgNodeVariableValue
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_VARIABLE_VALUE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t nodeVariableIndex;
  uint8_t value;
} VlcbNetMsgNodeVariableValue;

/**
 * VlcbNetMsgShortEventAccessoryOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_ON
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgShortEventAccessoryOn;

/**
 * VlcbNetMsgShortEventAccessoryOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgShortEventAccessoryOff;

/**
 * VlcbNetMsgQueryShortEventAccessoryState
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_SHORT_EVENT_ACCESSORY_STATE
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgQueryShortEventAccessoryState;

/**
 * VlcbNetMsgNodeParameterValue
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_PARAMETER_VALUE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t parameterIndex;
  uint8_t value;
} VlcbNetMsgNodeParameterValue;

/**
 * VlcbNetMsgQueryEventVariable
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_EVENT_VARIABLE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t eventIndex;
  uint8_t value;
} VlcbNetMsgQueryEventVariable;

/**
 * VlcbNetMsgShortEventAccessoryStateOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgShortEventAccessoryStateOn;

/**
 * VlcbNetMsgShortEventAccessoryStateOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF
 */
typedef struct {
  VlcbEvent event;
} VlcbNetMsgShortEventAccessoryStateOff;

/**
 * VlcbNetMsgExtOpcode3
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE3
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[3];
} VlcbNetMsgExtOpcode3;

/**
 * VlcbNetMsgDccSendRawPacket4
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_RAW_PACKET4
 */
typedef struct {
  uint8_t repeatTimes;
  uint8_t data[4];
} VlcbNetMsgDccSendRawPacket4;

/**
 * VlcbNetMsgDccWriteCvInServiceMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_WRITE_CV_IN_SERVICE_MODE
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  uint8_t mode; // TODO: this probably has some enum
  uint8_t value;
} VlcbNetMsgDccWriteCvInServiceMode;

/**
 * VlcbNetMsgHeartbeat
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_HEARTBEAT
 */
typedef struct {
  VlcbNodeNumber sourceNodeNumber;
  uint8_t sequenceNr;
  uint8_t status;
} VlcbNetMsgHeartbeat;

/**
 * VlcbNetMsgServiceDiscoveryResponse
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SERVICE_DISCOVERY_RESPONSE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
  VlcbServiceType serviceType;
  uint8_t version;
} VlcbNetMsgServiceDiscoveryResponse;

/**
 * VlcbNetMsgGenericResponse
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_GENERIC_RESPONSE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbOpCode opcode;
  VlcbServiceType serviceType;
  uint8_t result;
} VlcbNetMsgGenericResponse;

/**
 * VlcbNetMsgLongEventAccessoryOn1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_ON1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetMsgLongEventAccessoryOn1;

/**
 * VlcbNetMsgLongEventAccessoryOff1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_OFF1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetMsgLongEventAccessoryOff1;

/**
 * VlcbNetMsgQueryEventVariableByIdex
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_EVENT_VARIABLE_BY_IDEX
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventVariableIndex;
} VlcbNetMsgQueryEventVariableByIdex;

/**
 * VlcbNetMsgLongEventAccessoryStateOn1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetMsgLongEventAccessoryStateOn1;

/**
 * VlcbNetMsgLongEventAccessoryStateOff1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetMsgLongEventAccessoryStateOff1;

/**
 * VlcbNetMsgEventVariableValue
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_EVENT_VARIABLE_VALUE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t eventIndex;
  uint8_t eventVariableIndex;
  uint8_t eventVariableValue;
} VlcbNetMsgEventVariableValue;

/**
 * VlcbNetMsgModuleInfo
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_MODULE_INFO
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbManufacturer manufacturer;
  uint8_t moduleId;
  VlcbModuleFlags flags;
} VlcbNetMsgModuleInfo;

/**
 * VlcbNetMsgShortEventAccessoryOn1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_ON1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetMsgShortEventAccessoryOn1;

/**
 * VlcbNetMsgShortEventAccessoryOff1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetMsgShortEventAccessoryOff1;

/**
 * VlcbNetMsgShortEventAccessoryStateOn1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetMsgShortEventAccessoryStateOn1;

/**
 * VlcbNetMsgShortEventAccessoryStateOff1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetMsgShortEventAccessoryStateOff1;

/**
 * VlcbNetMsgExtOpcode4
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE4
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[4];
} VlcbNetMsgExtOpcode4;

/**
 * VlcbNetMsgDccSendRawPacket5
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_RAW_PACKET5
 */
typedef struct {
  uint8_t repeatTimes;
  uint8_t data[5];
} VlcbNetMsgDccSendRawPacket5;

/**
 * VlcbNetMsgDccWriteCvByteInOpsModeByAddress
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_WRITE_CV_BYTE_IN_OPS_MODE_BY_ADDRESS
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
  uint16_t CV;
  uint16_t mode; // TODO: this probably has some enum
  uint8_t value;
} VlcbNetMsgDccWriteCvByteInOpsModeByAddress;

/**
 * VlcbNetMsgDccSendDataToCab
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_DATA_TO_CAB
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
  uint8_t dataCode;
  uint8_t data[3];
} VlcbNetMsgDccSendDataToCab;

/**
 * VlcbNetMsgDiagnosticData
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DIAGNOSTIC_DATA
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
  uint8_t diagnosticCode;
  uint8_t diagnosticValue;
} VlcbNetMsgDiagnosticData;

/**
 * VlcbNetMsgFastClock
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_FAST_CLOCK
 */
typedef struct {
  uint8_t minutes;
  uint8_t hours;
  VlcbTimeWeekDay weekDay;
  uint8_t dayOfMonth;
  VlcbTimeMonth month;
  // 0 means freeze
  uint8_t dividerFactor;
  int8_t temperature;
} VlcbNetMsgFastClock;

/**
 * VlcbNetMsgLongEventAccessoryOn2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_ON2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetMsgLongEventAccessoryOn2;

/**
 * VlcbNetMsgLongEventAccessoryOff2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_OFF2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetMsgLongEventAccessoryOff2;

/**
 * VlcbNetMsgTeachEvent
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_TEACH_EVENT
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventVariableIndex;
  uint8_t eventVariableValue;
} VlcbNetMsgTeachEvent;

/**
 * VlcbNetMsgEventVariableValueInLearnMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_EVENT_VARIABLE_VALUE_IN_LEARN_MODE
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventVariableIndex;
  uint8_t eventVariableValue;
} VlcbNetMsgEventVariableValueInLearnMode;

/**
 * VlcbNetMsgLongEventAccessoryStateOn2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetMsgLongEventAccessoryStateOn2;

/**
 * VlcbNetMsgLongEventAccessoryStateOff2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetMsgLongEventAccessoryStateOff2;

/**
 * VlcbNetMsgShortEventAccessoryOn2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_ON2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetMsgShortEventAccessoryOn2;

/**
 * VlcbNetMsgShortEventAccessoryOff2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetMsgShortEventAccessoryOff2;

/**
 * VlcbNetMsgShortEventAccessoryStateOn2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetMsgShortEventAccessoryStateOn2;

/**
 * VlcbNetMsgShortEventAccessoryStateOff2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetMsgShortEventAccessoryStateOff2;

/**
 * VlcbNetMsgExtOpcode5
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE5
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[5];
} VlcbNetMsgExtOpcode5;

/**
 * VlcbNetMsgDccSendRawPacket6
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_RAW_PACKET6
 */
typedef struct {
  uint8_t repeatTimes;
  uint8_t data[6];
} VlcbNetMsgDccSendRawPacket6;

/**
 * VlcbNetMsgDccLocoReport
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DCC_LOCO_REPORT
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccDecoderAddr decoderAddr;
  uint8_t
      speed_dir; // TODO: this needs rework...i didn't find anything in docs yet
  struct {
    uint8_t F0_F4;
    uint8_t F5_F8;
    uint8_t F9_F12;
  } functionStates;
} VlcbNetMsgDccLocoReport;

/**
 * VlcbNetMsgModuleName
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_MODULE_NAME
 */
typedef struct {
  char moduleName[7];
} VlcbNetMsgModuleName;

/**
 * VlcbNetMsgDccCommandStationStatus
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_COMMAND_STATION_STATUS
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  struct {
    bool selfTestHwError;
    bool busIsHalted;
    bool resetFinished;
    bool dccTrackError;
    bool dccTrackIsOn;
    bool dccEmergencyStop;
    bool dccInServiceMode;
  } flags;
  VlcbModuleVersion moduleVersion;
} VlcbNetMsgDccCommandStationStatus;

/**
 * VlcbNetMsgEventAck
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EVENT_ACK
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbOpCode acknowledgedOpcode;
  VlcbEvent event;
} VlcbNetMsgEventAck;

/**
 * VlcbNetMsgExtendedServiceDiscoveryResponse
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_EXTENDED_SERVICE_DISCOVERY_RESPONSE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
  VlcbServiceType serviceType;
  uint8_t serviceData[3]; // TODO: Union of structs?
} VlcbNetMsgExtendedServiceDiscoveryResponse;

/**
 * VlcbNetMsgStreamPacket
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_STREAM_PACKET
 */
typedef struct {
  uint8_t streamId;
  uint8_t sequenceNr;
  union {
    struct {
      uint16_t messageLen;
      uint16_t checksum;
      uint8_t flags;
    } fistPacket;
    struct {
      uint8_t data[5];
    } dataPacket;
  } data;
} VlcbNetMsgStreamPacket;

/**
 * VlcbNetMsgNodeParametersReport
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_PARAMETERS_REPORT
 */
typedef struct {
  uint8_t params[7];
} VlcbNetMsgNodeParametersReport;

/**
 * VlcbNetMsgLongEventAccessoryOn3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_ON3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetMsgLongEventAccessoryOn3;

/**
 * VlcbNetMsgLongEventAccessoryOff3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_OFF3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetMsgLongEventAccessoryOff3;

/**
 * VlcbNetMsgLearnedEventResponse
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LEARNED_EVENT_RESPONSE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbEvent event;
  uint8_t eventIndex;
} VlcbNetMsgLearnedEventResponse;

/**
 * VlcbNetMsgLongEventAccessoryStateOn3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetMsgLongEventAccessoryStateOn3;

/**
 * VlcbNetMsgLongEventAccessoryStateOff3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetMsgLongEventAccessoryStateOff3;

/**
 * VlcbNetMsgTeachEventByIndex
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_TEACH_EVENT_BY_INDEX
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventIndex;
  uint8_t eventVariableIndex;
  uint8_t eventVariableValue;
} VlcbNetMsgTeachEventByIndex;

/**
 * VlcbNetMsgDataEventAccessory
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DATA_EVENT_ACCESSORY
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t data[5];
} VlcbNetMsgDataEventAccessory;

/**
 * VlcbNetMsgNodeAccessoryData
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_ACCESSORY_DATA
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t data[5];
} VlcbNetMsgNodeAccessoryData;

/**
 * VlcbNetMsgShortEventAccessoryOn3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_ON3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetMsgShortEventAccessoryOn3;

/**
 * VlcbNetMsgShortEventAccessoryOff3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetMsgShortEventAccessoryOff3;

/**
 * VlcbNetMsgDeviceDataEventShortMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DEVICE_DATA_EVENT_SHORT_MODE
 */
typedef struct {
  uint16_t devideNumber;
  uint8_t data[5];
} VlcbNetMsgDeviceDataEventShortMode;

/**
 * VlcbNetMsgDeviceDataShortMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DEVICE_DATA_SHORT_MODE
 */
typedef struct {
  uint16_t devideNumber;
  uint8_t data[5];
} VlcbNetMsgDeviceDataShortMode;

/**
 * VlcbNetMsgWriteData
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_WRITE_DATA
 */
typedef struct {
  uint16_t devideNumber;
  uint8_t data[5];
} VlcbNetMsgWriteData;

/**
 * VlcbNetMsgShortEventAccessoryStateOn3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetMsgShortEventAccessoryStateOn3;

/**
 * VlcbNetMsgShortEventAccessoryStateOff3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetMsgShortEventAccessoryStateOff3;

/**
 * VlcbNetMsgExtOpcode6
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE6
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[6];
} VlcbNetMsgExtOpcode6;
