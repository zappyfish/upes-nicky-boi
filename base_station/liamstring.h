//
// Created by Liam Kelly on 2/23/19.
//

#ifndef UPES_STRING_H
#define UPES_STRING_H

#include <cstring>

#define START_LENGTH 10

class LiamString {

public:

    LiamString() : curLength(0), maxLength(START_LENGTH) {
        data = new char[START_LENGTH];
        data[0] = '\0';
    }
    ~LiamString() {
        delete data;
    }

    void add(char c) {
        if (curLength + 1 >= maxLength) {
            maxLength += START_LENGTH;
            char *tmp = new char[maxLength];
            for (int i = 0; i < curLength; i++) {
                tmp[i] = data[i];
            }
            char *del = data;
            data = tmp;
            delete[] del;
        }
        data[curLength++] = c;
        data[curLength] = '\0';
    }

    void add(char *str) {
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            add(str[i]);
        }
    }

    char *getDataAndClear() {
        char *ret = new char[curLength + 1];
        for (int i = 0; i < curLength; i++) {
            ret[i] = data[i];
        }
        ret[curLength] = '\0';
        clear();
        return ret;
    }

    int get_length() {
        return curLength;
    }

    void clear() {
        curLength = 0;
        data[curLength] = '\0';
    }

    char *data;
    int curLength;
    int maxLength;
};

#endif //UPES_STRING_H
