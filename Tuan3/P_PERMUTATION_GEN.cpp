#include <bits/stdc++.h>
#define SIZE 100
int A[SIZE], A_MARK[SIZE] = {0}, n;

using namespace std;

void printSolution()
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    printf("\n");
}

void Try(int k)
{
    if (k == n)
    {
        printSolution();
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (A_MARK[i] == 0)
            {
                A[k] = i + 1;
                A_MARK[i] = 1;
                Try(k + 1);
                A_MARK[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    Try(0);
    return 0;
}