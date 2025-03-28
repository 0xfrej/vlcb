#include "vlcb/net/message/data.h"
#include "vlcb/net/packet/vlcb.h"

/**
 * @brief Net message VlcbNetMsgDccQueryLocoStatus serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccQueryLocoStatus_Serialize(
    VlcbNetMsgDccQueryLocoStatus msg);

/**
 * @brief Net message VlcbNetMsgDccQueryLocoStatus deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccQueryLocoStatus_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccQueryLocoStatus *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccQueryLocoStatus message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccQueryLocoStatus_New(VlcbDccSessionNr session);

/**
 * @brief Net message VlcbNetMsgDccSessionKeepAlive serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccSessionKeepAlive_Serialize(
    VlcbNetMsgDccSessionKeepAlive msg);

/**
 * @brief Net message VlcbNetMsgDccSessionKeepAlive deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSessionKeepAlive_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSessionKeepAlive *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSessionKeepAlive message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSessionKeepAlive_New(VlcbDccSessionNr session);

/**
 * @brief Net message VlcbNetMsgDebugMsg1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgDebugMsg1_Serialize(VlcbNetMsgDebugMsg1 msg);

/**
 * @brief Net message VlcbNetMsgDebugMsg1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDebugMsg1_Deserialize(
    const VlcbNetPacket datagramPacket, VlcbNetMsgDebugMsg1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDebugMsg1 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDebugMsg1_New(uint8_t status);

/**
 * @brief Net message VlcbNetMsgExtOpcode0 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgExtOpcode0_Serialize(VlcbNetMsgExtOpcode0 msg);

/**
 * @brief Net message VlcbNetMsgExtOpcode0 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode0_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgExtOpcode0 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgExtOpcode0 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode0_New(uint8_t opcodeExtension);

/**
 * @brief Net message VlcbNetMsgDccRequestNewSession serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccRequestNewSession_Serialize(
    VlcbNetMsgDccRequestNewSession msg);

/**
 * @brief Net message VlcbNetMsgDccRequestNewSession deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccRequestNewSession_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccRequestNewSession *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccRequestNewSession message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccRequestNewSession_New(
    VlcbDccDecoderAddr decoderAddr);

/**
 * @brief Net message VlcbNetMsgDccQueryConsist serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgDccQueryConsist_Serialize(VlcbNetMsgDccQueryConsist msg);

/**
 * @brief Net message VlcbNetMsgDccQueryConsist deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccQueryConsist_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccQueryConsist *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccQueryConsist message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccQueryConsist_New(VlcbDccConsistId consist,
                                               uint8_t index);

/**
 * @brief Net message VlcbNetMsgSetNodeNumber serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgSetNodeNumber_Serialize(VlcbNetMsgSetNodeNumber msg);

/**
 * @brief Net message VlcbNetMsgSetNodeNumber deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgSetNodeNumber_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgSetNodeNumber *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgSetNodeNumber message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgSetNodeNumber_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgDccAllocateLocoToActivity serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgDccAllocateLocoToActivity_Serialize(
    VlcbNetMsgDccAllocateLocoToActivity msg);

/**
 * @brief Net message VlcbNetMsgDccAllocateLocoToActivity deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccAllocateLocoToActivity_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccAllocateLocoToActivity *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccAllocateLocoToActivity message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccAllocateLocoToActivity_New(
    VlcbDccSessionNr session, uint8_t allocationCode);

/**
 * @brief Net message VlcbNetMsgDccSetThrottleMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccSetThrottleMode_Serialize(
    VlcbNetMsgDccSetThrottleMode msg);

/**
 * @brief Net message VlcbNetMsgDccSetThrottleMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSetThrottleMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSetThrottleMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSetThrottleMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSetThrottleMode_New(
    VlcbDccSessionNr session, VlcbDccThrottleSpeedMode throttleMode,
    bool inServiceMode, bool inSoundControlMode);

/**
 * @brief Net message VlcbNetMsgDccConsistAddLoco serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccConsistAddLoco_Serialize(
    VlcbNetMsgDccConsistAddLoco msg);

/**
 * @brief Net message VlcbNetMsgDccConsistAddLoco deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccConsistAddLoco_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccConsistAddLoco *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccConsistAddLoco message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccConsistAddLoco_New(VlcbDccSessionNr session,
                                                 VlcbDccConsistId consist);

/**
 * @brief Net message VlcbNetMsgDccConsistRemoveLoco serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccConsistRemoveLoco_Serialize(
    VlcbNetMsgDccConsistRemoveLoco msg);

/**
 * @brief Net message VlcbNetMsgDccConsistRemoveLoco deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccConsistRemoveLoco_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccConsistRemoveLoco *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccConsistRemoveLoco message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccConsistRemoveLoco_New(VlcbDccSessionNr session,
                                                    VlcbDccConsistId consist);

/**
 * @brief Net message VlcbNetMsgDccSetLocoThrottle serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccSetLocoThrottle_Serialize(
    VlcbNetMsgDccSetLocoThrottle msg);

/**
 * @brief Net message VlcbNetMsgDccSetLocoThrottle deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSetLocoThrottle_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSetLocoThrottle *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSetLocoThrottle message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSetLocoThrottle_New(
    VlcbDccSessionNr session, uint8_t speed, VlcbDccLocoDirection direction);

/**
 * @brief Net message VlcbNetMsgDccSetLocoFlags serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgDccSetLocoFlags_Serialize(VlcbNetMsgDccSetLocoFlags msg);

/**
 * @brief Net message VlcbNetMsgDccSetLocoFlags deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSetLocoFlags_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSetLocoFlags *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSetLocoFlags message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSetLocoFlags_New(
    VlcbDccSessionNr session, VlcbDccThrottleSpeedMode speedMode, bool lightsOn,
    VlcbDccLocoDirection direction, VlcbDccLocoState state);

/**
 * @brief Net message VlcbNetMsgDccLocoFunctionOn serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccLocoFunctionOn_Serialize(
    VlcbNetMsgDccLocoFunctionOn msg);

/**
 * @brief Net message VlcbNetMsgDccLocoFunctionOn deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccLocoFunctionOn_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccLocoFunctionOn *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccLocoFunctionOn message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccLocoFunctionOn_New(VlcbDccSessionNr session,
                                                 uint8_t functionNr);

/**
 * @brief Net message VlcbNetMsgDccLocoFunctionOff serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccLocoFunctionOff_Serialize(
    VlcbNetMsgDccLocoFunctionOff msg);

/**
 * @brief Net message VlcbNetMsgDccLocoFunctionOff deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccLocoFunctionOff_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccLocoFunctionOff *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccLocoFunctionOff message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccLocoFunctionOff_New(VlcbDccSessionNr session,
                                                  uint8_t functionNr);

/**
 * @brief Net message VlcbNetMsgDccServiceModeStatus serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccServiceModeStatus_Serialize(
    VlcbNetMsgDccServiceModeStatus msg);

/**
 * @brief Net message VlcbNetMsgDccServiceModeStatus deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccServiceModeStatus_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccServiceModeStatus *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccServiceModeStatus message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccServiceModeStatus_New(VlcbDccSessionNr session,
                                                    uint8_t status);

/**
 * @brief Net message VlcbNetMsgResetModuleToFactory serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgResetModuleToFactory_Serialize(
    VlcbNetMsgResetModuleToFactory msg);

/**
 * @brief Net message VlcbNetMsgResetModuleToFactory deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgResetModuleToFactory_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgResetModuleToFactory *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgResetModuleToFactory message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgResetModuleToFactory_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgRequestNewNodeNumber serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgRequestNewNodeNumber_Serialize(
    VlcbNetMsgRequestNewNodeNumber msg);

/**
 * @brief Net message VlcbNetMsgRequestNewNodeNumber deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgRequestNewNodeNumber_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgRequestNewNodeNumber *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgRequestNewNodeNumber message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgRequestNewNodeNumber_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgNodeNumberReleased serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgNodeNumberReleased_Serialize(
    VlcbNetMsgNodeNumberReleased msg);

/**
 * @brief Net message VlcbNetMsgNodeNumberReleased deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgNodeNumberReleased_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgNodeNumberReleased *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgNodeNumberReleased message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgNodeNumberReleased_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgNodeNumberAck serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgNodeNumberAck_Serialize(VlcbNetMsgNodeNumberAck msg);

/**
 * @brief Net message VlcbNetMsgNodeNumberAck deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgNodeNumberAck_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgNodeNumberAck *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgNodeNumberAck message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgNodeNumberAck_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgPutNodeIntoLearnMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgPutNodeIntoLearnMode_Serialize(
    VlcbNetMsgPutNodeIntoLearnMode msg);

/**
 * @brief Net message VlcbNetMsgPutNodeIntoLearnMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgPutNodeIntoLearnMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgPutNodeIntoLearnMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgPutNodeIntoLearnMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgPutNodeIntoLearnMode_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgReleaseNodeFromLearnMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgReleaseNodeFromLearnMode_Serialize(
    VlcbNetMsgReleaseNodeFromLearnMode msg);

/**
 * @brief Net message VlcbNetMsgReleaseNodeFromLearnMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgReleaseNodeFromLearnMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgReleaseNodeFromLearnMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgReleaseNodeFromLearnMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgReleaseNodeFromLearnMode_New(
    VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgForgetAllLearnedEvents serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgForgetAllLearnedEvents_Serialize(
    VlcbNetMsgForgetAllLearnedEvents msg);

/**
 * @brief Net message VlcbNetMsgForgetAllLearnedEvents deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgForgetAllLearnedEvents_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgForgetAllLearnedEvents *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgForgetAllLearnedEvents message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgForgetAllLearnedEvents_New(
    VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgQueryAvailableEventSlots serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryAvailableEventSlots_Serialize(
    VlcbNetMsgQueryAvailableEventSlots msg);

/**
 * @brief Net message VlcbNetMsgQueryAvailableEventSlots deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryAvailableEventSlots_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryAvailableEventSlots *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryAvailableEventSlots message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryAvailableEventSlots_New(
    VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgQueryAllLearnedEvents serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryAllLearnedEvents_Serialize(
    VlcbNetMsgQueryAllLearnedEvents msg);

/**
 * @brief Net message VlcbNetMsgQueryAllLearnedEvents deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryAllLearnedEvents_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryAllLearnedEvents *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryAllLearnedEvents message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryAllLearnedEvents_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgQueryLearnedEventCount serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryLearnedEventCount_Serialize(
    VlcbNetMsgQueryLearnedEventCount msg);

/**
 * @brief Net message VlcbNetMsgQueryLearnedEventCount deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryLearnedEventCount_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryLearnedEventCount *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryLearnedEventCount message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryLearnedEventCount_New(
    VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgWriteAck serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgWriteAck_Serialize(VlcbNetMsgWriteAck msg);

/**
 * @brief Net message VlcbNetMsgWriteAck deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgWriteAck_Deserialize(
    const VlcbNetPacket datagramPacket, VlcbNetMsgWriteAck *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgWriteAck message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgWriteAck_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgQueryNodeAccessoryData serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryNodeAccessoryData_Serialize(
    VlcbNetMsgQueryNodeAccessoryData msg);

/**
 * @brief Net message VlcbNetMsgQueryNodeAccessoryData deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryNodeAccessoryData_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryNodeAccessoryData *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryNodeAccessoryData message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryNodeAccessoryData_New(
    VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgQueryDeviceDataShortMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryDeviceDataShortMode_Serialize(
    VlcbNetMsgQueryDeviceDataShortMode msg);

/**
 * @brief Net message VlcbNetMsgQueryDeviceDataShortMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryDeviceDataShortMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryDeviceDataShortMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryDeviceDataShortMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryDeviceDataShortMode_New(
    VlcbNodeNumber dataNumber);

/**
 * @brief Net message VlcbNetMsgRebootIntoBootloader serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgRebootIntoBootloader_Serialize(
    VlcbNetMsgRebootIntoBootloader msg);

/**
 * @brief Net message VlcbNetMsgRebootIntoBootloader deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgRebootIntoBootloader_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgRebootIntoBootloader *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgRebootIntoBootloader message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgRebootIntoBootloader_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgForceCanEnumeration serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgForceCanEnumeration_Serialize(
    VlcbNetMsgForceCanEnumeration msg);

/**
 * @brief Net message VlcbNetMsgForceCanEnumeration deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgForceCanEnumeration_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgForceCanEnumeration *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgForceCanEnumeration message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgForceCanEnumeration_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgRestartNode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgRestartNode_Serialize(VlcbNetMsgRestartNode msg);

/**
 * @brief Net message VlcbNetMsgRestartNode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgRestartNode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgRestartNode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgRestartNode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgRestartNode_New(VlcbNodeNumber nodeNumber);

/**
 * @brief Net message VlcbNetMsgExtOpcode1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgExtOpcode1_Serialize(VlcbNetMsgExtOpcode1 msg);

/**
 * @brief Net message VlcbNetMsgExtOpcode1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode1_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgExtOpcode1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgExtOpcode1 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode1_New(uint8_t opcodeExtension,
                                          uint8_t data[1]);

/**
 * @brief Net message VlcbNetMsgDccSetLocoFunctions serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccSetLocoFunctions_Serialize(
    VlcbNetMsgDccSetLocoFunctions msg);

/**
 * @brief Net message VlcbNetMsgDccSetLocoFunctions deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSetLocoFunctions_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSetLocoFunctions *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSetLocoFunctions message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSetLocoFunctions_New(
    VlcbDccSessionNr session, VlcbDccLocoFunctionRange range,
    uint8_t functionStates);

/**
 * @brief Net message VlcbNetMsgDccQueryLocoSession serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccQueryLocoSession_Serialize(
    VlcbNetMsgDccQueryLocoSession msg);

/**
 * @brief Net message VlcbNetMsgDccQueryLocoSession deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccQueryLocoSession_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccQueryLocoSession *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccQueryLocoSession message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccQueryLocoSession_New(
    VlcbDccDecoderAddr decoderAddr, VlcbDccSessionQueryMode mode);

/**
 * @brief Net message VlcbNetMsgDccCommandStationError serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccCommandStationError_Serialize(
    VlcbNetMsgDccCommandStationError msg);

/**
 * @brief Net message VlcbNetMsgDccCommandStationError deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccCommandStationError_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccCommandStationError *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccCommandStationError message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccCommandStationError_New(
    VlcbDccDecoderAddr decoderAddr, uint8_t errorCode);

/**
 * @brief Net message VlcbNetMsgCommandError serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgCommandError_Serialize(VlcbNetMsgCommandError msg);

/**
 * @brief Net message VlcbNetMsgCommandError deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgCommandError_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgCommandError *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgCommandError message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgCommandError_New(VlcbNodeNumber nodeNumber,
                                            uint8_t errorCode);

/**
 * @brief Net message VlcbNetMsgAvailableEventSlots serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgAvailableEventSlots_Serialize(
    VlcbNetMsgAvailableEventSlots msg);

/**
 * @brief Net message VlcbNetMsgAvailableEventSlots deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgAvailableEventSlots_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgAvailableEventSlots *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgAvailableEventSlots message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgAvailableEventSlots_New(VlcbNodeNumber nodeNumber,
                                                   uint8_t availableSlots);

/**
 * @brief Net message VlcbNetMsgQueryNodeVariable serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryNodeVariable_Serialize(
    VlcbNetMsgQueryNodeVariable msg);

/**
 * @brief Net message VlcbNetMsgQueryNodeVariable deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryNodeVariable_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryNodeVariable *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryNodeVariable message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryNodeVariable_New(VlcbNodeNumber nodeNumber,
                                                 uint8_t nodeVariableIndex);

/**
 * @brief Net message VlcbNetMsgQueryLearnedEventByIndex serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryLearnedEventByIndex_Serialize(
    VlcbNetMsgQueryLearnedEventByIndex msg);

/**
 * @brief Net message VlcbNetMsgQueryLearnedEventByIndex deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryLearnedEventByIndex_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryLearnedEventByIndex *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryLearnedEventByIndex message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryLearnedEventByIndex_New(
    VlcbNodeNumber nodeNumber, uint8_t eventIndex);

/**
 * @brief Net message VlcbNetMsgQueryNodeParameterByIndex serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgQueryNodeParameterByIndex_Serialize(
    VlcbNetMsgQueryNodeParameterByIndex msg);

/**
 * @brief Net message VlcbNetMsgQueryNodeParameterByIndex deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryNodeParameterByIndex_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryNodeParameterByIndex *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryNodeParameterByIndex message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryNodeParameterByIndex_New(
    VlcbNodeNumber nodeNumber, uint8_t parameterIndex);

/**
 * @brief Net message VlcbNetMsgLearnedEventCount serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLearnedEventCount_Serialize(
    VlcbNetMsgLearnedEventCount msg);

/**
 * @brief Net message VlcbNetMsgLearnedEventCount deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLearnedEventCount_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLearnedEventCount *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLearnedEventCount message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLearnedEventCount_New(VlcbNodeNumber nodeNumber,
                                                 uint8_t learnedEventCount);

/**
 * @brief Net message VlcbNetMsgSetNodeCanId serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgSetNodeCanId_Serialize(VlcbNetMsgSetNodeCanId msg);

/**
 * @brief Net message VlcbNetMsgSetNodeCanId deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgSetNodeCanId_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgSetNodeCanId *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgSetNodeCanId message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgSetNodeCanId_New(VlcbNodeNumber nodeNumber,
                                            VlcbCanId canId);

/**
 * @brief Net message VlcbNetMsgChangeModuleMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgChangeModuleMode_Serialize(
    VlcbNetMsgChangeModuleMode msg);

/**
 * @brief Net message VlcbNetMsgChangeModuleMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgChangeModuleMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgChangeModuleMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgChangeModuleMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgChangeModuleMode_New(VlcbNodeNumber nodeNumber,
                                                VlcbNetMsgModuleMode mode);

/**
 * @brief Net message VlcbNetMsgQueryServiceDiscovery serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryServiceDiscovery_Serialize(
    VlcbNetMsgQueryServiceDiscovery msg);

/**
 * @brief Net message VlcbNetMsgQueryServiceDiscovery deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryServiceDiscovery_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryServiceDiscovery *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryServiceDiscovery message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryServiceDiscovery_New(VlcbNodeNumber nodeNumber,
                                                     uint8_t serviceIndex);

/**
 * @brief Net message VlcbNetMsgExtOpcode2 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgExtOpcode2_Serialize(VlcbNetMsgExtOpcode2 msg);

/**
 * @brief Net message VlcbNetMsgExtOpcode2 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode2_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgExtOpcode2 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgExtOpcode2 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode2_New(uint8_t opcodeExtension,
                                          uint8_t data[2]);

/**
 * @brief Net message VlcbNetMsgDccSendRawPacket3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccSendRawPacket3_Serialize(
    VlcbNetMsgDccSendRawPacket3 msg);

/**
 * @brief Net message VlcbNetMsgDccSendRawPacket3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSendRawPacket3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSendRawPacket3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSendRawPacket3 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSendRawPacket3_New(uint8_t repeatTimes,
                                                 uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgDccWriteCvByteInOpsMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccWriteCvByteInOpsMode_Serialize(
    VlcbNetMsgDccWriteCvByteInOpsMode msg);

/**
 * @brief Net message VlcbNetMsgDccWriteCvByteInOpsMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccWriteCvByteInOpsMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccWriteCvByteInOpsMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccWriteCvByteInOpsMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccWriteCvByteInOpsMode_New(VlcbDccSessionNr session,
                                                       uint16_t CV,
                                                       uint8_t value);

/**
 * @brief Net message VlcbNetMsgDcWriteCvBitInOpsMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDcWriteCvBitInOpsMode_Serialize(
    VlcbNetMsgDcWriteCvBitInOpsMode msg);

/**
 * @brief Net message VlcbNetMsgDcWriteCvBitInOpsMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDcWriteCvBitInOpsMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDcWriteCvBitInOpsMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDcWriteCvBitInOpsMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDcWriteCvBitInOpsMode_New(VlcbDccSessionNr session,
                                                     uint16_t CV,
                                                     uint8_t value);

/**
 * @brief Net message VlcbNetMsgDccReadCv serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgDccReadCv_Serialize(VlcbNetMsgDccReadCv msg);

/**
 * @brief Net message VlcbNetMsgDccReadCv deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccReadCv_Deserialize(
    const VlcbNetPacket datagramPacket, VlcbNetMsgDccReadCv *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccReadCv message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccReadCv_New(VlcbDccSessionNr session, uint16_t CV,
                                         uint8_t mode);

/**
 * @brief Net message VlcbNetMsgDccCvValue serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgDccCvValue_Serialize(VlcbNetMsgDccCvValue msg);

/**
 * @brief Net message VlcbNetMsgDccCvValue deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccCvValue_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccCvValue *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccCvValue message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccCvValue_New(VlcbDccSessionNr session, uint16_t CV,
                                          uint8_t value);

/**
 * @brief Net message VlcbNetMsgQueryDiagnosticData serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryDiagnosticData_Serialize(
    VlcbNetMsgQueryDiagnosticData msg);

/**
 * @brief Net message VlcbNetMsgQueryDiagnosticData deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryDiagnosticData_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryDiagnosticData *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryDiagnosticData message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryDiagnosticData_New(VlcbNodeNumber nodeNumber,
                                                   uint8_t serviceIndex,
                                                   uint8_t diagnosticCode);

/**
 * @brief Net message VlcbNetMsgSetNodeVariable serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgSetNodeVariable_Serialize(VlcbNetMsgSetNodeVariable msg);

/**
 * @brief Net message VlcbNetMsgSetNodeVariable deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgSetNodeVariable_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgSetNodeVariable *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgSetNodeVariable message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgSetNodeVariable_New(VlcbNodeNumber nodeNumber,
                                               uint8_t nodeVariableIndex,
                                               uint8_t value);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOn serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn_Serialize(
    VlcbNetMsgLongEventAccessoryOn msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOn deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryOn *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryOn message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOff serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff_Serialize(
    VlcbNetMsgLongEventAccessoryOff msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOff deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryOff *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryOff message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgQueryLongEventAccessoryState serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgQueryLongEventAccessoryState_Serialize(
    VlcbNetMsgQueryLongEventAccessoryState msg);

/**
 * @brief Net message VlcbNetMsgQueryLongEventAccessoryState deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryLongEventAccessoryState_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryLongEventAccessoryState *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryLongEventAccessoryState
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryLongEventAccessoryState_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOn serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn_Serialize(
    VlcbNetMsgLongEventAccessoryStateOn msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOn deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryStateOn *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryStateOn message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOff serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff_Serialize(
    VlcbNetMsgLongEventAccessoryStateOff msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOff deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryStateOff *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryStateOff message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgForgetLearnedEvent serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgForgetLearnedEvent_Serialize(
    VlcbNetMsgForgetLearnedEvent msg);

/**
 * @brief Net message VlcbNetMsgForgetLearnedEvent deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgForgetLearnedEvent_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgForgetLearnedEvent *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgForgetLearnedEvent message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgForgetLearnedEvent_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgLegacySetNodeVariable serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLegacySetNodeVariable_Serialize(
    VlcbNetMsgLegacySetNodeVariable msg);

/**
 * @brief Net message VlcbNetMsgLegacySetNodeVariable deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLegacySetNodeVariable_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLegacySetNodeVariable *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLegacySetNodeVariable message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLegacySetNodeVariable_New(VlcbNodeNumber nodeNumber,
                                                     uint8_t nodeVariableIndex,
                                                     uint8_t value);

/**
 * @brief Net message VlcbNetMsgNodeVariableValue serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgNodeVariableValue_Serialize(
    VlcbNetMsgNodeVariableValue msg);

/**
 * @brief Net message VlcbNetMsgNodeVariableValue deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgNodeVariableValue_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgNodeVariableValue *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgNodeVariableValue message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgNodeVariableValue_New(VlcbNodeNumber nodeNumber,
                                                 uint8_t nodeVariableIndex,
                                                 uint8_t value);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOn serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn_Serialize(
    VlcbNetMsgShortEventAccessoryOn msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOn deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryOn *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryOn message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOff serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff_Serialize(
    VlcbNetMsgShortEventAccessoryOff msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOff deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryOff *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryOff message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgQueryShortEventAccessoryState serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgQueryShortEventAccessoryState_Serialize(
    VlcbNetMsgQueryShortEventAccessoryState msg);

/**
 * @brief Net message VlcbNetMsgQueryShortEventAccessoryState deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryShortEventAccessoryState_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryShortEventAccessoryState *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryShortEventAccessoryState
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryShortEventAccessoryState_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgNodeParameterValue serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgNodeParameterValue_Serialize(
    VlcbNetMsgNodeParameterValue msg);

/**
 * @brief Net message VlcbNetMsgNodeParameterValue deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgNodeParameterValue_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgNodeParameterValue *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgNodeParameterValue message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgNodeParameterValue_New(VlcbNodeNumber nodeNumber,
                                                  uint8_t parameterIndex,
                                                  uint8_t value);

/**
 * @brief Net message VlcbNetMsgQueryEventVariable serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryEventVariable_Serialize(
    VlcbNetMsgQueryEventVariable msg);

/**
 * @brief Net message VlcbNetMsgQueryEventVariable deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryEventVariable_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryEventVariable *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryEventVariable message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryEventVariable_New(VlcbNodeNumber nodeNumber,
                                                  uint8_t eventIndex,
                                                  uint8_t value);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOn serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn_Serialize(
    VlcbNetMsgShortEventAccessoryStateOn msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOn deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryStateOn *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryStateOn message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOff serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff_Serialize(
    VlcbNetMsgShortEventAccessoryStateOff msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOff deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryStateOff *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryStateOff
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff_New(VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgExtOpcode3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgExtOpcode3_Serialize(VlcbNetMsgExtOpcode3 msg);

/**
 * @brief Net message VlcbNetMsgExtOpcode3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgExtOpcode3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgExtOpcode3 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode3_New(uint8_t opcodeExtension,
                                          uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgDccSendRawPacket4 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccSendRawPacket4_Serialize(
    VlcbNetMsgDccSendRawPacket4 msg);

/**
 * @brief Net message VlcbNetMsgDccSendRawPacket4 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSendRawPacket4_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSendRawPacket4 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSendRawPacket4 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSendRawPacket4_New(uint8_t repeatTimes,
                                                 uint8_t data[4]);

/**
 * @brief Net message VlcbNetMsgDccWriteCvInServiceMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccWriteCvInServiceMode_Serialize(
    VlcbNetMsgDccWriteCvInServiceMode msg);

/**
 * @brief Net message VlcbNetMsgDccWriteCvInServiceMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccWriteCvInServiceMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccWriteCvInServiceMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccWriteCvInServiceMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccWriteCvInServiceMode_New(VlcbDccSessionNr session,
                                                       uint16_t CV,
                                                       uint8_t mode,
                                                       uint8_t value);

/**
 * @brief Net message VlcbNetMsgHeartbeat serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgHeartbeat_Serialize(VlcbNetMsgHeartbeat msg);

/**
 * @brief Net message VlcbNetMsgHeartbeat deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgHeartbeat_Deserialize(
    const VlcbNetPacket datagramPacket, VlcbNetMsgHeartbeat *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgHeartbeat message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgHeartbeat_New(VlcbNodeNumber sourceNodeNumber,
                                         uint8_t sequenceNr, uint8_t status);

/**
 * @brief Net message VlcbNetMsgServiceDiscoveryResponse serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgServiceDiscoveryResponse_Serialize(
    VlcbNetMsgServiceDiscoveryResponse msg);

/**
 * @brief Net message VlcbNetMsgServiceDiscoveryResponse deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgServiceDiscoveryResponse_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgServiceDiscoveryResponse *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgServiceDiscoveryResponse message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgServiceDiscoveryResponse_New(
    VlcbNodeNumber nodeNumber, uint8_t serviceIndex,
    VlcbServiceType serviceType, uint8_t version);

/**
 * @brief Net message VlcbNetMsgGenericResponse serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgGenericResponse_Serialize(VlcbNetMsgGenericResponse msg);

/**
 * @brief Net message VlcbNetMsgGenericResponse deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgGenericResponse_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgGenericResponse *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgGenericResponse message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgGenericResponse_New(VlcbNodeNumber nodeNumber,
                                               VlcbOpCode opcode,
                                               VlcbServiceType serviceType,
                                               uint8_t result);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOn1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn1_Serialize(
    VlcbNetMsgLongEventAccessoryOn1 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOn1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn1_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryOn1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryOn1 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn1_New(VlcbEvent event,
                                                     uint8_t eventData[1]);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOff1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff1_Serialize(
    VlcbNetMsgLongEventAccessoryOff1 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOff1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff1_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryOff1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryOff1 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff1_New(VlcbEvent event,
                                                      uint8_t eventData[1]);

/**
 * @brief Net message VlcbNetMsgQueryEventVariableByIdex serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgQueryEventVariableByIdex_Serialize(
    VlcbNetMsgQueryEventVariableByIdex msg);

/**
 * @brief Net message VlcbNetMsgQueryEventVariableByIdex deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgQueryEventVariableByIdex_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgQueryEventVariableByIdex *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgQueryEventVariableByIdex message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgQueryEventVariableByIdex_New(
    VlcbEvent event, uint8_t eventVariableIndex);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOn1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn1_Serialize(
    VlcbNetMsgLongEventAccessoryStateOn1 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOn1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn1_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryStateOn1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryStateOn1 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn1_New(VlcbEvent event,
                                                          uint8_t eventData[1]);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOff1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff1_Serialize(
    VlcbNetMsgLongEventAccessoryStateOff1 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOff1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff1_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryStateOff1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryStateOff1
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff1_New(
    VlcbEvent event, uint8_t eventData[1]);

/**
 * @brief Net message VlcbNetMsgEventVariableValue serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgEventVariableValue_Serialize(
    VlcbNetMsgEventVariableValue msg);

/**
 * @brief Net message VlcbNetMsgEventVariableValue deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgEventVariableValue_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgEventVariableValue *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgEventVariableValue message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgEventVariableValue_New(VlcbNodeNumber nodeNumber,
                                                  uint8_t eventIndex,
                                                  uint8_t eventVariableIndex,
                                                  uint8_t eventVariableValue);

/**
 * @brief Net message VlcbNetMsgModuleInfo serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgModuleInfo_Serialize(VlcbNetMsgModuleInfo msg);

/**
 * @brief Net message VlcbNetMsgModuleInfo deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgModuleInfo_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgModuleInfo *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgModuleInfo message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgModuleInfo_New(VlcbNodeNumber nodeNumber,
                                          VlcbManufacturer manufacturer,
                                          uint8_t moduleId,
                                          VlcbModuleFlags flags);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOn1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn1_Serialize(
    VlcbNetMsgShortEventAccessoryOn1 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOn1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn1_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryOn1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryOn1 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn1_New(VlcbEvent event,
                                                      uint8_t eventData[1]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOff1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff1_Serialize(
    VlcbNetMsgShortEventAccessoryOff1 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOff1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff1_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryOff1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryOff1 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff1_New(VlcbEvent event,
                                                       uint8_t eventData[1]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOn1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn1_Serialize(
    VlcbNetMsgShortEventAccessoryStateOn1 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOn1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn1_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryStateOn1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryStateOn1
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn1_New(
    VlcbEvent event, uint8_t eventData[1]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOff1 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff1_Serialize(
    VlcbNetMsgShortEventAccessoryStateOff1 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOff1 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff1_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryStateOff1 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryStateOff1
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff1_New(
    VlcbEvent event, uint8_t eventData[1]);

/**
 * @brief Net message VlcbNetMsgExtOpcode4 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgExtOpcode4_Serialize(VlcbNetMsgExtOpcode4 msg);

/**
 * @brief Net message VlcbNetMsgExtOpcode4 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode4_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgExtOpcode4 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgExtOpcode4 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode4_New(uint8_t opcodeExtension,
                                          uint8_t data[4]);

/**
 * @brief Net message VlcbNetMsgDccSendRawPacket5 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccSendRawPacket5_Serialize(
    VlcbNetMsgDccSendRawPacket5 msg);

/**
 * @brief Net message VlcbNetMsgDccSendRawPacket5 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSendRawPacket5_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSendRawPacket5 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSendRawPacket5 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSendRawPacket5_New(uint8_t repeatTimes,
                                                 uint8_t data[5]);

/**
 * @brief Net message VlcbNetMsgDccWriteCvByteInOpsModeByAddress serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgDccWriteCvByteInOpsModeByAddress_Serialize(
    VlcbNetMsgDccWriteCvByteInOpsModeByAddress msg);

/**
 * @brief Net message VlcbNetMsgDccWriteCvByteInOpsModeByAddress deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccWriteCvByteInOpsModeByAddress_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccWriteCvByteInOpsModeByAddress *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccWriteCvByteInOpsModeByAddress
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccWriteCvByteInOpsModeByAddress_New(
    VlcbDccDecoderAddr decoderAddr, uint16_t CV, uint16_t mode, uint8_t value);

/**
 * @brief Net message VlcbNetMsgDccSendDataToCab serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccSendDataToCab_Serialize(
    VlcbNetMsgDccSendDataToCab msg);

/**
 * @brief Net message VlcbNetMsgDccSendDataToCab deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSendDataToCab_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSendDataToCab *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSendDataToCab message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSendDataToCab_New(VlcbDccDecoderAddr decoderAddr,
                                                uint8_t dataCode,
                                                uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgDiagnosticData serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgDiagnosticData_Serialize(VlcbNetMsgDiagnosticData msg);

/**
 * @brief Net message VlcbNetMsgDiagnosticData deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDiagnosticData_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDiagnosticData *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDiagnosticData message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDiagnosticData_New(VlcbNodeNumber nodeNumber,
                                              uint8_t serviceIndex,
                                              uint8_t diagnosticCode,
                                              uint8_t diagnosticValue);

/**
 * @brief Net message VlcbNetMsgFastClock serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgFastClock_Serialize(VlcbNetMsgFastClock msg);

/**
 * @brief Net message VlcbNetMsgFastClock deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgFastClock_Deserialize(
    const VlcbNetPacket datagramPacket, VlcbNetMsgFastClock *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgFastClock message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgFastClock_New(
    uint8_t minutes, uint8_t hours, VlcbTimeWeekDay weekDay, uint8_t dayOfMonth,
    VlcbTimeMonth month, uint8_t dividerFactor, int8_t temperature);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOn2 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn2_Serialize(
    VlcbNetMsgLongEventAccessoryOn2 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOn2 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn2_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryOn2 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryOn2 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn2_New(VlcbEvent event,
                                                     uint8_t eventData[2]);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOff2 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff2_Serialize(
    VlcbNetMsgLongEventAccessoryOff2 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOff2 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff2_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryOff2 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryOff2 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff2_New(VlcbEvent event,
                                                      uint8_t eventData[2]);

/**
 * @brief Net message VlcbNetMsgTeachEvent serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgTeachEvent_Serialize(VlcbNetMsgTeachEvent msg);

/**
 * @brief Net message VlcbNetMsgTeachEvent deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgTeachEvent_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgTeachEvent *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgTeachEvent message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgTeachEvent_New(VlcbEvent event,
                                          uint8_t eventVariableIndex,
                                          uint8_t eventVariableValue);

/**
 * @brief Net message VlcbNetMsgEventVariableValueInLearnMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgEventVariableValueInLearnMode_Serialize(
    VlcbNetMsgEventVariableValueInLearnMode msg);

/**
 * @brief Net message VlcbNetMsgEventVariableValueInLearnMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgEventVariableValueInLearnMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgEventVariableValueInLearnMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgEventVariableValueInLearnMode
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgEventVariableValueInLearnMode_New(
    VlcbEvent event, uint8_t eventVariableIndex, uint8_t eventVariableValue);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOn2 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn2_Serialize(
    VlcbNetMsgLongEventAccessoryStateOn2 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOn2 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn2_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryStateOn2 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryStateOn2 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn2_New(VlcbEvent event,
                                                          uint8_t eventData[2]);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOff2 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff2_Serialize(
    VlcbNetMsgLongEventAccessoryStateOff2 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOff2 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff2_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryStateOff2 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryStateOff2
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff2_New(
    VlcbEvent event, uint8_t eventData[2]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOn2 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn2_Serialize(
    VlcbNetMsgShortEventAccessoryOn2 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOn2 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn2_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryOn2 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryOn2 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn2_New(VlcbEvent event,
                                                      uint8_t eventData[2]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOff2 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff2_Serialize(
    VlcbNetMsgShortEventAccessoryOff2 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOff2 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff2_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryOff2 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryOff2 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff2_New(VlcbEvent event,
                                                       uint8_t eventData[2]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOn2 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn2_Serialize(
    VlcbNetMsgShortEventAccessoryStateOn2 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOn2 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn2_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryStateOn2 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryStateOn2
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn2_New(
    VlcbEvent event, uint8_t eventData[2]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOff2 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff2_Serialize(
    VlcbNetMsgShortEventAccessoryStateOff2 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOff2 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff2_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryStateOff2 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryStateOff2
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff2_New(
    VlcbEvent event, uint8_t eventData[2]);

/**
 * @brief Net message VlcbNetMsgExtOpcode5 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgExtOpcode5_Serialize(VlcbNetMsgExtOpcode5 msg);

/**
 * @brief Net message VlcbNetMsgExtOpcode5 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode5_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgExtOpcode5 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgExtOpcode5 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode5_New(uint8_t opcodeExtension,
                                          uint8_t data[5]);

/**
 * @brief Net message VlcbNetMsgDccSendRawPacket6 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccSendRawPacket6_Serialize(
    VlcbNetMsgDccSendRawPacket6 msg);

/**
 * @brief Net message VlcbNetMsgDccSendRawPacket6 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccSendRawPacket6_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccSendRawPacket6 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccSendRawPacket6 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccSendRawPacket6_New(uint8_t repeatTimes,
                                                 uint8_t data[6]);

/**
 * @brief Net message VlcbNetMsgDccLocoReport serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgDccLocoReport_Serialize(VlcbNetMsgDccLocoReport msg);

/**
 * @brief Net message VlcbNetMsgDccLocoReport deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccLocoReport_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccLocoReport *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccLocoReport message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccLocoReport_New(
    VlcbDccSessionNr session, VlcbDccDecoderAddr decoderAddr, uint8_t speed_dir,
    VlcbNetMsgDccLocoReportFunctionStates functionStates);

/**
 * @brief Net message VlcbNetMsgModuleName serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgModuleName_Serialize(VlcbNetMsgModuleName msg);

/**
 * @brief Net message VlcbNetMsgModuleName deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgModuleName_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgModuleName *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgModuleName message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgModuleName_New(char moduleName[7]);

/**
 * @brief Net message VlcbNetMsgDccCommandStationStatus serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDccCommandStationStatus_Serialize(
    VlcbNetMsgDccCommandStationStatus msg);

/**
 * @brief Net message VlcbNetMsgDccCommandStationStatus deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDccCommandStationStatus_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDccCommandStationStatus *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDccCommandStationStatus message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDccCommandStationStatus_New(
    VlcbNodeNumber nodeNumber,
    VlcbNetMsgDccCommandStationStatusErrorFlags flags,
    VlcbModuleVersion moduleVersion);

/**
 * @brief Net message VlcbNetMsgEventAck serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgEventAck_Serialize(VlcbNetMsgEventAck msg);

/**
 * @brief Net message VlcbNetMsgEventAck deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgEventAck_Deserialize(
    const VlcbNetPacket datagramPacket, VlcbNetMsgEventAck *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgEventAck message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgEventAck_New(VlcbNodeNumber nodeNumber,
                                        VlcbOpCode acknowledgedOpcode,
                                        VlcbEvent event);

/**
 * @brief Net message VlcbNetMsgExtendedServiceDiscoveryResponse serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgExtendedServiceDiscoveryResponse_Serialize(
    VlcbNetMsgExtendedServiceDiscoveryResponse msg);

/**
 * @brief Net message VlcbNetMsgExtendedServiceDiscoveryResponse deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgExtendedServiceDiscoveryResponse_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgExtendedServiceDiscoveryResponse *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgExtendedServiceDiscoveryResponse
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgExtendedServiceDiscoveryResponse_New(
    VlcbNodeNumber nodeNumber, uint8_t serviceIndex,
    VlcbServiceType serviceType, uint8_t serviceData[3]);

/**
 * @brief Net message VlcbNetMsgStreamPacket serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgStreamPacket_Serialize(VlcbNetMsgStreamPacket msg);

/**
 * @brief Net message VlcbNetMsgStreamPacket deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgStreamPacket_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgStreamPacket *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgStreamPacket message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgStreamPacket_New(uint8_t streamId,
                                            uint8_t sequenceNr,
                                            VlcbNetMsgStreamPacketPayload data);

/**
 * @brief Net message VlcbNetMsgNodeParametersReport serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgNodeParametersReport_Serialize(
    VlcbNetMsgNodeParametersReport msg);

/**
 * @brief Net message VlcbNetMsgNodeParametersReport deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgNodeParametersReport_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgNodeParametersReport *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgNodeParametersReport message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgNodeParametersReport_New(uint8_t params[7]);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOn3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn3_Serialize(
    VlcbNetMsgLongEventAccessoryOn3 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOn3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryOn3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryOn3 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOn3_New(VlcbEvent event,
                                                     uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOff3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff3_Serialize(
    VlcbNetMsgLongEventAccessoryOff3 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryOff3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryOff3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryOff3 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryOff3_New(VlcbEvent event,
                                                      uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgLearnedEventResponse serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgLearnedEventResponse_Serialize(
    VlcbNetMsgLearnedEventResponse msg);

/**
 * @brief Net message VlcbNetMsgLearnedEventResponse deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLearnedEventResponse_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLearnedEventResponse *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLearnedEventResponse message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLearnedEventResponse_New(VlcbNodeNumber nodeNumber,
                                                    VlcbEvent event,
                                                    uint8_t eventIndex);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOn3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn3_Serialize(
    VlcbNetMsgLongEventAccessoryStateOn3 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOn3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryStateOn3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryStateOn3 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOn3_New(VlcbEvent event,
                                                          uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOff3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff3_Serialize(
    VlcbNetMsgLongEventAccessoryStateOff3 msg);

/**
 * @brief Net message VlcbNetMsgLongEventAccessoryStateOff3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgLongEventAccessoryStateOff3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgLongEventAccessoryStateOff3
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgLongEventAccessoryStateOff3_New(VlcbEvent event,
                                                           uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgTeachEventByIndex serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgTeachEventByIndex_Serialize(
    VlcbNetMsgTeachEventByIndex msg);

/**
 * @brief Net message VlcbNetMsgTeachEventByIndex deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgTeachEventByIndex_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgTeachEventByIndex *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgTeachEventByIndex message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgTeachEventByIndex_New(VlcbEvent event,
                                                 uint8_t eventIndex,
                                                 uint8_t eventVariableIndex,
                                                 uint8_t eventVariableValue);

/**
 * @brief Net message VlcbNetMsgDataEventAccessory serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDataEventAccessory_Serialize(
    VlcbNetMsgDataEventAccessory msg);

/**
 * @brief Net message VlcbNetMsgDataEventAccessory deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDataEventAccessory_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDataEventAccessory *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDataEventAccessory message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDataEventAccessory_New(VlcbNodeNumber nodeNumber,
                                                  uint8_t data[5]);

/**
 * @brief Net message VlcbNetMsgNodeAccessoryData serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgNodeAccessoryData_Serialize(
    VlcbNetMsgNodeAccessoryData msg);

/**
 * @brief Net message VlcbNetMsgNodeAccessoryData deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgNodeAccessoryData_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgNodeAccessoryData *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgNodeAccessoryData message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgNodeAccessoryData_New(VlcbNodeNumber nodeNumber,
                                                 uint8_t data[5]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOn3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn3_Serialize(
    VlcbNetMsgShortEventAccessoryOn3 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOn3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryOn3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryOn3 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOn3_New(VlcbEvent event,
                                                      uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOff3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff3_Serialize(
    VlcbNetMsgShortEventAccessoryOff3 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryOff3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryOff3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryOff3 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryOff3_New(VlcbEvent event,
                                                       uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgDeviceDataEventShortMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDeviceDataEventShortMode_Serialize(
    VlcbNetMsgDeviceDataEventShortMode msg);

/**
 * @brief Net message VlcbNetMsgDeviceDataEventShortMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDeviceDataEventShortMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDeviceDataEventShortMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDeviceDataEventShortMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDeviceDataEventShortMode_New(uint16_t devideNumber,
                                                        uint8_t data[5]);

/**
 * @brief Net message VlcbNetMsgDeviceDataShortMode serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket vlcb_net_msg_VlcbNetMsgDeviceDataShortMode_Serialize(
    VlcbNetMsgDeviceDataShortMode msg);

/**
 * @brief Net message VlcbNetMsgDeviceDataShortMode deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgDeviceDataShortMode_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgDeviceDataShortMode *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgDeviceDataShortMode message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgDeviceDataShortMode_New(uint16_t devideNumber,
                                                   uint8_t data[5]);

/**
 * @brief Net message VlcbNetMsgWriteData serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgWriteData_Serialize(VlcbNetMsgWriteData msg);

/**
 * @brief Net message VlcbNetMsgWriteData deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgWriteData_Deserialize(
    const VlcbNetPacket datagramPacket, VlcbNetMsgWriteData *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgWriteData message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgWriteData_New(uint16_t devideNumber,
                                         uint8_t data[5]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOn3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn3_Serialize(
    VlcbNetMsgShortEventAccessoryStateOn3 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOn3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryStateOn3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryStateOn3
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOn3_New(VlcbEvent event,
                                                           uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOff3 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff3_Serialize(
    VlcbNetMsgShortEventAccessoryStateOff3 msg);

/**
 * @brief Net message VlcbNetMsgShortEventAccessoryStateOff3 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff3_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgShortEventAccessoryStateOff3 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgShortEventAccessoryStateOff3
 * message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgShortEventAccessoryStateOff3_New(VlcbEvent event,
                                                            uint8_t data[3]);

/**
 * @brief Net message VlcbNetMsgExtOpcode6 serializer
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 * @return VlcbNetPacket serialized message into a datagram packet
 */
VlcbNetPacket
vlcb_net_msg_VlcbNetMsgExtOpcode6_Serialize(VlcbNetMsgExtOpcode6 msg);

/**
 * @brief Net message VlcbNetMsgExtOpcode6 deserializer
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode6_Deserialize(
    const VlcbNetPacket datagramPacket,
    VlcbNetMsgExtOpcode6 *const msg);

/**
 * @brief Construct new instance of VlcbNetMsgExtOpcode6 message
 *
 * @return Whether the construction was successful
 * @retval 0 successful packet construction
 */
int vlcb_net_msg_VlcbNetMsgExtOpcode6_New(uint8_t opcodeExtension,
                                          uint8_t data[6]);
