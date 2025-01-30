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
 * VlcbNetDataDccReleaseSession
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_RELEASE_SESSION
 */
typedef struct {
  VlcbDccSessionNr session;
} VlcbNetDataDccReleaseSession;

/**
 * VlcbNetDataDccQueryLocoStatus
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_QUERY_LOCO_STATUS
 */
typedef struct {
  VlcbDccSessionNr session;
} VlcbNetDataDccQueryLocoStatus;

/**
 * VlcbNetDataDccSessionKeepAlive
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SESSION_KEEP_ALIVE
 */
typedef struct {
  VlcbDccSessionNr session;
} VlcbNetDataDccSessionKeepAlive;

/**
 * VlcbNetDataDebugMsg1
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DEBUG_MSG1
 */
typedef struct {
  uint8_t status;
} VlcbNetDataDebugMsg1;

/**
 * VlcbNetDataExtOpcode0
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE0
 */
typedef struct {
  uint8_t opcodeExtension;
} VlcbNetDataExtOpcode0;

/**
 * VlcbNetDataDccRequestNewSession
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_REQUEST_NEW_SESSION
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
} VlcbNetDataDccRequestNewSession;

/**
 * VlcbNetDataDccQueryConsist
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DCC_QUERY_CONSIST
 */
typedef struct {
  VlcbDccConsistId consist;
  uint8_t index;
} VlcbNetDataDccQueryConsist;

/**
 * VlcbNetDataSetNodeNumber
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_SET_NODE_NUMBER
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataSetNodeNumber;

/**
 * VlcbNetDataDccAllocateLocoToActivity
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_ALLOCATE_LOCO_TO_ACTIVITY
 */
typedef struct {
  VlcbDccSessionNr session;
  uint8_t allocationCode;
} VlcbNetDataDccAllocateLocoToActivity;

/**
 * VlcbNetDataDccSetThrottleMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SET_THROTTLE_MODE
 * TODO: custom serialization - look at docs
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccThrottleSpeedMode throttleMode;
  bool inServiceMode;
  bool inSoundControlMode;
} VlcbNetDataDccSetThrottleMode;

/**
 * VlcbNetDataDccConsistAddLoco
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_CONSIST_ADD_LOCO
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccConsistId consist;
} VlcbNetDataDccConsistAddLoco;

/**
 * VlcbNetDataDccConsistRemoveLoco
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_CONSIST_REMOVE_LOCO
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccConsistId consist;
} VlcbNetDataDccConsistRemoveLoco;

/**
 * VlcbNetDataDccSetLocoThrottle
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SET_LOCO_THROTTLE
 * TODO: custom serialization
 */
typedef struct {
  VlcbDccSessionNr session;
  /* 7 bit wide */
  uint8_t speed;
  VlcbDccLocoDirection direction;
} VlcbNetDataDccSetLocoThrottle;

/**
 * VlcbNetDataDccSetLocoFlags
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SET_LOCO_FLAGS
 * TODO: custom serialization
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccThrottleSpeedMode speedMode;
  bool lighsOn;
  VlcbDccLocoDirection direction;
  VlcbDccLocoState state;
} VlcbNetDataDccSetLocoFlags;

/**
 * VlcbNetDataDccLocoFunctionOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_LOCO_FUNCTION_ON
 */
typedef struct {
  VlcbDccSessionNr session;
  uint8_t functionNr;
} VlcbNetDataDccLocoFunctionOn;

/**
 * VlcbNetDataDccLocoFunctionOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_LOCO_FUNCTION_OFF
 */
typedef struct {
  VlcbDccSessionNr session;
  uint8_t functionNr;
} VlcbNetDataDccLocoFunctionOff;

/**
 * VlcbNetDataDccServiceModeStatus
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SERVICE_MODE_STATUS
 */
typedef struct {
  VlcbDccSessionNr session;
  /* @remark possible status values are unknown at the moment*/
  uint8_t status;
} VlcbNetDataDccServiceModeStatus;

/**
 * VlcbNetDataResetModuleToFactory
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_RESET_MODULE_TO_FACTORY
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataResetModuleToFactory;

/**
 * VlcbNetDataRequestNewNodeNumber
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_REQUEST_NEW_NODE_NUMBER
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataRequestNewNodeNumber;

/**
 * VlcbNetDataNodeNumberReleased
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_NUMBER_RELEASED
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataNodeNumberReleased;

/**
 * VlcbNetDataNodeNumberAck
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_NODE_NUMBER_ACK
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataNodeNumberAck;

/**
 * VlcbNetDataPutNodeIntoLearnMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_PUT_NODE_INTO_LEARN_MODE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataPutNodeIntoLearnMode;

/**
 * VlcbNetDataReleaseNodeFromLearnMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_RELEASE_NODE_FROM_LEARN_MODE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataReleaseNodeFromLearnMode;

/**
 * VlcbNetDataForgetAllLearnedEvents
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_FORGET_ALL_LEARNED_EVENTS
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataForgetAllLearnedEvents;

/**
 * VlcbNetDataQueryAvailableEventSlots
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_AVAILABLE_EVENT_SLOTS
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataQueryAvailableEventSlots;

/**
 * VlcbNetDataQueryAllLearnedEvents
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_ALL_LEARNED_EVENTS
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataQueryAllLearnedEvents;

/**
 * VlcbNetDataQueryLearnedEventCount
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_LEARNED_EVENT_COUNT
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataQueryLearnedEventCount;

/**
 * VlcbNetDataWriteAck
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_WRITE_ACK
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataWriteAck;

/**
 * VlcbNetDataQueryNodeAccessoryData
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_NODE_ACCESSORY_DATA
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataQueryNodeAccessoryData;

/**
 * VlcbNetDataQueryDeviceDataShortMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_DEVICE_DATA_SHORT_MODE
 */
typedef struct {
  VlcbNodeNumber dataNumber;
} VlcbNetDataQueryDeviceDataShortMode;

/**
 * VlcbNetDataRebootIntoBootloader
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_REBOOT_INTO_BOOTLOADER
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataRebootIntoBootloader;

/**
 * VlcbNetDataForceCanEnumeration
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_FORCE_CAN_ENUMERATION
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataForceCanEnumeration;

/**
 * VlcbNetDataRestartNode
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_RESTART_NODE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
} VlcbNetDataRestartNode;

/**
 * VlcbNetDataExtOpcode1
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE1
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[1];
} VlcbNetDataExtOpcode1;

/**
 * VlcbNetDataDccSetLocoFunctions
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SET_LOCO_FUNCTIONS
 */
typedef struct {
  VlcbDccSessionNr session;
  VlcbDccLocoFunctionRange range;
  uint8_t functionStates;
} VlcbNetDataDccSetLocoFunctions;

/**
 * VlcbNetDataDccQueryLocoSession
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_QUERY_LOCO_SESSION
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
  VlcbDccSessionQueryMode mode;
} VlcbNetDataDccQueryLocoSession;

/**
 * VlcbNetDataDccCommandStationError
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_COMMAND_STATION_ERROR
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
  uint8_t errorCode;
} VlcbNetDataDccCommandStationError;

/**
 * VlcbNetDataCommandError
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_COMMAND_ERROR
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t errorCode;
} VlcbNetDataCommandError;

/**
 * VlcbNetDataAvailableEventSlots
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_AVAILABLE_EVENT_SLOTS
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t availableSlots;
} VlcbNetDataAvailableEventSlots;

/**
 * VlcbNetDataQueryNodeVariable
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_NODE_VARIABLE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t nodeVariableIndex;
} VlcbNetDataQueryNodeVariable;

/**
 * VlcbNetDataQueryLearnedEventByIndex
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_LEARNED_EVENT_BY_INDEX
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t eventIndex;
} VlcbNetDataQueryLearnedEventByIndex;

/**
 * VlcbNetDataQueryNodeParameterByIndex
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_NODE_PARAMETER_BY_INDEX
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t parameterIndex;
} VlcbNetDataQueryNodeParameterByIndex;

/**
 * VlcbNetDataLearnedEventCount
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LEARNED_EVENT_COUNT
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t learnedEventCount;
} VlcbNetDataLearnedEventCount;

/**
 * VlcbNetDataSetNodeCanId
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_SET_NODE_CAN_ID
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbCanId canId;
} VlcbNetDataSetNodeCanId;

typedef uint8_t VlcbNetDataModuleMode;
enum VlcbNetDataModuleMode {
  VLCB_NET_DATA_MODULE_MODE_SETUP = 0,
  VLCB_NET_DATA_MODULE_MODE_NORMAL = 1,
};

/**
 * VlcbNetDataChangeModuleMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_CHANGE_MODULE_MODE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbNetDataModuleMode mode;
} VlcbNetDataChangeModuleMode;

/**
 * VlcbNetDataQueryServiceDiscovery
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_SERVICE_DISCOVERY
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
} VlcbNetDataQueryServiceDiscovery;

/**
 * VlcbNetDataExtOpcode2
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE2
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[2];
} VlcbNetDataExtOpcode2;

/**
 * VlcbNetDataDccSendRawPacket3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_RAW_PACKET3
 */
typedef struct {
  uint8_t repeatTimes;
  uint8_t data[3];
} VlcbNetDataDccSendRawPacket3;

/**
 * VlcbNetDataDccWriteCvByteInOpsMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_WRITE_CV_BYTE_IN_OPS_MODE
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  uint8_t value;
} VlcbNetDataDccWriteCvByteInOpsMode;

/**
 * VlcbNetDataDcWriteCvBitInOpsMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DC_WRITE_CV_BIT_IN_OPS_MODE
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  uint8_t value;
} VlcbNetDataDcWriteCvBitInOpsMode;

/**
 * VlcbNetDataDccReadCv
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DCC_READ_CV
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  /* @remark possible values unknown */
  uint8_t mode;
} VlcbNetDataDccReadCv;

/**
 * VlcbNetDataDccCvValue
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DCC_CV_VALUE
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  uint8_t value;
} VlcbNetDataDccCvValue;

/**
 * VlcbNetDataQueryDiagnosticData
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_DIAGNOSTIC_DATA
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
  uint8_t diagnosticCode;
} VlcbNetDataQueryDiagnosticData;

/**
 * VlcbNetDataSetNodeVariable
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_SET_NODE_VARIABLE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t nodeVariableIndex;
  uint8_t value;
} VlcbNetDataSetNodeVariable;

/**
 * VlcbNetDataLongEventAccessoryOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_ON
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataLongEventAccessoryOn;

/**
 * VlcbNetDataLongEventAccessoryOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_OFF
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataLongEventAccessoryOff;

/**
 * VlcbNetDataQueryLongEventAccessoryState
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_LONG_EVENT_ACCESSORY_STATE
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataQueryLongEventAccessoryState;

/**
 * VlcbNetDataLongEventAccessoryStateOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataLongEventAccessoryStateOn;

/**
 * VlcbNetDataLongEventAccessoryStateOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataLongEventAccessoryStateOff;

/**
 * VlcbNetDataForgetLearnedEvent
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_FORGET_LEARNED_EVENT
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataForgetLearnedEvent;

/**
 * VlcbNetDataLegacySetNodeVariable
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LEGACY_SET_NODE_VARIABLE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t nodeVariableIndex;
  uint8_t value;
} VlcbNetDataLegacySetNodeVariable;

/**
 * VlcbNetDataNodeVariableValue
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_VARIABLE_VALUE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t nodeVariableIndex;
  uint8_t value;
} VlcbNetDataNodeVariableValue;

/**
 * VlcbNetDataShortEventAccessoryOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_ON
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataShortEventAccessoryOn;

/**
 * VlcbNetDataShortEventAccessoryOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataShortEventAccessoryOff;

/**
 * VlcbNetDataQueryShortEventAccessoryState
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_SHORT_EVENT_ACCESSORY_STATE
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataQueryShortEventAccessoryState;

/**
 * VlcbNetDataNodeParameterValue
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_PARAMETER_VALUE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t parameterIndex;
  uint8_t value;
} VlcbNetDataNodeParameterValue;

/**
 * VlcbNetDataQueryEventVariable
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_EVENT_VARIABLE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t eventIndex;
  uint8_t value;
} VlcbNetDataQueryEventVariable;

/**
 * VlcbNetDataShortEventAccessoryStateOn
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataShortEventAccessoryStateOn;

/**
 * VlcbNetDataShortEventAccessoryStateOff
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF
 */
typedef struct {
  VlcbEvent event;
} VlcbNetDataShortEventAccessoryStateOff;

/**
 * VlcbNetDataExtOpcode3
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE3
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[3];
} VlcbNetDataExtOpcode3;

/**
 * VlcbNetDataDccSendRawPacket4
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_RAW_PACKET4
 */
typedef struct {
  uint8_t repeatTimes;
  uint8_t data[4];
} VlcbNetDataDccSendRawPacket4;

/**
 * VlcbNetDataDccWriteCvInServiceMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_WRITE_CV_IN_SERVICE_MODE
 */
typedef struct {
  VlcbDccSessionNr session;
  uint16_t CV;
  uint8_t mode; // TODO: this probably has some enum
  uint8_t value;
} VlcbNetDataDccWriteCvInServiceMode;

/**
 * VlcbNetDataHeartbeat
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_HEARTBEAT
 */
typedef struct {
  VlcbNodeNumber sourceNodeNumber;
  uint8_t sequenceNr;
  uint8_t status;
  // uint8_t statusBits; TODO: Reserved set to 0
} VlcbNetDataHeartbeat;

/**
 * VlcbNetDataServiceDiscoveryResponse
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SERVICE_DISCOVERY_RESPONSE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
  VlcbServiceType serviceType;
  uint8_t version;
} VlcbNetDataServiceDiscoveryResponse;

/**
 * VlcbNetDataGenericResponse
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_GENERIC_RESPONSE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbOpCode opcode;
  VlcbServiceType serviceType;
  uint8_t result;
} VlcbNetDataGenericResponse;

/**
 * VlcbNetDataLongEventAccessoryOn1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_ON1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetDataLongEventAccessoryOn1;

/**
 * VlcbNetDataLongEventAccessoryOff1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_OFF1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetDataLongEventAccessoryOff1;

/**
 * VlcbNetDataQueryEventVariableByIdex
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_QUERY_EVENT_VARIABLE_BY_IDEX
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventVariableIndex;
} VlcbNetDataQueryEventVariableByIdex;

/**
 * VlcbNetDataLongEventAccessoryStateOn1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetDataLongEventAccessoryStateOn1;

/**
 * VlcbNetDataLongEventAccessoryStateOff1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetDataLongEventAccessoryStateOff1;

/**
 * VlcbNetDataEventVariableValue
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_EVENT_VARIABLE_VALUE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t eventIndex;
  uint8_t eventVariableIndex;
  uint8_t eventVariableValue;
} VlcbNetDataEventVariableValue;

/**
 * VlcbNetDataModuleInfo
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_MODULE_INFO
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbManufacturer manufacturer;
  uint8_t moduleId;
  VlcbModuleFlags flags;
} VlcbNetDataModuleInfo;

/**
 * VlcbNetDataShortEventAccessoryOn1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_ON1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetDataShortEventAccessoryOn1;

/**
 * VlcbNetDataShortEventAccessoryOff1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetDataShortEventAccessoryOff1;

/**
 * VlcbNetDataShortEventAccessoryStateOn1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetDataShortEventAccessoryStateOn1;

/**
 * VlcbNetDataShortEventAccessoryStateOff1
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF1
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[1];
} VlcbNetDataShortEventAccessoryStateOff1;

/**
 * VlcbNetDataExtOpcode4
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE4
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[4];
} VlcbNetDataExtOpcode4;

/**
 * VlcbNetDataDccSendRawPacket5
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_RAW_PACKET5
 */
typedef struct {
  uint8_t repeatTimes;
  uint8_t data[5];
} VlcbNetDataDccSendRawPacket5;

/**
 * VlcbNetDataDccWriteCvByteInOpsModeByAddress
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_WRITE_CV_BYTE_IN_OPS_MODE_BY_ADDRESS
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
  uint16_t CV;
  uint16_t mode; // TODO: this probably has some enum
  uint8_t value;
} VlcbNetDataDccWriteCvByteInOpsModeByAddress;

/**
 * VlcbNetDataDccSendDataToCab
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_DATA_TO_CAB
 */
typedef struct {
  VlcbDccDecoderAddr decoderAddr;
  uint8_t dataCode;
  uint8_t data[3];
} VlcbNetDataDccSendDataToCab;

/**
 * VlcbNetDataDiagnosticData
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_DIAGNOSTIC_DATA
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
  uint8_t diagnosticCode;
  uint8_t diagnosticValue;
} VlcbNetDataDiagnosticData;

#define VLCB_TIME_DIVIDER_FREEZE 0
/**
 * VlcbNetDataFastClock
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_FAST_CLOCK
 */
typedef struct {
  uint8_t minutes;
  uint8_t hours;
  VlcbTimeWeekDay weekDay;
  uint8_t dayOfMonth;
  VlcbTimeMonth month; // TODO: custom serialization
  // 0 means freeze
  uint8_t dividerFactor;
  int8_t temperature;
} VlcbNetDataFastClock;

/**
 * VlcbNetDataLongEventAccessoryOn2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_ON2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetDataLongEventAccessoryOn2;

/**
 * VlcbNetDataLongEventAccessoryOff2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_OFF2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetDataLongEventAccessoryOff2;

/**
 * VlcbNetDataTeachEvent
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_TEACH_EVENT
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventVariableIndex;
  uint8_t eventVariableValue;
} VlcbNetDataTeachEvent;

/**
 * VlcbNetDataEventVariableValueInLearnMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_EVENT_VARIABLE_VALUE_IN_LEARN_MODE
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventVariableIndex;
  uint8_t eventVariableValue;
} VlcbNetDataEventVariableValueInLearnMode;

/**
 * VlcbNetDataLongEventAccessoryStateOn2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetDataLongEventAccessoryStateOn2;

/**
 * VlcbNetDataLongEventAccessoryStateOff2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetDataLongEventAccessoryStateOff2;

/**
 * VlcbNetDataShortEventAccessoryOn2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_ON2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetDataShortEventAccessoryOn2;

/**
 * VlcbNetDataShortEventAccessoryOff2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetDataShortEventAccessoryOff2;

/**
 * VlcbNetDataShortEventAccessoryStateOn2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetDataShortEventAccessoryStateOn2;

/**
 * VlcbNetDataShortEventAccessoryStateOff2
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF2
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventData[2];
} VlcbNetDataShortEventAccessoryStateOff2;

/**
 * VlcbNetDataExtOpcode5
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE5
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[5];
} VlcbNetDataExtOpcode5;

/**
 * VlcbNetDataDccSendRawPacket6
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DCC_SEND_RAW_PACKET6
 */
typedef struct {
  uint8_t repeatTimes;
  uint8_t data[6];
} VlcbNetDataDccSendRawPacket6;

/**
 * VlcbNetDataDccLocoReport
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
} VlcbNetDataDccLocoReport;

/**
 * VlcbNetDataModuleName
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_MODULE_NAME
 */
typedef struct {
  char moduleName[7];
} VlcbNetDataModuleName;

/**
 * VlcbNetDataDccCommandStationStatus
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
} VlcbNetDataDccCommandStationStatus;

/**
 * VlcbNetDataEventAck
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EVENT_ACK
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbOpCode acknowledgedOpcode;
  VlcbEvent event;
} VlcbNetDataEventAck;

/**
 * VlcbNetDataExtendedServiceDiscoveryResponse
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_EXTENDED_SERVICE_DISCOVERY_RESPONSE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t serviceIndex;
  VlcbServiceType serviceType;
  uint8_t serviceData[3]; // TODO: Union of structs?
} VlcbNetDataExtendedServiceDiscoveryResponse;

/**
 * VlcbNetDataStreamPacket
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
} VlcbNetDataStreamPacket;

/**
 * VlcbNetDataNodeParametersReport
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_PARAMETERS_REPORT
 */
typedef struct {
  uint8_t params[7];
} VlcbNetDataNodeParametersReport;

/**
 * VlcbNetDataLongEventAccessoryOn3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_ON3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetDataLongEventAccessoryOn3;

/**
 * VlcbNetDataLongEventAccessoryOff3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_OFF3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetDataLongEventAccessoryOff3;

/**
 * VlcbNetDataLearnedEventResponse
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LEARNED_EVENT_RESPONSE
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbEvent event;
  uint8_t eventIndex;
} VlcbNetDataLearnedEventResponse;

/**
 * VlcbNetDataLongEventAccessoryStateOn3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetDataLongEventAccessoryStateOn3;

/**
 * VlcbNetDataLongEventAccessoryStateOff3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetDataLongEventAccessoryStateOff3;

/**
 * VlcbNetDataTeachEventByIndex
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_TEACH_EVENT_BY_INDEX
 */
typedef struct {
  VlcbEvent event;
  uint8_t eventIndex;
  uint8_t eventVariableIndex;
  uint8_t eventVariableValue;
} VlcbNetDataTeachEventByIndex;

/**
 * VlcbNetDataDataEventAccessory
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DATA_EVENT_ACCESSORY
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t data[5];
} VlcbNetDataDataEventAccessory;

/**
 * VlcbNetDataNodeAccessoryData
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_NODE_ACCESSORY_DATA
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  uint8_t data[5];
} VlcbNetDataNodeAccessoryData;

/**
 * VlcbNetDataShortEventAccessoryOn3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_ON3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetDataShortEventAccessoryOn3;

/**
 * VlcbNetDataShortEventAccessoryOff3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetDataShortEventAccessoryOff3;

/**
 * VlcbNetDataDeviceDataEventShortMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DEVICE_DATA_EVENT_SHORT_MODE
 */
typedef struct {
  uint16_t devideNumber;
  uint8_t data[5];
} VlcbNetDataDeviceDataEventShortMode;

/**
 * VlcbNetDataDeviceDataShortMode
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_DEVICE_DATA_SHORT_MODE
 */
typedef struct {
  uint16_t devideNumber;
  uint8_t data[5];
} VlcbNetDataDeviceDataShortMode;

/**
 * VlcbNetDataWriteData
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_WRITE_DATA
 */
typedef struct {
  uint16_t devideNumber;
  uint8_t data[5];
} VlcbNetDataWriteData;

/**
 * VlcbNetDataShortEventAccessoryStateOn3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetDataShortEventAccessoryStateOn3;

/**
 * VlcbNetDataShortEventAccessoryStateOff3
 *
 * Message data structure for opcode @see VlcbOpCode
 * #VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF3
 */
typedef struct {
  VlcbEvent event;
  uint8_t data[3];
} VlcbNetDataShortEventAccessoryStateOff3;

/**
 * VlcbNetDataExtOpcode6
 *
 * Message data structure for opcode @see VlcbOpCode #VLCB_OPC_EXT_OPCODE6
 */
typedef struct {
  uint8_t opcodeExtension;
  uint8_t data[6];
} VlcbNetDataExtOpcode6;
