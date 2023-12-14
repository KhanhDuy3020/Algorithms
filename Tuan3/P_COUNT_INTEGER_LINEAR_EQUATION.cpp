#include<bits/stdc++.h>
using namespace std;

int n, M;
int T = 0,result = 0;
int arr[100];
int X[100];

// void printSol() {
//     for (int i = 1; i <= n; i++)
//         cout << X[i] << " ";
//     cout << endl;
// }

bool check(int v, int k) {
    T += v * arr[k];
    if (k < n) {
        return T <= M;
    } else {
        return T == M;
    }
}

void Try(int k) {
    for (int v = 1; v <= M - T; v++) {
        if (check(v, k)) {
            X[k] = v;
            if (k == n) {
                // printSol();
                result++;
            } else {
                Try(k + 1);
            }
            T -= v * arr[k];
        } else {
            T -= v * arr[k];
        }
    }
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    Try(1);
    cout<<result;
    return 0;
}
