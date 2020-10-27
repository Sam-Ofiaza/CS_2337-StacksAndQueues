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
        foo.message = inputLine.substr(1);

        tasks.push_back(foo);
        //cout << "Timestamp: " << foo.timestamp << ", Message: " << foo.message << endl;
    }

    Queue test1();
    Stack test2();

    while(!(test1.isEmpty()) || !(test2.isEmpty()))

    }
}