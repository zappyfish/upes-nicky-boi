//
// Created by Liam Kelly on 2/23/19.
//

#ifndef UPES_RECEIVE_FUNCTION_H
#define UPES_RECEIVE_FUNCTION_H

#include "packet.h"

class ReceiveFunction {

public:

    ReceiveFunction(char *name, void (*action)(Packet*));
    ReceiveFunction(ReceiveFunction &toCopy);
    ~ReceiveFunction();

    ReceiveFunction& operator=(const ReceiveFunction &rhs);

    void receive(Packet &packet);

private:

    char  *mName;
    void (*mAction)(Packet*);

};


#endif //UPES_RECEIVE_FUNCTION_H
