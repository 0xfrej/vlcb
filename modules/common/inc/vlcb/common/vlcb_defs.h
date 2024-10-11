/**
 * VLCB opcodes
 */

typedef enum {

  /**
   * General Acknowledgement.
   *
   * Positive response to query/ request performed or report of availability
   * on-line.
   */

  VLCB_OPC_GENERAL_ACK = 0,

  /**
   * General No Ack.
   *
   * Negative response to query/ request denied.
   */

  VLCB_OPC_GENERAL_NACK = 1,

  /**
   * Bus Halt.
   *
   * Commonly broadcasted to all nodes to indicate CBUS is not available and
   * no further packets should be sent until a BON or ARST is received.
   */

  VLCB_OPC_BUS_HALT = 2,

  /**
   * Bus ON
   *
   * Commonly broadcasted to all nodes to indicate CBUS is available after a HLT
   * message was transmitted.
   */

  VLCB_OPC_BUS_RESUME = 3,

  /**
   * DCC track off.
   *
   * Commonly broadcasted to all nodes by a command station to indicate track
   * power is off and no further command packets should be sent, except
   * inquiries.
   */

  VLCB_OPC_DCC_TRACK_POWERED_OFF = 4,

  /**
   * DCC track on.
   *
   * Commonly broadcasted to all nodes by a command station to indicate track
   * power is on.
   */

  VLCB_OPC_DCC_TRACK_POWERED_ON = 5,

  /**
   * DCC emergency stop.
   *
   * Commonly broadcast to all nodes by a command station to indicate all
   * engines have been emergency stopped.
   */

  VLCB_OPC_DCC_EMERGENCY_STOP_ENGAGED = 6,

  /**
   * Perform reboot on all nodes.
   *
   * Commonly broadcasted to all nodes to indicate a full system restart.
   * Similar to NNRST which directs a single node to be restarted.
   */

  VLCB_OPC_RESTART_ALL_NODES = 7,

  /**
   * DCC request track off.
   *
   * Sent to request change of track power state to “off”.
   */

  VLCB_OPC_DCC_TRACK_POWER_OFF = 8,

  /**
   * DCC request track on.
   *
   * Sent to request change of track power state to “on”.
   */

  VLCB_OPC_DCC_TRACK_POWER_ON = 9,

  /**
   * DCC request emergency stop.
   *
   * Sent to request an emergency stop to all trains.
   * Does not affect accessory control.
   */

  VLCB_OPC_DCC_EMERGENCY_STOP = 10,

  /**
   * Request Command Station Status.
   *
   * Sent to query the status of the command station. See description of (STAT)
   * for the response from the command station.
   */

  VLCB_OPC_DCC_QUERY_COMMAND_STATION_STATUS = 12,

  /**
   * Query node number.
   *
   * Requests a PNN reply from each node on the bus.
   */

  VLCB_OPC_QUERY_NODE_INFO = 13,

  /**
   * Request node parameters.
   *
   * Sent to a node while in Setup mode to read its parameter set.
   * Used when initially configuring a node.
   */

  VLCB_OPC_QUERY_NODE_PARAMETERS = 16,

  /**
   * Request module name.
   *
   * Sent by a node to request the name of the type of module that is in setup
   * mode or Learn mode. The module in setup mode or learn mode will reply with
   * opcode NAME.
   */

  VLCB_OPC_QUERY_MODULE_NAME = 17,

  /**
   * Release Engine.
   *
   * Sent by a CAB to the Command Station. The engine with that Session number
   * is removed from the active engine list.
   */

  VLCB_OPC_DCC_RELEASE_SESSION = 33,

  /**
   * Query engine.
   *
   * Used to determine if the command station session is valid and to obtain
   * information about the status of the locomotive.
   */

  VLCB_OPC_DCC_QUERY_LOCO_STATUS = 34,

  /**
   * Session keep alive.
   *
   * The cab sends a keep alive at regular intervals for the active session.
   * The interval between keep alive messages must be less than the session
   * timeout implemented by the command station.
   */

  VLCB_OPC_DCC_SESSION_KEEP_ALIVE = 35,

  /**
   * Debug message with one data byte.
   *
   * Freeform status byte for debugging during CBUS module development. Not used
   * during normal operation.
   */

  VLCB_OPC_DEBUG_MSG1 = 48,

  /**
   * Extended opcode with zero additional bytes.
   * Reserved to allow the 0 additional bytes range to be extended by a further
   * 256 opcodes.
   */

  VLCB_OPC_EXT_OP_CODE = 63,

  /**
   * Request engine session.
   *
   * This command is typically sent by a cab to the command station following a
   * change of the controlled decoder address. RLOC is exactly equivalent to
   * GLOC with all flag bits set to zero, but command stations
   */

  VLCB_OPC_DCC_REQUEST_NEW_SESSION = 64,

  /**
   * Query Consist.
   *
   * Allows enumeration of a consist. Command station responds with PLOC if an
   * engine exists at the specified index, otherwise responds
   */

  VLCB_OPC_DCC_QUERY_CONSIST = 65,

  /**
   * Set Node Number.
   *
   * Sent by a configuration tool to assign a node number to a requesting node
   * in response to a RQNN message. The target node must be in
   */

  VLCB_OPC_SET_NODE_NUMBER = 66,

  /**
   * Allocate loco to activity.
   */

  VLCB_OPC_DCC_ALLOCATE_LOCO_TO_ACTIVITY = 67,

  /**
   * Set CAB session mode.
   *
   * Bits 0–1: speed mode
   * - 00 =128 speed steps
   * - 01 =14 speed steps
   * - 10 =28 speed steps with interleave steps
   * - 11 =28 speed steps
   *
   * Bit 2: service mode
   * Bit 3:sound control mode
   */

  VLCB_OPC_DCC_SET_THROTTLE_MODE = 68,

  /**
   * Consist Engine.
   *
   * Adds a decoder specified by Session to a consist.
   * Consist# has bit 7 set if consist direction is reversed.
   */

  VLCB_OPC_DCC_CONSIST_ADD_LOCO = 69,

  /**
   * Removes a loco from a consist.
   */

  VLCB_OPC_DCC_CONSIST_REMOVE_LOCO = 70,

  /**
   * Set Engine Speed/Dir.
   *
   * Speed/dir value, where the most significant bit is direction and the 7ls
   * bits are the unsigned speed value. Sent by a CAB or equivalent to request
   * an engine speed/dir change.
   */

  VLCB_OPC_DCC_SET_LOCO_THROTTLE = 71,

  /**
   * Set Engine Flags.
   *
   * Sent by a cab to notify the command station of a change in engine flags.
   *
   * Bits 0-1: Speed Mode (00 =128 speed steps, 01 =14 speed steps,10 =28 speed
   * steps with interleave steps, 11 =28 speed steps) Bit 2:Lights On/OFF Bit
   * 3:Engine relative direction Bits 4-5: Engine state (active =0 , consisted
   * =1, consist master=2, inactive=3) Bits 6-7: Reserved.
   */

  VLCB_OPC_DCC_SET_LOCO_FLAGS = 72,

  /**
   * Set Engine function on.
   *
   * Sent by a cab to turn on a specific loco function.
   * This provides an alternative method to DFUN for controlling loco functions.
   * A command
   */

  VLCB_OPC_DCC_LOCO_FUNCTION_ON = 73,

  /**
   * Set Engine function off.
   *
   * Sent by a cab to turn off a specific loco function.
   * This provides an alternative method to DFUN for controlling loco functions.
   * A command
   */

  VLCB_OPC_DCC_LOCO_FUNCTION_OFF = 74,

  /**
   * Service mode status.
   *
   * Status returned by command station/programmer at the end of a programming
   * operation that does not return data. Response to QCVS to indicate no data.
   */

  VLCB_OPC_DCC_SERVICE_MODE_STATUS = 76,

  /**
   * Reset to manufacturer settings.
   * Reset a module back to manufacturer settings.
   */

  VLCB_OPC_RESET_MODULE_TO_FACTORY = 79,

  /**
   * Request node number.
   *
   * The module is requesting that it is provided with a new node number.
   * A configuration tool should respond with SNN to provide the requesting
   */

  VLCB_OPC_REQUEST_NEW_NODE_NUMBER = 80,

  /**
   * Node number release.
   *
   * A node signals that it no longer requires a node number by sending NNREL.
   * The module will do this upon moving from normal mode to setup mode.
   */

  VLCB_OPC_NODE_NUMBER_RELEASED = 81,

  /**
   * Node number acknowledge.
   *
   * This message is sent in response to SNN.
   * A node signals that it will
   */

  VLCB_OPC_NODE_NUMBER_ACK = 82,

  /**
   * Set node into learn mode.
   *
   * Sent by a configuration tool to put a specific node into learn mode.
   */

  VLCB_OPC_PUT_NODE_INTO_LEARN_MODE = 83,

  /**
   * Release node from learn mode.
   *
   * Sent by a configuration tool to take the module out of learn mode and
   * revert to normal operation.
   */

  VLCB_OPC_RELEASE_NODE_FROM_LEARN_MODE = 84,

  /**
   * Clear all events from a node.
   *
   * Sent by a configuration tool to clear all events from a specific node.
   * Must be in learn mode first to safeguard against accidental erasure of all
   * events
   */

  VLCB_OPC_FORGET_ALL_LEARNED_EVENTS = 85,

  /**
   * Read the number of event slots available in a node.
   *
   * Sent by a configuration tool to read the number of available event slots in
   * a node.
   */

  VLCB_OPC_QUERY_AVAILABLE_EVENT_SLOTS = 86,

  /**
   * Read back all stored events in a node.
   *
   * There MUST be no hidden events.
   * Sent by a configuration tool to read all the stored events in a node.
   */

  VLCB_OPC_QUERY_ALL_LEARNED_EVENTS = 87,

  /**
   * Request to read number of stored events.
   *
   * Sent by a configuration tool to read the number of stored events in a node.
   */

  VLCB_OPC_QUERY_LEARNED_EVENT_COUNT = 88,

  /**
   * Write acknowledge.
   *
   * Sent by a node to indicate the completion of a write to memory operation.
   * All nodes must issue WRACK when a write operation to node variables, events
   * or event variables has completed. This allows for teaching nodes where the
   * processing time may be slow.
   */

  VLCB_OPC_WRITE_ACK = 89,

  /**
   * Request node data event.
   *
   * Sent by one node to read the data event from another node.(eg: RFID data).
   */

  VLCB_OPC_QUERY_NODE_DATA = 90,

  /**
   * Request device data –short mode.
   *
   * To request a ‘data set’ from a device using the short event method where DN
   * is the device number.
   */

  VLCB_OPC_REQUEST_DEVICE_DATA_SHORT_MODE = 91,

  /**
   * Put node into bootloading mode.
   * For modules with no NN then the NN of the command must be zero. For nodes
   * in Normal mode the command must contain the NN of the target node. Sent by
   * a configuration tool to prepare for loading a new program.
   */

  VLCB_OPC_REBOOT_INTO_BOOTLOADER = 92,

  /**
   * Force a self enumeration cycle for use with CAN.
   *
   * For nodes in Normal mode using CAN as a transport.
   * This message will force a self-enumeration cycle for the specified node.
   * A new CAN_ID will be allocated if needed.
   */

  VLCB_OPC_FORCE_CAN_ENUMERATION = 93,

  /**
   * Reset module’s CPU.
   *
   * Reset a module’s microprocessor.
   */

  VLCB_OPC_RESTART_NODE = 94,

  /**
   * Extended opcode with 1 additional byte.
   *
   * Reserved to allow the 1 additional bytes range to be extended by a further
   * 256 opcodes.
   */

  VLCB_OPC_EXT_OP_CODE1 = 95,

  /**
   * Set Engine functions.
   *
   * <Fn1>is the function range 1 is F0(FL) to F4, 2 is F5 to F8, 3 is F9 to
   * F12, 4 is F13 to F20, 5 is F21to F28) <Fn2> is the NMRA DCC format function
   * byte for that range in corresponding bits. A bit set to 1 turns function
   * “on” and a cleared bit sets function “off”. Sent by a CAB or equivalent to
   * request an engine Fn state change.
   */

  VLCB_OPC_DCC_SET_LOCO_FUNCTIONS = 96,

  /**
   * Get engine session.
   *
   * <Flags> contains flag bits as follows: Bit 0: Set for "Steal" mode Bit 1:
   * Set for "Share" mode. Both bits set to 0 is exactly equivalent to an RLOC
   * request but
   */

  VLCB_OPC_DCC_QUERY_LOCO_SESSION = 97,

  /**
   * Command Station Error report.
   *
   * Sent in response to an error situation by a command station.
   * See Appendix A - DCC ERR error codes for a list of error codes.
   */

  VLCB_OPC_DCC_COMMAND_STATION_ERROR = 99,

  /**
   * Error messages from nodes during configuration.
   *
   * Sent by node if there is an error when a configuration command is sent. See
   * Appendix C - CMDERR error codes for the list of supported codes.
   */

  VLCB_OPC_NODE_CONFIGURATION_ERROR = 111,

  /**
   * Event space left reply from node.
   *
   * Spaces is a one byte value giving the number of available event spaces left
   * in the node’s event table. This is the maximum number of additional events
   * that can be stored by the module.
   */

  VLCB_OPC_AVAILABLE_EVENT_SLOTS = 112,

  /**
   * Request read of a node variable.
   *
   * NV# is the index for the node variable value requested.
   * Response is NVANS.
   */

  VLCB_OPC_QUERY_NODE_VARIABLE = 113,

  /**
   * Request read of stored event by event index.
   *
   * EN# is the index for the stored event requested.
   */

  VLCB_OPC_QUERY_LEARNED_EVENT_BY_INDEX = 114,

  /**
   * Request read of a node parameter by index.
   *
   * Para# is the index for the parameter requested. Reading Index 0 first
   * returns a PARAN with the number of available
   */

  VLCB_OPC_QUERY_NODE_PARAMETER_BY_INDEX = 115,

  /**
   * Number of events stored by node.
   *
   * Response to request RQEVN
   */

  VLCB_OPC_LEARNED_EVENT_COUNT = 116,

  /**
   * Set the CAN_ID in the node.
   *
   * Used to force a specified CAN_ID into a node. Value range is from 1 to 0x63
   * (99 decimal). This OPC must be used with care as duplicate CAN_IDs are not
   * allowed.
   */

  VLCB_OPC_SET_NODE_CAN_ID = 117,

  /**
   * Request a change to a module’s operating mode.
   *
   * Request to change the operational mode of the module.
   */

  VLCB_OPC_PUT_NODE_INTO_MODE = 118,

  /**
   * Request service discovery.
   *
   * Request service data from a module.
   * If the ServiceIndex is zero then the module responds with a SD
   */

  VLCB_OPC_SERVICE_DISCOVERY_QUERY = 120,

  /**
   * Extended opcode with 2 additional bytes.
   *
   * Reserved to allow the 2 additional bytes range to be extended by a
   * further 256 opcodes.
   */

  VLCB_OPC_EXT_OP_CODE2 = 127,

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

  VLCB_OPC_EXT_OP_CODE3 = 159,

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

  VLCB_OPC_QUERY_EVENT_VARIABLE_IN_LEARN_MODE = 178,

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

  VLCB_OPC_NODE_INFO = 182,

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

  VLCB_OPC_EXT_OP_CODE4 = 191,

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

  VLCB_OPC_EXT_OP_CODE5 = 223,

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

  VLCB_OPC_NODE_DATA_EVENT_RESPONSE = 247,

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

  VLCB_OPC_DEVICE_DATA_RESPONSE_SHORT_MODE = 251,

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

  VLCB_OPC_EXT_OP_CODE6 = 255,

} VlcbOpCode;
/**
 * VLCB Service Types
 */

typedef enum {

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

} VlcbServiceType;
/**
 * Parameters to the MODE op-code
 *
 * Exclusive modes
 */

typedef enum {

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

} VlcbModuleMode;
/**
 * GRSP codes
 */

typedef enum {

  /**
   * Success
   */

  VLCB_GENERIC_RESPONSE_STAT_OK = 0,

  /**
   * Unknown non volatile memory type
   */

  VLCB_GENERIC_RESPONSE_STAT_UNKNOWN_PERSISTENT_MEMORY_TYPE = 254,

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

} VlcbGenericResponseStatus;
/**
 * SysPixie Module types (Konrad Orlowski)
 */

typedef enum {

  /**
   * Motorised point motor driver with current sense
   */

  VLCB_SYSPIXIE_MODULE_CANPMSENSE = 1,

} VlcbSysPixieModuleType;
/**
 * Modes for STMOD
 */

typedef enum {

  /**
   * 128-step speed mode
   */

  VLCB_DCC_THROTTLE_MODE_STEP128 = 0,

  /**
   * 14-step speed mode
   */

  VLCB_DCC_THROTTLE_MODE_STEP14 = 1,

  /**
   * interleaved 28-step speed mode
   */

  VLCB_DCC_THROTTLE_MODE_STEP28INTERLEAVED = 2,

  /**
   * 28-step speed mode
   */

  VLCB_DCC_THROTTLE_MODE_STEP28 = 3,

} VlcbDccThrottleMode;
/**
 * Status codes for SSTAT message
 */

typedef enum {

  VLCB_DCC_SVC_MODE_STAT_NO_ACK = 1,

  VLCB_DCC_SVC_MODE_STAT_OVLD = 2,

  VLCB_DCC_SVC_MODE_STAT_WRITE_ACK = 3,

  VLCB_DCC_SVC_MODE_STAT_BUSY = 4,

  VLCB_DCC_SVC_MODE_STAT_CV_ERROR = 5,

} VlcbDccServiceModeStatus;
/**
 * Sprog Module types
 */

typedef enum {

  /**
   * Pi-SPROG 3 programmer/command station
   */

  VLCB_SPROG_MODULE_CANPI_SPRG3 = 1,

  /**
   * SPROG 3 Plus programmer/command station
   */

  VLCB_SPROG_MODULE_CANSPROG3P = 2,

  /**
   * CAN SPROG programmer/command station
   */

  VLCB_SPROG_MODULE_CANSPROG = 3,

  /**
   * System Booster
   */

  VLCB_SPROG_MODULE_CANSBOOST = 4,

  /**
   * Pi-SPROG 3 Plus programmer/command station
   */

  VLCB_SPROG_MODULE_CANPI_SPRGP = 5,

  /**
   * 8-channel (4-pairs) Solenoid I/O module
   */

  VLCB_SPROG_MODULE_CANSOLNOID = 8,

  /**
   * 8-channel Servo I/O module
   */

  VLCB_SPROG_MODULE_CANSERVOIO = 50,

  /**
   * CAN ISB Isolated CAN USB Interface
   */

  VLCB_SPROG_MODULE_CANISB = 100,

  /**
   * 8-channel (4-pairs) Solenoid I/O module
   */

  VLCB_SPROG_MODULE_CANSOLIO = 101,

} VlcbSprogModuleType;
/**
 * Spectrum Engineering Animated Modeller module types
 */

typedef enum {

  /**
   * Animation controller (firmware derived from cancmd)
   */

  VLCB_SPECTRUM_MODULE_AMCTRLR = 1,

  /**
   * Dual cab based on cancab
   */

  VLCB_SPECTRUM_MODULE_DUALCAB = 2,

} VlcbSpectrumModuleType;
/**
 * Rocrail Module types
 */

typedef enum {

  /**
   * RS232 PC interface
   */

  VLCB_ROCRAIL_MODULE_CANGC1 = 1,

  /**
   * 16 I/O
   */

  VLCB_ROCRAIL_MODULE_CANGC2 = 2,

  /**
   * Command station (derived from cancmd)
   */

  VLCB_ROCRAIL_MODULE_CANGC3 = 3,

  /**
   * 8 channel RFID reader
   */

  VLCB_ROCRAIL_MODULE_CANGC4 = 4,

  /**
   * Cab for fixed panels (derived from cancab)
   */

  VLCB_ROCRAIL_MODULE_CANGC5 = 5,

  /**
   * 4 channel servo controller
   */

  VLCB_ROCRAIL_MODULE_CANGC6 = 6,

  /**
   * Fast clock module
   */

  VLCB_ROCRAIL_MODULE_CANGC7 = 7,

  /**
   * CAN<->Ethernet interface
   */

  VLCB_ROCRAIL_MODULE_CANGC1E = 11,

} VlcbRocRailModuleType;
/**
 * Parameter index numbers (readable by OPC_RQNPN, returned in OPC_PARAN)
 * Index numbers count from 1, subtract 1 for offset into parameter block
 * Note that RQNPN with index 0 returns the parameter count
 */

typedef enum {

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

  VLCB_MODULE_PARAM_NODE_FLAGS = 8,

  /**
   * Processor type
   */

  VLCB_MODULE_PARAM_CPU_ID = 9,

  /**
   * Bus type
   */

  VLCB_MODULE_PARAM_BUS_TYPE = 10,

  /**
   * load address, 4 bytes
   */

  VLCB_MODULE_PARAM_LOAD_ADDRESS = 11,

  /**
   * CPU manufacturer's id as read from the chip config space, 4 bytes (note -
   * read from cpu at runtime, so not included in checksum)
   */

  VLCB_MODULE_PARAM_CPU_MANUFACTURER_ID = 15,

  /**
   * CPU manufacturer code
   */

  VLCB_MODULE_PARAM_CPU_MANUFACTURER = 19,

  /**
   * Beta revision (numeric), or 0 if release
   */

  VLCB_MODULE_PARAM_BETA_VERSION = 20,

} VlcbModuleParam;
/**
 * Flags in node parameter FLAGS
 */

typedef enum {

  /**
   * Module doesn't support events
   */

  VLCB_MODULE_FLAG_EVENTS_UNSUPPORTED = 0x0,

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
   */

  VLCB_MODULE_FLAG_EVENT_COMBI = 0x3,

  /**
   * Module is in FLiM (CBUS)
   */

  VLCB_MODULE_FLAG_FLI_M = 0x4,

  /**
   * Module is in Normal mode (VLCB)
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

  /**
   * Module supports Service Discovery (Deprecated in favour of PF_VLCB.)
   */

  VLCB_MODULE_FLAG_SERVICE_DISCOVERY = 0x40,

} ModuleFlags;
/**
 * MERG Module types
 */

typedef enum {

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

} VlcbMergModuleType;
/**
 * Manufacturer definitions
 *
 * Here are definitions for all known MERG registered manufacturers.
 */

typedef enum {

  /**
   * Develoment mode manufacturer
   *
   * For manufacturers who don't have a manufacturer id yet or
   * for lib developers during testing.
   *
   * Do not use in production!
   */

  VLCB_MANU_DEVELOPMENT = 13,

  /**
   * https://www.merg.co.uk
   */

  VLCB_MANU_MERG = 165,

  /**
   * https://www.sprog-dcc.co.uk/
   */

  VLCB_MANU_SPROG = 44,

  /**
   * http://www.rocrail.net
   */

  VLCB_MANU_ROCRAIL = 70,

  /**
   * http://animatedmodeler.com  (Spectrum Engineering)
   */

  VLCB_MANU_SPECTRUM = 80,

  /**
   * range of MERG VLCB modules
   */

  VLCB_MANU_MERG_VLCB = 250,

  /**
   * Konrad Orlowski
   */

  VLCB_MANU_SYSPIXIE = 249,

  /**
   * http://rmeuk.com  (Railway Modelling Experts Limited)
   */

  VLCB_MANU_RME = 248,

} VlcbManufacturer;
/**
 * Error codes for ERR message
 */

typedef enum {

  VLCB_DCC_ERRLOCO_STACK_IS_FULL = 1,

  VLCB_DCC_ERRLOCO_ADDRESS_IS_TAKEN = 2,

  VLCB_DCC_ERRSESSION_IS_NOT_PRESENT = 3,

  VLCB_DCC_ERREMPTY_CONSIST = 4,

  VLCB_DCC_ERRLOCO_WAS_NOT_FOUND = 5,

  VLCB_DCC_ERRRX_BUFFER_OVERFLOW = 6,

  VLCB_DCC_ERRINVALID_REQUEST = 7,

  VLCB_DCC_ERRSESSION_WAS_CANCELLED = 8,

} VlcbDccError;
/**
 * Error codes for CMDERR message
 */

typedef enum {

  /**
   * Invalid command
   */

  VLCB_CMDERRINVALID_COMMAND = 1,

  /**
   * The mode is not currently in learn mode
   */

  VLCB_CMDERRNOT_IN_LEARN_MODE = 2,

  /**
   * The mode is not currently in setup mode
   */

  VLCB_CMDERRNOT_IN_SETUP_MODE = 3,

  /**
   * Too many events provisioned in module
   *
   * The event storage is exhausted
   */

  VLCB_CMDERRTOO_MANY_EVENTS = 4,

  /**
   * No Event-Variable
   */

  VLCB_CMDERRNO_EV = 5,

  /**
   * Invalid EV index
   */

  VLCB_CMDERRINVALID_EV_INDEX = 6,

  /**
   * Invalid event
   */

  VLCB_CMDERRINVALID_EVENT = 7,

  /**
   * Invalid event index
   */

  VLCB_CMDERRINVALID_EVENT_INDEX = 8,

  /**
   * Invalid param index
   */

  VLCB_CMDERRINVALID_PARAM_INDEX = 9,

  /**
   * Invalid NV index
   */

  VLCB_CMDERRINVALID_NV_INDEX = 10,

  /**
   * Invalid EV value
   */

  VLCB_CMDERRINVALID_EV_VALUE = 11,

  /**
   * Invalid NV value
   */

  VLCB_CMDERRINVALID_NV_VALUE = 12,

  /**
   * Another module is already in learn mode
   *
   * Sent when module in learn mode sees NNLRN for different module (also exits
   * learn mode)
   */

  VLCB_CMDERRANOTHER_MODULE_IS_IN_LEARN_MODE = 13,

} VlcbCommandError;
/**
 * Defines the meaning of the remaining 3 bytes of the CABDAT message
 */

typedef enum {

  /**
   * CABSIG
   * Transmitted by a layout control system to send
   * signal aspects to be displayed on a cab handset as cab
   * signalling.
   */

  VLCB_DCC_CAB_CAB_SIGNALLING = 1,

} VlcbDccCabDataCode;
/**
 * BUS type that module is connected to
 */

typedef enum {

  VLCB_BUS_CAN = 1,

  VLCB_BUS_ETHERNET = 2,

  VLCB_BUS_MIWI = 3,

  VLCB_BUS_USB = 4,

} VlcbBusType;
/**
 * Microchip Processor type codes (used by FCU to identify correct bootloader
 * compatibility)
 */

typedef enum {

  VLCB_PM_MICROCHIP_P18F2480 = 1,

  VLCB_PM_MICROCHIP_P18F4480 = 2,

  VLCB_PM_MICROCHIP_P18F2580 = 3,

  VLCB_PM_MICROCHIP_P18F4580 = 4,

  VLCB_PM_MICROCHIP_P18F2585 = 5,

  VLCB_PM_MICROCHIP_P18F4585 = 6,

  VLCB_PM_MICROCHIP_P18F2680 = 7,

  VLCB_PM_MICROCHIP_P18F4680 = 8,

  VLCB_PM_MICROCHIP_P18F2682 = 9,

  VLCB_PM_MICROCHIP_P18F4682 = 10,

  VLCB_PM_MICROCHIP_P18F2685 = 11,

  VLCB_PM_MICROCHIP_P18F4685 = 12,

  VLCB_PM_MICROCHIP_P18F25K80 = 13,

  VLCB_PM_MICROCHIP_P18F45K80 = 14,

  VLCB_PM_MICROCHIP_P18F26K80 = 15,

  VLCB_PM_MICROCHIP_P18F46K80 = 16,

  VLCB_PM_MICROCHIP_P18F65K80 = 17,

  VLCB_PM_MICROCHIP_P18F66K80 = 18,

  VLCB_PM_MICROCHIP_P18F25K83 = 19,

  VLCB_PM_MICROCHIP_P18F26K83 = 20,

  VLCB_PM_MICROCHIP_P18F27Q84 = 21,

  VLCB_PM_MICROCHIP_P18F47Q84 = 22,

  VLCB_PM_MICROCHIP_P18F27Q83 = 23,

  VLCB_PM_MICROCHIP_P18F14K22 = 25,

  VLCB_PM_MICROCHIP_P32MX534F064 = 30,

  VLCB_PM_MICROCHIP_P32MX564F064 = 31,

  VLCB_PM_MICROCHIP_P32MX564F128 = 32,

  VLCB_PM_MICROCHIP_P32MX575F256 = 33,

  VLCB_PM_MICROCHIP_P32MX575F512 = 34,

  VLCB_PM_MICROCHIP_P32MX764F128 = 35,

  VLCB_PM_MICROCHIP_P32MX775F256 = 36,

  VLCB_PM_MICROCHIP_P32MX775F512 = 37,

  VLCB_PM_MICROCHIP_P32MX795F512 = 38,

} VlcbMicrochipProcessor;
/**
 * ARM Processor type codes (used by FCU to identify correct bootloader
 * compatibility)
 */

typedef enum {

  VLCB_PM_ARM_ARM1176JZFS = 1,

  VLCB_PM_ARM_CORTEXA7 = 2,

  VLCB_PM_ARM_CORTEXA53 = 3,

} VlcbArmProcessor;
/**
 * Processor manufacturer codes
 */

typedef enum {

  VLCB_PM_MICROCHIP = 1,

  VLCB_PM_ATMEL = 2,

  VLCB_PM_ARM = 3,

} VlcbProcessorManufacturer;
#pragma once

#pragma once
