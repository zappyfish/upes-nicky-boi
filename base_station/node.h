//
// Created by Liam Kelly on 2/23/19.
//

#ifndef UPES_NODE_H
#define UPES_NODE_H

template <class T>
class Node {

public:

    Node(char *key, T val) : mKey(key), mVal(val) {

    }

    char *mKey;
    T mVal;
    Node *next;

};


#endif //UPES_NODE_H
