#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100];

void printSolution()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    printf("\n");
}

void Try(int k)
{
    for (int i = 0; i < 2; i++)
    {
        arr[k] = i;
        if (k == n - 1)
        {
            printSolution();
        }
        else
        {
            Try(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    Try(0);
    return 0;
}