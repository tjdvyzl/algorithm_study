#include <iostream>
using namespace std;
#include <vector>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

vector<int> graph[200002];

vector<int> vec[200002];

bool v[200002];

long long ans = 0;
int N;
string arr;

void dfs(int bound, int input)
{
    v[input] = true;

    for (int i = 0; i < graph[input].size(); i++)
    {
        int e = graph[input][i];

        if (v[e])
            continue;

        // 처음 실외를 방문할 때
        if (bound == -1 && arr[e - 1] == '0')
        {
            vec[e].push_back(input);
            dfs(e, e);
        }

        // 처음 실외를 방문하지 않을 때
        else if (arr[e - 1] == '0')
        {
            dfs(bound, e);
        }

        // 다음 정점이 실내일 때
        if (arr[e - 1] == '1')
        {
            // 실외를 방문한 적이 있을 때
            if (bound != -1)
            {
                vec[bound].push_back(e);
            }
            else
            {
                ans++;
            }
        }
    }
}

int main()
{
    FIO;

    cin >> N >> arr;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (arr[i - 1] == '1')
        {
            dfs(-1, i);
            v[i] = false;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        ans += vec[i].size() * (vec[i].size() - 1);
    }

    cout << ans << "\n";
}