//C++ 
#include <bits/stdc++.h> 

using namespace std;

int main() 
{ 
    queue<int> queue;
    string command;
    int value;
    while (cin >> command) {
        if (command == "#") {
            break;
        }
        if (command == "PUSH") {
            cin >> value;
            queue.push(value);
        } else if (command == "POP") {
            if (queue.empty()) {
                cout << "NULL" << "\n";
            } else {
                cout << queue.front() << "\n";
                queue.pop();
            }
        }
    }
    
    return 0;
}