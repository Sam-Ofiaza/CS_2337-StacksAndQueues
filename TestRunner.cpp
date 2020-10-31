//
// Created by Sam on 10/26/2020.
//

#include <iostream>
#include <vector>
#include "TestRunner.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

struct task{
    int timestamp;
    string message;
};

void TestRunner::runTest() {
    vector<task> tasks; // Vector stores all input
    int lines;
    cin >> lines;
    for(int i = 0; i < lines; i++) {
        task foo;

        cin >> foo.timestamp;

        string inputLine;
        getline(cin, inputLine);
        foo.message = inputLine.substr(0); // Sets foo.message to the entire input line
                                               // minus the first string index/timestamp

        tasks.push_back(foo);
    }

    Queue queue;
    Stack stack;
    int timestamp = 0; //Timestamp iterator
    string savedQueuePops = "Queue process order:\n";
    string savedStackPops = "Stack process order:\n";

    while(!tasks.empty() || (!queue.isEmpty() && !stack.isEmpty())) {
        for(int i = 0; i < tasks.size(); i++){
            if(tasks.at(i).timestamp == timestamp){
                queue.push(tasks.at(i).message); // Adds matching timestamp to queue
                stack.push(tasks.at(i).message); // and stack
                tasks.erase(tasks.begin()+i); // Removes vector item at index i
                tasks.shrink_to_fit(); // Resizes array to adjust vector length
                i--; // Prevents for loop index incrementation to match to the correct index
                     // at the item after the removed index, which is now the current index
            }
        }
        string queuePop = queue.pop();
        string stackPop = stack.pop();
        if(queuePop != "") { // Queue and Stack return "" if popped node is nullptr
            savedQueuePops += queuePop + "\n";
        }
        if(stackPop != "") {
            savedStackPops += stackPop + "\n";
        }

        timestamp++;
    }

    cout << savedStackPops << savedQueuePops;
}