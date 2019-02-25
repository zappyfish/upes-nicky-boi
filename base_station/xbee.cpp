//
// Created by Liam Kelly on 2/24/19.
//

#include "xbee.h"

Xbee::Xbee() {
    Serial2.begin(9600);
}

Xbee::~Xbee() {}

void Xbee::send(char *str, int length) {
    for (int i = 0; i < length; i++) {
        Serial.write(str[i]);
    }
}

int Xbee::checkForData(char *buffer, int maxSize) {
    int received = Serial.available();

    for (int i = 0; i < received && i < maxSize; i++) {
        buffer[i] = Serial.read();
    }

    return received;
}