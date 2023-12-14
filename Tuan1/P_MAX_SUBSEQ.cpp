#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> sequence(n);

    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }
    // Thuật toán Kadane
    int max_so_far = 0;      // Giá trị đoạn con lớn nhất
    int max_ending_here = 0; // Giá trị đoạn con đến hiện tại

    for (int i = 0; i < n; i++)
    {
        max_ending_here += sequence[i];
        if (max_ending_here > max_so_far) // Khi giá trị hiện tại lớn hơn max
        {
            max_so_far = max_ending_here; // Cập nhật max
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0; // Nếu giá trị hiện tại < 0 thì reset
        }
    }

    cout << max_so_far << endl;
    return 0;
}