//
// Created by Liam Kelly on 2/23/19.
//

#ifndef UPES_QUEUE_H
#define UPES_QUEUE_H

#include "queue_node.h"

template <class T>
class Queue {

public:

    Queue() : first(nullptr) {}
    ~Queue() {
        while (first != nullptr) {
            auto tmp = first;
            first = first->next;
            delete tmp;
        }
    }

    QueueNode<T>* first;
    QueueNode<T>* last;

    T dequeue() {
        QueueNode<T>* tmp = first;
        first = first->next;
        T ret = tmp->val;
        delete tmp;
        return ret;
    }

    void enqueue(T val) {
        auto next = new QueueNode<T>(val);
        if (first == nullptr) {
            first = next;
            last = first;
        } else {
            last->next = next;
            last = next;
        }
        last ->next = nullptr;
    }

    bool empty() {
        return first == nullptr;
    }


};

#endif //UPES_QUEUE_H
