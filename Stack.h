//
// Created by Sam on 10/26/2020.
//

#ifndef STACK_AND_QUEUE_TEMPLATE_STACK_H
#define STACK_AND_QUEUE_TEMPLATE_STACK_H

#include <string>
#include "LinkedList.h"

using namespace std;

class Stack {
public:
    Stack();

    bool isEmpty();

    void push(string value);
    string pop();

    void print();

private:
    LinkedList list;
};

#endif //STACK_AND_QUEUE_TEMPLATE_STACK_H
