#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int sum_month[13];

int N;

int ans = 1;

vector<pair<int, int>> vec;
// bound_src 부터 bound_dst 사이에는 무조건 꽃이 한 가지 이상 피어있어야함
// 60 ~ 334

/*
    60 ~ 334 사이의 꽃들을 무조건 만족 시켜야한다.
    dst가 최대한 커야한다. (60 ~ 334 사이에 빈 공간이 없도록 하면서)
*/

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

void init()
{
    sum_month[1] = month[1];

    int s = month[1];

    for (int i = 2; i <= 12; i++)
    {
        sum_month[i] = s + month[i];
        s += month[i];
    }
}

int main()
{
    FIO;

    init();

    const int bound_src = sum_month[2] + 1;
    const int bound_dst = sum_month[10] + 30 + 1;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int src1, dst1, src2, dst2;
        cin >> src1 >> dst1 >> src2 >> dst2;

        int total_src = sum_month[src1 - 1] + dst1;
        int total_dst = sum_month[src2 - 1] + dst2;

        if (total_dst >= 60 && total_src <= 334)
            vec.push_back(make_pair(total_src, total_dst));
    }

    sort(vec.begin(), vec.end(), compare);

    int bs = -1, bd = -1;

    int i = 0;

    // 처음에 src가 60이하라면 dst가 가장 큰 값을 기준으로 잡아야한다.
    for (i; i < vec.size(); i++)
    {
        if (vec[i].first > 60)
            break;
        if (bd < vec[i].second)
        {
            bs = vec[i].first;
            bd = vec[i].second;
        }
    }

    i--;

    for (i; i < vec.size(); i++)
    {

        if (bd >= bound_dst)
            break;

        int temp = bd;

        for (int j = i; j < vec.size(); j++)
        {
            if (vec[j].first > bd)
                break;

            temp = max(temp, vec[j].second);
        }
        if (temp != bd)
        {
            bd = temp;
            ans++;
        }
    }

    if (bs > bound_src || bd < bound_dst)
        cout << 0 << "\n";
    else if (bs <= bound_src && bd >= bound_dst)
        cout << ans << "\n";
}