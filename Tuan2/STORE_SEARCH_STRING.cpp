#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> str;
    string input;
    while (true)
    {
        cin >> input;
        if (input == "*")
        {
            break;
        }
        str.insert(input);
    }
    while (true)
    {
        cin >> input;
        if (input == "***")
        {
            break;
        }
        if (input == "find")
        {
            string substr;
            cin >> substr;
            if (str.find(substr) != str.end())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        if (input == "insert")
        {
            string substr;
            cin >> substr;
            if (str.find(substr) != str.end())
            {
                cout << 0 << "\n";
            }
            else
            {
                str.insert(substr);
                cout << 1 << "\n";
            }
        }
    }
    return 0;
}