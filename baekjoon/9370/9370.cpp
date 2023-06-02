#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0);
#define MAX 1000000005
typedef pair<int,int> pii;
typedef pair<long long, long long> pllll;
typedef long long ll;

int tc;

int dis[2002];
vector<pii> graph[2002];
bool target[2002];
bool v[2002];
pii gh;

void init() {
    fill(&dis[0], &dis[0] + 2002, MAX);
    for(int i=1;i<=2000;i++) graph[i].clear();
    memset(target, false, sizeof(target));
    memset(v, false, sizeof(v));
}

void bfs(int src) {
    dis[src] = 0;
    queue<pii> q;
    q.push({src,0});
    while(!q.empty()){
        pii t = q.front(); q.pop();
        for(int i=0;i<graph[t.first].size();i++){
            int next_pos = graph[t.first][i].first;
            int next_cost = graph[t.first][i].second;
            if(next_cost + t.second >= dis[next_pos]) continue;
            if((t.first == gh.first || t.first == gh.second) && (next_pos == gh.first || next_pos == gh.second)) gh = {t.first, next_pos};
            dis[next_pos] = next_cost + t.second;
            q.push({next_pos, next_cost + t.second});
        }
    }
}

vector<int> bfs2(int src) {
    vector<int> res;
    queue<pii> q;
    if(target[src]) {
        v[src] = true;
        res.push_back(src);
    }
    q.push({src, dis[src]});
    while(!q.empty()){
        pii t = q.front(); q.pop();
        for(int i=0;i<graph[t.first].size();i++){
            int next_pos = graph[t.first][i].first;
            int next_cost = graph[t.first][i].second;
            if(next_cost + t.second == dis[next_pos] && !v[next_pos]) {
                if(target[next_pos]) res.push_back(next_pos);
                q.push({next_pos, next_cost + t.second});
                v[next_pos] = true;
            }
        }
    }
    return res;
}

int main() {
    FIO;

    cin >> tc;

    while(tc--){
        init();

        int n,m,t; // 교차로, 도로, 목적지의 후보 개수 
        cin >> n >> m >> t;

        int s,g,h; // 출발지, g h 사이의 교차로를 무조건 들러야함 
        cin >> s >> g >> h;

        gh = {g,h};

        for(int i=0;i<m;i++){
            int a,b,d; // a와 b 사이에 길이 d의 양방향 도로 
            cin >> a >> b >> d;
            graph[a].push_back({b,d});
            graph[b].push_back({a,d});
        }

        for(int i=0;i<t;i++){
            int input; cin >> input;
            target[input] = true;
        }

        bfs(s);

        int src = gh.second;

        vector<int> ans = bfs2(src);

        sort(ans.begin(), ans.end());

        for(auto e:ans) cout << e << " ";
        cout << "\n";
    }
}

