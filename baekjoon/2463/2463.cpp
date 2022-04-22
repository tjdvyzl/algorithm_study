#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define C 1000000000
typedef long long ll;

class node
{
public:
    int a;
    int b;
    int w;
    node(int a, int b, int w) : a(a), b(b), w(w) {}
};

int parent[100005];

ll v[100005];

int N, M;

ll sum = 0;

ll ans = 0;

vector<node> vec;

bool compare(node a, node b)
{
    return a.w > b.w;
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b, int w)
{
    //cout << a << ", " << b << ", " << sum << ", " << ans << "\n";
    a = find(a);
    b = find(b);
    if (a == b)
    {
        sum -= w;
        return;
    }
    else if (a > b)
    {
        parent[a] = b;
        ans += v[a] * v[b] * sum;
        v[b] += v[a];
    }
    else
    {
        parent[b] = a;
        ans += v[a] * v[b] * sum;
        v[a] += v[b];
    }
    sum -= w;
    ans %= C;
}

int main()
{
    FIO;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i, v[i] = 1;

    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        sum += w;
        vec.push_back(node(a, b, w));
    }

    sort(vec.begin(), vec.end(), compare);

    for (auto e : vec)
    {
        merge(e.a, e.b, e.w);
    }

    cout << ans % C << "\n";
}