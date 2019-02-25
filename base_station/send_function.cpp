//
// Created by Liam Kelly on 2/23/19.
//

#include "send_function.h"


SendFunction::SendFunction(void (*action)(char *packetString, int length)) : mAction(action){

}

SendFunction::~SendFunction() {}

void SendFunction::send(char* packetString, int length) {
    mAction(packetString, length);
}
