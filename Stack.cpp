//
// Created by Sam on 10/26/2020.
//

#include "Stack.h"

using namespace std;

Stack::Stack() {
    LinkedList list();
}

bool Stack::isEmpty() {
    if(list.getLength() == 0) {
        return true;
    }
    return false;
}

void Stack::push(string value) {
    list.addItemToFront(new LinkedListItem(value));
}

string Stack::pop() {
    LinkedListItem *item = list.removeFirstItem();
    if(item == nullptr) {
        return "";
    }
    return item->getItem();
}