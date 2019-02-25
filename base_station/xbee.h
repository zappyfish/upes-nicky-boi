//
// Created by Liam Kelly on 2/24/19.
//

#ifndef NICK_CODE_XBEE_H
#define NICK_CODE_XBEE_H

#include "Arduino.h"

class Xbee {

public:

    Xbee();
    ~Xbee();

    void send(char *str, int length);
    int checkForData(char *buffer, int maxSize);

};

#endif //NICK_CODE_XBEE_H
