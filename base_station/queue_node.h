//
// Created by Liam Kelly on 2/24/19.
//

#ifndef UPES_QUEUE_NODE_H
#define UPES_QUEUE_NODE_H

template <class T>
class QueueNode {

public:

    QueueNode(T v) : val(v) {}

    T val;
    QueueNode* next;
};

#endif //UPES_QUEUE_NODE_H

