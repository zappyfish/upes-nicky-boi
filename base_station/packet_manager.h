//
// Created by Liam Kelly on 2/23/19.
//

#ifndef UPES_PACKET_MANAGER_H
#define UPES_PACKET_MANAGER_H

#include "packet.h"
#include "receive_function.h"
#include "list.h"
#include "queue.h"
#include "liamstring.h"
#include "xbee.h"

#define MAX_BUFFER_SIZE 100

class PacketManager {

public:

    PacketManager();
    ~PacketManager();

    void sendPacket(Packet &packet);
    void setPacketCallback(char* packetName, ReceiveFunction *function);
    void handleData(char* receivedData, int length);
    void checkForPackets();

private:

    List<ReceiveFunction *> mReceiveFunctions;
    Queue<char> mReceivedData;
    Xbee mXbeeLink;

    char mReadBuffer[MAX_BUFFER_SIZE];

    void parseForPacket();
    void handleCallback(char* packetName, List<char*> &params);

};



#endif //UPES_PACKET_MANAGER_H
