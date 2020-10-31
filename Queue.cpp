//
// Created by Sam on 10/26/2020.
//

#include "Queue.h"

using namespace std;

Queue::Queue() {
    LinkedList list();
}

bool Queue::isEmpty() {
    if(list.getLength() == 0) {
        return true;
    }
    return false;
}

void Queue::push(string value) {
    list.addItemToFront(new LinkedListItem(value));
}

string Queue::pop() {
    LinkedListItem *item = list.removeLastItem();
    if(item == nullptr) {
        return "";
    }
    return item->getItem();
}

