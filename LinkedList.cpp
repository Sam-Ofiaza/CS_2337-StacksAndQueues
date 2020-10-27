//
// Created by Sam on 10/13/2020.
//

#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

LinkedListItem *LinkedList::getFirstItem() {
    return head;
}

LinkedListItem *LinkedList::getItemAt(int index) {
    if(index < 0 || index == length)
        throw LinkedListException();
    LinkedListItem *current = head;
    for(int i = 0; i < length; i++) {
        if (i == index)
            return current;
        current = head->getNextItem();
    }
}

LinkedListItem *LinkedList::getLastItem() {
    return tail;
}

int LinkedList::getLength() {
    return length;
}

void LinkedList::incrementLength() {
    length++;
}

void LinkedList::decrementLength() {
    length--;
}

void LinkedList::addItemToFront(LinkedListItem *item) {
    if (item == nullptr)
        throw LinkedListException();
    else if (length == 0) {
        head = item;
        tail = item;
        head->setNextItem(nullptr);     //just in case a node with existing
        head->setPreviousItem(nullptr); //pointers was added
    }
    else {
        item->setNextItem(head);
        item->setPreviousItem(nullptr);
        head->setPreviousItem(item);
        head = item;
    }

    incrementLength();
}

void LinkedList::addItemAt(int index, LinkedListItem *item) {
    if(index < 0 || index > length)
        throw LinkedListException();
    else if(index == 0)
        addItemToFront(item);
    else if(index == length)
        addItemToBack(item);
    else{
        item->setNextItem(getItemAt(index));
        item->setPreviousItem(getItemAt(index-1));
        getItemAt(index)->setPreviousItem(item);
        getItemAt(index-1)->setNextItem(item);
        incrementLength();
    }
}

void LinkedList::addItemToBack(LinkedListItem *item) {
    if(item == nullptr)
        throw LinkedListException();
    else if(length == 0){
        tail = item;
        head = item;
        tail->setNextItem(nullptr);
        tail->setPreviousItem(nullptr);
    }
    else{
        item->setPreviousItem(tail);
        item->setNextItem(nullptr);
        tail->setNextItem(item);
        tail = item;
    }

    incrementLength();
}

LinkedListItem *LinkedList::removeFirstItem() {
    LinkedListItem *current = head;
    if(length == 0)
        return nullptr;
    else if(length == 1){
        head = nullptr;
        tail = nullptr;
        decrementLength();
        return current;
    }
    head = head->getNextItem();
    head->setPreviousItem(nullptr);
    decrementLength();
    return current;
}

LinkedListItem *LinkedList::removeItemAt(int index) {
    if(index == 0)
        return removeFirstItem();
    else if(index == length-1)
        return removeLastItem();
    LinkedListItem *current = getItemAt(index);
    getItemAt(index-1)->setNextItem(getItemAt(index+1));
    getItemAt(index+1)->setPreviousItem(getItemAt(index-1));
    decrementLength();
    return current;
}

LinkedListItem *LinkedList::removeLastItem() {
    LinkedListItem *current = tail;
    if(length == 0)
        return nullptr;
    else if(length == 1){
        tail = nullptr;
        head = nullptr;
        decrementLength();
        return current;
    }
    tail = tail->getPreviousItem();
    tail->setNextItem(nullptr);
    decrementLength();
    return current;
}

void LinkedList::printList() {
    for (int i = 0; i < length; i++) {
        if(i == length-1)
            cout << getItemAt(i)->getItem() << " " << endl;
        else
            cout << getItemAt(i)->getItem() << " ";
    }
}

void LinkedList::printListBackwards() {
    for (int i = length-1; i >= 0; i--) {
        if(i == 0)
            cout << getItemAt(i)->getItem() << " " << endl;
        else
            cout << getItemAt(i)->getItem() << " ";
    }
}