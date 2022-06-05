#include <iostream>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int WHITE = 0;
const int YELLOW = 1;
const int GREEN = 2;
const int BLUE = 3;
const int RED = 4;
const int ORANGE = 5;

char color_arr[6] = {'w', 'y', 'g', 'b', 'r', 'o'};

class node
{
public:
    int color[6];
    node()
    {
        for (int i = 0; i < 6; i++)
            color[i] = i;
    }
};

node cube[3][3][3];

void XZ(char side, int dir)
{
    int color[4];
    if (side == 'L')
    {
        // 시계 방향 위 -> 앞 -> 밑 -> 뒤
        // L+
        if (dir == 1)
        {
            for (int z = 0; z < 3; z++)
            {
                for (int y = 0; y < 3; y++)
                {
                    // {위 밑 좌 우 앞 뒤}
                    color[0] = cube[z][y][0].color[0]; // 위
                    color[1] = cube[z][y][0].color[1]; // 밑
                    color[2] = cube[z][y][0].color[4]; // 앞
                    color[3] = cube[z][y][0].color[5]; // 뒤

                    cube[z][y][0].color[0] = color[3]; // 위 <- 뒤
                    cube[z][y][0].color[1] = color[2]; // 밑 <- 앞
                    cube[z][y][0].color[4] = color[0]; // 앞 <- 위
                    cube[z][y][0].color[5] = color[1]; // 뒤 <- 밑
                }
            }

            //                  0               2               8               6
            node t[4] = {cube[0][0][0], cube[0][2][0], cube[2][2][0], cube[2][0][0]};
            cube[0][0][0] = t[3]; // 0 <- 6
            cube[0][2][0] = t[0]; // 2 <- 0
            cube[2][2][0] = t[1]; // 8 <- 2
            cube[2][0][0] = t[2]; // 6 <- 8

            //                  1               5               7               3
            node tt[4] = {cube[0][1][0], cube[1][2][0], cube[2][1][0], cube[1][0][0]};
            cube[0][1][0] = tt[3]; // 1 <- 3
            cube[1][2][0] = tt[0]; // 5 <- 1
            cube[2][1][0] = tt[1]; // 7 <- 5
            cube[1][0][0] = tt[2]; // 3 <- 7
        }
        // 반시계 방향 위 -> 뒤 -> 밑 -> 앞
        // L-
        else
        {
            for (int z = 0; z < 3; z++)
            {
                for (int y = 0; y < 3; y++)
                {
                    // {위 밑 좌 우 앞 뒤}
                    color[0] = cube[z][y][0].color[0]; // 위
                    color[1] = cube[z][y][0].color[1]; // 밑
                    color[2] = cube[z][y][0].color[4]; // 앞
                    color[3] = cube[z][y][0].color[5]; // 뒤

                    cube[z][y][0].color[0] = color[2]; // 위 <- 앞
                    cube[z][y][0].color[1] = color[3]; // 밑 <- 뒤
                    cube[z][y][0].color[4] = color[1]; // 앞 <- 밑
                    cube[z][y][0].color[5] = color[0]; // 뒤 <- 위
                }
            }

            //                  0               2               8               6
            node t[4] = {cube[0][0][0], cube[0][2][0], cube[2][2][0], cube[2][0][0]};
            cube[0][0][0] = t[1]; // 0 <- 2
            cube[0][2][0] = t[2]; // 2 <- 8
            cube[2][2][0] = t[3]; // 8 <- 6
            cube[2][0][0] = t[0]; // 6 <- 0

            //                  1               5               7               3
            node tt[4] = {cube[0][1][0], cube[1][2][0], cube[2][1][0], cube[1][0][0]};
            cube[0][1][0] = tt[1]; // 1 <- 5
            cube[1][2][0] = tt[2]; // 5 <- 7
            cube[2][1][0] = tt[3]; // 7 <- 3
            cube[1][0][0] = tt[0]; // 3 <- 1
        }
    }
    else
    {
        // 시계 방향 위 -> 뒤 -> 밑 -> 앞
        // R+
        if (dir == 1)
        {
            for (int z = 0; z < 3; z++)
            {
                for (int y = 0; y < 3; y++)
                {
                    // {위 밑 좌 우 앞 뒤}
                    color[0] = cube[z][y][2].color[0]; // 위
                    color[1] = cube[z][y][2].color[1]; // 밑
                    color[2] = cube[z][y][2].color[4]; // 앞
                    color[3] = cube[z][y][2].color[5]; // 뒤

                    cube[z][y][2].color[0] = color[2]; // 위 <- 앞
                    cube[z][y][2].color[1] = color[3]; // 밑 <- 뒤
                    cube[z][y][2].color[4] = color[1]; // 앞 <- 밑
                    cube[z][y][2].color[5] = color[0]; // 뒤 <- 위
                }
            }
            //                  0               2               8               6
            node t[4] = {cube[0][0][2], cube[0][2][2], cube[2][2][2], cube[2][0][2]};
            cube[0][0][2] = t[1]; // 0 <- 2
            cube[0][2][2] = t[2]; // 2 <- 8
            cube[2][2][2] = t[3]; // 8 <- 6
            cube[2][0][2] = t[0]; // 6 <- 0

            //                  1               5               7               3
            node tt[4] = {cube[0][1][2], cube[1][2][2], cube[2][1][2], cube[1][0][2]};
            cube[0][1][2] = tt[1]; // 1 <- 5
            cube[1][2][2] = tt[2]; // 5 <- 7
            cube[2][1][2] = tt[3]; // 7 <- 3
            cube[1][0][2] = tt[0]; // 3 <- 1
        }
        // 반시계 방향 위->앞->밑->뒤
        // R-
        else
        {
            for (int z = 0; z < 3; z++)
            {
                for (int y = 0; y < 3; y++)
                {
                    // {위 밑 좌 우 앞 뒤}
                    color[0] = cube[z][y][2].color[0]; // 위
                    color[1] = cube[z][y][2].color[1]; // 밑
                    color[2] = cube[z][y][2].color[4]; // 앞
                    color[3] = cube[z][y][2].color[5]; // 뒤

                    cube[z][y][2].color[0] = color[3]; // 위 <- 뒤
                    cube[z][y][2].color[1] = color[2]; // 밑 <- 앞
                    cube[z][y][2].color[4] = color[0]; // 앞 <- 위
                    cube[z][y][2].color[5] = color[1]; // 뒤 <- 밑
                }
            }
            //                  0               2               8               6
            node t[4] = {cube[0][0][2], cube[0][2][2], cube[2][2][2], cube[2][0][2]};
            cube[0][0][2] = t[3]; // 0 <- 6
            cube[0][2][2] = t[0]; // 2 <- 0
            cube[2][2][2] = t[1]; // 8 <- 2
            cube[2][0][2] = t[2]; // 6 <- 8

            //                  1               5               7               3
            node tt[4] = {cube[0][1][2], cube[1][2][2], cube[2][1][2], cube[1][0][2]};
            cube[0][1][2] = tt[3]; // 1 <- 3
            cube[1][2][2] = tt[0]; // 5 <- 1
            cube[2][1][2] = tt[1]; // 7 <- 5
            cube[1][0][2] = tt[2]; // 3 <- 7
        }
    }
}

void XY(char side, int dir)
{
    int color[4];
    if (side == 'U')
    {
        // 시계 방향 앞 -> 좌 -> 뒤 -> 우
        // 위 밑 좌 우 앞 뒤
        // U+
        if (dir == 1)
        {
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    color[0] = cube[0][y][x].color[4]; // 앞
                    color[1] = cube[0][y][x].color[5]; // 뒤
                    color[2] = cube[0][y][x].color[2]; // 좌
                    color[3] = cube[0][y][x].color[3]; // 우

                    cube[0][y][x].color[4] = color[3]; // 앞 <- 우
                    cube[0][y][x].color[5] = color[2]; // 뒤 <- 좌
                    cube[0][y][x].color[2] = color[0]; // 좌 <- 앞
                    cube[0][y][x].color[3] = color[1]; // 우 <- 뒤
                }
            }

            //                  0               2           8                 6
            node t[4] = {cube[0][0][0], cube[0][0][2], cube[0][2][2], cube[0][2][0]};
            cube[0][0][0] = t[3]; // 0 <- 6
            cube[0][0][2] = t[0]; // 2 <- 0
            cube[0][2][2] = t[1]; // 8 <- 2
            cube[0][2][0] = t[2]; // 6 <- 8

            //                  1               5               7               3
            node tt[4] = {cube[0][0][1], cube[0][1][2], cube[0][2][1], cube[0][1][0]};
            cube[0][0][1] = tt[3]; // 1 <- 3
            cube[0][1][2] = tt[0]; // 5 <- 1
            cube[0][2][1] = tt[1]; // 7 <- 5
            cube[0][1][0] = tt[2]; // 3 <- 7
        }
        //반시계 방향 앞 -> 우 -> 뒤 -> 좌
        // U-
        else
        {
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    color[0] = cube[0][y][x].color[4]; // 앞
                    color[1] = cube[0][y][x].color[5]; // 뒤
                    color[2] = cube[0][y][x].color[2]; // 좌
                    color[3] = cube[0][y][x].color[3]; // 우

                    cube[0][y][x].color[4] = color[2]; // 앞 <- 좌
                    cube[0][y][x].color[5] = color[3]; // 뒤 <- 우
                    cube[0][y][x].color[2] = color[1]; // 좌 <- 뒤
                    cube[0][y][x].color[3] = color[0]; // 우 <- 앞
                }
            }

            //                  0               2           8                 6
            node t[4] = {cube[0][0][0], cube[0][0][2], cube[0][2][2], cube[0][2][0]};
            cube[0][0][0] = t[1]; // 0 <- 2
            cube[0][2][0] = t[0]; // 6 <- 0
            cube[0][2][2] = t[3]; // 8 <- 6
            cube[0][0][2] = t[2]; // 2 <- 8

            //                  1               5               7               3
            node tt[4] = {cube[0][0][1], cube[0][1][2], cube[0][2][1], cube[0][1][0]};
            cube[0][0][1] = tt[1]; // 1 <- 5
            cube[0][1][0] = tt[0]; // 3 <- 1
            cube[0][2][1] = tt[3]; // 7 <- 3
            cube[0][1][2] = tt[2]; // 5 <- 7
        }
    }
    else
    {
        // 시계 방향 앞 -> 우 -> 뒤 -> 좌
        // 위 밑 좌 우 앞 뒤
        if (dir == 1)
        {
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    color[0] = cube[2][y][x].color[4]; // 앞
                    color[1] = cube[2][y][x].color[5]; // 뒤
                    color[2] = cube[2][y][x].color[2]; // 좌
                    color[3] = cube[2][y][x].color[3]; // 우

                    cube[2][y][x].color[4] = color[2]; // 앞 <- 좌
                    cube[2][y][x].color[5] = color[3]; // 뒤 <- 우
                    cube[2][y][x].color[2] = color[1]; // 좌 <- 뒤
                    cube[2][y][x].color[3] = color[0]; // 우 <- 앞
                }
            }

            //                  0               2           8                 6
            node t[4] = {cube[2][0][0], cube[2][0][2], cube[2][2][2], cube[2][2][0]};
            cube[2][0][0] = t[1]; // 0 <- 2
            cube[2][2][0] = t[0]; // 6 <- 0
            cube[2][2][2] = t[3]; // 8 <- 6
            cube[2][0][2] = t[2]; // 2 <- 8

            //                  1               5               7               3
            node tt[4] = {cube[2][0][1], cube[2][1][2], cube[2][2][1], cube[2][1][0]};
            cube[2][0][1] = tt[1]; // 1 <- 5
            cube[2][1][0] = tt[0]; // 3 <- 1
            cube[2][2][1] = tt[3]; // 7 <- 3
            cube[2][1][2] = tt[2]; // 5 <- 7
        }
        //반시계 방향 앞 -> 좌 -> 뒤 -> 우
        else
        {
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    color[0] = cube[2][y][x].color[4]; // 앞
                    color[1] = cube[2][y][x].color[5]; // 뒤
                    color[2] = cube[2][y][x].color[2]; // 좌
                    color[3] = cube[2][y][x].color[3]; // 우

                    cube[2][y][x].color[4] = color[3]; // 앞 <- 우
                    cube[2][y][x].color[5] = color[2]; // 뒤 <- 좌
                    cube[2][y][x].color[2] = color[0]; // 좌 <- 앞
                    cube[2][y][x].color[3] = color[1]; // 우 <- 뒤
                }
            }
            //                  0               2           8                 6
            node t[4] = {cube[2][0][0], cube[2][0][2], cube[2][2][2], cube[2][2][0]};
            cube[2][0][0] = t[3]; // 0 <- 6
            cube[2][0][2] = t[0]; // 2 <- 0
            cube[2][2][2] = t[1]; // 8 <- 2
            cube[2][2][0] = t[2]; // 6 <- 8

            //                  1               5               7               3
            node tt[4] = {cube[2][0][1], cube[2][1][2], cube[2][2][1], cube[2][1][0]};
            cube[2][0][1] = tt[3]; // 1 <- 3
            cube[2][1][2] = tt[0]; // 5 <- 1
            cube[2][2][1] = tt[1]; // 7 <- 5
            cube[2][1][0] = tt[2]; // 3 <- 7
        }
    }
}

void YZ(char side, int dir)
{
    int color[4];
    if (side == 'F')
    {
        // 0  1  2  3  4  5
        // 위 밑 좌 우 앞 뒤
        // 시계 방향 위 -> 우 -> 밑 -> 좌
        // F+
        if (dir == 1)
        {
            for (int z = 0; z < 3; z++)
            {
                for (int x = 0; x < 3; x++)
                {
                    color[0] = cube[z][2][x].color[0]; // 위
                    color[1] = cube[z][2][x].color[3]; // 우
                    color[2] = cube[z][2][x].color[1]; // 밑
                    color[3] = cube[z][2][x].color[2]; // 좌

                    cube[z][2][x].color[0] = color[3]; // 위 <- 좌
                    cube[z][2][x].color[3] = color[0]; // 우 <- 위
                    cube[z][2][x].color[1] = color[1]; // 밑 <- 우
                    cube[z][2][x].color[2] = color[2]; // 좌 <- 밑
                }
            }
            //                  0               2             8             6
            node t[4] = {cube[0][2][0], cube[0][2][2], cube[2][2][2], cube[2][2][0]};

            cube[0][2][0] = t[3]; // 0 <- 6
            cube[0][2][2] = t[0]; // 2 <- 0
            cube[2][2][2] = t[1]; // 8 <- 2
            cube[2][2][0] = t[2]; // 6 <- 8

            //                  1               5              7               3
            node tt[4] = {cube[0][2][1], cube[1][2][2], cube[2][2][1], cube[1][2][0]};

            cube[0][2][1] = tt[3]; // 1 <- 3
            cube[1][2][2] = tt[0]; // 5 <- 1
            cube[2][2][1] = tt[1]; // 7 <- 5
            cube[1][2][0] = tt[2]; // 3 <- 7
        }
        // 0  1  2  3  4  5
        // 위 밑 좌 우 앞 뒤
        // 반시계 방향 위 -> 좌 -> 밑 -> 우
        // F-
        else
        {
            for (int z = 0; z < 3; z++)
            {
                for (int x = 0; x < 3; x++)
                {
                    color[0] = cube[z][2][x].color[0]; // 위
                    color[1] = cube[z][2][x].color[3]; // 우
                    color[2] = cube[z][2][x].color[1]; // 밑
                    color[3] = cube[z][2][x].color[2]; // 좌

                    cube[z][2][x].color[0] = color[1]; // 위 <- 우
                    cube[z][2][x].color[3] = color[2]; // 우 <- 밑
                    cube[z][2][x].color[1] = color[3]; // 밑 <- 좌
                    cube[z][2][x].color[2] = color[0]; // 좌 <- 위
                }
            }
            //                  0               2             8             6
            node t[4] = {cube[0][2][0], cube[0][2][2], cube[2][2][2], cube[2][2][0]};

            cube[0][2][0] = t[1]; // 0 <- 2
            cube[2][2][0] = t[0]; // 6 <- 0
            cube[2][2][2] = t[3]; // 8 <- 6
            cube[0][2][2] = t[2]; // 2 <- 8

            //                  1               5              7               3
            node tt[4] = {cube[0][2][1], cube[1][2][2], cube[2][2][1], cube[1][2][0]};

            cube[0][2][1] = tt[1]; // 1 <- 5
            cube[1][2][0] = tt[0]; // 3 <- 1
            cube[2][2][1] = tt[3]; // 7 <- 3
            cube[1][2][2] = tt[2]; // 5 <- 7
        }
    }
    else
    {
        // 시계 방향 위 -> 좌 -> 밑 -> 우
        // B+
        if (dir == 1)
        {
            for (int z = 0; z < 3; z++)
            {
                for (int x = 0; x < 3; x++)
                {
                    color[0] = cube[z][0][x].color[0]; // 위
                    color[1] = cube[z][0][x].color[3]; // 우
                    color[2] = cube[z][0][x].color[1]; // 밑
                    color[3] = cube[z][0][x].color[2]; // 좌

                    cube[z][0][x].color[0] = color[1]; // 위 <- 우
                    cube[z][0][x].color[3] = color[2]; // 우 <- 밑
                    cube[z][0][x].color[1] = color[3]; // 밑 <- 좌
                    cube[z][0][x].color[2] = color[0]; // 좌 <- 위
                }
            }
            //                  0               2             8             6
            node t[4] = {cube[0][0][0], cube[0][0][2], cube[2][0][2], cube[2][0][0]};

            cube[0][0][0] = t[1]; // 0 <- 2
            cube[2][0][0] = t[0]; // 6 <- 0
            cube[2][0][2] = t[3]; // 8 <- 6
            cube[0][0][2] = t[2]; // 2 <- 8

            //                  1               5              7               3
            node tt[4] = {cube[0][0][1], cube[1][0][2], cube[2][0][1], cube[1][0][0]};

            cube[0][0][1] = tt[1]; // 1 <- 5
            cube[1][0][0] = tt[0]; // 3 <- 1
            cube[2][0][1] = tt[3]; // 7 <- 3
            cube[1][0][2] = tt[2]; // 5 <- 7
        }
        // 반시계 방향 위 -> 우 -> 밑 -> 좌
        else
        {
            for (int z = 0; z < 3; z++)
            {
                for (int x = 0; x < 3; x++)
                {
                    color[0] = cube[z][0][x].color[0]; // 위
                    color[1] = cube[z][0][x].color[3]; // 우
                    color[2] = cube[z][0][x].color[1]; // 밑
                    color[3] = cube[z][0][x].color[2]; // 좌

                    cube[z][0][x].color[0] = color[3]; // 위 <- 좌
                    cube[z][0][x].color[3] = color[0]; // 우 <- 위
                    cube[z][0][x].color[1] = color[1]; // 밑 <- 우
                    cube[z][0][x].color[2] = color[2]; // 좌 <- 밑
                }
            }

            //                  0               2             8             6
            node t[4] = {cube[0][0][0], cube[0][0][2], cube[2][0][2], cube[2][0][0]};

            cube[0][0][0] = t[3]; // 0 <- 6
            cube[0][0][2] = t[0]; // 2 <- 0
            cube[2][0][2] = t[1]; // 8 <- 2
            cube[2][0][0] = t[2]; // 6 <- 8

            //                  1               5              7               3
            node tt[4] = {cube[0][0][1], cube[1][0][2], cube[2][0][1], cube[1][0][0]};

            cube[0][0][1] = tt[3]; // 1 <- 3
            cube[1][0][2] = tt[0]; // 5 <- 1
            cube[2][0][1] = tt[1]; // 7 <- 5
            cube[1][0][0] = tt[2]; // 3 <- 7
        }
    }
}

void show_map()
{
    // 윗면
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            cout << color_arr[cube[0][y][x].color[0]];
        }
        cout << "\n";
    }
}

int main()
{
    FIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        for (int z = 0; z < 3; z++)
            for (int y = 0; y < 3; y++)
                for (int x = 0; x < 3; x++)
                    cube[z][y][x] = node();

        for (int i = 0; i < n; i++)
        {
            char side, dir_clock;
            cin >> side >> dir_clock;
            int dir = (dir_clock == '+') ? 1 : -1;
            if (side == 'U' || side == 'D')
                XY(side, dir);
            if (side == 'L' || side == 'R')
                XZ(side, dir);
            if (side == 'F' || side == 'B')
                YZ(side, dir);
        }
        show_map();
    }
}