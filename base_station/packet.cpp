//
// Created by Liam Kelly on 2/23/19.
//

#include "packet.h"

Packet::Packet(char* packetName) : mPacketName(packetName) {
}

Packet::~Packet() {}

void Packet::addParam(char* key, char* val) {
    mParams.add(key, val);
}

char* Packet::getName() {
    return mPacketName;
}

char* Packet::getParam(char *key) {
    return mParams.find(key)->mVal;
}

char* Packet::serialize(int *length) {
    LiamString toSend;
    toSend.add(getName());
    toSend.add(PACKET_START);

    auto tmp = mParams.first;

    while (tmp != nullptr) {
        toSend.add(tmp->mKey);
        toSend.add(PACKET_DELIMITER);
        toSend.add(tmp->mVal);
        tmp = tmp->next;
        if (tmp != nullptr) {
            toSend.add(PACKET_DELIMITER);
        }
    }
    toSend.add(PACKET_END);
    char *result = new char[toSend.curLength + 1];
    for (int i = 0; i < toSend.curLength; i++) {
        result[i] = toSend.data[i];
    }
    *length = toSend.curLength;
    return result;
}

