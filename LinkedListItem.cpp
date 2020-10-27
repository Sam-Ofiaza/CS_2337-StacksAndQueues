//
// Created by Sam on 10/13/2020.
//

#include "LinkedListItem.h"

LinkedListItem::LinkedListItem(string value)
        : value(value), next(nullptr), prev(nullptr) {}

string LinkedListItem::getItem() {
    return value;
}

LinkedListItem* LinkedListItem::getNextItem() {
    return next;
}

LinkedListItem* LinkedListItem::getPreviousItem() {
    return prev;
}

void LinkedListItem::setNextItem(LinkedListItem *next){
    this->next = next;
}

void LinkedListItem::setPreviousItem(LinkedListItem *prev) {
    this->prev = prev;
}
