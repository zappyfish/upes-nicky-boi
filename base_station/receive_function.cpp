//
// Created by Liam Kelly on 2/23/19.
//

#include "receive_function.h"

ReceiveFunction::ReceiveFunction(char *name, void (*action)(Packet*)) : mName(name), mAction(action){}

ReceiveFunction::ReceiveFunction(ReceiveFunction &toCopy) : mName(toCopy.mName), mAction(toCopy.mAction) {}

ReceiveFunction::~ReceiveFunction() {}

ReceiveFunction& ReceiveFunction::operator=(const ReceiveFunction &rhs) {
    mName = rhs.mName;
    mAction = rhs.mAction;
    return *this;
}

void ReceiveFunction::receive(Packet &packet) {
    mAction(&packet);
}