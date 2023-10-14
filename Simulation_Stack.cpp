//C++ 
#include <bits/stdc++.h> 

using namespace std;

int main() {
    stack<int> stack;
    string command;
    int value;
    while (cin >> command) {
        if (command == "#") {
            break;
        }
        if (command == "PUSH") {
            cin >> value;
            stack.push(value);
        } else if  (command == "POP") {
            cout << stack.top() << "\n";
            stack.pop();
        }
    }
    return 0;
}