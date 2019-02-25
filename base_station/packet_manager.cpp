//
// Created by Liam Kelly on 2/23/19.
//

#include "packet_manager.h"

PacketManager::PacketManager() {}

PacketManager::~PacketManager() {}

void PacketManager::setPacketCallback(char* packetName, ReceiveFunction *function) {
    mReceiveFunctions.add(packetName, function);
}

void PacketManager::handleData(char* receivedData, int length) {
    size_t packetsToParse = 0;
    for (int i = 0; i < length; i++) {
        char c = receivedData[i];
        mReceivedData.enqueue(c);
        if (c == Packet::PACKET_END) {
            packetsToParse++;
        }
    }

    for (size_t i = 0; i < packetsToParse; i++) {
        parseForPacket();
    }
}

void PacketManager::parseForPacket() {
    List<char*> params;
    LiamString key;
    LiamString val;
    LiamString packetName;
    bool gotName = false;
    bool dataIsKey = true;

    char c;

    while (!mReceivedData.empty()) {
        c = mReceivedData.dequeue();

        if (!gotName) {
            if (c == Packet::PACKET_START) {
                gotName = true;
            } else {
                packetName.add(c);
            }
        } else {
            switch(c) {
                case Packet::PACKET_END:
                    params.add(key.getDataAndClear(), val.getDataAndClear());
                    handleCallback(packetName.data, params);
                    Serial.print("done");
                    return;
                case Packet::PACKET_DELIMITER:
                    if (dataIsKey) {
                        val.clear();
                    } else {
                        params.add(key.getDataAndClear(), val.getDataAndClear());
                        key.clear();
                    }
                    dataIsKey = !dataIsKey;
                    break;
                default:
                    if (dataIsKey) {
                        key.add(c);
                    } else {
                        val.add(c);
                    }
                    break;
            }
        }
    }
}

void PacketManager::handleCallback(char* packetName, List<char*> &params) {
    auto node = mReceiveFunctions.find(packetName);
    if (node != nullptr) {
        Packet packet(packetName);
        auto tmp = params.first;
        while (tmp != nullptr) {
            packet.addParam(tmp->mKey, tmp->mVal);
            tmp = tmp->next;
        }
        mReceiveFunctions.find(packetName)->mVal->receive(packet);
        // now clean up
        tmp = params.first;
        while (tmp != nullptr) {
            delete[] tmp->mKey;
            delete[] tmp->mVal;
            tmp = tmp->next;
        }
    }
}

void PacketManager::sendPacket(Packet &packet) {
    int length;
    char *serialized = packet.serialize(&length);
    mXbeeLink.send(serialized, length);
    delete[] serialized;
}

void PacketManager::checkForPackets() {
    int bytesReceived = mXbeeLink.checkForData(mReadBuffer, MAX_BUFFER_SIZE);
    if (bytesReceived > 0) {
        handleData(mReadBuffer, bytesReceived);
    }
}
