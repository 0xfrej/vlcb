/**
 * @brief {{.Serialize.Brief}}
 *
 * Serialization assumes the packet is properly constructed and does no further
 * checks!
 */
VlcbNetPacketDatagram vlcb_net_msg_{{.Message.Name}}_Serialize({{.Message.Type}} msg);

/**
 * @brief {{.Deserialize.Brief}}
 *
 * @return Whether the deserialization was successful
 * @retval 0 successful deserialization
 * @retval -1 invalid data packet
 */
int vlcb_net_msg_{{.Message.Name}}_Deserialize(
    const VlcbNetPacketDatagram datagramPacket, {{.Message.Type}} *const msg);

/**
 * @brief {{.New.Brief}}
 */
void vlcb_net_msg_{{.Message.Name}}_New({{}});

