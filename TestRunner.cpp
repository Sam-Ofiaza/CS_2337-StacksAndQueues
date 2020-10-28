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

//Can we use vectors?
//Will we add to the queue/stack before while loop?

void TestRunner::runTest() {
    vector<task> tasks;
    int lines;
    cin >> lines;
    for(int i = 0; i < lines; i++) {
        task foo;

        cin >> foo.timestamp;

        string inputLine;
        getline(cin, inputLine);
        foo.message = inputLine.substr(0);

        tasks.push_back(foo);
    }

    Queue queue;
    Stack stack;
    int timestamp = 0;
    string savedQueuePops = "Queue process order:\n";
    string savedStackPops = "Stack process order:\n";

    while(!tasks.empty() || !queue.isEmpty() || !stack.isEmpty()) {
        for(int i = 0; i < tasks.size(); i++){
            if(tasks.at(i).timestamp == timestamp){
                queue.push(tasks.at(i).message);
                stack.push(tasks.at(i).message);
                tasks.erase(tasks.begin()+i);
                tasks.shrink_to_fit();
                i--;
            }
        }
        savedQueuePops += queue.pop() + "\n";
        savedStackPops += stack.pop() + "\n";

        timestamp++;
    }

    cout << savedStackPops << savedQueuePops;
}