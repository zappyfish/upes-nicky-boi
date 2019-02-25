//
// Created by Liam Kelly on 2/23/19.
//

#ifndef UPES_LIST_H
#define UPES_LIST_H

#include "node.h"
#include "Arduino.h"

template <class T>
class List {

public:

    List() : first(nullptr), size(0) {}
    ~List() {
        while (first != nullptr) {
            auto tmp = first;
            first = first->next;
            delete tmp;
        }
    }

    Node<T>* first;
    Node<T>* last;

    Node<T>* find(char *key) {
        if (first != nullptr) {
            auto tmp = first;
            while (tmp != nullptr) {
                if (!strcmp(key, tmp->mKey)) {
                    return tmp;
                }
                tmp = tmp->next;
            }
        }
        return nullptr;
    }

    void add(char* key, T val) {
        if (first == nullptr) {
            first = new Node<T>(key, val);
            last = first;
        } else {
            auto next = new Node<T>(key, val);
            last->next = next;
            last = next;
        }
        size++;
        last->next = nullptr;
    }

    int size;

};


#endif //UPES_LIST_H
