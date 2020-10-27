//
// Created by Sam on 10/26/2020.
//

#ifndef STACK_AND_QUEUE_TEMPLATE_QUEUE_H
#define STACK_AND_QUEUE_TEMPLATE_QUEUE_H

#include <string>
#include "LinkedList.h"

using namespace std;

class Queue {
public:
    Queue();

    bool isEmpty();

    void push(string value);
    string pop();

private:
    LinkedList list;
};

#endif //STACK_AND_QUEUE_TEMPLATE_QUEUE_H
