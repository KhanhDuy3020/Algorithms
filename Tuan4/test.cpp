#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int N, M;               // N Số môn, M số kỳ học
int C[MAX];             // Số tín chỉ mỗi môn
int A[MAX][MAX];        // Ma trận môn i bắt buộc học trước môn j
int X[MAX];      // Tập chỉ số môn học được học ở kỳ nào
int maxAllKy[MAX];      // Tập chứa giá trị lớn nhất của các kỳ
int maxKy = INT_MIN;    // Giá trị lớn nhất mỗi kỳ
int minAllKy = INT_MAX; // Giá trị nhỏ nhất của các max

bool check(int v, int k)
{ // Kiểm tra môn học k tại kỳ v
    for (int i = 0; i < k; i++)
    {
        if (A[i][k]) // Nếu môn i phải đăng ký trước môn k
        {
            if (X[i] >= v)
                return false; // Khi kỳ học môn i >= kỳ học môn k thì false
        }
        else if (A[k][i]) // Nếu môn k phải đăng ký trước môn i
        {
            if (v >= X[i])
                return false; // Khi kỳ học môn i <= kỳ học môn k thì false
        }
    }
    return true;
}

void Try(int k)
{
    for (int i = 0; i < M; i++)
    {
        if (check(i, k))
        {
            X[k] = i; // Môn k được học vào kỳ i
            maxAllKy[i] += C[k];
            if (k == N - 1)
            {
                maxKy = INT_MIN;
                for (int i = 0; i < M; i++)
                {
                    maxKy = max(maxKy, maxAllKy[i]);
                }
                minAllKy = min(maxKy, minAllKy);
            }
            else
                Try(k + 1);
            maxAllKy[i] -= C[k];
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    Try(0);
    cout << minAllKy << endl;
    return 0;
}