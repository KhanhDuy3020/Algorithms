#include <bits/stdc++.h>

#define MAX 100

using namespace std;
int n;
vector<int> a;

int MaxLeftMid(int i, int j)
{
    int maxLM = a[j];
    int s = 0;
    for (int k = j; k >= i; k --)
    {
        s += a[k];
        maxLM = max(maxLM, s);
    }
    return maxLM;
}

int MaxRightMid(int i, int j)
{
    int maxRM = a[i];
    int s = 0;
    for (int k = i; k <= j; k++)
    {
        s += a[k];
        maxRM = max(maxRM, s);
    }
    return maxRM;
}

int SubSeqMax(int i, int j)
{
    if (i == j)
        return a[i];
    int mid = (i + j) / 2;
    int wL = SubSeqMax(i, mid);
    int wR = SubSeqMax(mid + 1, j);
    int maxLM = MaxLeftMid(i, mid);
    int maxRM = MaxRightMid(mid + 1, j);
    int wM = maxLM + maxRM;
    return max(max(wL, wR), wM);
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    cout << SubSeqMax(0,n-1);
    return 0;
}