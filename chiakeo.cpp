#include<bits/stdc++.h>
using namespace std;

int n,M;
int T = 0;
int X[100];


void printSol() {
    for (int i = 1; i <= n; i++) 
        cout << X[i] << " ";
    printf("\n");
}

bool check(int v, int k) {
    T += v;
    if (k < n) {
        return T < M;
    } else {
        return T == M;
    }
}

void Try(int k) {
    for (int v = 1; v <= M - T - (n - k); v++) {
        if (check(v, k)) {
            X[k] = v;
            if (k == n) {
                printSol();
            } else {
                Try(k+1);
            }
            T-=v;
        } else {
            T-=v;
        }
    }
}

int main () {
    cin >> n >> M;
    Try(1);
    return 0;
}