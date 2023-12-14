#include <bits/stdc++.h>

#define MAX 100

using namespace std;
int n,hasMax,has;
int c[2 * MAX + 1][2 * MAX + 1];
int cmin = INT_MAX;
int X[2 * MAX + 1];
int visited[2 * MAX + 1] = {0};
int d = 0;
int ans = INT_MAX;

bool check(int k, int i)
{
    if (visited[i])
        return false;
    if (i <= n)
    {
        if (has == hasMax)
            return false; // Nếu i <= n mà xe đã có người thì không đón nữa
    }
    else
    {
        if (visited[i - n] == 0)
            return false; // Nếu i > n mà chưa đón khách ở i - n thì không thể trả
    }
    return true;
}

void Try(int k)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (check(k, i))
        {
            if (i <= n)
                has++; // Khi i <=n thì đón khách
            else
                has--; // Khi i > n thì trả khách
            visited[i] = 1;
            X[k] = i;
            d += c[X[k - 1]][X[k]];
            if (k == 2 * n)
            {
                ans = min(ans, d + c[X[2 * n]][X[0]]);
            }
            else if (ans > (d + (2 * n - i + 1) * cmin))
            {
                Try(k + 1);
            }
            visited[i] = 0;
            d -= c[X[k - 1]][X[k]];
            if (i <= n)
                has--;
            else
                has++;
        }
    }
}

int main()
{
    cin >> n>>hasMax;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }
    X[0] = 0;
    Try(1);
    cout << ans;
    return 0;
}