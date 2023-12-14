#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int CHECK[MAX];
int n, m, d[MAX][MAX], X[MAX], totalDistance = 0;
bool check = true;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
        CHECK[X[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> d[i][j];
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (CHECK[a] >= CHECK[b])
        {
            check = false;
        }
    }

    if (!check)
    {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i < n; ++i)
    {
        totalDistance += d[X[i]][X[i + 1]];
    }
    totalDistance += d[X[n]][X[1]];

    cout << totalDistance << "\n";

    return 0;
}
