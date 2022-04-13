#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <cmath>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N;

pair<int, int> arr_even[3] = {{1, 2}, {1, 3}, {2, 3}};
pair<int, int> arr_odd[3] = {{1, 3}, {1, 2}, {3, 2}};

// a에서 b로 옮길 수 있는지 확인
bool check(stack<int> st[4], int a, int b)
{
    if (!st[a].empty() && (st[b].empty() || (st[a].top() < st[b].top())))
        return true;
    return false;
}

int main()
{
    FIO;

    cin >> N;

    stack<int> t[4];

    for (int i = N; i >= 1; i--)
        t[1].push(i);

    cout << (int)pow(2, N) - 1 << "\n";

    pair<int, int> arr[3];

    if (N % 2)
        for (int i = 0; i < 3; i++)
            arr[i] = arr_odd[i];
    else
        for (int i = 0; i < 3; i++)
            arr[i] = arr_even[i];

    int k = 0;

    while (t[3].size() < N)
    {
        int src = arr[k % 3].first;
        int dst = arr[k % 3].second;

        if (check(t, src, dst))
        {
            int tt = t[src].top();
            t[src].pop();
            t[dst].push(tt);
            cout << src << " " << dst << "\n";
        }
        else
        {
            int tt = t[dst].top();
            t[dst].pop();
            t[src].push(tt);
            cout << dst << " " << src << "\n";
        }
        k++;
    }
}