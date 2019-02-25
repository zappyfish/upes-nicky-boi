//
// Created by Liam Kelly on 2/23/19.
//

#ifndef UPES_PACKET_H
#define UPES_PACKET_H

#include "list.h"
#include "liamstring.h"

class Packet {

public:

    static const char PACKET_START = ':';
    static const char PACKET_DELIMITER = ',';
    static const char PACKET_END = ';';

    Packet(char* packetName);
    ~Packet();

    char* serialize(int *length);

    void addParam(char* key, char* val);

    char* getParam(char* key);

    char* getName();

    static const char* NOT_FOUND;

private:

    char* mPacketName;
    List<char*> mParams;
};


#endif //UPES_PACKET_H
