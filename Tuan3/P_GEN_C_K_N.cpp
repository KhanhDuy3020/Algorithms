#include <bits/stdc++.h>

using namespace std;

int k, n, A[100];

void printSolution()
{
    for (int i = 0; i < k; i++)
    {
        cout << A[i] << " ";
    }
    printf("\n");
}

void Try(int m, int start)
{
    if (m == k)
    {
        printSolution();
        return;
    }

    for (int i = start; i < n; i++)
    {
        A[m] = i + 1;
        Try(m + 1, i + 1);
    }
}


int main()
{
    cin >> k >> n;
    Try(0,0);
    return 0;
}