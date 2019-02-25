//
// Created by Liam Kelly on 2/23/19.
//

#ifndef UPES_SEND_FUNCTION_H
#define UPES_SEND_FUNCTION_H

#include "packet.h"

class SendFunction {

public:

    SendFunction(void (*action)(char*, int));
    ~SendFunction();

    void send(char *packetString, int length);

private:

    void (*mAction)(char*, int);
};


#endif //UPES_SEND_FUNCTION_H
