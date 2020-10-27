//
// Created by Sam on 10/13/2020.
//

#ifndef LINKED_LIST_SAMPLE_LINKEDLISTITEM_H
#define LINKED_LIST_SAMPLE_LINKEDLISTITEM_H

#include <string>

using namespace std;

class LinkedListItem {
public:
    LinkedListItem(string value);

    string getItem();
    LinkedListItem* getNextItem();
    LinkedListItem* getPreviousItem();
    void setNextItem(LinkedListItem *next);
    void setPreviousItem(LinkedListItem *prev);

private:
    string value;
    LinkedListItem *next;
    LinkedListItem *prev;
};

#endif //LINKED_LIST_SAMPLE_LINKEDLISTITEM_H
