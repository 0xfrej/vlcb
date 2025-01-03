#pragma once

#include <stdint.h>

/**
 * @brief VLCB opcodes
 */
typedef uint8_t VlcbOpCode;
enum VlcbOpCode {
  /**
   * @brief General Acknowledgement.
   *
   * Positive response to query/request performed or report of availability
   * on-line.
   *
   * Short name: ACK
   */
  VLCB_OPC_GENERAL_ACK = 0,

  /**
   * @brief General No Ack.
   *
   * Negative response to query/request denied by the target.
   *
   * Short name: NAK
   */
  VLCB_OPC_GENERAL_NACK = 1,

  /**
   * @brief Bus Halt.
   *
   * Commonly broadcasted to all nodes to indicate CBUS is not available and
   * no further packets should be sent until a #VLCB_OPC_BUS_RESUME or
   * #VLCB_OPC_RESTART_ALL_NODES is received.
   *
   * Short name: HLT
   */
  VLCB_OPC_BUS_HALT = 2,

  /**
   * @brief Bus ON
   *
   * Commonly broadcasted to all nodes to indicate CBUS is available after a
   * #VLCB_OPC_BUS_HALT message was transmitted.
   *
   * Short name: BON
   */
  VLCB_OPC_BUS_RESUME = 3,

  /**
   * @brief DCC track off.
   *
   * Commonly broadcasted to all nodes by a command station to indicate track
   * power is off and no further command packets should be sent, except
   * inquiries.
   *
   * Short name: TOF
   */
  VLCB_OPC_DCC_TRACK_POWERED_OFF = 4,

  /**
   * @brief DCC track on.
   *
   * Commonly broadcasted to all nodes by a command station to indicate track
   * power is on.
   *
   * Short name: TON
   */
  VLCB_OPC_DCC_TRACK_POWERED_ON = 5,

  /**
   * @brief DCC emergency stop.
   *
   * Commonly broadcast to all nodes by a command station to indicate all
   * engines have been emergency stopped.
   *
   * Short name: ESTOP
   */
  VLCB_OPC_DCC_EMERGENCY_STOP_ENGAGED = 6,

  /**
   * @brief Perform reboot on all nodes.
   *
   * Commonly broadcasted to all nodes to indicate a full system restart.
   * Similar to #VLCB_OPC_RESTART_NODE which directs a single node to be
   * restarted.
   *
   * Short name: ARST
   */
  VLCB_OPC_RESTART_ALL_NODES = 7,

  /**
   * @brief DCC request track off.
   *
   * Sent to request change of track power state to “off”.
   *
   * Short name: RTOF
   */
  VLCB_OPC_DCC_TRACK_POWER_OFF = 8,

  /**
   * @brief DCC request track on.
   *
   * Sent to request change of track power state to “on”.
   *
   * Short name: RTON
   */
  VLCB_OPC_DCC_TRACK_POWER_ON = 9,

  /**
   * @brief DCC request emergency stop.
   *
   * Sent to request an emergency stop to all trains.
   * Does not affect accessory control.
   *
   * Short name: RESTP
   */
  VLCB_OPC_DCC_EMERGENCY_STOP = 10,

  /**
   * @brief Request Command Station Status.
   *
   * Sent to query the status of the command station. See description of
   * #VLCB_OPC_DCC_COMMAND_STATION_STATUS for the response from the command
   * station.
   *
   * Short name: RSTAT
   */
  VLCB_OPC_DCC_QUERY_COMMAND_STATION_STATUS = 12,

  /**
   * @brief Query node number.
   *
   * Requests a #VLCB_OPC_MODULE_INFO reply from each node on the bus.
   * Can be used by management software to obtain list of nodes on the
   * network
   *
   * Short name: QNN
   */
  VLCB_OPC_QUERY_MODULE_INFO = 13,

  /**
   * @brief Request node parameters.
   *
   * Sent to a node while in Setup mode to read its parameter set.
   * Used when initially configuring a node.
   *
   * Short name: RQNP
   */
  VLCB_OPC_QUERY_MODULE_PARAMETERS = 16,

  /**
   * @brief Request module name.
   *
   * Sent by a node to request the name of the type of module that is in setup
   * mode or Learn mode. The module in setup mode or learn mode will reply with
   * #VLCB_OPC_MODULE_NAME message.
   *
   * Note: if there are two modules one in setup mode and the other in learn
   * mode, both will respond to the query.
   *
   * Short name: RQMN
   */
  VLCB_OPC_QUERY_MODULE_NAME = 17,

  /**
   * @brief Release Engine.
   *
   * Sent by a CAB to the Command Station. The engine with that Session number
   * is removed from the active engine list.
   *
   * Short name: KLOC
   *
   * On session not found: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_RELEASE_SESSION = 33,

  /**
   * @brief query engine.
   *
   * used to determine if the command station session is valid and to obtain
   * information about the status of the locomotive.
   *
   * short name: qloc
   *
   * on `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_QUERY_LOCO_STATUS = 34,

  /**
   * @brief Session keep alive.
   *
   * The cab sends a keep alive at regular intervals for the active session.
   * The interval between keep alive messages must be less than the session
   * timeout implemented by the command station.
   *
   * Sort name: DKEEP
   */
  VLCB_OPC_DCC_SESSION_KEEP_ALIVE = 35,

  /**
   * @brief Debug message with one data byte.
   *
   * Freeform status byte for debugging during CBUS module development. Not used
   * during normal operation.
   *
   * Short name: DBG1
   */
  VLCB_OPC_DEBUG_MSG1 = 48,

  /**
   * @brief Extended opcode with zero additional bytes.
   *
   * Reserved to allow the 0 additional bytes range to be extended by a further
   * 256 opcodes.
   *
   * Short name: EXTC
   */
  VLCB_OPC_EXT_OPCODE0 = 63,

  /**
   * @brief Request engine session.
   *
   * This command is typically sent by a cab to the command station following a
   * change of the controlled decoder address. Thsi is exactly equivalent to
   * #VLCB_OPC_DCC_QUERY_LOCO_SESSION with all flag bits set to zero.
   *
   * Short name: RLOC
   *
   * On `success`: target responds with #VLCB_OPC_DCC_LOCO_REPORT
   * On `decoder address being already assigned`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * On `no available session slots`: target responds with
   * #VLCB_DCC_ERR_LOCO_ADDRESS_IS_TAKEN code #VLCB_DCC_ERR_LOCO_STACK_IS_FULL
   */
  VLCB_OPC_DCC_REQUEST_NEW_SESSION = 64,

  /**
   * @brief Query Consist.
   *
   * Allows enumeration of a consist. Command station responds with
   * #VLCB_OPC_DCC_LOCO_REPORT if an engine exists at the specified index,
   * otherwise responds with #VLCB_OPC_DCC_COMMAND_STATION_ERROR and code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   *
   * Short name: QCON
   *
   * On `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_QUERY_CONSIST = 65,

  /**
   * @brief Set Node Number.
   *
   * Sent by a configuration tool to assign a node number to a requesting node
   * in response to a #VLCB_OPC_REQUEST_NEW_NODE_NUMBER message. The target node
   * must be in `setup` mode.
   *
   * Short name: SNN
   *
   * On `success`: target responds with #VLCB_OPC_NODE_NUMBER_ACK
   */
  VLCB_OPC_SET_NODE_NUMBER = 66,

  /**
   * @brief Allocate loco to activity.
   *
   * Short name: ALOC
   *
   * On `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_ALLOCATE_LOCO_TO_ACTIVITY = 67,

  /**
   * @brief Set CAB session mode.
   *
   * Short name: STMOD
   *
   * On `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_SET_THROTTLE_MODE = 68,

  /**
   * @brief Consist Engine.
   *
   * Adds a decoder specified by Session to a consist.
   * If a consist with that ID does not exist yet, new consist will be
   * created with the specified ID.
   *
   * Short name: PCON
   *
   * On `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_CONSIST_ADD_LOCO = 69,

  /**
   * @brief Removes a loco from a consist.
   *
   * Short name: KCON
   *
   * On `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_CONSIST_REMOVE_LOCO = 70,

  /**
   * @brief Set Engine Speed/Dir.
   *
   * Sent by a CAB or equivalent to request an engine speed/direction change.
   *
   * Short name: DSPD
   *
   * On `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_SET_LOCO_THROTTLE = 71,

  /**
   * @brief Set Engine Flags.
   *
   * Sent by a cab to notify the command station of a change in engine flags.
   *
   * Short name: DFLG
   *
   * On `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_SET_LOCO_FLAGS = 72,

  /**
   * @brief Set Engine function on.
   *
   * Sent by a cab to turn on a specific loco function.
   * This provides an alternative method to #VLCB_OPC_DCC_SET_LOCO_FUNCTIONS for
   * controlling loco functions.
   *
   * Short name: DFNON
   *
   * On `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_LOCO_FUNCTION_ON = 73,

  /**
   * @brief Set Engine function off.
   *
   * Sent by a cab to turn off a specific loco function.
   * This provides an alternative method to #VLCB_OPC_DCC_SET_LOCO_FUNCTIONS for
   * controlling loco functions.
   *
   * Short name: DFNOF
   *
   * On `session not found`: target responds with
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_LOCO_FUNCTION_OFF = 74,

  /**
   * @brief Service mode status.
   *
   * Status returned by command station/programmer at the end of a programming
   * operation that does not return data.
   *
   * Response to #VLCB_OPC_DCC_READ_CV to indicate no data.
   *
   * Short name: SSTAT
   */
  VLCB_OPC_DCC_SERVICE_MODE_STATUS = 76,

  /**
   * @brief Reset to manufacturer settings.
   *
   * Reset a module back e to manufacturer settings.
   *
   * Short name: NNRSM
   *
   * On `success`: target responds with #VLCB_OPC_GENERIC_RESPONSE code
   * #VLCB_GENERIC_RESPONSE_STAT_OK
   */
  VLCB_OPC_RESET_MODULE_TO_FACTORY = 79,

  /**
   * @brief Request node number.
   *
   * The module is requesting that it is provided with a new node number.
   * A configuration tool should respond with #VLCB_OPC_SET_NODE_NUMBER to
   * provide the requesting node a new number.
   *
   * If the module won't receive a #VLCB_OPC_SET_NODE_NUMBER within 30 seconds,
   * it returns to previous state and reclaims it old node number with
   * #VLCB_OPC_NODE_NUMBER_ACK
   *
   * Short name: RQNN
   */
  VLCB_OPC_REQUEST_NEW_NODE_NUMBER = 80,

  /**
   * @brief Node number release.
   *
   * A node signals that it no longer requires it's node number.
   *
   * The module will do this upon moving from normal mode to setup mode.
   *
   * Short name: NNREL
   */
  VLCB_OPC_NODE_NUMBER_RELEASED = 81,

  /**
   * @brief Node number acknowledge.
   *
   * This message is sent in response to #VLCB_OPC_SET_NODE_NUMBER.
   * A node signals that it will now use the provided node number.
   *
   * Short name: NNACK
   */
  VLCB_OPC_NODE_NUMBER_ACK = 82,

  /**
   * @brief Set node into learn mode.
   *
   * Sent by a configuration tool to put a specific node into learn mode.
   *
   * Short name: NNLRN
   *
   * @deprecated replaced by #VLCB_OPC_CHANGE_MODULE_MODE
   *
   * @warning When feature `EXPERIMENTAL_CBUS_DEPRECATION_DROP` is enabled, this
   * will not be available
   */
  VLCB_OPC_PUT_NODE_INTO_LEARN_MODE = 83,

  /**
   * @brief Release node from learn mode.
   *
   * Sent by a configuration tool to take the module out of learn mode and
   * revert to normal operation.
   *
   * Short name: NNULN
   *
   * @deprecated replaced by #VLCB_OPC_CHANGE_MODULE_MODE
   *
   * @warning When feature `EXPERIMENTAL_CBUS_DEPRECATION_DROP` is enabled, this
   * will not be available
   */
  VLCB_OPC_RELEASE_NODE_FROM_LEARN_MODE = 84,

  /**
   * @brief Clear all events from a node.
   *
   * Sent by a configuration tool to clear all events from a specific node.
   * Must be in learn mode first to safeguard against accidental erasure of all
   * events
   *
   * Short name: NNCLR
   *
   * On `success`: tearget responds with #VLCB_OPC_WRITE_ACK
   * On `module not in learn mode`: target responds with #VLCB_OPC_COMMAND_ERROR
   * code #VLCB_CMDERR_NOT_IN_LEARN_MODE and #VLCB_OPC_GENERIC_RESPONSE code
   * #VLCB_GENERIC_RESPONSE_NOT_IN_LEARN_MODE
   * @warning When feature `EXPERIMENTAL_CBUS_DEPRECATION_DROP` is enabled,
   * modules implemented by this SDK will respond only with
   * #VLCB_OPC_GENERIC_RESPONSE
   */
  VLCB_OPC_FORGET_ALL_LEARNED_EVENTS = 85,

  /**
   * @brief Read the number of event slots available in a node.
   *
   * Sent by a configuration tool to read the number of available event slots in
   * a node.
   *
   * Short name: NNEVN
   *
   * On `success`: target responds with #VLCB_OPC_AVAILABLE_EVENT_SLOTS
   */
  VLCB_OPC_QUERY_AVAILABLE_EVENT_SLOTS = 86,

  /**
   * @brief Read back all stored events in a node.
   *
   * There must be no hidden events.
   * Sent by a configuration tool to read all the stored events in a node.
   *
   * Short name: NERD
   *
   * On `success`: target responds with #VLCB_OPC_LEARNED_EVENT_RESPONSE
   */
  VLCB_OPC_QUERY_ALL_LEARNED_EVENTS = 87,

  /**
   * @brief Request to read number of stored events.
   *
   * Sent by a configuration tool to read the number of stored events in a node.
   *
   * Short name RQEVN
   *
   * On `success`: target responds with #VLCB_OPC_LEARNED_EVENT_COUNT
   */
  VLCB_OPC_QUERY_LEARNED_EVENT_COUNT = 88,

  /**
   * @brief Write acknowledge.
   *
   * Sent by a node to indicate the completion of a write to memory operation.
   * All nodes must issue #VLCB_OPC_WRITE_ACK when a write operation to node
   * variables, events or event variables has completed. This allows for
   * teaching nodes where the processing time may be slow.
   *
   * Short name: WRACK
   *
   * @deprecated replaced by #VLCB_OPC_GENERIC_RESPONSE
   * @@warning When feature `EXPERIMENTAL_CBUS_DEPRECATION_DROP` is enabled,
   * this will not be available
   */
  VLCB_OPC_WRITE_ACK = 89,

  /**
   * @brief Request node data event.
   *
   * Sent by one node to read the data event from another node.(eg: RFID data).
   *
   * Short name: RQDAT
   *
   * On `success`: target responds with #VLCB_OPC_NODE_ACCESSORY_DATA
   */
  VLCB_OPC_QUERY_NODE_ACCESSORY_DATA = 90,

  /**
   * @brief Request device data (short mode).
   *
   * To request a ‘data set’ from a device using the short event method where DN
   * is the device number.
   *
   * On `success`: target responds with #VLCB_OPC_DEVICE_DATA_SHORT_MODE
   */
  VLCB_OPC_QUERY_DEVICE_DATA_SHORT_MODE = 91,

  /**
   * @brief Put node into bootloading mode.
   *
   * For modules with no node number, the value shall be 0. For nodes
   * in Normal mode the command must contain current node number of the target.
   * Sent by a configuration tool to prepare for loading a new program.
   *
   * Short name: BOOTM
   *
   * @deprecated replaced by #VLCB_OPC_CHANGE_MODULE_MODE
   * @warning When feature `EXPERIMENTAL_CBUS_DEPRECATION_DROP` is enabled, this
   * will not be available
   */
  VLCB_OPC_REBOOT_INTO_BOOTLOADER = 92,

  /**
   * @brief Force a self enumeration cycle for use with CAN.
   *
   * For nodes in Normal mode using CAN as a transport.
   * This message will force a self-enumeration cycle for the specified node.
   * A new CAN ID will be allocated if needed.
   *
   * Short name: ENUM
   *
   * On `success`: target responds with #VLCB_OPC_NODE_NUMBER_ACK
   * On `enumeration failure`: target responds with #VLCB_OPC_COMMAND_ERROR code
   * #VLCB_CMDERR_INVALID_EVENT
   *
   * @deprecated Replaced by automatic enumeration implementation with duplicate
   * CAN ID detection.
   * @warning Modules implemented using this SDK will ignore this command,
   * unless user handles it themselves.
   */
  VLCB_OPC_FORCE_CAN_ENUMERATION = 93,

  /**
   * @brief Reset module’s CPU.
   *
   * Reset a module’s microprocessor.
   *
   * Short name: NNRST
   */
  VLCB_OPC_RESTART_NODE = 94,

  /**
   * @brief Extended opcode with 1 additional byte.
   *
   * Reserved to allow the 1 additional bytes range to be extended by a further
   * 256 opcodes.
   *
   * Short name: EXTC1
   */
  VLCB_OPC_EXT_OPCODE1 = 95,

  /**
   * @brief Set Engine functions.
   *
   * Short name: DFUN
   *
   * On `session not found`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_SET_LOCO_FUNCTIONS = 96,

  /**
   * @brief Get engine session.
   *
   * Short name: GLOC
   *
   * On `success`: target responds with #VLCB_OPC_DCC_LOCO_REPORT
   * On `loco address taken and mode is not steal/share`: target responds with
   * #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_LOCO_ADDRESS_IS_TAKEN On `no available session slots`: target
   * responds with #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_LOCO_STACK_IS_FULL On `session for loco not found`: target
   * responds with #VLCB_OPC_DCC_COMMAND_STATION_ERROR code
   * #VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT
   */
  VLCB_OPC_DCC_QUERY_LOCO_SESSION = 97,

  /**
   * @brief Command Station Error report.
   *
   * Sent in response to an error situation by a command station.
   *
   * @see VlcbDccError for possible error code values
   *
   * Short name: ERR
   */
  VLCB_OPC_DCC_COMMAND_STATION_ERROR = 99,

  /**
   * @brief Error messages from nodes during configuration.
   *
   * Sent by node if there is an error when a configuration command is sent.
   *
   * @see VlcbCommandError for possible error code values
   *
   * Short name: CMDERR
   *
   * @deprecated replaced by #VLCB_OPC_GENERIC_RESPONSE
   * @warning  feature `EXPERIMENTAL_CBUS_DEPRECATION_DROP` is enabled, this
   * will not be available
   */
  VLCB_OPC_COMMAND_ERROR = 111,

  /**
   * @brief Event space left reply from node.
   *
   * Spaces is a one byte value giving the number of available event spaces left
   * in the node’s event table. This is the maximum number of additional events
   * that can be stored by the module.
   *
   * Sent as a response to #VLCB_OPC_QUERY_AVAILABLE_EVENT_SLOTS
   *
   * Short name: EVNLF
   */
  VLCB_OPC_AVAILABLE_EVENT_SLOTS = 112,

  /**
   * @brief Request read of a node variable.
   *
   * NV# is the index for the node variable value requested.
   *
   * If NV# is of value 0, then the target will respond with
   * #VLCB_OPC_NODE_VARIABLE_VALUE for each of it's stored node variable.
   *
   * Short name: NVRD
   *
   * On `success`: target responds with one or seies of
   * #VLCB_OPC_NODE_VARIABLE_VALUE messages, depending on the NV# requested On
   * `NV# requested is larger than supported mount of node variables`: target
   * responds with #VLCB_OPC_COMMAND_ERROR code #VLCB_CMDERR_INVALID_NV_INDEX
   * and #VLCB_OPC_GENERIC_RESPONSE code #VLCB_GENERIC_RESPONSE_INVALID_NV_INDEX
   */
  VLCB_OPC_QUERY_NODE_VARIABLE = 113,

  /**
   * @brief Request read of stored event by event index.
   *
   * EN# is the index for the stored event requested.
   *
   * Short name: NENRD
   *
   * On `success`: target responds with #VLCB_OPC_LEARNED_EVENT_RESPONSE
   * On `invalid EN# index`: target responds with #VLCB_OPC_COMMAND_ERROR code
   * #VLCB_CMDERR_INVALID_EVENT_INDEX
   */
  VLCB_OPC_QUERY_LEARNED_EVENT_BY_INDEX = 114,

  /**
   * @brief Request read of a node parameter by index.
   *
   * Para# is the index for the parameter requested.
   * If request contains Para# of value 0, target returns a response with number
   * of node parameters available
   *
   * Short name: RQNPN
   *
   * on `success`: target responds with #VLCB_OPC_NODE_PARAMETER_VALUE. For
   * requests with Para# of value 0, target shall respond with
   * #VLCB_OPC_NODE_PARAMETER_VALUE containing the lenght of available
   * parameters and a series of #VLCB_OPC_NODE_PARAMETER_VALUE messages, each
   * containing one of the parameters (starting from parameter 1 up to the
   * limit)
   */
  VLCB_OPC_QUERY_NODE_PARAMETER_BY_INDEX = 115,

  /**
   * @brief Number of events stored by node.
   *
   * Response to #VLCB_OPC_QUERY_LEARNED_EVENT_COUNT
   *
   * Short name: NUMEV
   */
  VLCB_OPC_LEARNED_EVENT_COUNT = 116,

  /**
   * @brief Forcefully set the node's CAN ID.
   *
   * Used to force a specified CAN ID for a node. Value range is from 1 to 0x63
   * (99 decimal). This OPC must be used with care as duplicate CAN IDs are not
   * allowed.
   *
   * Short name: CANID
   *
   * @deprecated Replaced with self-enumeration
   * @warning Modules implemented by this SDK will ignore the command, unless it
   * is handled by the user
   */
  VLCB_OPC_SET_NODE_CAN_ID = 117,

  /**
   * @brief Request a change to module’s operating mode.
   *
   * Request to change the operational mode of the module.
   */
  VLCB_OPC_CHANGE_MODULE_MODE = 118,

  /**
   * Request service discovery.
   *
   * Request service data from a module.
   * If the ServiceIndex is zero then the module responds with a SD
   */
  VLCB_OPC_QUERY_SERVICE_DISCOVERY = 120,

  /**
   * Extended opcode with 2 additional bytes.
   *
   * Reserved to allow the 2 additional bytes range to be extended by a
   * further 256 opcodes.
   */
  VLCB_OPC_EXT_OPCODE2 = 127,

  /**
   * Request 3-byte DCC Packet.
   *
   * Allows a CAB or equivalent to request a 3 byte DCC packet to be sent to the
   * track. The packet is sent <REP> times and is not refreshed on a regular
   * basis. Note: a 3 byte DCC packet is the minimum allowed.
   */
  VLCB_OPC_DCC_SEND_RAW_PACKET3 = 128,

  /**
   * Write CV (byte) in OPS mode.
   *
   * Sent to the command station to write a DCC CV byte in OPS mode to a
   * specific loco (on the main).
   */
  VLCB_OPC_DCC_WRITE_CV_BYTE_IN_OPS_MODE = 130,

  /**
   * Write CV (bit) in OPS mode.
   * Sent to the command station to write a DCC CV in OPS mode to specific loco
   * (on the main). The format for Value is that specified in RP 9.2.1 for OTM
   * bit manipulation in a DCC packet. This is ‘111CDBBB’ where C here is always
   * 1 as only ‘writes’ are possible OTM (unless some loco ACK scheme like
   * RailCom is used). D is the bit value, either 0 or 1 and BBB is the bit
   * position in the CV byte. 000 to 111 for bits 0 to 7.
   */
  VLCB_OPC_DC_WRITE_CV_BIT_IN_OPS_MODE = 131,

  /**
   * Read CV.
   * This command is used exclusively with service mode.
   * Sent by the cab to the command station in order to read a CV value.
   */
  VLCB_OPC_DCC_READ_CV = 132,

  /**
   * Report CV.
   *
   * This command is used exclusively with service mode.
   * Sent by the command station to report a read CV in response to QCVS.
   */
  VLCB_OPC_DCC_CV_VALUE = 133,

  /**
   * Request diagnostic data.
   *
   * Request diagnostic data from a module.
   * If the requested diagnostic data is zero then a response for all diagnostic
   * data is returned.
   */
  VLCB_OPC_QUERY_DIAGNOSTIC_DATA = 135,

  /**
   * Set a NV value with read back.
   * Sets a NV value and additionally responds with the new value.nvset
   * The new value may not be the value which was requested to be written.
   */
  VLCB_OPC_SET_NODE_VARIABLE = 142,

  /**
   * Accessory ON long event.
   *
   * Indicates an ‘ON’ event using the full event number of 4 bytes (long
   * event). An event is sent by a module when it detects a change of state.
   * Modules may consume the event and perform actions.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_ON = 144,

  /**
   * Accessory OFF long event.
   *
   * Indicates an ‘OFF’ event using the full event number of 4 bytes (long
   * event). An event is sent by a module when it detects a change of state.
   * Modules may consume the event and perform actions.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_OFF = 145,

  /**
   * Accessory Request Event.
   *
   * Indicates a ‘request’ event using the full event number of 4 bytes (long
   * event). A request event is used to elicit a status response from a producer
   * when it is required to know the ‘state’ of the producer without producing
   * an ON or OFF event.
   */
  VLCB_OPC_QUERY_LONG_EVENT_ACCESSORY_STATE = 146,

  /**
   * Accessory Response Event.
   *
   * Indicates an ‘ON’ response. A response is a reply to a status request
   * (AREQ) without producing an ON or OFF event.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON = 147,

  /**
   * Accessory Response Event (AROF).
   *
   * Indicates an ‘OFF’ response. A response is a reply to a status request
   * (AREQ) without producing an ON or OFF event.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF = 148,

  /**
   * Unlearn an event in learn mode.
   *
   * Sent by a configuration tool to remove an event from a node.
   */
  VLCB_OPC_FORGET_LEARNED_EVENT = 149,

  /**
   * Set a node variable.
   *
   * Sent by a configuration tool to set a node variable. NV# is the NV index
   * number.
   */
  VLCB_OPC_LEGACY_SET_NODE_VARIABLE = 150,

  /**
   * Response to a request for a node variable value.
   *
   * Sent by node in response to request NVRD or NVSETRD.
   */
  VLCB_OPC_NODE_VARIABLE_VALUE = 151,

  /**
   * Accessory Short ON.
   *
   * Indicates an ‘ON’ event using the short event number of 2 LS bytes. An
   * event is sent by a module when it detects a change of state. Modules may
   * consume the event and perform actions. The NN is not used to match events,
   * the NN normally indicates the source of the event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_ON = 152,

  /**
   * Accessory Short OFF.
   *
   * Indicates an ‘OFF’ event using the short event number of 2 LS bytes. An
   * event is sent by a module when it detects a change of state. Modules may
   * consume the event and perform actions. The NN is not used to match events,
   * the NN normally indicates the source of the event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF = 153,

  /**
   * Accessory Short Request Event.
   *
   * Indicates a ‘request’ event using the short event number of 2 LS bytes. A
   * request event is used to elicit a status response from a producer when it
   * is required to know the ‘state’ of the producer without producing an ON or
   * OFF event.
   */
  VLCB_OPC_QUERY_SHORT_EVENT_ACCESSORY_STATE = 154,

  /**
   * Response to request for individual node parameter RQNPN.
   *
   * NN is the node number of the sending node. Para# is the index of the
   * parameter and Para val is the parameter value. Returns a parameter value.
   * Parameter index is the parameter number and matches that in the RQNPN
   * request.
   */
  VLCB_OPC_NODE_PARAMETER_VALUE = 155,

  /**
   * Request for read of an event variable.
   *
   * This request differs from B2 (REQEV) as it doesn’t need to be in learn
   */
  VLCB_OPC_QUERY_EVENT_VARIABLE = 156,

  /**
   * Accessory Short Response Event.
   *
   * Indicates an ‘ON’ response. A response is a reply to a status request
   * (ASRQ) without producing an ON or OFF event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON = 157,

  /**
   * Accessory Short Response Event.
   *
   * Indicates an ‘OFF’ response. A response is a reply to a status request
   * (ASRQ) without producing an ON or OFF event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF = 158,

  /**
   * Extended opcode with 3 additional bytes.
   * Reserved to allow the 3 additional bytes range to be extended by a further
   * 256 opcodes.
   */
  VLCB_OPC_EXT_OPCODE3 = 159,

  /**
   * Request 4-byte DCC Packet.
   * Allows a CAB or equivalent to request a 4 byte DCC packet to be sent to the
   * track. The packet is sent <REP> times and is not refreshed on a regular
   * basis.
   */
  VLCB_OPC_DCC_SEND_RAW_PACKET4 = 160,

  /**
   * Write CV in Service mode.
   * Sent to the command station to write a DCC CV in service mode.
   */
  VLCB_OPC_DCC_WRITE_CV_IN_SERVICE_MODE = 162,

  /**
   * Heartbeat from module.
   *
   * Heartbeat message from module indicating that the module is alive and
   * communicating on the bus. Sent every 5 seconds by a module to confirm it is
   * alive and connected to the network along with an indication of module
   * status. Sequence is a count from 0 incrementing on each message transmitted
   * and wrapping around to zero, It facilitates detection of missing frames.
   * Status: This is a binary representation of the module’s diagnostic status
   * as outlined in MNS Specification Section 8.3. 0x00 Shall always represent
   * “normal“ operation. StatusBits: Reserved for future expansion, set to 0x00
   */
  VLCB_OPC_HEARTBEAT = 171,

  /**
   * Service discovery response.
   *
   * The version of a service supported by a module.
   * Sent in response to RQSD with ServiceIndex = 0. A number of SD
   */
  VLCB_OPC_SERVICE_DISCOVERY_RESPONSE = 172,

  /**
   * Generic Response.
   *
   * Generic response for a configuration change request. Result byte indicates
   * ok for success or an error code in case of failure. Indicates the module is
   * ready for further configuration. The CMDERR codes are supported and in
   * addition service specific
   */
  VLCB_OPC_GENERIC_RESPONSE = 175,

  /**
   * Accessory ON.
   *
   * Indicates an ‘ON’ event using the full event number of 4 bytes with one
   * additional data byte. An event is sent by a module when it detects a change
   * of state. Modules may consume the event and perform actions. The meaning of
   * the additional data is dependent upon the application and must be agreed
   * between the producer and consumer of the event.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_ON1 = 176,

  /**
   * Accessory OFF.
   *
   * Indicates an ‘OFF’ event using the full event number of 4 bytes with one
   * additional databyte. An event is sent by a module when it detects a change
   * of state. Modules may consume the event and perform actions. The meaning of
   * the additional data is dependent upon the application and must be agreed
   * between the producer and consumer of the event.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_OFF1 = 177,

  /**
   * Read event variable in learn mode.
   *
   * Allows a configuration tool to read stored event variables from a node. EV#
   * is the EV variable index. NN and EN identify the event and not the module.
   * Reading EV#0 shall first return the number of EVs followed by a series of
   * EVANS with the value for each EV.
   */
  VLCB_OPC_QUERY_EVENT_VARIABLE_BY_IDEX = 178,

  /**
   * Accessory Response Event.
   *
   * Indicates an ‘ON’ response with one additional data byte. A response is a
   * reply to a status request (AREQ) without producing an ON or OFF
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON1 = 179,

  /**
   * Accessory Response Event.
   * Indicates an ‘OFF’ response with one additional data byte. A response is a
   * reply to a status request (AREQ) without producing an ON or OFF
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF1 = 180,

  /**
   * Response to request for read of EV value.
   *
   * This is the response to the request to read an EV - REVAL.
   */
  VLCB_OPC_EVENT_VARIABLE_VALUE = 181,

  /**
   * Response to Query Node - QNN.
   *
   * Sent in response to a QNN request.
   */
  VLCB_OPC_MODULE_INFO = 182,

  /**
   * Accessory Short ON.
   *
   * Indicates an ‘ON’ event using the short event number of 2 LS bytes with one
   * added data byte. An event is sent by a module when it detects a change of
   * state. Modules may consume the event and perform actions. The NN is not
   * used to match events, the NN normally indicates the source of the event.
   * The meaning of the additional data is dependent upon the application and
   * must be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_ON1 = 184,

  /**
   * Accessory Short OFF.
   *
   * Indicates an ‘OFF’ event using the short event number of 2 LS bytes with
   * one added data byte. An event is sent by a module when it detects a change
   * of state. Modules may consume the event and perform actions. The NN is not
   * used to match events, the NN normally indicates the source of the event.
   * The meaning of the additional data is dependent upon the application and
   * must be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF1 = 185,

  /**
   * Accessory Short Response Event.
   * Indicates an ‘ON’ response with one added data byte. A response is a reply
   * to a status request (ASRQ)without producing an ON or OFF
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON1 = 189,

  /**
   * Accessory Short Response Event with one data byte.
   * Indicates an ‘OFF’ response with one added data byte. A response is a reply
   * to a status request (ASRQ) without producing an ON or OFF event. A response
   * event is a reply to a status request (ASRQ)without
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF1 = 190,

  /**
   * Extended opcode with 4 additional bytes.
   * Reserved to allow the 4 additional bytes range to be extended by a further
   * 256 opcodes.
   */
  VLCB_OPC_EXT_OPCODE4 = 191,

  /**
   * Request 5-byte DCC Packet.
   * Allows a CAB or equivalent to request a 5 byte DCC packet to be sent to the
   * track. The packet is sent <REP> times and is not refreshed on a regular
   * basis.
   */
  VLCB_OPC_DCC_SEND_RAW_PACKET5 = 192,

  /**
   * Write CV (byte) in OPS mode by address.
   *
   * Sent to the command station to write a DCC CV byte in OPS mode to specific
   * loco (on the main). Used by computer based ops mode programmer that does
   * not have a valid throttle handle.
   */
  VLCB_OPC_DCC_WRITE_CV_BYTE_IN_OPS_MODE_BY_ADDRESS = 193,

  /**
   * Send data to the DCC CAB which is controlling a particular loco.
   *
   * addrH and addrL are the loco address in the same format as RLOC and GLOC 7
   * bit addresses have (addrH=0). 14 bit addresses have bits 6,7 of addrH set
   * to 1. dataCode defines the meaning of the remaining 3 bytes. The following
   * values for dataCod have currently been defined: ● 01 - CABSIG - Transmitted
   * by a layout control system to send signal aspects to be displayed on a cab
   * handset as cab signalling. Parameter data1 is used for aspect1 Parameter
   * data2 is used for aspect2 Parameter data3 is used for speed aspect1 is
   * signalling system independent, and is defined as follows (colours in
   * brackets correspond to UK colour light signalling, the given aspect names
   * may be displayed differently in other signalling systems): Bits 0-1 - 2 bit
   * aspect code 00=danger (red), 01=caution (yellow), 10=preliminary caution
   * (double yellow), 11=proceed (green) Bit 2 - set 1 for calling on or shunt
   * aspect (bits 0-1 would be set to 00 for danger when calling on) Bit 3 - Set
   * 0 to indicate upper nibble is feather location, set 1 for upper nibble is
   * theatre type route indicator Bits 4-7 - 0 - no route indicated, 1 to 6 =
   * feather position or 1 to 16 for theatre route indication aspect1 should be
   * set to 0xFF if no signal information is available. This can be used, for
   * example, to indicate leaving a cab signalling area. A cab should extinguish
   * any currently showing aspect on receipt of this code. Note that because
   * bits 0 and 1 should be set to zero when bit 2 is set, the code 0xFF is not
   * otherwise a valid aspect. <aspect2> may be used as required for specific
   * signalling systems. The meaning will vary for each signalling system. For
   * the UK 2003 rulebook, bit 0 set indicates a flashing aspect, applicable to
   * caution, preliminary caution or proceed. For UK semaphore signalling, where
   * there are multiple arms for
   */
  VLCB_OPC_DCC_SEND_DATA_TO_CAB = 194,

  /**
   * Diagnostic data response.
   *
   * Diagnostic data value from a module. Sent in response to RDGN.
   */
  VLCB_OPC_DIAGNOSTIC_DATA = 199,

  /**
   * Fast Clock.
   *
   * Used to implement a fast clock for the layout.
   */
  VLCB_OPC_FAST_CLOCK = 207,

  /**
   * Accessory ON.
   *
   * Indicates an ‘ON’ event using the full event number of 4 bytes with two
   * additional data bytes. An event is sent by a module when it detects a
   * change of state. Modules may consume the event and perform actions. The
   * meaning of the additional data is dependent upon the application and must
   * be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_ON2 = 208,

  /**
   * Accessory OFF.
   *
   * Indicates an ‘OFF’ event using the full event number of 4 bytes with two
   * additional data bytes. An event is sent by a module when it detects a
   * change of state. Modules may consume the event and perform actions. The
   * meaning of the additional data is dependent upon the application and must
   * be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_OFF2 = 209,

  /**
   * Teach an event in learn mode.
   *
   * Sent by a configuration tool to a node in learn mode to teach it an event
   * variable. Also teaches it the associated event. This command is repeated
   * for each EV required.
   */
  VLCB_OPC_TEACH_EVENT = 210,

  /**
   * Response to a request for an EV value in a node in learn mode.
   *
   * A node response to a request from a configuration tool for the EVs
   * associated with an event (REQEV). For multiple EVs, there will be one
   */
  VLCB_OPC_EVENT_VARIABLE_VALUE_IN_LEARN_MODE = 211,

  /**
   * Accessory Response Event.
   *
   * Indicates an ‘ON’ response event with two added data bytes. A response is a
   * reply to a status request (AREQ) without producing an
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON2 = 212,

  /**
   * Accessory Response Event.
   *
   * Indicates an ‘OFF’ response event with two added data bytes. A response is
   * a reply to a status request (AREQ) without producing an
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF2 = 213,

  /**
   * Accessory Short ON.
   * Indicates an ‘ON’ event using the short event number of 2 LS bytes with two
   * added data bytes. An event is sent by a module when it detects a change of
   * state. Modules may consume the event and perform actions. The NN is not
   * used to match events, the NN normally indicates the source of the event.
   * The meaning of the additional data is dependent upon the application and
   * must be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_ON2 = 216,

  /**
   * Accessory Short OFF.
   * Indicates an ‘OFF’ event using the short event number of 2 LS bytes with
   * two added data bytes. An event is sent by a module when it detects a change
   * of state. Modules may consume the event and perform actions. The NN is not
   * used to match events, the NN normally indicates the source of the event.
   * The meaning of the additional data is dependent upon the application and
   * must be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF2 = 217,

  /**
   * Accessory Short Response Event ON with two data bytes.
   *
   * Indicates an ‘ON’ response event with two added data bytes. A response is a
   * reply to a status request (ASRQ)without producing an ON
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON2 = 221,

  /**
   * Accessory Short Response Event OFF with two data bytes.
   *
   * Indicates an ‘OFF’ response event with two added data bytes. A response is
   * a reply to a status request (ASRQ) without producing an
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF2 = 222,

  /**
   * Extended opcode with 5 additional bytes.
   *
   * Reserved to allow the 5 additional bytes range to be extended by a further
   * 256 opcodes.
   */
  VLCB_OPC_EXT_OPCODE5 = 223,

  /**
   * Request 6-byte DCC Packet.
   *
   * Allows a CAB or equivalent to request a 6 byte DCC packet to be sent to the
   * track. The packet is sent <REP> times and is not refreshed on a regular
   * basis.
   */
  VLCB_OPC_DCC_SEND_RAW_PACKET6 = 224,

  /**
   * Engine report.
   *
   * A report of an engine entry sent by the command station. Sent in response
   * to QLOC or as an acknowledgement of acquiring an engine
   */
  VLCB_OPC_DCC_LOCO_REPORT = 225,

  /**
   * Response to request for node name string.
   *
   * Returns the type name for the module in response to RQMN. Any
   */
  VLCB_OPC_MODULE_NAME = 226,

  /**
   * Command Station status report.
   *
   * Sent by the command station in response to RSTAT.
   */
  VLCB_OPC_DCC_COMMAND_STATION_STATUS = 227,

  /**
   * Event Acknowledge.
   *
   * Sent by a module to acknowledge the consumption of an event. Used for
   * diagnostic purposes.
   */
  VLCB_OPC_EVENT_ACK = 230,

  /**
   * Extended service discovery response.
   *
   * Detailed information about a service supported by a module. The data
   * supplied is service specific. Sent in response to RQSD with ServiceIndex is
   * not zero. A single ESD
   */
  VLCB_OPC_EXTENDED_SERVICE_DISCOVERY_RESPONSE = 231,

  /**
   * Streaming protocol (RFC0005).
   *
   * Used to transport a relatively large block of data. StreamID is a unique
   * layout wide identifier of a particular message stream. It is the
   * responsibility of the layout installer/module installer to ensure that any
   * StreamIDs are unique across the installation. StreamIDs 0~20 are reserved
   * as CBUS system wide IDs. Users would not allocate these IDs to private
   * streams. SequenceNum is a 0x00 to 0xFF identification of the frame sequence
   * . 0x00 is used to denote a header frame , any number != 0x00 indicates a
   * continuation frame. MessageLen is a 16 bit size in bytes of the transmitted
   * message , However as only 254 continuation frames are possible the Message
   * Len is limited to a count of 1275. However private protocols may be
   * deployed to send larger messages and the full extent of these fields can be
   * used. A Message length of Zero is supported, albeit rather pointless. 16 15
   * 2 CRC16 is a standard implementation of CRC, ie P(x) = x +x +x +1. CRC
   * fields are optional and set to 0x00 if not implemented. Continuation frames
   * merely contain the StreamID and SequenceNum and 5 bytes of message data It
   * is recommended that continuation frames are throttled at 1 over 20ms.
   */
  VLCB_OPC_STREAM_PACKET = 233,

  /**
   * Response to request for node parameters.
   *
   * Returns the first 7 parameters for the module in response to RQNP.
   */
  VLCB_OPC_NODE_PARAMETERS_REPORT = 239,

  /**
   * Accessory ON.
   *
   * Indicates an ‘ON’ event using the full event number of 4 bytes with three
   * additional data bytes. An event is sent by a module when it detects a
   * change of state. Modules may consume the event and perform actions. The
   * meaning of the additional data is dependent upon the application and must
   * be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_ON3 = 240,

  /**
   * Accessory OFF.
   *
   * Indicates an ‘OFF’ event using the full event number of 4 bytes with three
   * additional data bytes. An event is sent by a module when it detects a
   * change of state. Modules may consume the event and perform actions. The
   * meaning of the additional data is dependent upon the application and must
   * be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_OFF3 = 241,

  /**
   * Response to request to read node events.
   *
   * This is a response to either NERD or NENRD.
   */
  VLCB_OPC_LEARNED_EVENT_RESPONSE = 242,

  /**
   * Accessory Response Event.
   *
   * Indicates an ‘ON’ response event with three added data bytes. A response is
   * a reply to a status request (AREQ) without producing an
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_ON3 = 243,

  /**
   * Accessory Response Event.
   *
   * Indicates an ‘OFF’ response event with three added data bytes. A response
   * is a reply to a status request (AREQ) without producing an
   */
  VLCB_OPC_LONG_EVENT_ACCESSORY_STATE_OFF3 = 244,

  /**
   * Teach an event in learn mode using event indexing.
   *
   * Sent by a configuration tool to a node in learn mode to teach it an event.
   * The event index must be known. Also teaches it the associated event
   * variables (EVs). This command is repeated for each EV required. Parameter
   * EN# is ignored and this request is similar to EVLRN.
   */
  VLCB_OPC_TEACH_EVENT_BY_INDEX = 245,

  /**
   * Accessory node data event.
   *
   * Indicates an event from this node with 5 bytes of data. For example, this
   * can be used to send the 40 bits of an RFID tag. There is no event number in
   * order to allow space for 5 bytes of data in the packet, so there can only
   * be one data event per node. The meaning of the event is therefore dependent
   * upon the type and use of the module.
   */
  VLCB_OPC_DATA_EVENT_ACCESSORY = 246,

  /**
   * Accessory node data Response.
   *
   * Indicates a node data response. A response event is a reply to a status
   * request (RQDAT) without producing a new data event.
   */
  VLCB_OPC_NODE_ACCESSORY_DATA = 247,

  /**
   * Accessory Short ON.
   *
   * Indicates an ‘ON’ event using the short event number of 2 LS bytes with
   * three added data bytes. An event is sent by a module when it detects a
   * change of state. Modules may consume the event and perform actions. The NN
   * is not used to match events, the NN normally indicates the source of the
   * event. The meaning of the additional data is dependent upon the application
   * and must be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_ON3 = 248,

  /**
   * Accessory Short OFF.
   *
   * Indicates an ‘OFF’ event using the short event number of 2 LS bytes with
   * three added data bytes. An event is sent by a module when it detects a
   * change of state. Modules may consume the event and perform actions. The NN
   * is not used to match events, the NN normally indicates the source of the
   * event. The meaning of the additional data is dependent upon the application
   * and must be agreed between the producer and consumer of the event.
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_OFF3 = 249,

  /**
   * Device data event (short mode).
   *
   * Function is the same as ACDAT but uses device addressing so it can
   */
  VLCB_OPC_DEVICE_DATA_EVENT_SHORT_MODE = 250,

  /**
   * Device data response (short mode).
   *
   * The response to a RQDDS request for data from a device.
   */
  VLCB_OPC_DEVICE_DATA_SHORT_MODE = 251,

  /**
   * Write data.
   *
   * Used to write data to a device such as a RFID tag. data1 ~ data5 is data to
   * be written to the device. RC522 devices should have data1 set to 0
   */
  VLCB_OPC_WRITE_DATA = 252,

  /**
   * Accessory Short Response Event.
   *
   * Indicates an ‘ON’ response event with three added data bytes.A response is
   * a reply to a status request (ASRQ)without producing an ON
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_ON3 = 253,

  /**
   * Accessory Short Response Event.
   *
   * Indicates an ‘OFF’ response event with three added data bytes.A response is
   * a reply to a status request (ASRQ) without producing an
   */
  VLCB_OPC_SHORT_EVENT_ACCESSORY_STATE_OFF3 = 254,

  /**
   * Extended opcode with 6 additional bytes.
   *
   * Reserved to allow the 6 additional bytes range to be extended by a further
   * 256 opcodes.
   */
  VLCB_OPC_EXT_OPCODE6 = 255,
};
