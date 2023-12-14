#include <bits/stdc++.h>

using namespace std;

int n, Q, num, dem = 0;

int main()
{
    cin >> n >> Q;
    unordered_map<int,int> map;

    for (int i = 0; i< n;i++) {
        cin >> num;
        if (map.find(Q-num) != map.end()) {
            dem+=map[Q-num];
        }
        map[num]++;
    }
    cout << dem << endl;
    return 0;
}
