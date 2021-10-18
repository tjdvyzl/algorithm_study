# 문제주소
https://programmers.co.kr/learn/courses/30/lessons/81302


<br><br>
# 문제 접근 방법
bfs(다익스트라) + 브루트포스로 접근해서 풀었다. string 이차원 벡터로 값들 모두 저장하고, 크기가 총 5개라고 이미 지정이 되어있기 때문에 for문 i를 0부터 5까지 돌려서 string 일차원 벡터 graph에 초기화하고 담는 과정을 반복했다. 좌표값이 P인 좌표를 vec 배열에 저장한 후에 vec를 탐색하면서 각 좌표에 대한 bfs를 돌렸다.
그리고 내가 생각하기에 가장 중요했던 방역수칙을 위반하는 좌표를 어떻게 확인하는지가 관건인데, 이것은 다익스트라로 bfs를 탐색하는과정에서 최소 거리를 저장했고, 좌표값 끼리 뺀 절대값과 비교하여 같은 경우에 탐색 과정에서 X를 방문한 적이 있는지의 여부에 따라 문제를 해결했다.
 

<br><br>
# 착각했던 점
<p>
bool 함수인 check 함수에서 y나 x가 4인 경우를 간과하여 테케 2,8,22 가 틀렸다고 나왔다.
</p>
<br><br>


# 코드
<pre>
<code>
#include < string>
#include < vector>
#include < iostream>
#include < queue>

using namespace std;

#define FIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define MAX 987654321

class wall {
public:
    int y;
    int x;
    bool isPassed; // bfs 과정에서 O를 방문 했는지 체크.
    int cost;

    wall(int y, int x, bool isPassed, int cost) :y(y), x(x), isPassed(isPassed),cost(cost) {};
};

string graph[6]; // 인덱스 마다 대기실 정보 저장.
vector< pair< int, int>> vec;

int dy[4] = { -1,1,0,0 }; //상 하 좌 우
int dx[4] = { 0,0,-1,1 };

bool check(int y, int x) {
    if (y < 0 || y > 4 || x < 0 || x > 4)
        return false;

    return true;
}

bool bfs(int yy, int xx) {
    queue< wall> q;
    q.push(wall(yy, xx, false, 0));

    int dis[6][6];
    bool v[6][6]; // true면 방역위반인 사람이 있음.

    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++) {
            dis[y][x] = MAX;
            v[y][x] = false;
        }

    dis[yy][xx] = -1;

    while (!q.empty()) {
        wall t = q.front(); q.pop();
        
        if ((t.y != yy || t.x != xx) && graph[t.y][t.x] == 'P') {
            int dis_x = abs(xx - t.x);
            int dis_y = abs(yy - t.y);

            int total_dis = dis_x + dis_y;

            if (total_dis == t.cost) {
                if (total_dis <= 1)
                    return false;

                else if (total_dis <= 2)
                {
                    if (t.isPassed == false)
                        return false;
                }
            }
        }

        for (int d = 0; d < 4; d++) {
            int ty = t.y + dy[d];
            int tx = t.x + dx[d];
            int tcost = t.cost + 1;

            if (check(ty, tx) && dis[ty][tx] >= tcost) {
                dis[ty][tx] = tcost;

                if (graph[ty][tx] == 'X')
                    q.push(wall(ty, tx, true, tcost));
                
                if (graph[ty][tx] == 'O') 
                    q.push(wall(ty, tx, t.isPassed, tcost));

                if(graph[ty][tx] == 'P')
                    q.push(wall(ty, tx, t.isPassed, tcost));
            }
        }
    }

    return true;
}

vector< int> solution(vector< vector< string>> places) {
    FIO;

    vector< int> answer;


    for (int e = 0; e < 5; e++) { // places 전체 탐색 --> e 당 대기실 하나
        bool isFinish = true;
        bool isP = false;

        graph->clear();
        vec.clear();

        for (int i = 0; i < 5; i++) {// 각 p 좌표값 하나하나 bfs 돌려서 해당 좌표에 대한 거리두기 여부 체크
            graph[i] = places[e][i];
        }

        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                if (graph[y][x] == 'P') {
                    vec.push_back(make_pair(y, x));
                    isP = true;
                }
            }
        }

        if (isP == false) {
            answer.push_back(1);
        }
        else {
            bool check[6][6];
            for (int y = 0; y < 5; y++)
                for (int x = 0; x < 5; x++)
                    check[y][x] = false;

            for (int w = 0; w < vec.size(); w++) {
                bool tmp;
                if (check[vec[w].first][vec[w].second] != true) {
                    check[vec[w].first][vec[w].second] = true;
                    tmp = bfs(vec[w].first, vec[w].second);
                }
                
                if (tmp != true)
                {
                    isFinish = false;
                    break;
                }
            }

            if (isFinish == false)
                answer.push_back(0);
            else
                answer.push_back(1);
        }
    }

    return answer;
}
</code>
</pre>

<br><br>
<p>

</p>